#include <unistd.h>
#include "parser.h"

namespace parser {
FileParser::FileParser(const std::string& filename, utils::ErrorHandler* handler) : filename_(filename), err_handler_(handler) {}
FileParser::~FileParser() {
  for (auto v : visitor_tracker_) {
    delete v;
  }

  for (auto decl : decls_map_) {
    delete decl.second;
  }
}

ast::ASTNode* FileParser::_ParseFile(std::error_code& ec, bool check) {
  antlr4::ANTLRFileStream input(filename_);
  SesameLexer lexer(&input);

  // add err listener for lexer
  ErrorVerboseListener lexer_err;
  lexer.removeErrorListeners();
  lexer.addErrorListener(&lexer_err);

  antlr4::CommonTokenStream tokens(&lexer);
  tokens.fill();
  if (lexer_err.has_error()) {
    err_handler_->Error("token parse failed in file: " + filename_);
    err_handler_->Error(lexer_err.err_message());
    ec = utils::CompileError::SYNTAX_ERROR;
    return nullptr;
  }

  // get token strings
  for (auto& token : tokens.getTokens()) {
    token_strings_.push_back(token->toString());

#ifdef DEBUG_0
    std::cout << token->toString() << std::endl;
#endif
  }

  SesameParser parser(&tokens);
  // SLL optimization for antlr4 parser
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);

  // add err listener for parser
  ErrorVerboseListener parser_err;
  parser.removeErrorListeners();
  parser.setErrorHandler(std::make_shared<antlr4::BailErrorStrategy>());

  SesameParser::Compilation_unitContext* compile_ctx = nullptr;
  try {
    compile_ctx = parser.compilation_unit();
  } catch (antlr4::ParseCancellationException& ex) {
    tokens.reset();
    parser.reset();

    parser.addErrorListener(&parser_err);
    parser.setErrorHandler(std::make_shared<antlr4::DefaultErrorStrategy>());
    parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);
    compile_ctx = parser.compilation_unit();
  }

#ifdef DEBUG_0
  std::cout << ((antlr4::tree::ParseTree*)(compile_ctx))->toStringTree(&parser) << std::endl;
#endif

  if (parser_err.has_error()) {
    err_handler_->Error("Parse failed in file: " + filename_);
    err_handler_->Error(parser_err.err_message());
    ec = utils::CompileError::SYNTAX_ERROR;
    return nullptr;
  }

  if (check) {
    // check syntax only
    return nullptr;
  }

  parser::BuildAstVisitor* visitor = new parser::BuildAstVisitor(&parser, filename_);
  visitor_tracker_.push_back(visitor);
  ast::ASTNode* ast = (ast::ASTNode *)(visitor->visitCompilation_unit(compile_ctx));
  AddImportFiles(visitor->import_files());
  return ast;
}

bool FileParser::ParseFile() {
  std::error_code ec;
  _ParseFile(ec, true);
  if (ec) {
    return false;
  } else {
    return true;
  }
}

ast::ASTNode* FileParser::BuildAst(std::vector<std::string> import_path) {
  std::error_code ec;
  auto sesame_ast = _ParseFile(ec, false);

  if (ec) {
    return nullptr;
  }
  sesame_ast->SetTokenStrings(token_strings_); // save token strings to ast

  // import files
  AddPath(import_path);
  for (auto iter = unloaded_file_map_.begin(); iter != unloaded_file_map_.end(); ) {
    LoadImportFile(iter->second);
    iter = unloaded_file_map_.erase(iter);
  }

  // add all declarations to ast
  for (auto it : decls_map_) {
    sesame_ast->AddDeclarations(it.second);
  }

  return sesame_ast;
}

ast::Declarations* FileParser::ParseImportFile(const std::string& fname) {
  antlr4::ANTLRFileStream input(fname);
  SesameLexer lexer(&input);

  // add err listener for lexer
  ErrorVerboseListener lexer_err;
  lexer.removeErrorListeners();
  lexer.addErrorListener(&lexer_err);

  antlr4::CommonTokenStream tokens(&lexer);
  tokens.fill();
  if (lexer_err.has_error()) {
    err_handler_->Error("token parse failed in file: " + fname);
    err_handler_->Error(lexer_err.err_message());
    return nullptr;
  }

  // get token strings
  for (auto& token : tokens.getTokens()) {
#ifdef DEBUG_0
    std::cout << token->toString() << std::endl;
#endif
  }

  SesameParser parser(&tokens);
  // SLL optimization for antlr4 parser
  parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);

  // add err listener for parser
  ErrorVerboseListener parser_err;
  parser.removeErrorListeners();
  parser.setErrorHandler(std::make_shared<antlr4::BailErrorStrategy>());

  SesameParser::Declaration_fileContext* decl_ctx = nullptr;
  try {
    decl_ctx = parser.declaration_file();
  } catch (antlr4::ParseCancellationException& ex) {
    tokens.reset();
    parser.reset();

    parser.addErrorListener(&parser_err);
    parser.setErrorHandler(std::make_shared<antlr4::DefaultErrorStrategy>());
    parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);
    decl_ctx = parser.declaration_file();
  }

#ifdef DEBUG_0
  std::cout << ((antlr4::tree::ParseTree*)(decl_ctx))->toStringTree(&parser) << std::endl;
#endif

  if (parser_err.has_error()) {
    err_handler_->Error("Parse failed in file: " + fname);
    err_handler_->Error(parser_err.err_message());
    return nullptr;
  }

  parser::BuildAstVisitor* visitor = new parser::BuildAstVisitor(&parser, fname);
  visitor_tracker_.push_back(visitor);
  ast::Declarations* decls = (ast::Declarations *)(visitor->visitDeclaration_file(decl_ctx));
  AddImportFiles(visitor->import_files());
  return decls;
}

std::vector<std::string> FileParser::GetTokenStrings() {
  return token_strings_;
}

void FileParser::AddPath(const std::string& path) {
  load_path_.push_back(path);
}

void FileParser::AddPath(std::vector<std::string> paths) {
  for (auto& p : paths) {
    load_path_.push_back(p);
  }
}

/************************************************************************************
* @fn GetImportFilePath
* @brief get file absolutely path by load_path_
* @param
* @author Jona
* @date 2020/12/29
************************************************************************************/
std::string FileParser::GetImportFilePath(const std::string& filename) {
  if (access(filename.c_str(), F_OK) == 0) {
    return filename;
  }

  for (auto& p : load_path_) {
    std::string filepath {""};
    if (p.back() == '/') {
      filepath = p + filename;
    } else {
      filepath = p + "/" + filename;
    }

    if (access(filepath.c_str(), F_OK) != 0) {
      continue;
    } else {
      return filepath;
    }
  }

  return "";
}

void FileParser::LoadImportFile(ast::ImportFileNode* imp_file) {
  std::string fname = ReplaceFilePath(imp_file->filename());
  auto filepath = GetImportFilePath(fname);
  if (filepath.empty()) {
    err_handler_->Error(imp_file->location(), "can not find file " + fname);
    return;
  }

  auto search = decls_map_.find(filepath);
  if (search != decls_map_.end()) {
    // file had been loaded, return 
    return;
  }

  auto decls = ParseImportFile(filepath);
  decls_map_.emplace(std::make_pair(filepath, decls));
}

void FileParser::AddImportFiles(std::vector<ast::ImportFileNode *> files) {
  for (auto f : files) {
    unloaded_file_map_.emplace(std::make_pair(f->filename(), f));
  }
}

/************************************************************************************
* @fn ReplaceFilePath
* @brief import file name like sys.stdio or sys/stdio or sys.stdio.hb or sys/stdio.hb
* @param
* @author Jona
* @date 2020/12/29
************************************************************************************/
std::string FileParser::ReplaceFilePath(std::string fname) {
  std::size_t pos = 0;
  if ((pos = fname.find_first_of(".hb")) != std::string::npos) {
    fname = fname.substr(0, fname.length() - 3);
  }

  while ((pos = fname.find_first_of(".")) != std::string::npos) {
    fname.replace(pos, 1, "/");
  }

  fname += ".hb";
  return fname;
}

} /* end parser */
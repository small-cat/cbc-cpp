#include "parser.h"
#include "antlr4-runtime.h"
#include "SesameLexer.h"
#include "SesameParser.h"
#include "../error_verbose_listener.hpp"

namespace parser {
FileParser::FileParser(const std::string& filename) : filename_(filename) {}
FileParser::~FileParser() {}

bool FileParser::ParseFile() {
  antlr4::ANTLRFileStream input(filename_);
  SesameLexer lexer(&input);

  // add err listener for lexer
  ErrorVerboseListener lexer_err;
  lexer.removeErrorListeners();
  lexer.addErrorListener(&lexer_err);

  antlr4::CommonTokenStream tokens(&lexer);
  tokens.fill();
  if (lexer_err.has_error()) {
    std::cout << "token parse failed in file: " << filename_ << std::endl;
    std::cout << "err msg: " << lexer_err.err_message() << std::endl;
    return false;
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
    std::cout << "Parser failed in file: " << filename_ << std::endl;
    std::cout << "err msg: " << parser_err.err_message() << std::endl;
    return false;
  }

  return true;
}

std::vector<std::string> FileParser::GetTokenStrings() {
  return token_strings_;
}

} /* end parser */

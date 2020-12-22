#include <iostream>
#include "compiler.h"
#include "parser/parser.h"
#include "ast/dumpable.h"

namespace compiler {
const std::string Compiler::kProgramName = AX(PROGNAME);
const std::string Compiler::kProgVersion = AX(PROG_VERSION);

Compiler::Compiler(const std::string& progname) {
  err_handler_ = new utils::ErrorHandler(progname);
}

Compiler::~Compiler() {
  if (err_handler_ != nullptr) {
    delete err_handler_;
  }

  err_handler_ = nullptr;
}

void Compiler::CommandMain(int argc, char* argv[]) {
  Options opts;
  opts.ParseArgs(argc, argv);

  // just check syntax of the source file
  if (opts.mode().mode() == CompilerMode::Mode::CheckSyntax) {
    if (CheckSyntax(&opts)) {
      exit(EXIT_SUCCESS);
    } else {
      exit(EXIT_FAILURE);
    }
  }

  Build(&opts);
  exit(EXIT_SUCCESS);
}

void Compiler::Build(Options* opts) {
  // get source file and build to generate asm
  for (auto& src : opts->source_file()) {
    if (src.IsCFlatSource()) {
      std::string dest = opts->AsmFileNameOf(&src);
      Compile(src.Path(), dest, opts);
      src.SetCurrentName(dest);
    }

    // if not need to translate assembly code
    if (!opts->IsAssembleRequired()) {
      continue;
    }

    if (src.IsAssemblySource()) {
      std::string dest = opts->ObjFileNameOf(&src);
      //Assemble(src.Path(), dest, opts);
      //src.SetCurrentName(dest);
    }

    if (!opts->IsLinkRequired()) {
      return;
    }

    // Link(opts); // link .o files to ELF file
  }
}

/**
 * @fn CheckSyntax
 * @brief check syntax for source files by antlr4
 * @param 
 * @author Jona
 * @date 20/10/2020 11:15:33 
*/ 
bool Compiler::CheckSyntax(Options* opts) {
  bool syntax_ok = true;
  for (auto& src : opts->source_file()) {
    parser::FileParser fp(src.Path());
    if (fp.ParseFile()) {
      std::cout << src.Path() << ": Syntax OK" << std::endl;
    } else {
      err_handler_->Error(src.Path() + " Syntax Error");
      syntax_ok = false;
    }
  }

  return syntax_ok;
}

/**
 * @fn Compile
 * @brief the core function of cbc, generate ast, semantic checking, 
 *        generate intermediate representation, and generate asm
 * @param 
 * @author Jona
 * @date 20/10/2020 15:23:00 
*/ 
void Compiler::Compile(const std::string& src, const std::string& dest, Options* opts) {
  // @todo { compile something }
  ast::ASTNode* ast = GetAstByParseFile(src, opts);
  if (nullptr == ast) {
    err_handler_->Error("ast build failed");
  }

  if (DumpAst(ast, opts->mode())) return;
  delete ast;
}

ast::ASTNode* Compiler::GetAstByParseFile(const std::string& src, Options* opts) {
  // build ast
  parser::FileParser fp(src);
  return fp.BuildAst();
}

bool Compiler::DumpAst(ast::ASTNode* ast, CompilerMode mode) {
  switch(mode.mode()) {
    case CompilerMode::Mode::DumpAST:
      {
        ast::Dumpable d(&(std::cout));
        ast->DumpAst(&d);
        return true;
      }
    case CompilerMode::Mode::DumpTokens:
      ast->DumpTokens();
      return true;
    default:
      return false;
  }

  return false;
}

} /* end compiler */

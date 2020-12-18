/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : compiler.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-20
 * @brief : main of cbc
*/
#ifndef __COMPILER_H__
#define __COMPILER_H__

#include "options.h"
#include "source_file.h"
#include "../utils/error_handler.h"
#include "../ast/ast.hpp"

namespace compiler {
class Compiler {
public:
  const static std::string kProgramName;
  const static std::string kProgVersion;

  Compiler(const std::string& progname);
  virtual ~Compiler();

  void CommandMain(int argc, char* argv[]);
  void Build(Options* opts);
  bool CheckSyntax(Options* opts);
  void Compile(const std::string& src, const std::string& dest, Options* opts);

  // AST, ASM
  // @todo { ast and asm generated and dump }
  ast::ASTNode* GetAstByParseFile(const std::string& src, Options* opts);
  bool DumpAst(ast::ASTNode* ast, CompilerMode mode);
private:
  utils::ErrorHandler* err_handler_;
};
} /* end compiler */

#endif /* __COMPILER_H__ */

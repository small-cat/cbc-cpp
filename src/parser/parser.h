/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : parser.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-20
 * @brief : This is ...
*/
#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <vector>

#include "antlr4-runtime.h"
#include "syntax/generated/SesameLexer.h"
#include "syntax/generated/SesameParser.h"
#include "error_verbose_listener.hpp"
#include "utils/errors.hpp"
#include "ast/ast.hpp"
#include "build_ast.h"

namespace parser {
class FileParser {
public:
  FileParser(const std::string& filename);
  virtual ~FileParser();

  bool ParseFile();
  ast::ASTNode* BuildAst();
  std::vector<std::string> GetTokenStrings();
private:
  ast::ASTNode* _ParseFile(std::error_code& ec, bool check);
  std::string filename_;
  std::vector<std::string> token_strings_; // dump tokens
};
} /* end parser */

#endif /* __PARSER_H__ */
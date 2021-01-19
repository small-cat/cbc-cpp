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
#include "ast/import_file_node.h"
#include "build_ast.h"

namespace parser {
class FileParser {
public:
  FileParser(const std::string& filename, utils::ErrorHandler* handler);
  virtual ~FileParser();

  bool ParseFile();
  ast::ASTNode* BuildAst(std::vector<std::string> import_path);
  std::vector<std::string> GetTokenStrings();

  // for parsing import files
  ast::Declarations* ParseImportFile(const std::string& fname);
  void LoadImportFile(ast::ImportFileNode* imp_file);
  std::string ReplaceFilePath(std::string fname);
  void AddPath(const std::string& path);
  void AddPath(std::vector<std::string> paths);
  void AddImportFiles(std::vector<ast::ImportFileNode *> files);
  std::string GetImportFilePath(const std::string& filename);
private:
  ast::ASTNode* _ParseFile(std::error_code& ec, bool check);
  std::string filename_;    // 解析的源代码文件
  std::vector<std::string> token_strings_; // dump tokens

  // visitor 包含有管理ast整个树形节点的 tracker
  std::vector<parser::BuildAstVisitor *> visitor_tracker_;

  // for import file
  std::vector<std::string> load_path_;
  std::map<std::string, ast::ImportFileNode *> unloaded_file_map_;
  std::map<std::string, bool> loaded_file_map_;
  std::map<std::string, ast::Declarations *> decls_map_;
  utils::ErrorHandler* err_handler_;
};

} /* end parser */

#endif /* __PARSER_H__ */

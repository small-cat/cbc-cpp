/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: load_import_file.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/29
 * @brief: Load import file and return Declarations which are all declarations, such as functions, 
 *         variables, constants and typedefs
*/
#ifndef __LOAD_IMPORT_FILE_H__
#define __LOAD_IMPORT_FILE_H__

#include <vector>
#include <map>
#include <string>

#include "utils/error_handler.h"
#include "ast/declarations.hpp"
#include "ast/import_file_node.h"
#include "parser.h"

namespace parser {
class LoadImportFile {
public:
  LoadImportFile(utils::ErrorHandler* handler);
  virtual ~LoadImportFile();

  void AddPath(const std::string& path);
  void AddPath(std::vector<std::string> paths);
  std::map<std::string, ast::Declarations *> GetAllDeclarations();
  void LoadImportFile(ast::ImportFileNode* imp_file);
  std::string GetImportFilePath(const std::string& filename);
private:
  std::vector<std::string> load_path_;
  std::map<std::string, ast::ImportFileNode *> loaded_file_map_;
  std::map<std::string, ast::Declarations *> decls_map_;
  utils::ErrorHandler* err_handler_;
};
} /* parser */

#endif
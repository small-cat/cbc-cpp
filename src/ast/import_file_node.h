/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: import_file_node.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/29
 * @brief: ast node for import filen
*/
#ifndef __IMPORT_FILE_NODE_H__
#define __IMPORT_FILE_NODE_H__

#include "node.hpp"

namespace ast {
class ImportFileNode : public Node {
public:
  ImportFileNode(std::string name, Location* loc);
  virtual ~ImportFileNode();

  Location* location();
  std::string GetClass();
  std::string filename();
private:
  std::string filename_;
  Location* location_;
};
} /* ast */

#endif
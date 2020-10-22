/**
 * @copyright (c) Copyright 2020 Secsmart. All Rights Reserved.
 * @license
 * @file  : dumper.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-23
 * @brief : dumper ast for txt or other formats
*/
#ifndef __DUMPER_H__
#define __DUMPER_H__

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "node.hpp"

namespace ast {
class Dumper  {
public:
  Dumper(std::fstream* fs);
  virtual ~Dumper();

  void PrintClass(Node* node, Location* loc);
  void PrintNodeList(const std::string& name, std::vector<Node*> nodes);

  // for int long boolean Type TypeRef
  void PrintMember(const std::string& name, Node* node);

  void Indent();
  void UnIndent();
  void PrintIndent();

  const static std::string INDENT_STRING;
private:
  int indent_;
  std::ostream* stream_;
};
} /* end ast */

#endif /* __DUMPER_H__ */

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
#include "../entity/entity.h"
#include "../entity/defined_function.h"
#include "../entity/defined_variable.h"
#include "../entity/parameter.h"
#include "../entity/params.h"

#include "expr/expr_node.hpp"
#include "stmt/stmt_node.hpp"

namespace ast {
class Dumper  {
public:
  Dumper(std::fstream* fs);
  virtual ~Dumper();

  void PrintClass(Node* node, Location* loc);
  void PrintClass(entity::Entity* node, Location* loc);

  void PrintNodeList(const std::string& name, std::vector<Node *> nodes);
  void PrintNodeList(const std::string& name, std::vector<ExprNode *> nodes);
  void PrintNodeList(const std::string &name, std::vector<entity::DefinedVariable *> nodes);
  void PrintNodeList(const std::string &name, std::vector<entity::DefinedFunction *> nodes);
  void PrintNodeList(const std::string &name, std::vector<entity::Parameter *> nodes);

  // for int long boolean Type TypeRef
  void PrintMember(const std::string& name, int n);
  void PrintMember(const std::string& name, long l);
  void PrintMember(const std::string& name, bool b);
  void PrintMember(const std::string& name, std::string val);
  void PrintMember(const std::string& name, type::TypeRef* ref);
  void PrintMember(const std::string& name, type::Type* t);
  void PrintMember(const std::string& name, std::string str, bool is_resolved);
  void PrintMember(const std::string& name, ast::TypeNode* tn);
  void PrintMember(const std::string& name, entity::Params* pams);
  void PrintMember(const std::string& name, ast::StmtNode* stmt);
  void PrintMember(const std::string& name, ast::ExprNode* expr);
  void PrintPair(const std::string& name, std::string val);

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

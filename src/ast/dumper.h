/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: dumpable.h
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/21
* @brief: abstract interface for dumper
*/

#ifndef __DUMPER_H__
#define __DUMPER_H__

#include <string>
#include <vector>

// pre declaration
namespace ast {
class Node;
class ExprNode;
class TypeNode;
class StmtNode;
class CaseNode;
class SlotNode;
class Location;
} /* ast */

namespace entity {
class Entity;
class DefinedVariable;
class DefinedFunction;
class Parameter;
class Params;
} /* entity */

namespace type {
class Type;
class TypeRef;
} /* type */

namespace ast {
class Dumper  {
public:
  Dumper();
  virtual ~Dumper();

  virtual void PrintClass(ast::Node* node, ast::Location* loc) = 0;
  virtual void PrintClass(entity::Entity* node, ast::Location* loc) = 0;
  virtual void PrintNodeList(const std::string& name, std::vector<Node *> nodes) = 0;
  virtual void PrintNodeList(const std::string& name, std::vector<ExprNode *> nodes) = 0;
  virtual void PrintNodeList(const std::string &name, std::vector<entity::DefinedVariable *> nodes) = 0;
  virtual void PrintNodeList(const std::string &name, std::vector<entity::DefinedFunction *> nodes) = 0;
  virtual void PrintNodeList(const std::string &name, std::vector<entity::Parameter *> nodes) = 0;
  virtual void PrintNodeList(const std::string &name, std::vector<StmtNode *> nodes) = 0;
  virtual void PrintNodeList(const std::string &name, std::vector<CaseNode *> nodes) = 0;
  virtual void PrintNodeList(const std::string &name, std::vector<SlotNode *> nodes) = 0;

  // for int long boolean Type TypeRef
  virtual void PrintMember(const std::string& name, int n) = 0;
  virtual void PrintMember(const std::string& name, long l) = 0;
  virtual void PrintMember(const std::string& name, bool b) = 0;
  virtual void PrintMember(const std::string& name, std::string val) = 0;
  virtual void PrintMember(const std::string& name, type::TypeRef* ref) = 0;
  virtual void PrintMember(const std::string& name, type::Type* t) = 0;
  virtual void PrintMember(const std::string& name, std::string str, bool is_resolved) = 0;
  virtual void PrintMember(const std::string& name, ast::TypeNode* tn) = 0;
  virtual void PrintMember(const std::string& name, entity::Params* pams) = 0;
  virtual void PrintMember(const std::string& name, ast::StmtNode* stmt) = 0;
  virtual void PrintMember(const std::string& name, ast::ExprNode* expr) = 0;
};
} /* ast */

#endif

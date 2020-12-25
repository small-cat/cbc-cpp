#ifndef __VARIABLE_NODE_H__
#define __VARIABLE_NODE_H__

#include "lhs_node.hpp"
#include "../../entity/entity.h"
#include "../../entity/defined_variable.h"

namespace ast {
class VariableNode : public LHSNode {
public:
  VariableNode(Location* l, std::string n);
  VariableNode(entity::DefinedVariable* var);
  virtual ~VariableNode();

  std::string name();
  
  bool IsResolved();
  entity::Entity* entity();
  void SetEntity(entity::DefinedVariable* var);
  TypeNode* type_node();
  bool IsParameter();
  type::Type* original_type();

  Location* location();
  void _dump(Dumper* d);
  virtual std::string GetClass();

  void Accept(ASTVisitor * visitor);
private:
  Location* location_;
  std::string name_;
  entity::Entity* entity_;    // 在变量消解过程中，给该变量添加 Variable 的信息, 即变量的定义, 此处仅仅是变量的引用，也就是表达式中对变量的使用
};
} /* end ast */

#endif /* __VARIABLE_NODE_H__ */

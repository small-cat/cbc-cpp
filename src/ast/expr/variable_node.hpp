#ifndef __VARIABLE_NODE_H__
#define __VARIABLE_NODE_H__

#include "lhs_node.hpp"

namespace ast {
class VariableNode : public LHSNode {
public:
  VariableNode(Location* l, std::string n);
  // VariableNode(DefinedVariable var);
  virtual ~VariableNode();

  std::string name();
  
  /*
  bool IsResolved();
  Entity entity();
  void SetEntity();
  TypeNode* type_node();
  bool IsParameter();
  type::Type* OrigialType();
  */

  Location* location();
  void _dump(Dumper* d);
private:
  Location* location_;
  std::string name_;
  // Entity* entity_; // @todo { 当前输出 ast，不处理ir或者实际类型 }
};
} /* end ast */

#endif /* __VARIABLE_NODE_H__ */

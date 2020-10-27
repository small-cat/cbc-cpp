#ifndef __VARIABLE_NODE_H__
#define __VARIABLE_NODE_H__

#include "lhs_node.hpp"
#include "../../entity/entity.h"

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
  entity::Entity* entity_; 
};
} /* end ast */

#endif /* __VARIABLE_NODE_H__ */

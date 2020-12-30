#ifndef __STRUCT_NODE_H__
#define __STRUCT_NODE_H__

#include "composite_type_definition_node.hpp"

namespace ast {
class StructTypeNode : public CompositeTypeDefinitionNode {
public:
  StructTypeNode(Location* l, type::TypeRef* tr, std::string n, std::vector<SlotNode*> membs);
  virtual ~StructTypeNode();

  std::string Kind();
  bool IsStruct();
  type::Type* DefiningType();
  virtual std::string GetClass();

  virtual void Accept(ASTVisitor *visitor);
private:
  /* data */
};
} /* end ast */

#endif /* __STRUCT_NODE_H__ */

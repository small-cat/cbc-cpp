#ifndef __TYPE_DEFINITION_NODE_H__
#define __TYPE_DEFINITION_NODE_H__

#include "../node.hpp"

namespace ast {
class TypeDefinitionNode : public Node {
public:
  TypeDefinitionNode(Location* l, TypeRef* ref, std::string name);
  virtual ~TypeDefinitionNode();

  std::string name();
  Location* location();
  TypeNode* type_node();
  TypeRef* TypeRef();
  Type* Type();

private:
  std::string name_;
  Location* location_;
  TypeNode* type_node_;
};
} /* end ast */

#endif /* __TYPE_DEFINITION_NODE_H__ */

#ifndef __TYPEDEF_NODE_H__
#define __TYPEDEF_NODE_H__

#include "type_definition_node.hpp"

namespace ast {
class TypeDefNode : public TypeDefinitionNode {
public:
  TypeDefNode(Location* l, TypeRef* real, std::string name);
  virtual ~TypeDefNode();

  bool IsUserType();
  TypeNode* RealTypeNode();
  Type* RealType();
  TypeRef* RealTypeRef();
  Type* DefiningType();

  void Dump(Dumper* d);
  // todo: Accept()

private:
  TypeNode* real_;
};
} /* end ast */

#endif /* __TYPEDEF_NODE_H__ */

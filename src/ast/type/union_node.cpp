#include "union_node.hpp"
#include "../../type/union_type.hpp"

namespace ast {
UnionTypeNode::UnionTypeNode(Location* l, type::TypeRef* tr, std::string n, std::vector<SlotNode*> m)
  : CompositeTypeDefinitionNode(l, tr, n, m) {}

UnionTypeNode::~UnionTypeNode() {}

std::string UnionTypeNode::Kind() {
  return "union";
}

bool UnionTypeNode::IsUnion() {
  return true;
}

std::string UnionTypeNode::GetClass() {
  return "UnionTypeNode";
}

type::Type* UnionTypeNode::DefiningType() {
  return new type::UnionType(name(), members(), location());
}
} /* end ast */

#include "struct_node.hpp"
#include "../../type/struct_type.hpp"

namespace ast {
StructTypeNode::StructTypeNode(Location* l, type::TypeRef* tr, std::string n, std::vector<SlotNode*> membs)
  : CompositeTypeDefinitionNode(l, tr, n, membs) {}

StructTypeNode::~StructTypeNode() {}

std::string StructTypeNode::Kind() {
  return "Struct";
}

bool StructTypeNode::IsStruct() {
  return true;
}

std::string StructTypeNode::GetClass() {
  return "StructTypeNode";
}

void StructTypeNode::Accept(ASTVisitor *visitor) {
  visitor->Visit(this);
}

type::Type* StructTypeNode::DefiningType() {
  return new type::StructType(name(), members(), location());
}

} /* end ast */

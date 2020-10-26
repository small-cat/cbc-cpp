#include "composite_type_definition_node.hpp"

namespace ast {
CompositeTypeDefinitionNode::CompositeTypeDefinitionNode(Location* l, type::TypeRef* tr, std::string n, std::vector<SlotNode*> m)
  : TypeDefinitionNode(l, tr, n) {
    members_.swap(m);
  }

CompositeTypeDefinitionNode::~CompositeTypeDefinitionNode() {}

bool CompositeTypeDefinitionNode::IsCompositeType() { return true; }
std::vector<SlotNode*> CompositeTypeDefinitionNode::members() {
  return members_;
}

void CompositeTypeDefinitionNode::_dump(Dumper* d) {
  // @todo { not implement _dump }
}
} /* end ast */

#include "literal_node.hpp"

namespace ast {
LiteralNode::LiteralNode(Location* l, type::TypeRef* tr) : location_(l) {
  type_node_ = new TypeNode(tr);
}

LiteralNode::~LiteralNode() {}

Location* LiteralNode::location() {
  return location_;
}

type::Type* LiteralNode::type() {
  return type_node_->type();
}

TypeNode* LiteralNode::type_node() {
  return type_node_;
}

bool LiteralNode::IsConstant() {
  return true;
}
} /* end ast */

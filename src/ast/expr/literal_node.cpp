#include "literal_node.hpp"

namespace ast {
LiteralNode::LiteralNode(Location* l, type::TypeRef* tr) : location_(l) {
  type_node_ = new TypeNode(tr);
}

LiteralNode::~LiteralNode() {
  if (nullptr != type_node_) {
    delete type_node_;
    type_node_ = nullptr;
  }

  if (nullptr != location_) {
    delete location_;
    location_ = nullptr;
  }
}

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

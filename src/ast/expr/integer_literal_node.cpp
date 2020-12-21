#include "integer_literal_node.hpp"

namespace ast {
IntegerLiteralNode::IntegerLiteralNode(Location* l, type::TypeRef* tr, long val) : LiteralNode(l, tr), value_(val) {}

IntegerLiteralNode::~IntegerLiteralNode() {}

long IntegerLiteralNode::value() {
  return value_;
}

std::string IntegerLiteralNode::GetClass() {
  return "IntegerLiteralNode";
}

void IntegerLiteralNode::_dump(Dumper* d) {
  d->PrintMember("TypeNode", type_node());
  d->PrintMember("Value", value_);
}
} /* end type */

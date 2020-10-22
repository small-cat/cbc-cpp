#include "integer_literal_node.hpp"

namespace ast {
IntegerLiteralNode::IntegerLiteralNode(Location* l, type::TypeRef* tr, long val) : LiteralNode(l, tr), value_(val) {}

IntegerLiteralNode::~IntegerLiteralNode() {}

long IntegerLiteralNode::value() {
  return value_;
}

void IntegerLiteralNode::_dump(Dumper* d) {}
} /* end type */

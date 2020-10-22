#include "string_literal_node.hpp"

namespace ast {
StringLiteralNode::StringLiteralNode(Location* l, type::TypeRef* tr, std::string val) : LiteralNode(l, tr), value_(val) {}

StringLiteralNode::~StringLiteralNode() {}

std::string StringLiteralNode::value() { return value_; }

void StringLiteralNode::_dump(Dumper* d) {}
  
} /* end ty */

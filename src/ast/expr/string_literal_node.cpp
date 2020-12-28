#include "string_literal_node.hpp"

namespace ast {
StringLiteralNode::StringLiteralNode(Location* l, type::TypeRef* tr, std::string val) : LiteralNode(l, tr), value_(val) {}

StringLiteralNode::~StringLiteralNode() {}

std::string StringLiteralNode::value() { return value_; }

std::string StringLiteralNode::GetClass() {
  return "StringLiteralNode";
}

void StringLiteralNode::_dump(Dumper* d) {
  d->PrintMember("Value", value_);
}

void StringLiteralNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}

entity::ConstantEntry* StringLiteralNode::entry() {
  return entry_;
}

void StringLiteralNode::SetEntry(entity::ConstantEntry* e) {
  entry_ = e;
}
  
} /* end ty */

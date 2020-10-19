#include "type_node.hpp"

namespace ast {
using type::TypeRef;
using type::Type;

TypeNode::TypeNode(TypeRef* ref) : type_(nullptr) {
  type_ref_ = ref;
}

TypeNode::TypeNode(Type* t) : type_ref_(nullptr) {
  type_ = t;
}

TypeNode::~TypeNode() {}

TypeRef* TypeNode::type_ref() {
  return type_ref_;
}

Type* TypeNode::type() {
  return type_;
}

bool TypeNode::IsResolved() {
  return type_ != nullptr;
}

void TypeNode::SetType(Type* t) {
  if (type_ != nullptr) {
    throw RuntimeException("TypeNode#SetType called twice");
  }

  type_ = t;
}

Location* TypeNode::location() {
  return type_ref_ == nullptr ? nullptr : type_ref_->location();
}

void TypeNode::Dump(Dumper* d) {
  // @todo {  things to be done }
}

TypeNode TypeNode::Accept(ASTVisitor* visitor) {
  throw RuntimeException("do not call TypeNode#Accept");
}

} /* end ast */

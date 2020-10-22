#include "aref_node.hpp"
#include "../../utils/cpp_utils.hpp"
#include "../../type/array_type.h"

namespace ast {
ARefNode::ARefNode(ExprNode* e, ExprNode* i) : expr_(e), index_(i) {}
ARefNode::~ARefNode() {}

ExprNode* ARefNode::expr() {
  return expr_;
}

ExprNode* ARefNode::index() {
  return index_;
}

bool ARefNode::IsMultiDimension() {
  return (utils::is<ARefNode*>(expr_) && !expr_->OriginalType()->IsPointer());
}

ExprNode* ARefNode::base_expr() {
  return IsMultiDimension() ? ((ARefNode*)expr_)->base_expr() : expr_;
}

long ARefNode::ElementSize() {
  return OriginalType()->AllocSize();
}

long ARefNode::Length() {
  ((type::ArrayType*)(expr_->OriginalType()))->length();
}

type::Type* ARefNode::OriginalType() {
  return expr_->OriginalType()->base_type();
}

Location* ARefNode::location() {
  return expr_->location();
}

void ARefNode::_dump(Dumper* d) {
  // @todo { change dump to visitor pattern }
}
} /* end ast */

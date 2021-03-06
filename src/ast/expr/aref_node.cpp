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
  return ((type::ArrayType*)(expr_->OriginalType()))->length();
}

type::Type* ARefNode::original_type() {
  return expr_->OriginalType()->base_type();
}

Location* ARefNode::location() {
  return expr_->location();
}

std::string ARefNode::GetClass() {
  return "ArrayNode";
}

void ARefNode::_dump(Dumper* d) {
  if (GetLhsNodeType() != nullptr) {
    d->PrintMember("Type", GetLhsNodeType());
  }

  d->PrintMember("Expr", expr_);
  d->PrintMember("Index", index_);
}

void ARefNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}

} /* end ast */

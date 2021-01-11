#include "member_node.hpp"

namespace ast {
MemberNode::MemberNode(ExprNode* e, std::string m) : expr_(e), member_(m) {}
MemberNode::~MemberNode() {}

type::CompositeType* MemberNode::BaseType() {
  return expr_->type()->GetCompositeType();
}

ExprNode* MemberNode::expr() {
  return expr_;
}

std::string MemberNode::member() {
  return member_;
}

long MemberNode::Offset() {
  return BaseType()->MemberOffset(member_);
}

type::Type* MemberNode::original_type() {
  return BaseType()->MemberType(member_);
}

Location* MemberNode::location() {
  return expr_->location();
}

std::string MemberNode::GetClass() {
  return "MemberNode";
}

void MemberNode::_dump(Dumper* d) {
  if (GetLhsNodeType() != nullptr) {
    d->PrintMember("Type", GetLhsNodeType());
  }

  d->PrintMember("Expr", expr_);
  d->PrintMember("Member", member_);
}

void MemberNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}

} /* end ast */

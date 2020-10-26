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

type::Type* MemberNode::OriginalType() {
  return BaseType()->MemberType(member_);
}

Location* MemberNode::location() {
  return expr_->location();
}

void MemberNode::_dump(Dumper* d) {}
} /* end ast */

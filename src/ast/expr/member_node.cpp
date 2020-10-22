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
  // @todo { not implement }
  return 0;
}

type::Type* MemberNode::OriginalType() {
  // @todo { not implement }
  return nullptr;
}

Location* MemberNode::location() {
  return expr_->location();
}

void MemberNode::_dump(Dumper* d) {}
} /* end ast */

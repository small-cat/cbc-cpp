#include "ptr_member_node.hpp"
#include "../../type/pointer_type.hpp"

namespace ast {
PtrMemberNode::PtrMemberNode(ExprNode* e, std::string m) : expr_(e), member_(m) {}
PtrMemberNode::~PtrMemberNode() {}

type::CompositeType* PtrMemberNode::DereferedCompositeType() {
  type::PointerType* pt = expr_->type()->GetPointerType();

  return pt->base_type()->GetCompositeType();
}

type::Type* PtrMemberNode::DereferedType() {
  type::PointerType* pt = expr_->type()->GetPointerType();
  return pt->base_type();
}

ExprNode* PtrMemberNode::expr() {
  return expr_;
}

std::string PtrMemberNode::member() {
  return member_;
}

Location* PtrMemberNode::location() {
  return expr_->location();
}

void PtrMemberNode::_dump(Dumper* d) {
  if (GetLhsNodeType() != nullptr) {
    d->PrintMember("Type", GetLhsNodeType());
  }

  d->PrintMember("Expr", expr_);
  d->PrintMember("Member", member_);
}

long PtrMemberNode::Offset() {
  return DereferedCompositeType()->MemberOffset(member_);
}

std::string PtrMemberNode::GetClass() {
  return "PtrMemberNode";
}

type::Type* PtrMemberNode::original_type() {
  return DereferedCompositeType()->MemberType(member_);
}

void PtrMemberNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}

} /* end ast */

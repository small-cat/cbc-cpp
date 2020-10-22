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

void PtrMemberNode::_dump(Dumper* d) {}

long PtrMemberNode::Offset() {
  // @todo { not implement }
  return 0;
}

type::Type* PtrMemberNode::OriginalType() {
  // @todo { not implement }
  return nullptr;
}
} /* end ast */

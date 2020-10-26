#include "dereference_node.hpp"

namespace ast {
DereferenceNode::DereferenceNode(ExprNode* e) : expr_(e) {}
DereferenceNode::~DereferenceNode() {}

type::Type* DereferenceNode::OriginalType() {
  return expr_->type()->base_type();
}

ExprNode* DereferenceNode::expr() {
  return expr_;
}

void DereferenceNode::SetExpr(ExprNode* e) {
  expr_ = e;
}

Location* DereferenceNode::location() {
  return expr_->location();
}

void DereferenceNode::_dump(Dumper* d) {
  // @todo { _dump }
}
} /* end ast */

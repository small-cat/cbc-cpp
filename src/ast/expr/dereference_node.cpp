#include "dereference_node.hpp"

namespace ast {
DereferenceNode::DereferenceNode(ExprNode* e) : expr_(e) {}
DereferenceNode::~DereferenceNode() {}

type::Type* DereferenceNode::original_type() {
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

std::string DereferenceNode::GetClass() {
  return "DereferenceNode";
}

void DereferenceNode::_dump(Dumper* d) {
  if (type() != nullptr) {
    d->PrintMember("Type", type());
  }

  d->PrintMember("Expr", expr_);
}
} /* end ast */

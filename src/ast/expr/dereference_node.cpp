#include "dereference_node.hpp"

namespace ast {
DereferenceNode::DereferenceNode(ExprNode* e) : expr_(e) {}
DereferenceNode::~DereferenceNode() {
  if (nullptr != expr_) {
    delete expr_;
    expr_ = nullptr;
  }
}

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

void DereferenceNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}
} /* end ast */

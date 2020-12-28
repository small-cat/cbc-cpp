#include "sizeof_expr_node.hpp"

namespace ast {
SizeofExprNode::SizeofExprNode(ExprNode* e, type::TypeRef* tr) : expr_(e) {
  type_node_ = new TypeNode(tr);
}

SizeofExprNode::~SizeofExprNode() {
  if (type_node_ != nullptr) {
    delete type_node_;
    type_node_ = nullptr;
  }
}

ExprNode* SizeofExprNode::expr() {
  return expr_;
}

void SizeofExprNode::SetExpr(ExprNode* e) {
  expr_ = e;
}

type::Type* SizeofExprNode::type() {
  return type_node_->type();
}

TypeNode* SizeofExprNode::type_node() {
  return type_node_;
}

Location* SizeofExprNode::location() {
  return expr_->location();
}

std::string SizeofExprNode::GetClass() {
  return "SizeofExprNode";
}

void SizeofExprNode::_dump(Dumper* d) {
  d->PrintMember("Expr", expr_);
}

void SizeofExprNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}

} /* end type */

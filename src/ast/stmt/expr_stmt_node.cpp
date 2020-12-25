#include "expr_stmt_node.hpp"

namespace ast {
ExprStmtNode::ExprStmtNode(Location* l, ExprNode* e) : StmtNode(l), expr_(e) {}
ExprStmtNode::~ExprStmtNode() {
  if (nullptr != expr_) {
    delete expr_;
    expr_ = nullptr;
  }
}

ExprNode* ExprStmtNode::expr() { return expr_; }

void ExprStmtNode::SetExpr(ExprNode* e) {
  expr_ = e;
}

std::string ExprStmtNode::GetClass() {
  return "ExprStmtNode";
}

void ExprStmtNode::_dump(Dumper* d) {
  d->PrintMember("expr", expr_);
}

void ExprStmtNode::Accept(ASTVisitor *visitor) {
  visitor->Visit(this);
}
} /* end ast */

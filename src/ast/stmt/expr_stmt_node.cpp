#include "expr_stmt_node.hpp"

namespace ast {
ExprStmtNode::ExprStmtNode(Location* l, ExprNode* e) : StmtNode(l), expr_(e) {}
ExprStmtNode::~ExprStmtNode() {}

ExprNode* ExprStmtNode::expr() { return expr_; }

void ExprStmtNode::SetExpr(ExprNode* e) {
  expr_ = e;
}

void ExprStmtNode::_dump(Dumper* d) {
  // @todo { not implement _dump }
}
} /* end ast */

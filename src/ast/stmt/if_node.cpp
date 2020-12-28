#include "if_node.hpp"

namespace ast {
IfNode::IfNode(Location* l, ExprNode* c, StmtNode* t, StmtNode* e) 
  : StmtNode(l), cond_(c), then_body_(t), else_body_(e) {}

IfNode::~IfNode() {}

ExprNode* IfNode::cond() {
  return cond_;
}

StmtNode* IfNode::then_body() {
  return then_body_;
}

StmtNode* IfNode::else_body() {
  return else_body_;
}

std::string IfNode::GetClass() {
  return "IfStmtNode";
}

void IfNode::_dump(Dumper* d) {
  d->PrintMember("CondExpr", cond_);
  d->PrintMember("ThenStmt", then_body_);
  d->PrintMember("ElseStmt", else_body_);
}

void IfNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}
} /* end ast */

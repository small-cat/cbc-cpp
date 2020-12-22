#include "while_node.hpp"

namespace ast {
WhileNode::WhileNode(Location* l, ExprNode* c, StmtNode* b) 
  : StmtNode(l), cond_(c), body_(b) {}

WhileNode::~WhileNode() {
  if (nullptr != cond_) {
    delete cond_;
    cond_ = nullptr;
  }

  if (nullptr != body_) {
    delete body_;
    body_ = nullptr;
  }
}

ExprNode* WhileNode::cond() {
  return cond_;
}

StmtNode* WhileNode::body() {
  return body_;
}

std::string WhileNode::GetClass() {
  return "WhileStmtNode";
}

void WhileNode::_dump(Dumper* d) {
  d->PrintMember("CondExpr", cond_);
  d->PrintMember("body", body_);
}

} /* end ast */

#include "do_while_node.hpp"

namespace ast {
DoWhileNode::DoWhileNode(Location* l, StmtNode* b, ExprNode* c) : StmtNode(l),
                                                                  body_(b),
                                                                  cond_(c) {}
DoWhileNode::~DoWhileNode() {
  if (nullptr != cond_) {
    delete cond_;
    cond_ = nullptr;
  }

  if (nullptr != body_) {
    delete body_;
    body_ = nullptr;
  }
}

StmtNode* DoWhileNode::body() {
  return body_;
}

ExprNode* DoWhileNode::cond() {
  return cond_;
}

std::string DoWhileNode::GetClass() {
  return "DoWhileStmtNode";
}

void DoWhileNode::_dump(Dumper* d) {
  d->PrintMember("CondExpr", cond_);
  d->PrintMember("body", body_);
}

void DoWhileNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}
} /* end ast */

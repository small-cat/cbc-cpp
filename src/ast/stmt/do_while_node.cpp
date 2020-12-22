#include "do_while_node.hpp"

namespace ast {
DoWhileNode::DoWhileNode(Location* l, StmtNode* b, ExprNode* c) : StmtNode(l),
                                                                  body_(b),
                                                                  cond_(c) {}
DoWhileNode::~DoWhileNode() {}

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
} /* end ast */

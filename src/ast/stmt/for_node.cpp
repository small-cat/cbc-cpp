#include "for_node.hpp"

namespace ast {
ForNode::ForNode(Location* l, ExprNode* init, ExprNode* c, ExprNode* incr, StmtNode* body) 
  : StmtNode(l), cond_(c), body_(body) {
    init_ = new ExprStmtNode(init->location(), init);
    incr_ = new ExprStmtNode(incr->location(), incr);
  }

ForNode::~ForNode() {
  if (nullptr != init_) {
    delete init_;
    init_ = nullptr;
  }

  if (nullptr != incr_) {
    delete incr_;
    incr_ = nullptr;
  }

  if (nullptr != cond_) {
    delete cond_;
    cond_ = nullptr;
  }

  if (nullptr != body_) {
    delete body_;
    body_ = nullptr;
  }

}

StmtNode* ForNode::init() {
  return init_;
}

ExprNode* ForNode::cond() {
  return cond_;
}

StmtNode* ForNode::incr() {
  return incr_;
}

StmtNode* ForNode::body() {
  return body_;
}

std::string ForNode::GetClass() {
  return "ForStmtNode";
}

void ForNode::_dump(Dumper* d) {
  d->PrintMember("InitExpr", init_);
  d->PrintMember("CondExpr", cond_);
  d->PrintMember("IncrExpr", incr_);
  d->PrintMember("Body", body_);
}

void ForNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}
} /* end ast */

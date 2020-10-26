#include "for_node.hpp"

namespace ast {
ForNode::ForNode(Location* l, ExprNode* init, ExprNode* c, ExprNode* incr, StmtNode* body) 
  : StmtNode(l), cond_(c), body_(body) {
    init_ = new ExprStmtNode(init->location(), init);
    incr_ = new ExprStmtNode(incr->location(), incr);
  }

ForNode::~ForNode() {
  if (nullptr == init_) {
    delete init_;
  }

  if (nullptr == incr_) {
    delete incr_;
  }

  init_ = nullptr;
  incr_ = nullptr;
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

void ForNode::_dump(Dumper* d) {
  // @todo { not implement _dump }
}
} /* end ast */

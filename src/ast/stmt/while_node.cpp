#include "while_node.hpp"

namespace ast {
WhileNode::WhileNode(Location* l, ExprNode* c, StmtNode* b) 
  : StmtNode(l), cond_(c), body_(b) {}

WhileNode::~WhileNode() {}

ExprNode* WhileNode::cond() {
  return cond_;
}

StmtNode* WhileNode::body() {
  return body_;
}

void WhileNode::_dump(Dumper* d) {
  // @todo { not implement _dump }
}
} /* end ast */

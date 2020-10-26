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

void DoWhileNode::_dump(Dumper* d) {
  // @todo { not implement _dump }
}
} /* end ast */

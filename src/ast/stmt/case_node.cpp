#include "case_node.hpp"

namespace ast {
CaseNode::CaseNode(Location* l, std::vector<ExprNode*> vs, BlockNode* b)
  : StmtNode(l), body_(b) {
    values_.swap(vs);
  }

CaseNode::~CaseNode() {}

std::vector<ExprNode*> CaseNode::values() {
  return values_;
}

bool CaseNode::IsDefault() {
  return values_.empty();
}

BlockNode* CaseNode::body() {
  return body_;
}

void CaseNode::_dump(Dumper* d) {
  // @todo { not implement _dump }
}
} /* end ast */

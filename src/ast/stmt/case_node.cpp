#include "case_node.hpp"

namespace ast {
CaseNode::CaseNode(Location* l, std::vector<ExprNode*> vs, BlockNode* b)
  : StmtNode(l), body_(b) {
    values_.swap(vs);
  }

CaseNode::~CaseNode() {
  for (auto& v : values_) {
    delete v;
    v = nullptr;
  }

  if (nullptr != body_) {
    delete body_;
    body_ = nullptr;
  }
}

std::vector<ExprNode*> CaseNode::values() {
  return values_;
}

bool CaseNode::IsDefault() {
  return values_.empty();
}

BlockNode* CaseNode::body() {
  return body_;
}

std::string CaseNode::GetClass() {
  return "CaseNode";
}

void CaseNode::_dump(Dumper* d) {
  d->PrintNodeList("CaseValues", values_);
  d->PrintMember("body", body_);
}

void CaseNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}
} /* end ast */

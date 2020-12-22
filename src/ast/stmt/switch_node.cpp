#include "switch_node.hpp"

namespace ast {
SwitchNode::SwitchNode(Location* l, ExprNode* c, std::vector<CaseNode*> cases) 
  : StmtNode(l), cond_(c) {
    cases_.swap(cases);
  }

SwitchNode::~SwitchNode() {
  if (nullptr != cond_) {
    delete cond_;
    cond_ = nullptr;
  }

  for (auto& c : cases_) {
    delete c;
    c = nullptr;
  }
}

ExprNode* SwitchNode::cond() {
  return cond_;
}

std::vector<CaseNode*> SwitchNode::cases() {
  return cases_;
}

std::string SwitchNode::GetClass() {
  return "SwitchStmtNode";
}

void SwitchNode::_dump(Dumper* d) {
  d->PrintMember("CondExpr", cond_);
  d->PrintNodeList("CaseNodes", cases_);
}
} /* end ast */

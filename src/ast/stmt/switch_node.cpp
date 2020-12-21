#include "switch_node.hpp"

namespace ast {
SwitchNode::SwitchNode(Location* l, ExprNode* c, std::vector<CaseNode*> cases) 
  : StmtNode(l), cond_(c) {
    cases_.swap(cases);
  }

SwitchNode::~SwitchNode() {}

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
  // @todo { not implement _dump }
}
} /* end ast */

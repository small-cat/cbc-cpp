#include "label_node.hpp"

namespace ast {
LabelNode::LabelNode(Location* l, std::string n, StmtNode* s) 
  : StmtNode(l), name_(n), stmt_(s) {}

LabelNode::~LabelNode() {
  if (nullptr != stmt_) {
    delete stmt_;
    stmt_ = nullptr;
  }
}

std::string LabelNode::name() {
  return name_;
}

StmtNode* LabelNode::stmt() {
  return stmt_;
}

std::string LabelNode::GetClass() {
  return "LabelNode";
}

void LabelNode::_dump(Dumper* d) {
  d->PrintMember("Label", name_);
  d->PrintMember("Statement", stmt_);
}
} /* end ast */

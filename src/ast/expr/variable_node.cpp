#include "variable_node.hpp"

namespace ast {
VariableNode::VariableNode(Location* l, std::string n) : location_(l), name_(n) {}
VariableNode::~VariableNode() {}

std::string VariableNode::name() {
  return name_;
}

Location* VariableNode::location() {
  return location_;
}

void VariableNode::_dump(Dumper* d) {}
} /* end type */

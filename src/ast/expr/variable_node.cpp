#include "variable_node.hpp"

namespace ast {
VariableNode::VariableNode(Location* l, std::string n) : location_(l), name_(n) {}
VariableNode::VariableNode(entity::DefinedVariable* var) : entity_(var) {
  name_ = var->name();
}
VariableNode::~VariableNode() {}

std::string VariableNode::name() {
  return name_;
}

bool VariableNode::IsResolved() {
  return entity_ != nullptr;
}

entity::Entity* VariableNode::entity() { return entity_; }
void VariableNode::SetEntity(entity::DefinedVariable* var) {
  entity_ = var;
}

TypeNode* VariableNode::type_node() {
  return entity_->type_node();
}

bool VariableNode::IsParameter() {
  return entity_->IsParameter();
}

type::Type* VariableNode::original_type() {
  return entity_->GetType();
}

Location* VariableNode::location() {
  return location_;
}

void VariableNode::_dump(Dumper* d) {
  if (type() != nullptr) {
    d->PrintMember("Type", type());
  }

  d->PrintMember("name", name_, IsResolved());
}

std::string VariableNode::GetClass() {
  return "VariableNode";
}

} /* end type */

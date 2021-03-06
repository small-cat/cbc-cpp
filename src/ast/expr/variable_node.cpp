#include "variable_node.hpp"

namespace ast {
VariableNode::VariableNode(Location* l, std::string n) : location_(l), name_(n), entity_(nullptr) {}
VariableNode::VariableNode(entity::DefinedVariable* var) : entity_(var) {
  location_ = nullptr;
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
void VariableNode::SetEntity(entity::Entity* var) {
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
  if (GetLhsNodeType() != nullptr) {
    d->PrintMember("Type", GetLhsNodeType());
  }

  d->PrintMember("name", name_, IsResolved());
}

std::string VariableNode::GetClass() {
  return "VariableNode";
}

void VariableNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}

} /* end type */

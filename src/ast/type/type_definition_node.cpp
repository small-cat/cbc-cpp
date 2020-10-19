#include "type_definition_node.hpp"

namespace ast {

TypeDefinitionNode::TypeDefinitionNode(Location* l, TypeRef* ref, std::string name)
  : name_(name), location_(l) {
    type_node_ = new TypeNode(ref);
  }

TypeDefinitionNode::~TypeDefinitionNode() {
  if (type_node_ != nullptr) {
    delete type_node_;
  }

  type_node_ = nullptr;
}

std::string TypeDefinitionNode::name() {
  return name_;
}

Location* TypeDefinitionNode::location() {
  return location_;
}

TypeNode* TypeDefinitionNode::type_node() {
  return type_node_;
}

TypeRef* TypeDefinitionNode::TypeRef() {
  return type_node_->typeref();
}

Type* TypeDefinitionNode::Type() {
  return type_node_->type();
}

} /* end ast */

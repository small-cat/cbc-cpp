#include "typedef_node.hpp"

namespace ast {

TypeDefNode::TypeDefNode(Location* l, TypeRef* real, std::string name) : TypeDefinitionNode(l, new UserTypeRef(name), name) {
  real_ = new TypeNode(real);
}

TypeDefNode::~TypeDefNode() {
  if (real_ != nullptr) {
    delete real_;
  }

  real_ = nullptr;
}

bool TypeDefNode::IsUserType() {
  return true;
}

TypeNode* TypeDefNode::RealTypeNode() {
  return real_;
}

Type* TypeDefNode::RealType() {
  return real_->type();
}

TypeRef* TypeDefNode::RealTypeRef() {
  return real_->typeref();
}

Type* TypeDefNode::DefiningType() {
  return new UserType(name(), RealTypeNode(), location());
}

} /* end ast */

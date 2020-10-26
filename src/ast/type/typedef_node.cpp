#include "typedef_node.hpp"

namespace ast {

// UserTypeRef 不能直接这样作为参数，要在传入参数的时候，直接传递
TypeDefNode::TypeDefNode(Location* l, type::TypeRef* real, type::UserTypeRef* user_ref, std::string name) 
  : TypeDefinitionNode(l, user_ref, name) {
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

type::Type* TypeDefNode::RealType() {
  return real_->type();
}

type::TypeRef* TypeDefNode::RealTypeRef() {
  return real_->type_ref();
}

type::Type* TypeDefNode::DefiningType() {
  return new type::UserType(name(), RealTypeNode(), location());
}

} /* end ast */

#include "entity.h"

namespace entity {
Entity::Entity(bool priv, ast::TypeNode* tn, std::string n) : is_private_(priv), 
                                                              type_node_(tn),
                                                              name_(n) {
  refered_ = 0;
}

Entity::~Entity() {}

std::string Entity::name() {
  return name_;
}

std::string Entity::SymbolString() {
  return name_;
}

bool Entity::IsConstant() {
  return false;
}

bool Entity::IsParameter() {
  return false;
}

bool Entity::is_private() {
  return is_private_;
}

ast::TypeNode* Entity::type_node() {
  return type_node_;
}

type::Type* Entity::GetType() {
  return type_node_->type();
}

long Entity::AllocSize() {
  return GetType()->AllocSize();
}

long Entity::Alignment() {
  return GetType()->Alignment();
}

void Entity::refered() {
  refered_++;
}

bool Entity::IsRefered() {
  return refered_ > 0;
}

ast::Location* Entity::GetLocation() {
  return type_node_->location();
}
} /* end entity */

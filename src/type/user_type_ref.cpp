#include "user_type_ref.hpp"

namespace type {
UserTypeRef::UserTypeRef(std::string n) : TypeRef(nullptr), name_(n) {}
UserTypeRef::UserTypeRef(ast::Location* l, std::string n) 
  : TypeRef(l), name_(n) {}

UserTypeRef::~UserTypeRef() {}

bool UserTypeRef::IsUserType() { return true; }

std::string UserTypeRef::name() const {
  return name_;
}

std::string UserTypeRef::ToString() {
  return name_;
}
} /* end ast */

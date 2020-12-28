#include "type_ref.hpp"

namespace type {
TypeRef::TypeRef(ast::Location* l) : location_(l) {}

TypeRef::~TypeRef() {}

ast::Location* TypeRef::location() {
  return location_;
}

void TypeRef::SetLocation(ast::Location* l) {
  location_ = l;
}

std::string TypeRef::ToString() {
  return "";
}

} /* end type */

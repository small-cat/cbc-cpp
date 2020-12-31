#include "type_ref.hpp"
#include "utils/string_utils.hpp"

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

std::string TypeRef::name() const {
  return "";
}

bool TypeRef::operator< (const TypeRef &other) const {
  return strcmp(name().c_str(), other.name().c_str()) < 0;
}

} /* end type */

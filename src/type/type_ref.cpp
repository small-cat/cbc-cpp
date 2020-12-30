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

std::string TypeRef::name() {
  return "";
}

bool operator< (TypeRef lhs, TypeRef rhs) {
  return utils::StringUtils::StrCmp(lhs.name(), rhs.name());
}


} /* end type */

#include "type_ref.hpp"

namespace type {
TypeRef::TypeRef(ast::Location* l) : location_(l) {}

TypeRef::~TypeRef() {}

ast::Location* TypeRef::location() {
  return location_;
}
} /* end type */

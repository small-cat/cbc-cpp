#include "union_type_ref.h"

namespace type {
UnionTypeRef::UnionTypeRef(std::string name) : TypeRef(nullptr), union_name_(name) {}
UnionTypeRef::UnionTypeRef(ast::Location* l, std::string name) : TypeRef(l), union_name_(name) {}
UnionTypeRef::~UnionTypeRef() {}

bool UnionTypeRef::IsUnion() { return true; }
std::string UnionTypeRef::name() const { return union_name_; }

std::string UnionTypeRef::ToString() {
  return "union " + union_name_;
}

bool operator==(const UnionTypeRef& src, const UnionTypeRef& other) {
  if (&src == &other) {
    return true;
  }

  return src.union_name_ == other.union_name_;
}
} /* type */
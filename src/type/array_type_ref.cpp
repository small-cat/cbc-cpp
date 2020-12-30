#include "array_type_ref.h"

namespace type {
ArrayTypeRef::ArrayTypeRef(TypeRef* base) : TypeRef(base->location()), base_type_(base) {}
ArrayTypeRef::ArrayTypeRef(TypeRef* base, long len) : TypeRef(base->location()), base_type_(base), length_(len) {}
ArrayTypeRef::~ArrayTypeRef() {}

bool ArrayTypeRef::IsArray() {
  return true;
}

TypeRef* ArrayTypeRef::base_type() {
  return base_type_;
}

long ArrayTypeRef::length() { return length_; }

bool ArrayTypeRef::IsArrayUndefined() { return length_ == UNDEFINED; }

std::string ArrayTypeRef::ToString() {
  std::string ret = base_type_->ToString();
  return ret + "[" + (length_ == UNDEFINED? "" : std::to_string(length_)) + "]";
}

std::string ArrayTypeRef::name() {
  return base_type_->name();
}

} /* type */
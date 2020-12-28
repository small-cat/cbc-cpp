#include "pointer_type_ref.h"

namespace type {
PointerTypeRef::PointerTypeRef(TypeRef* base) : TypeRef(base->location()), base_type_(base) {}
PointerTypeRef::~PointerTypeRef() {}

bool PointerTypeRef::IsPointer() { return true; }
TypeRef* PointerTypeRef::base_type() { return base_type_; }
std::string PointerTypeRef::ToString() {
  return base_type_->ToString() + "*";
}
} /* type */
#include "pointer_type_ref.h"

namespace type {
PointerTypeRef::PointerTypeRef(TypeRef* base) : TypeRef(base->location()), base_typeref_(base) {}
PointerTypeRef::~PointerTypeRef() {}

bool PointerTypeRef::IsPointer() { return true; }
TypeRef* PointerTypeRef::base_typeref() { return base_typeref_; }
std::string PointerTypeRef::ToString() {
  return base_typeref_->ToString() + "*";
}

std::string PointerTypeRef::name() {
  return base_typeref_->name();
}

} /* type */
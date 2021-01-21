#include "pointer_type_ref.h"

namespace type {
PointerTypeRef::PointerTypeRef(TypeRef* base) : TypeRef(base->location()), base_typeref_(base) {}
PointerTypeRef::~PointerTypeRef() {}

bool PointerTypeRef::IsPointer() { return true; }
TypeRef* PointerTypeRef::base_typeref() { return base_typeref_; }
std::string PointerTypeRef::ToString() {
  return base_typeref_->ToString() + "*";
}

std::string PointerTypeRef::name() const {
  return base_typeref_->name();
}

bool PointerTypeRef::IsSameTypeRef(TypeRef *other) {
  if (! utils::is<PointerTypeRef *>(other)) {
    return false;
  }

  auto other_ptr =  (PointerTypeRef *)other;
  return base_typeref_->IsSameTypeRef(other_ptr->base_typeref());
}

} /* type */
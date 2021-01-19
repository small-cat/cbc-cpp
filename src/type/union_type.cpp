#include "union_type.hpp"
#include "../utils/asm_utils.hpp"

namespace type {
UnionType::UnionType(std::string n, std::vector<ast::SlotNode*> membs, ast::Location* l)
  : CompositeType(n, membs, l) {}

UnionType::~UnionType() {}

bool UnionType::IsUnion() { 
  return true;
}

bool UnionType::IsSameType(Type* other) {
  if (this == other) { return true; }
  if (!other->IsUnion()) {
    return false;
  }

  return CompositeType::IsSameType(other);
}

bool UnionType::EqualType(Type *other) {
  return IsSameType(other);
}

void UnionType::ComputeOffsets() {
  long max_size = 0;
  long max_align = 1;
  for (auto s : members()) {
    s->SetOffset(0);
    max_size = max_size > s->AllocSize() ? max_size : s->AllocSize();
    max_align = max_align > s->Alignment() ? max_align : s->Alignment();
  }

  SetCachedSize(utils::AsmUtils::Align(max_size, max_align));
  SetCachedAlign(max_align);
}

std::string UnionType::ToString() {
  return "Union" + name();
}

} /* end type */

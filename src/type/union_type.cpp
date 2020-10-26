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
  if (!other->IsUnion()) {
    return false;
  }

  // @todo { IsSameType }
  return true;
  // return *this == *other;
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

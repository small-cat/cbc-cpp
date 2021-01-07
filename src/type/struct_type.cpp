#include "struct_type.hpp"
#include "../utils/asm_utils.hpp"

namespace type {
StructType::StructType(std::string n, std::vector<ast::SlotNode*> membs, ast::Location* l) 
  : CompositeType(n, membs, l) {}

StructType::~StructType() {}

bool StructType::IsStruct() {
  return true;
}

bool StructType::IsSameType(Type* other) {
  if (!other->IsStruct()) {
    return false;
  }

  return CompositeType::IsSameType(other);
}

void StructType::ComputeOffsets() {
  long offset = 0;
  long max_align = 1;

  for (auto s : members()) {
    offset = utils::AsmUtils::Align(offset, s->AllocSize());
    s->SetOffset(offset);

    offset += s->AllocSize();
    max_align = max_align > s->Alignment() ? max_align : s->Alignment();
  }

  SetCachedSize(utils::AsmUtils::Align(offset, max_align));
  SetCachedAlign(max_align);
}

std::string StructType::ToString() {
  return "Struct" + name();
}
} /* end type */

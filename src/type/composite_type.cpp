#include "composite_type.hpp"
#include "../utils/string_utils.hpp"

#include <iostream>
#include <stdio.h>

namespace type {

bool CompositeType::IsSameType(Type* other) {
  if (!CompareMemberTypes(other)) {
    return false;
  }

  CompositeType* other_type = other->GetCompositeType();
  auto it = other_type->MemberTypes().begin();
  for (auto& t : MemberTypes()) {
    if (!t->IsSameType(*it++)) {
      return false;
    }
  }

  return true;
}

bool CompositeType::IsCompatible(Type* target) {
  if (!CompareMemberTypes(target)) {
    return false;
  }

  CompositeType* other_type = target->GetCompositeType();
  auto it = other_type->MemberTypes().begin();
  for (auto& t : MemberTypes()) {
    if (!t->IsCompatible(*it++)) {
      return false;
    }
  }

  return true;
}

bool CompositeType::IsCastableTo(Type* target) {
  if (!CompareMemberTypes(target)) {
    return false;
  }

  CompositeType* other_type = target->GetCompositeType();
  auto it = other_type->MemberTypes().begin();
  for (auto& t : MemberTypes()) {
    if (!t->IsCastableTo(*it++)) {
      return false;
    }
  }

  return true;
}
  
bool CompositeType::CompareMemberTypes(Type* other) {
  if (IsStruct() && !other->IsStruct()) {
    return false;
  }

  if (IsUnion() && !other->IsUnion()) {
    return false;
  }

  auto other_type = other->GetCompositeType();
  if (members().size() != other_type->members().size()) {
    return false;
  }

  return true;
}

long CompositeType::Size() {
  if (cached_size_ == Type::SizeUnknown) {
    ComputeOffsets();
  }

  return cached_size_;
}

long CompositeType::Alignment() {
  if (cached_align_ == Type::SizeUnknown) {
    ComputeOffsets();
  }

  return cached_align_;
}

std::vector<ast::SlotNode*> CompositeType::members() {
  return members_;
}

std::vector<Type*> CompositeType::MemberTypes() {
  std::vector<Type*> vt;
  for (auto s : members_) {
    vt.push_back(s->type());
  }

  return vt;
}

bool CompositeType::HasMember(std::string mem_name) {
  return Get(mem_name) != nullptr;
}

Type* CompositeType::MemberType(std::string mem_name) {
  auto s = Fetch(mem_name);
  return s->type();
}

long CompositeType::MemberOffset(std::string mem_name) {
  ast::SlotNode* s = Fetch(mem_name);

  if (s->offset() == Type::SizeUnknown) {
    ComputeOffsets();
  }

  return s->offset();
}

ast::SlotNode* CompositeType::Fetch(std::string mem_name) {
  auto s = Get(mem_name);
  if (nullptr == s) {
    std::cout << "Semantic Error: " << ToString() << " has no member " << mem_name << std::endl;
    exit(EXIT_FAILURE);
  }

  return s;
}

// get member by name
ast::SlotNode* CompositeType::Get(std::string mem_name) {
  for (auto s : members_) {
    if (utils::StringUtils::StrCmp(s->name(), mem_name) == 0) {
      return s;
    }
  }

  return nullptr;
}

long CompositeType::cached_size() {
  return cached_size_;
}

void CompositeType::SetCachedSize(long size) {
  cached_size_ = size;
}

long CompositeType::cached_align() {
  return cached_align_;
}

void CompositeType::SetCachedAlign(long size) {
  cached_align_ = size;
}
} /* end composite_type */

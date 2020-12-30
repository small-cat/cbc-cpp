#include "struct_type_ref.h"
#include "../utils/cpp_utils.hpp"

namespace type {
StructTypeRef::StructTypeRef(std::string name) : TypeRef(nullptr), struct_name_(name) {}
StructTypeRef::StructTypeRef(ast::Location* l, std::string name) : TypeRef(l), struct_name_(name) {}
StructTypeRef::~StructTypeRef() {}

std::string StructTypeRef::name() {
  return struct_name_;
}

bool StructTypeRef::IsStruct() { return true; }
std::string StructTypeRef::ToString() {
  return "struct " + struct_name_;
}

bool StructTypeRef::Equals(TypeRef* other) {
  if (utils::is<StructTypeRef*>(other)) {
    return false;
  }

  return ((StructTypeRef*)other)->name() == struct_name_;
}

bool operator==(const StructTypeRef& src, const StructTypeRef& other) {
  if (&src == &other) {
    return true;
  }

  return src.struct_name_ == other.struct_name_;
}

} /* type */
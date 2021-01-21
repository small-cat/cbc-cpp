#include <iostream>
#include "integer_type_ref.h"
#include "utils/string_utils.hpp"

namespace type {
std::map<IntegerTypeRef::IntegerTypeClass, std::string> IntegerTypeRef::IntegerTypeNames = {
  {SESAME_CHAR,   "char"},
  {SESAME_SHORT,  "short"},
  {SESAME_INT,    "int"},
  {SESAME_LONG,   "long"},
  {SESAME_UCHAR,  "unsigned char"},
  {SESAME_USHORT, "unsigned short"},
  {SESAME_UINT,   "unsigned int"},
  {SESAME_ULONG,  "unsigned long"},
};

IntegerTypeRef::IntegerTypeRef(std::string name) : TypeRef(nullptr), integer_type_name_(name) {}
IntegerTypeRef::IntegerTypeRef(ast::Location* l, std::string name) : TypeRef(l), integer_type_name_(name) {}
IntegerTypeRef::~IntegerTypeRef() {}

std::string IntegerTypeRef::name() const { return integer_type_name_; }
std::string IntegerTypeRef::ToString() { return integer_type_name_; }

std::string IntegerTypeRef::GetIntegerTypeClassName(std::map<IntegerTypeRef::IntegerTypeClass, std::string> map, 
                                                    IntegerTypeRef::IntegerTypeClass cls) {
  auto search = map.find(cls);
  if (search == map.end()) {
    std::cout << "no integer type class found." << std::endl;
    return "";
  }

  return search->second;
}

IntegerTypeRef* IntegerTypeRef::GetIntegerTypeClass(IntegerTypeRef::IntegerTypeClass cls) {
  std::string clsname = GetIntegerTypeClassName(IntegerTypeNames, cls);
  if (clsname.empty()) {
    return nullptr;
  }
  
  return new IntegerTypeRef(clsname);
}

IntegerTypeRef* IntegerTypeRef::GetIntegerTypeClass(IntegerTypeRef::IntegerTypeClass cls, ast::Location* l) {
  std::string clsname = GetIntegerTypeClassName(IntegerTypeNames, cls);
  if (clsname.empty()) {
    return nullptr;
  }

  return new IntegerTypeRef(l, clsname);
}

bool IntegerTypeRef::IsSameTypeRef(TypeRef *other) {
  if (! utils::is<IntegerTypeRef *>(other)) {
    return false;
  }

  return utils::StringUtils::StrCmp(name(), other->name());
}

} /* type */
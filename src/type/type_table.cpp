#include "type_table.h"
#include "integer_type_ref.h"
#include "integer_type.hpp"
#include "void_type_ref.hpp"
#include "void_type.hpp"
#include "user_type_ref.hpp"
#include "user_type.hpp"
#include "pointer_type_ref.h"
#include "array_type_ref.h"
#include "array_type.h"
#include "function_type_ref.hpp"
#include "function_type.hpp"

#include "../utils/cpp_utils.hpp"

namespace type {
TypeTable::TypeTable() : int_size_(0), long_size_(0), pointer_size_(0) {
}

TypeTable::TypeTable(long isize, long lsize, long ptrsize) : int_size_(isize),
                                                             long_size_(lsize),
                                                             pointer_size_(ptrsize) {
  InitialTable();
}

TypeTable::~TypeTable() {
  param_types_tracker_.Reset();
  type_tracker_.Reset();
  typeref_tracker_.Reset();
}

void TypeTable::SetTypeTable(TypeTable::TypeTableClass cls) {
  switch(cls) {
    case TypeTable::TypeTableClass::ILP32:
    SetILPSize(4, 4, 4);
    break;
    case TypeTable::TypeTableClass::ILP64:
    SetILPSize(8, 8, 8);
    break;
    case TypeTable::TypeTableClass::LP64:
    SetILPSize(4, 8, 8);
    break;
    case TypeTable::TypeTableClass::LLP64:
    SetILPSize(4, 4, 8);
    break;
    default:
    break;
  }

  InitialTable();
}

void TypeTable::SetILPSize(long isize, long lsize, long ptrsize) {
  int_size_ = isize;
  long_size_ = lsize;
  pointer_size_ = ptrsize;
}

void TypeTable::InitialTable() {
  // char and short size is 1 and 2
  TypeRef* ref = typeref_tracker_.CreateInstance<VoidTypeRef>();
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<VoidType>()));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_CHAR);
  typeref_tracker_.AddInstance(ref);
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<IntegerType>(CHAR_SIZE, true, "char")));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_SHORT);
  typeref_tracker_.AddInstance(ref);
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<IntegerType>(SHORT_SIZE, true, "short")));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT);
  typeref_tracker_.AddInstance(ref);
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<IntegerType>(int_size_, true, "int")));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_LONG);
  typeref_tracker_.AddInstance(ref);
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<IntegerType>(long_size_, true, "long")));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_UCHAR);
  typeref_tracker_.AddInstance(ref);
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<IntegerType>(CHAR_SIZE, false, "unsigned char")));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_USHORT);
  typeref_tracker_.AddInstance(ref);
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<IntegerType>(SHORT_SIZE, false, "unsigned short")));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_UINT);
  typeref_tracker_.AddInstance(ref);
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<IntegerType>(int_size_, false, "unsigned int")));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG);
  typeref_tracker_.AddInstance(ref);
  table_.emplace(std::make_pair(ref, type_tracker_.CreateInstance<IntegerType>(long_size_, false, "unsigned long")));
}

bool TypeTable::IsDefined(TypeRef *ref) {
  auto search = table_.find(ref);
  if (search == table_.end()) {
    return false;
  }

  return true;
}

void TypeTable::AddType(TypeRef *ref, Type *t) {
  if (IsDefined(ref)) {
    std::cout << "duplicated type definition: " << ref->name() << std::endl;
    exit(EXIT_FAILURE);
  }

  table_.emplace(std::make_pair(ref, t));
}

Type* TypeTable::GetType(TypeRef *ref) {
  auto search = table_.find(ref);
  if (search != table_.end()) {
    return search->second;
  }

  if (utils::is<UserTypeRef *>(ref)) {
    // 未定义的类型，用于自定义的
    std::cout << "undefined type :" << ref->name() << std::endl;
    exit(EXIT_FAILURE);

  } else if (utils::is<PointerTypeRef *>(ref)) {
    PointerTypeRef* pref = (PointerTypeRef *)ref;
    Type* t = type_tracker_.CreateInstance<PointerType>(pointer_size_, GetType(pref->base_typeref()));
    AddType(pref, t);
    return t;

  } else if (utils::is<ArrayTypeRef *>(ref)) {
    ArrayTypeRef* aref = (ArrayTypeRef *)ref;
    Type* t = type_tracker_.CreateInstance<ArrayType>(GetType(aref->base_type()), aref->length(), pointer_size_);
    AddType(aref, t);
    return t;

  } else if (utils::is<FunctionTypeRef *>(ref)) {
    FunctionTypeRef* fref = (FunctionTypeRef *)ref;
    ParamTypeRefs* params_refs = fref->params();
    std::vector<Type *> types;

    for (auto tr : params_refs->GetTypeRefs()) {
      types.push_back(GetParamType(tr));
    }

    ParamTypes* param_types = param_types_tracker_.CreateInstance<ParamTypes>(params_refs->location(), types, params_refs->vararg());
    Type* t = type_tracker_.CreateInstance<FunctionType>(GetType(fref->return_type()), param_types);
    AddType(fref, t);

    return t;
  }

  return nullptr;
}

/************************************************************************************
* @fn GetParamType
* @brief 函数参数，如果值，就当作值处理，如果是指针就作为指针处理，如果是数组，仍然当作指针处理
* @param
* @author Jona
* @date 2020/12/30
************************************************************************************/
Type* TypeTable::GetParamType(TypeRef *ref) {
  auto t = GetType(ref);
  return t->IsArray()? PointerTo(t->base_type()) : t;
}

PointerType* TypeTable::PointerTo(Type *t) {
  return type_tracker_.CreateInstance<PointerType>(pointer_size_, t);
}

long TypeTable::int_size() {
  return int_size_;
}

long TypeTable::long_size() {
  return long_size_;
}

long TypeTable::pointer_size() {
  return pointer_size_;
}

} /* type */
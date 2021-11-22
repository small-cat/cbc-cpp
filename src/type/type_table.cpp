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
#include "composite_type.hpp"

#include "../utils/cpp_utils.hpp"

namespace type {
TypeTable::TypeMap::TypeMap() {}
TypeTable::TypeMap::~TypeMap() {}

std::vector<TypeRef *> TypeTable::TypeMap::keys() {
  return keys_;
}

std::vector<Type *> TypeTable::TypeMap::values() {
  return values_;
}

bool TypeTable::TypeMap::Contains(TypeRef *tr) {
  if (Find(tr) >= 0) {
    return true;
  }

  return false;
}

int TypeTable::TypeMap::Find(TypeRef *k) {
  decltype(keys_.size()) idx = 0;
  for (; idx < keys_.size(); idx++) {
    if (keys_.at(idx)->IsSameTypeRef(k)) {
      return idx;
    }
  }

  return -1;
}

void TypeTable::TypeMap::Put(TypeRef *k, Type *v) {
  if (Contains(k)) {
    return;
  }

  keys_.push_back(k);
  values_.push_back(v);
}

Type* TypeTable::TypeMap::Get(TypeRef *k) {
  int idx = Find(k);
  if (idx >= 0) {
    return values_.at(idx);
  }

  return nullptr;
}

TypeRef* TypeTable::TypeMap::GetTypeRef(TypeRef *k) {
  int idx = Find(k);
  if (idx >= 0) {
    return keys_.at(idx);
  }

  return nullptr;
}

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
  table_.Put(ref, type_tracker_.CreateInstance<VoidType>());

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_CHAR);
  typeref_tracker_.AddInstance(ref);
  table_.Put(ref, type_tracker_.CreateInstance<IntegerType>(CHAR_SIZE, true, "char"));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_SHORT);
  typeref_tracker_.AddInstance(ref);
  table_.Put(ref, type_tracker_.CreateInstance<IntegerType>(SHORT_SIZE, true, "short"));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT);
  typeref_tracker_.AddInstance(ref);
  table_.Put(ref, type_tracker_.CreateInstance<IntegerType>(int_size_, true, "int"));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_LONG);
  typeref_tracker_.AddInstance(ref);
  table_.Put(ref, type_tracker_.CreateInstance<IntegerType>(long_size_, true, "long"));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_UCHAR);
  typeref_tracker_.AddInstance(ref);
  table_.Put(ref, type_tracker_.CreateInstance<IntegerType>(CHAR_SIZE, false, "unsigned char"));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_USHORT);
  typeref_tracker_.AddInstance(ref);
  table_.Put(ref, type_tracker_.CreateInstance<IntegerType>(SHORT_SIZE, false, "unsigned short"));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_UINT);
  typeref_tracker_.AddInstance(ref);
  table_.Put(ref, type_tracker_.CreateInstance<IntegerType>(int_size_, false, "unsigned int"));

  ref = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG);
  typeref_tracker_.AddInstance(ref);
  table_.Put(ref, type_tracker_.CreateInstance<IntegerType>(long_size_, false, "unsigned long"));
}

bool TypeTable::IsDefined(TypeRef *ref) {
  return table_.Contains(ref);
}

void TypeTable::AddType(TypeRef *ref, Type *t) {
  if (IsDefined(ref)) {
    auto first_def_tr = table_.GetTypeRef(ref);
    std::cout << "duplicated type definition: " << ref->name() << ", first defined at " << first_def_tr->location()->ToString() << std::endl;
    exit(EXIT_FAILURE);
  }

  table_.Put(ref, t);
}

Type* TypeTable::GetType(TypeRef *ref) {
  auto t = table_.Get(ref);
  if (t != nullptr) {
    return t;
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

std::vector<Type *> TypeTable::GetTypes() {
  return table_.values();
}

TypeRef* TypeTable::GetTypeRef(TypeRef *ref) {
  return table_.GetTypeRef(ref);
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

void TypeTable::CheckVoidMembers(ArrayType *arr, utils::ErrorHandler *handler) {
  if (arr->base_type()->IsVoid()) {
    handler->Error("array can not contain void type member");
  }
}

// check if struct or union has void member
void TypeTable::CheckVoidMembers(CompositeType *ct, utils::ErrorHandler *handler) {
  for (Type *t : ct->MemberTypes()) {
    if (t->IsVoid()) {
      handler->Error("struct/union can not contain void type member");
    }
  }
}

// check if member exist more than once in struct or union definition
void TypeTable::CheckDuplicatedMembers(CompositeType *ct, utils::ErrorHandler *handler) {
  std::map<std::string, ast::SlotNode *> seen;
  for (auto m : ct->members()) {
    auto search = seen.find(m->name());
    if (search == seen.end()) {
      seen.emplace(std::make_pair(m->name(), m));
    } else {
      handler->Error(m->location(), ct->ToString() + " has duplicated member " + m->name());
    }
  }
}

/************************************************************************************
* @fn CheckRecursiveDefinition
* @brief 检查类型定义是否存在环。
* @param
* @author Jona
* @date 2021/01/04
************************************************************************************/
void TypeTable::CheckRecursiveDefinition(Type *t, utils::ErrorHandler *handler) {
  std::vector<Type *> type_check;
  std::vector<CheckType> type_check_flag;
  _CheckRecursiveDefinition(t, type_check, type_check_flag, handler);
}

/************************************************************************************
* @fn _CheckRecursiveDefinition
* @brief 对任一类型进行检查，先将其状态设置为 CHECKING，检查中，然后递归检查其返回值类型，参数类型
*        或者成员类型，如果检查的类型中，有类型状态为 CHECKING，说明存在环
* @param
* @author Jona
* @date 2021/01/07
************************************************************************************/
void TypeTable::_CheckRecursiveDefinition(Type *t, std::vector<Type *> &type_check, std::vector<CheckType> &type_check_flag, utils::ErrorHandler *handler) {
  int idx = FindCheckType(type_check, t);
  if (idx != -1 && type_check_flag.at(idx) == TypeTable::CheckType::CHECKING) {
    // 说明该 Type 已经检查过，类型定义中存在环
    handler->Error(((NamedType *)t)->location(), "recursive type definition: " + t->ToString());
    exit(EXIT_FAILURE);
  } else if (idx != -1 && type_check_flag.at(idx) == TypeTable::CheckType::CHECKED) {
    // 说明该 Type 已经检查结束，直接退出
    return;
  } else if (idx == -1) {
    // 说明该 Type 没有检查过
    type_check.push_back(t);
    type_check_flag.push_back(TypeTable::CheckType::CHECKING);

    if (utils::is<CompositeType *>(t)) {
      CompositeType *ct = t->GetCompositeType();
      for (auto s : ct->members()) {
        _CheckRecursiveDefinition(s->type(), type_check, type_check_flag, handler);
      }
    } else if (utils::is<ArrayType *>(t)) {
      ArrayType *at = t->GetArrayType();
      _CheckRecursiveDefinition(at->base_type(), type_check, type_check_flag, handler);
    } else if (utils::is<UserType *>(t)) {
      UserType *ut = (UserType *)t;
      _CheckRecursiveDefinition(ut->RealType(), type_check, type_check_flag, handler);
    }

    auto i = FindCheckType(type_check, t);
    type_check_flag[i] = TypeTable::CheckType::CHECKED;
  }
}

/************************************************************************************
* @fn FincCheckType
* @brief find check type from type_check array
* @param t the target type which we want to find from type_check
* @return success return unnegative num, -1 not found.
* @author Jona
* @date 2021/01/07
************************************************************************************/
int TypeTable::FindCheckType(std::vector<Type *> type_check, Type *t) {
  std::size_t index = 0;
  for (auto tp : type_check) {
    if (tp->EqualType(t)) {
      return index;
    }

    index++;
  }

  return -1;
}

void TypeTable::SemanticCheck(utils::ErrorHandler *handler) {
  for (auto t : GetTypes()) {
    if (utils::is<CompositeType *>(t))  {
      auto ct = t->GetCompositeType();
      CheckVoidMembers(ct, handler);
      CheckDuplicatedMembers(ct, handler);
      CheckVoidMembers(t->GetArrayType(), handler);
    }

    CheckRecursiveDefinition(t, handler);
  }
}

Type* TypeTable::PtrDiffType() {
  if (long_size_ == pointer_size_) {
    return GetIntegerType(IntegerTypeRef::IntegerTypeClass::SESAME_LONG);
  }
   
  if (int_size_ == pointer_size_) {
    return GetIntegerType(IntegerTypeRef::IntegerTypeClass::SESAME_INT);
  }

  // short
  std::cout << "Must not happen: interger.size != pointer.size" << std::endl;
  exit(EXIT_FAILURE);
}

IntegerType* TypeTable::GetIntegerType(IntegerTypeRef::IntegerTypeClass cls) {
  auto tr = IntegerTypeRef::GetIntegerTypeClass(cls);
  typeref_tracker_.AddInstance(tr);

  IntegerType* t = GetType(tr)->GetIntegerType();
  return t;
}

Type* TypeTable::SignedStackType() {
  return GetIntegerType(IntegerTypeRef::IntegerTypeClass::SESAME_LONG);
}

Type* TypeTable::UnsignedStackType() {
  return GetIntegerType(IntegerTypeRef::IntegerTypeClass::SESAME_ULONG);
}

} /* type */
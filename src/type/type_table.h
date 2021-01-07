/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: type_table.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/30
 * @brief: 一个保存有 TypeRef 和 Type 的映射表。在类型消解时，需要将所有的 TypeRef 全部转换成 Type， TypeRef 仅仅
 *         是类型的名称， Type 才是类型定义, 因为 TypeRef 是类型名称，所以这里的 map key 简化成了 string
 *         @todo[PROMOTE]: 将 key 作为 TypeRef 的方式，可以记录下第一次类型定义时出现的位置
*/
#ifndef __TYPE_TABLE_H__
#define __TYPE_TABLE_H__

#include <map>
#include <string>

#include "type_ref.hpp"
#include "type.hpp"
#include "pointer_type.hpp"
#include "param_slots.hpp"
#include "param_types.hpp"
#include "utils/error_handler.h"

#define CHAR_SIZE 1
#define SHORT_SIZE 2

namespace type {
class TypeTable {
public:
  TypeTable();
  TypeTable(long isize, long lsize, long ptrsize);
  virtual ~TypeTable();

  enum class TypeTableClass {
    ILP32 = 1,
    ILP64,
    LP64,
    LLP64
  };

  void SetTypeTable(TypeTableClass cls);
  bool IsDefined(TypeRef *ref);
  void AddType(TypeRef *ref, Type* t);
  Type* GetType(TypeRef *ref);
  Type* GetParamType(TypeRef *ref);
  std::vector<Type *> GetTypes();

  long int_size();
  long long_size();
  long pointer_size();

  Type* PtrDiffType();
  TypeRef* PtrDiffTypeRef();
  std::string PtrDiffTypeName();

  // stack type
  // integer type

  PointerType* PointerTo(Type *t);

  // semantic check
  void SemanticCheck(utils::ErrorHandler *handler);
  void CheckVoidMembers(ArrayType *arr, utils::ErrorHandler *handler);
  void CheckVoidMembers(CompositeType *ct, utils::ErrorHandler *handler);
  void CheckDuplicatedMembers(CompositeType *ct, utils::ErrorHandler *handler);
  void CheckRecursiveDefinition(Type *t, utils::ErrorHandler *handler);

private:
  void SetILPSize(long isize, long lsize, long ptrsize);
  void InitialTable();

  enum class CheckType {
    CHECKING,   // 处理中，没有处理完
    CHECKED,    // 处理结束
    UNCHECK     // 未处理
  };
  void _CheckRecursiveDefinition(Type *t, std::vector<Type *> &type_check, std::vector<CheckType> &type_check_flag, utils::ErrorHandler *handler);
  int FindCheckType(std::vector<Type *> type_check, Type *t);

private:
  long int_size_;
  long long_size_;
  long pointer_size_;
  std::map<TypeRef *, Type *, Less_TypeRef<TypeRef *>> table_;

  ParamSlotsTracker<ParamTypes> param_types_tracker_;
  ParamSlotsTracker<Type> type_tracker_;
  TypeRefTracker typeref_tracker_;
};
} /* type */

#endif
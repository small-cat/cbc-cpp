/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : type.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-21
 * @brief : abstract type definitions
*/
#ifndef __TYPE_HPP__
#define __TYPE_HPP__

#include <string>
#include <iostream>
#include <vector>

namespace type {
class IntegerType;
class PointerType;
class FunctionType;
class StructType;
class UnionType;
class CompositeType;
class ArrayType;

class Type {
public:
  Type() {}
  virtual ~Type() {}

  const static long SizeUnknown = -1;

  virtual long Size() = 0;
  virtual long AllocSize() { return false; }
  virtual long Alignment() {return false; }
  virtual bool IsSameType(Type *other) = 0;
  virtual bool EqualType(Type *other) = 0;
  virtual std::string ToString() = 0;

  virtual bool IsVoid() { return false; }
  virtual bool IsInt() { return false; }
  virtual bool IsInteger() { return false; }
  virtual bool IsSigned() { return false; } // error
  virtual bool IsPointer() { return false; }
  virtual bool IsArray() { return false; }
  virtual bool IsCompositeType() { return false; }
  virtual bool IsStruct() { return false; }
  virtual bool IsUnion() { return false; }
  virtual bool IsUserType() { return false; }
  virtual bool IsFunction() { return false; }

  // ability methods for unary
  virtual bool IsAllocatedArray() { return false; }
  virtual bool IsIncompleteArray() { return false; }

  // 是否是标量，只有指针和整数才是
  virtual bool IsScalar() { return false; }
  virtual bool IsCallable() { return false; }

  // abiliry methods for binary
  virtual bool IsCompatible(Type* other) = 0;
  virtual bool IsCastableTo(Type* target) = 0;

  virtual Type* base_type() { 
    std::cout << "#base_type called for undereferable type" << std::endl;
    return nullptr; 
  }

  // Cast methods
  IntegerType*   GetIntegerType()   { return (IntegerType*)this; }
  PointerType*   GetPointerType()   { return (PointerType*)this; }
  FunctionType*  GetFunctionType()  { return (FunctionType*)this; }
  StructType*    GetStructType()    { return (StructType*)this; }
  UnionType*     GetUnionType()     { return (UnionType*)this; }
  CompositeType* GetCompositeType() { return (CompositeType*)this; }
  ArrayType*     GetArrayType()     { return (ArrayType*)this; }
};

} /* end type */

#endif /* __TYPE_HPP__ */

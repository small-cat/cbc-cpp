#ifndef __ARRAY_TYPE_H__
#define __ARRAY_TYPE_H__

#include "type.hpp"

namespace type {
class ArrayType : public Type {
public:
  static long undefined;
  ArrayType(Type* base_type, long pointer_size);
  ArrayType(Type* base_type, long len, long pointer_size);
  virtual ~ArrayType();

  bool IsArray();
  bool IsAllocatedArray();
  bool IsIncompleteArray();
  Type* base_type();
  long length();
  long Size();
  long AllocSize();
  long Alignment();
 
  // equals

  bool IsSameType(Type *other);
  bool EqualType(Type *other);
  bool IsCompatible(Type *other);
  bool IsCastableTo(Type *target);
  std::string ToString();
private:
  Type* base_type_;     // type of array elements
  long length_;         // length of array
  long pointer_size_;
};
} /* end type */

#endif /* __ARRAY_TYPE_H__ */

#ifndef __VOID_TYPE_H__
#define __VOID_TYPE_H__

#include "type.hpp"

namespace type {
class VoidType : public Type {
public:
  VoidType() {}
  virtual ~VoidType() {}

  bool IsVoid() { return true; }
  long Size() { return 1; }

  bool IsSameType(Type* other) {
    return other->IsVoid();
  }

  bool EqualType(Type *other) {
    return IsSameType(other);
  }

  bool IsCompatible(Type* other) {
    return other->IsVoid();
  }

  bool IsCastableTo(Type* target) {
    return target->IsVoid();
  }

  std::string ToString() {
    return "void";
  }
};
} /* end type */

#endif /* __VOID_TYPE_H__ */

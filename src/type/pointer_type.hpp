#ifndef __POINTER_TYPE_H__
#define __POINTER_TYPE_H__

#include "type.hpp"

namespace type {
class PointerType : public Type {
public:
  PointerType(long s, Type* t) : size_(s), base_type_(t) {}
  virtual ~PointerType() {}

  bool IsPointer() { return true; }
  bool IsScalar() { return true; }
  bool IsSigned() { return false; }
  bool IsCallable() { return base_type_->IsFunction(); }

  long Size() {
    return size_;
  }

  Type* base_type() {
    return base_type_;
  }

  bool IsSameType(Type* other) {
    if (!other->IsPointer()) {
      return false;
    }

    return base_type_->IsSameType(other->base_type());
  }

  bool IsCompatible(Type* other) {
    if (!other->IsPointer()) {
      return false;
    }

    if (other->base_type()->IsVoid()) {
      return true;
    }

    return base_type_->IsCompatible(other->base_type());
  }

  bool IsCastableTo(Type* target) {
    return target->IsPointer() || target->IsInteger();
  }

  std::string ToString() {
    return base_type_->ToString() + "*";
  }
private:
  long size_;
  Type* base_type_;
};
} /* end type */

#endif /* __POINTER_TYPE_H__ */

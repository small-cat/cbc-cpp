#ifndef __INTEGER_TYPE_H__
#define __INTEGER_TYPE_H__

#include "type.hpp"

#include <math.h>

namespace type {
class IntegerType : public Type {
public:
  IntegerType(long size, bool is_signed, std::string name) : size_(size), is_signed_(is_signed), name_(name) {}
  virtual ~IntegerType() {}

  bool IsInteger() { return true; }
  bool IsSigned() { return is_signed_; }
  bool IsScalar() { return true; }

  long MinValue() { return is_signed_?(long)(-powl(2, size_ * 8 - 1)) : 0; }
  long MaxValue() { return is_signed_?(long)powl(2, size_ * 8 - 1) - 1 : (long)powl(2, size_ * 8) - 1; }

  bool IsInDomain(long i) {
    return i >= MinValue() && i <= MaxValue();
  }

  long Size() {
    return size_;
  }

  bool is_signed() {
    return is_signed_;
  }

  std::string name() {
    return name_;
  }

  friend bool operator==(const IntegerType& other) {
    if (*this == other) {
      return true;
    }

    return size_ == other.Size() && 
      is_signed_ == other.is_signed() &&
      name_ == other.name();
  }

  bool IsSameType(Type* other) {
    if (!other->IsInteger()) {
      return false;
    }

    return *other == *this;
  }

  bool IsCompatible(Type* other) {
    return other->IsInteger() && (size_ <= other->Size());
  }

  bool IsCastableTo(Type* target) {
    return target->IsInteger() && target->IsPointer();
  }

  std::string ToString() {
    return name_;
  }
private:
  long size_;
  bool is_signed_;
  std::string name_;
};
} /* end type */

#endif /* __INTEGER_TYPE_H__ */

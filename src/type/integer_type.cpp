#include "integer_type.hpp"

namespace type {

IntegerType::IntegerType(long size, bool is_signed, std::string name) : size_(size), is_signed_(is_signed), name_(name) {}
IntegerType::~IntegerType() {}

bool IntegerType::IsInteger() { return true; }
bool IntegerType::IsSigned() { return is_signed_; }
bool IntegerType::IsScalar() { return true; }

long IntegerType::MinValue() { return is_signed_ ? (long)(-powl(2, size_ * 8 - 1)) : 0; }
long IntegerType::MaxValue() { return is_signed_ ? (long)powl(2, size_ * 8 - 1) - 1 : (long)powl(2, size_ * 8) - 1; }

bool IntegerType::IsInDomain(long i) {
  return i >= MinValue() && i <= MaxValue();
}

long IntegerType::Size() {
  return size_;
}

bool IntegerType::is_signed() {
  return is_signed_;
}

std::string IntegerType::name() {
  return name_;
}

bool operator==(const IntegerType &src, const IntegerType &other) {
  if (&src == &other) {
    return true;
  }

  return src.size_ == other.size_ && src.is_signed_ == other.is_signed_
  && src.name_ == other.name_;
}

bool IntegerType::IsSameType(Type *other) {
  if (!other->IsInteger())
  {
    return false;
  }

  return *((IntegerType *)other) == *this;
}

bool IntegerType::IsCompatible(Type *other) {
  return other->IsInteger() && (size_ <= other->Size());
}

bool IntegerType::IsCastableTo(Type *target) {
  return target->IsInteger() && target->IsPointer();
}

std::string IntegerType::ToString() {
  return name_;
}
} // namespace type
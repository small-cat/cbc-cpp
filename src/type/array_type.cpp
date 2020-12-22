#include "array_type.h"

namespace type {
long ArrayType::undefined = -1;

ArrayType::ArrayType(Type* base_type, long pointer_size) : base_type_(base_type), 
                                                           length_(undefined),
                                                           pointer_size_(pointer_size) {}

ArrayType::ArrayType(Type* base_type, long len, long pointer_size) 
  : base_type_(base_type), length_(len), pointer_size_(pointer_size) {}

ArrayType::~ArrayType() {
  if (nullptr != base_type_) {
    delete base_type_;
    base_type_ = nullptr;
  }
}

bool ArrayType::IsArray() {
  return true;
}

bool ArrayType::IsAllocatedArray() {
  return length_ != ArrayType::undefined && 
    (!base_type_->IsArray() || base_type_->IsAllocatedArray());
}

bool ArrayType::IsIncompleteArray() {
  if (!base_type_->IsArray()) {
    return false;
  }

  return !base_type_->IsAllocatedArray();
}

Type* ArrayType::base_type() {
  return base_type_;
}

long ArrayType::length() {
  return length_;
}

// value size as pointer
long ArrayType::Size() {
  return pointer_size_;
}

// value size as allocated array, sum size of all the elements
long ArrayType::AllocSize() {
  if (length_ == ArrayType::undefined) {
    return pointer_size_;
  } else {
    return base_type_->AllocSize() * length_;
  }
}

long ArrayType::Alignment() {
  return base_type_->Alignment();
}

bool ArrayType::IsSameType(Type* other) {
  if (!other->IsPointer() && !other->IsArray()) {
    return false;
  }

  return base_type_->IsSameType(other->base_type());
}

bool ArrayType::IsCompatible(Type* other) {
  if (!other->IsPointer() && !other->IsArray()) {
    return false;
  }

  if (other->base_type()->IsVoid()) {
    return true;
  }

  return base_type_->IsCompatible(other->base_type()) &&
    base_type_->Size() == other->base_type()->Size();
}

bool ArrayType::IsCastableTo(Type* target) {
  return target->IsPointer() || target->IsArray();
}

std::string ArrayType::ToString() {
  if (length_ < 0) {
    return base_type_->ToString() + "[]";
  } else {
    return base_type_->ToString() + "[" + std::to_string(length_) + "]";
  }
}

} /* end type */

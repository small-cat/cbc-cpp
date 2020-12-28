/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : type_ref.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : name definition of type
*/

#ifndef __TYPE_REF_H__
#define __TYPE_REF_H__

#include <vector>
#include "ast/location.hpp"

namespace type {
class TypeRef {
public:
  TypeRef(ast::Location* l);
  virtual ~TypeRef();

  ast::Location* location();
  void SetLocation(ast::Location* l);
  // HashCode

  virtual std::string ToString();
private:
  ast::Location* location_;
};

class TypeRefTracker {
public:
  template <typename T, typename ... Args>
    T* CreateInstance(Args&& ... args) {
      static_assert(std::is_base_of<TypeRef, T>::value, "Argument must be TypeRef type");
      T *result = new T(args ...);
      allocated_.push_back(result);
      return result;
    }

  void AddInstance(TypeRef* ref) {
    allocated_.push_back(ref);
  }

  void Reset() {
    for (auto entry : allocated_) {
      delete entry;
    }
    allocated_.clear();
  }

private:
  std::vector<TypeRef *> allocated_;
};

} /* end type */
#endif /* __TYPE_REF_H__ */

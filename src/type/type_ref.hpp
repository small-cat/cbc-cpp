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
#include <string.h>
#include "ast/location.hpp"
#include "utils/cpp_utils.hpp"

namespace type {
class TypeRef {
public:
  TypeRef(ast::Location* l);
  virtual ~TypeRef();

  ast::Location* location();
  void SetLocation(ast::Location* l);
  // HashCode

  virtual std::string ToString();
  virtual std::string name() const;

  bool operator< (const TypeRef &other) const;

  // 判断 TypeRef 是否相同
  virtual bool IsSameTypeRef(TypeRef *other) = 0;
private:
  ast::Location* location_;
};

// std::map 以红黑树结构保存，以类指针作为key，comparator 应该做出 less / greater 的比较
template <typename T>
struct Less_TypeRef {
  bool operator() (const T &lhs, const T &rhs) {
    if (lhs->IsSameTypeRef(rhs)) {
      return false;
    } else {
      // typeref is not the same, compare by name
      return *lhs < *rhs;
    }
  }
};

} /* end type */
#endif /* __TYPE_REF_H__ */

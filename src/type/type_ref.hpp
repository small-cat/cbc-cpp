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

#include "../ast/location.hpp"

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
} /* end type */
#endif /* __TYPE_REF_H__ */

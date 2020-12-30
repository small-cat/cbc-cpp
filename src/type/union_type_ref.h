/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: union_type_ref.h
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/16
* @brief: union type ref
*/
#ifndef UNION_TYPE_REF_H
#define UNION_TYPE_REF_H

#include "type_ref.hpp"

namespace type {
class UnionTypeRef : public TypeRef {
public:
  UnionTypeRef(std::string name);
  UnionTypeRef(ast::Location* l, std::string name);
  virtual ~UnionTypeRef();

  bool IsUnion();
  std::string name();
  std::string ToString();
  friend bool operator==(const UnionTypeRef&, const UnionTypeRef&);
private:
  std::string union_name_;
};
} /* type */

#endif
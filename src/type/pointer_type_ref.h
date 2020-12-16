/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: pointer_type_ref.h
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/15
* @brief:  pointer type ref
*/
#ifndef POINTER_TYPE_REF_H
#define POINTER_TYPE_REF_H

#include "type_ref.hpp"

namespace type {
class PointerTypeRef : public TypeRef {
public:
  PointerTypeRef(TypeRef* base);
  virtual ~PointerTypeRef();

  bool IsPointer();
  TypeRef* base_type();
  virtual std::string ToString();
private:
  TypeRef* base_type_;
};
} /* type */

#endif
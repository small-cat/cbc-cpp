/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: array_type_ref.h
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/15
* @brief: array type ref definition
*/

#ifndef ARRAY_TYPE_REF_H
#define ARRAY_TYPE_REF_H

#include "type_ref.hpp"

namespace type {
class ArrayTypeRef : public TypeRef {
public:
  ArrayTypeRef(TypeRef* base);
  ArrayTypeRef(TypeRef* base, long len);
  virtual ~ArrayTypeRef();

  bool IsArray();
  TypeRef* base_type();
  long length();
  bool IsArrayUndefined();

  virtual std::string ToString();
  virtual std::string name();

  static const long UNDEFINED = -1;
private:
  TypeRef* base_type_;
  long length_;   // length of array
};
} /* type */

#endif
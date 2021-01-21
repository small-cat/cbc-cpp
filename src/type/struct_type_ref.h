/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: struct_type_ref.h
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/16
* @brief: struct type ref definition, reference to struct type name
*/
#ifndef STRUCT_TYPE_REF_H
#define STRUCT_TYPE_REF_H

#include "type_ref.hpp"

namespace type {
class StructTypeRef : public TypeRef {
public:
  StructTypeRef(std::string name);
  StructTypeRef(ast::Location* l, std::string name);
  virtual ~StructTypeRef();

  bool IsStruct();
  virtual std::string name() const;
  virtual std::string ToString();
  friend bool operator==(const StructTypeRef& src, const StructTypeRef& other);
  virtual bool IsSameTypeRef(TypeRef *other);

private:
  std::string struct_name_;
};
} /* type */

#endif
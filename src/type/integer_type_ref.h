/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: integer_type_ref.h
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/16
* @brief: integer type ref definition
*/
#ifndef INTEGER_TYPE_REF_H
#define INTEGER_TYPE_REF_H

#include <map>
#include "type_ref.hpp"

namespace type {
class IntegerTypeRef : public TypeRef {
public:
  IntegerTypeRef(std::string name);
  IntegerTypeRef(ast::Location* l, std::string name);
  virtual ~IntegerTypeRef();

  std::string integer_type_name();
  std::string ToString();

  enum IntegerTypeClass {
    SESAME_CHAR = 1,
    SESAME_SHORT,
    SESAME_INT,
    SESAME_LONG,
    SESAME_UCHAR,
    SESAME_USHORT,
    SESAME_UINT,
    SESAME_ULONG
  };

  static std::map<IntegerTypeClass, std::string> IntegerTypeNames;
  static std::string GetIntegerTypeClassName(std::map<IntegerTypeClass, std::string> map, IntegerTypeClass cls);
  static IntegerTypeRef* GetIntegerTypeClass(IntegerTypeClass cls);
  static IntegerTypeRef* GetIntegerTypeClass(IntegerTypeClass cls, ast::Location* l);
  
private:
  std::string integer_type_name_;
};
} /* type */

#endif
/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: platform.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/31
 * @brief: abstract interface for different platform
*/
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "type/type_table.h"

namespace sysdep {
class Platform {
public:
  Platform(type::TypeTable::TypeTableClass cls) : type_table_class_(cls) {}
  virtual ~Platform() {}

  virtual type::TypeTable::TypeTableClass GetTypeTableClass() { return type_table_class_; }
private:
  type::TypeTable::TypeTableClass type_table_class_;
};
} /* sysdep */

#endif
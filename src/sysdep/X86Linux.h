/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: X86Linux.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/31
 * @brief: platform for x86 linux 32bit
*/
#ifndef __X86LINUX_H__
#define __X86LINUX_H__

#include "platform.h"

namespace sysdep {
class X86Linux : public Platform {
public:
  X86Linux() : Platform(type::TypeTable::TypeTableClass::ILP32) {}
  virtual ~X86Linux() {}
};
} /* sysdep */

#endif
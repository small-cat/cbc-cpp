/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: constant_table.hpp
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/25
 * @brief: 常量符号表
*/
#ifndef __CONSTANT_TABLE_H__
#define __CONSTANT_TABLE_H__

#include <map>
#include <string>

#include "constant_entry.h"

namespace entity {
class ConstantTable  {
public:
  ConstantTable();
  ConstantTable(ConstantTable& tb);
  virtual ~ConstantTable();

  bool IsEmpty();
  ConstantEntry* Intern(std::string n);
  std::map<std::string, ConstantEntry *> table();
private:
  std::map<std::string, ConstantEntry *> table_;
};
} /* end entity */

#endif /* __CONSTANT_TABLE_H__ */

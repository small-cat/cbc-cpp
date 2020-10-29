/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : undefined_variable.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-29
 * @brief : declare in header file, and should be resolved with entity
*/

#ifndef __UNDEFINED_VARIABLE_H__
#define __UNDEFINED_VARIABLE_H__

#include <string>
#include "variable.h"
#include "../ast/type/type_node.hpp"

namespace entity {
class UndefinedVariable : public Variable {
public:
  UndefinedVariable(ast::TypeNode* t, std::string n) : Variable(false, t, n) {}
  virtual ~UndefinedVariable() {}

  bool IsDefined() { return false; }
  bool IsPrivate() { return false; }
  bool IsInitialized() { return false; }

  // @todo { not implement _dump accept }
  // void _dump();
  // void accept();
};
} /* end entity */

#endif /* __UNDEFINED_VARIABLE_H__ */

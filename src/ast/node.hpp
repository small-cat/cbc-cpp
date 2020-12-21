/**
 * @copyright (c) Copyright 2020 Secsmart. All Rights Reserved.
 * @license
 * @file  : node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-23
 * @brief : abstract node definitions for ast
*/
#ifndef __NODE_H__
#define __NODE_H__

#include "location.hpp"

namespace ast {

class Dumper;

class Node  {
public:
  Node() {}
  virtual ~Node() {}

  virtual Location* location() = 0;
  virtual void _dump(ast::Dumper* d) {}

  virtual std::string GetClass() = 0;
};
} /* end ast */

#endif /* __NODE_H__ */

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

#include "dumper.h"
#include "location.hpp"

namespace ast {

class Node  {
public:
  Node() {}
  virtual ~Node() {}

  virtual Location* location() = 0;
  void Dump(Dumper* d) {
    d->PrintClass(this, location());
    _dump(d);
  }

  virtual void _dump(Dumper* d) = 0;
};
} /* end ast */

#endif /* __NODE_H__ */

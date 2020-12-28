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

#include <vector>

#include "location.hpp"
#include "dumper.h"

namespace ast {

class Node  {
public:
  Node() {}
  virtual ~Node() {}

  virtual Location* location() = 0;
  virtual void _dump(ast::Dumper* d) {}

  virtual std::string GetClass() = 0;
};

class NodeTracker {
public:
  template <typename T, typename ... Args>
    T* CreateInstance(Args&& ... args) {
      static_assert(std::is_base_of<Node, T>::value, "Arguments must be Node type");
      T* result = new T(args ...);
      allocated_.push_back(result);
      return result;
    }

  void Reset() {
    for (auto entry : allocated_) {
      delete entry;
    }

    allocated_.clear();
  }

private:
  std::vector<Node *> allocated_;
};

} /* end ast */

#endif /* __NODE_H__ */

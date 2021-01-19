/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: node_tracker.hpp
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/12
 * @brief: node tracker for tree node management, create and reset
*/

#ifndef __NODE_TRACKER_H__
#define __NODE_TRACKER_H__

#include <iostream>
#include <vector>

namespace utils {
template <typename T>
class NodeTracker {
public:
  template <typename S, typename ... Args>
    S* CreateInstance(Args&& ... args) {
      static_assert(std::is_base_of<T, S>::value, "Argument type error");
      S* result = new S(args ...);
      allocated_.push_back(result);
      return result;
    }

  void Reset() {
    for (auto entry : allocated_) {
      delete entry;
    }
    allocated_.clear();
  }

  void AddInstance(T *ins) {
    allocated_.push_back(ins);
  }
private:
  std::vector<T *> allocated_;
};
} /* utils */

#endif
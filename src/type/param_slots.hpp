#ifndef __PARAM_SLOTS_H__
#define __PARAM_SLOTS_H__

#include <iostream>
#include <vector>
#include "../ast/location.hpp"

namespace type {

template<typename T>
class ParamSlots {
public:
  ParamSlots(std::vector<T*> param_desc) : location_(nullptr), vararg_(false) {
    param_descriptors_.swap(param_desc);
  }

  ParamSlots(ast::Location* l, std::vector<T*> param_desc) : location_(l), vararg_(false) {
    param_descriptors_.swap(param_desc);
  }

  ParamSlots(ast::Location* l, std::vector<T*> param_desc, bool var) : location_(l), vararg_(var) {
    param_descriptors_.swap(param_desc);
  }

  virtual ~ParamSlots() {}

  int Argc() {
    if (vararg_) {
      std::cout << "must not happen: Param#argc for vararg_" << std::endl;
    }

    return param_descriptors_.size();
  }

  int MinArgc() { return param_descriptors_.size(); }
  void AcceptVararg() { vararg_ = true; }
  bool vararg() { return vararg_; }
  ast::Location* location() { return location_; }
  std::vector<T*> ParamDecs() { return param_descriptors_; }
private:
  ast::Location* location_;
  std::vector<T*> param_descriptors_;
  bool vararg_;
};

template <typename T>
class ParamSlotsTracker {
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
private:
  std::vector<T *> allocated_;
};

} /* end type */

#endif /* __PARAM_SLOTS_H__ */

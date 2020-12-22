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

  virtual ~ParamSlots() {
    if (nullptr != location_) {
      delete location_;
      location_ = nullptr;
    }

    for (auto& p : param_descriptors_) {
      delete p;
      p = nullptr;
    }
  }

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

} /* end type */

#endif /* __PARAM_SLOTS_H__ */

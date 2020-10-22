#ifndef __PARAM_TYPES_H__
#define __PARAM_TYPES_H__

#include "param_slots.hpp"

namespace type {

class ParamTypes : public ParamSlots<Type> {
public:
  ParamTypes(ast::Location* l, std::list<Type*> param_desc, bool var) : ParamSlots<Type>(l, param_desc, var) {}
  virtual ~ParamTypes() {}

  std::list<Type*> Types() {
    return Params();
  }

  bool IsSameType(ParamTypes* t) {
    if (vararg() != t->vararg()) {
      return false;
    }

    if (MinArgc() != t->MinArgc()) {
      return false;
    }

    auto it1 = Params().begin();
    auto it2 = t->Params().begin();
    while (it1 != Params().end() && it2 != t->Params().end()) {
      if (!(*it1)->IsSameType(*it2)) {
        return false;
      }

      it1++;
      it2++;
    }
    return true;
  }
};
  
} /* end type */

#endif /* __PARAM_TYPES_H__ */

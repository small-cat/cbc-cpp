#ifndef __PARAM_TYPES_H__
#define __PARAM_TYPES_H__

#include "param_slots.hpp"

namespace type {

class ParamTypes : public ParamSlots<Type> {
public:
  ParamTypes(ast::Location* l, std::vector<Type*> param_desc, bool var) : ParamSlots<Type>(l, param_desc, var) {}
  virtual ~ParamTypes() {}

  std::vector<Type*> Types() {
    return ParamDecs();
  }

  bool IsSameType(ParamTypes* t) {
    if (t == this) { return true; }
    if (vararg() != t->vararg()) {
      return false;
    }

    if (MinArgc() != t->MinArgc()) {
      return false;
    }

    auto pam_types1 = Types();
    auto pam_types2 = t->Types();
    if (pam_types1.size() != pam_types2.size()) {
      return false;
    }

    std::vector<Type *>::size_type pos = 0;
    while (pos < pam_types1.size()) {
      if (!(pam_types1.at(pos))->IsSameType(pam_types2.at(pos))) {
        return false;
      }

      pos ++;
    }
    return true;
  }

  bool EqualType(ParamTypes *other) {
    return IsSameType(other);
  }
};
  
} /* end type */

#endif /* __PARAM_TYPES_H__ */

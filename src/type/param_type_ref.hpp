#ifndef __PARAM_TYPE_REF_H__
#define __PARAM_TYPE_REF_H__

#include "param_slots.hpp"
#include "../ast/location.hpp"

namespace type {
class ParamTypeRefs : public ParamSlots<TypeRef> {
public:
  ParamTypeRefs(std::vector<TypeRef*> param_decs) : ParamSlots<TypeRef>(param_decs) {}
  ParamTypeRefs(ast::Location* l, std::vector<TypeRef*> param_decs, bool vararg) 
    : ParamSlots<TypeRef>(l, param_decs, vararg) {}
  virtual ~ParamTypeRefs() {}

  std::vector<TypeRef*> GetTypeRefs() {
    return ParamDecs();
  }

  // @todo { not implement InternTypes }
  /*
  ParamTypes* InternTypes(TypeTable* table) {
    std::vector<Type*> types;
    for (auto& tr : ParamDecs()) {
      types.push_back(table->GetParamType(tr));
    }

    return new ParamTypes(location(), types, vararg());
  }
  */
};
} /* end type */

#endif /* __PARAM_TYPE_REF_H__ */

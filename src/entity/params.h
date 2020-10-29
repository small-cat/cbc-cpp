#ifndef __PARAMS_H__
#define __PARAMS_H__

#include "parameter.h"
#include "../type/param_slots.hpp"
#include "../ast/location.hpp"

namespace entity {
class Params : type::ParamSlots<Parameter> {
public:
  Params(ast::Location* l, std::vector<Parameter*> parameters);
  virtual ~Params();

  std::vector<Parameter*> GetParameters();

  // @todo { not implement functions below }
  // type::ParamTypeRefs* GetParameterTypeRefs();
  // void _dump(); // @todo { _dump }
private:
  /* data */
};
} /* end entity */

#endif /* __PARAMS_H__ */

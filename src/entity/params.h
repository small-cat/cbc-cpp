#ifndef __PARAMS_H__
#define __PARAMS_H__

#include "parameter.h"
#include "../type/param_slots.hpp"
#include "../ast/location.hpp"
#include "../type/param_type_ref.hpp"
#include "../ast/dumper.h"

namespace entity {
class Params : public type::ParamSlots<Parameter> {
public:
  Params(ast::Location* l, std::vector<Parameter*> parameters);
  virtual ~Params();

  std::vector<Parameter*> GetParameters();

  type::ParamTypeRefs* GetParameterTypeRefs();
  void _dump(ast::Dumper* d); 
private:
  /* data */
};
} /* end entity */

#endif /* __PARAMS_H__ */

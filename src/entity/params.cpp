#include "params.h"

namespace entity {
Params::Params(ast::Location* l, std::vector<Parameter*> parameters)
  : type::ParamSlots<Parameter>(l, parameters, false) {}

Params::~Params() {}

std::vector<Parameter*> Params::GetParameters() {
  return ParamDecs();
}

// // @todo { not implement GetParameterTypeRefs }
// type::ParamTypeRefs* Params::GetParameterTypeRefs() {}
} /* end entity */

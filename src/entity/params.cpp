#include "params.h"

namespace entity {
Params::Params(ast::Location* l, std::vector<Parameter*> parameters)
  : type::ParamSlots<Parameter>(l, parameters, false) {}

Params::~Params() {}

std::vector<Parameter*> Params::GetParameters() {
  return ParamDecs();
}

// // @todo { not implement GetParameterTypeRefs }

type::ParamTypeRefs* Params::GetParameterTypeRefs() {
  std::vector<type::TypeRef*> typeref_list;
  for (auto& p : ParamDecs()) {
    auto tr = p->type_node()->type_ref();
    typeref_list.push_back(tr);
  }

  return new type::ParamTypeRefs(location(), typeref_list, false); // vararg_ is false when constructure Params
}

void Params::_dump(ast::Dumper* d) {
  d->PrintNodeList("Params", GetParameters());
}
} /* end entity */

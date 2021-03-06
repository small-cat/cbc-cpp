#include "params.h"

namespace entity {
Params::Params(ast::Location* l, std::vector<Parameter*> parameters)
  : type::ParamSlots<Parameter>(l, parameters, false) {}

Params::~Params() {}

std::vector<Parameter*> Params::GetParameters() {
  return ParamDecs();
}

bool Params::IsParamsEmpty() {
  return IsParametersEmpty();
}

type::ParamTypeRefs* Params::GetParameterTypeRefs() {
  std::vector<type::TypeRef*> typeref_list;
  if (!IsParamsEmpty()) {
    for (auto &p : ParamDecs())
    {
      auto tr = p->type_node()->type_ref();
      typeref_list.push_back(tr);
    }
  }

  // 在构造 ast 的过程中，如果函数参数是可变参数， vararg() 返回 true
  return new type::ParamTypeRefs(location(), typeref_list, vararg());
}

void Params::_dump(ast::Dumper* d) {
  d->PrintNodeList("Params", GetParameters());
}
} /* end entity */

/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: param_type_ref.hpp
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/15
* @brief: 参数定义，TypeRef 仅仅是类型的名称和location，vararg 为true，表示接受可变参数，即参数末尾为 ... 形式
*/

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
    std::vector<TypeRef *> res;
    if (IsParametersEmpty()) {
      return res;
    } 

    return ParamDecs();
  }

  virtual bool IsSameTypeRef(TypeRef *other) {
    if (! utils::is<ParamTypeRefs *>(other)) {
      return false;
    }

    return IsSameTypeRef((ParamTypeRefs *)other);
  }

  virtual bool IsSameTypeRef(ParamTypeRefs *other) {
    if (vararg() != other->vararg()) {
      return false;
    }

    auto tr_list1 = GetTypeRefs();
    auto tr_list2 = other->GetTypeRefs();

    if (tr_list1.size() != tr_list2.size()) {
      return false;
    }

    int i = tr_list1.size() - 1;
    while (i >= 0) {
      if (! tr_list1.at(i)->IsSameTypeRef(tr_list2.at(i))) {
        return false;
      }
      i--;
    }

    return true;
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

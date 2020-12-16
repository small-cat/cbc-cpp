#ifndef __FUNCTION_TYPE_REF_H__
#define __FUNCTION_TYPE_REF_H__

#include "type_ref.hpp"
#include "param_type_ref.hpp"

namespace type {
class FunctionTypeRef : public TypeRef {
public:
  FunctionTypeRef(TypeRef* tr, ParamTypeRefs* param_tr);
  virtual ~FunctionTypeRef();

  bool IsFunction();
  TypeRef* return_type();
  ParamTypeRefs* params();

  virtual std::string ToString();
private:
  TypeRef* return_type_;
  ParamTypeRefs* params_;
};
} /* end type */

#endif /* __FUNCTION_TYPE_REF_H__ */

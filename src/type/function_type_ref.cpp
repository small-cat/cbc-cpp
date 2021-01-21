#include "function_type_ref.hpp"

namespace type {
FunctionTypeRef::FunctionTypeRef(TypeRef* tr, ParamTypeRefs* param_tr)
  : TypeRef(tr->location()) ,return_type_(tr), params_(param_tr) {
}

FunctionTypeRef::FunctionTypeRef(TypeRef *tr) : TypeRef(tr->location()), return_type_(tr), params_(nullptr) {}

FunctionTypeRef::~FunctionTypeRef() {}

bool FunctionTypeRef::IsFunction() {
  return true;
}

TypeRef* FunctionTypeRef::return_type() {
  return return_type_;
}

ParamTypeRefs* FunctionTypeRef::params() {
  return params_;
}

std::string FunctionTypeRef::ToString() const {
  std::string ret = return_type_->ToString();
  ret += " (";

  std::string sep{""};
  for (auto &p : params_->GetTypeRefs())
  {
    ret += sep;
    ret += p->ToString();
    sep = ", ";
  }

  ret += ")";
  return ret;
}

/************************************************************************************
* @fn name()
* @brief 函数类型名称，应该以整个函数原型作为名称，仅仅是返回值类型的名称，是没办法区分一般类型
*        和函数类型的，比如 int f(char), 如果进返回返回值类型名称，为 int，不能区分这个是不是函数。
*        在 type_ref.h 中，重定义了 operator< 方法，用于将 TypeRef 作为 map 的key 使用。所以
*        此处的 name() 返回值必须能够与一般类型区分开，否则 map 中的操作会出错
* @param
* @author Jona
* @date 2021/01/11
************************************************************************************/
std::string FunctionTypeRef::name() const {
  //return return_type_->name();
  return ToString();
}

bool FunctionTypeRef::IsSameTypeRef(TypeRef *other) {
  if (! utils::is<FunctionTypeRef *>(other)) {
    return false;
  }

  auto fun_tr = (FunctionTypeRef *)other;
  return return_type_->IsSameTypeRef(fun_tr->return_type()) && params_->IsSameTypeRef(fun_tr->params());
}

} /* end type */

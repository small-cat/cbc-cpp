#include "function_type_ref.hpp"

namespace type {
FunctionTypeRef::FunctionTypeRef(TypeRef* tr, ParamTypeRefs* param_tr)
  : TypeRef(tr->location()) ,return_type_(tr), params_(param_tr) {
}

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

std::string FunctionTypeRef::ToString() {
  std::string ret = return_type_->ToString();
  ret += " (";
  std::string sep {""};
  for (auto& p : params_->GetTypeRefs()) {
    ret += sep;
    ret += p->ToString();
    sep = ", ";
  }

  ret += ")";
  return ret;
}

std::string FunctionTypeRef::name() const {
  return return_type_->name();
}

} /* end type */

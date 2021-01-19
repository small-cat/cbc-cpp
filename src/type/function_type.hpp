#ifndef __FUNCTION_TYPE_H__
#define __FUNCTION_TYPE_H__

#include "type.hpp"
#include "param_types.hpp"

namespace type {
class FunctionType : public Type {
public:
  FunctionType(Type* ret, ParamTypes* ptypes) : return_type_(ret), param_types_(ptypes) {}
  virtual ~FunctionType() {}

  Type* return_type() { return return_type_; }
  ParamTypes* param_types() { return param_types_; }

  // 函数类型，可以看作是指针，长度应该是指针大小
  long Size() {
    /// NOTE:cbc regard it as an error
    std::cout << "FunctionType#Size called." << std::endl;  
    return 0;
  }

  bool IsFunction() { return true; }
  bool IsCallable() { return true; }

  bool IsSameType(Type* other) {
    if (this == other) { return true; }
    if (!other->IsFunction()) {
      return false;
    }

    FunctionType* t = other->GetFunctionType();
    return t->return_type()->IsSameType(return_type_) &&
      t->param_types()->IsSameType(param_types_);
  }

  bool EqualType(Type *other) { return IsSameType(other); }

  bool IsCompatible(Type* target) {
    if (!target->IsFunction()) {
      return false;
    }

    FunctionType* t = target->GetFunctionType();
    return t->return_type()->IsCompatible(return_type_) &&
      t->param_types()->IsSameType(param_types_);
  }

  bool IsCastableTo(Type* target) {
    return target->IsFunction();
  }

  /// 是否是可变参数
  bool IsVararg() {
    return param_types_->vararg();
  }

  bool AcceptsArgc(long num_args) {
    if (IsVararg()) {
      return num_args >= param_types_->MinArgc();
    }

    return num_args == param_types_->Argc();
  }

  long Alignment() {
    std::cout << "Error: FunctionType#Alignment called." << std::endl;
    exit(EXIT_FAILURE);
  }

  std::vector<Type *> GetParamTypes() {
    return param_types_->Types();
  }

  std::string ToString() {
    std::string res = return_type_->ToString();
    std::string sep {""};
    res += "(";
    for (auto& t : param_types_->Types()) {
      res += sep;
      res += t->ToString();
      sep = ", ";
    }
    res += ")";
    return res;
  }
private:
  Type* return_type_;
  ParamTypes* param_types_;
};
} /* end type */

#endif /* __FUNCTION_TYPE_H__ */

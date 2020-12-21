#include "function.h"
#include "../type/function_type.hpp"

namespace entity {
Function::Function(bool priv, ast::TypeNode* tn, std::string n) : Entity(priv, tn, n) {}
Function::~Function() {}

bool Function::IsInitialized() { 
  return true;
}

bool Function::IsDefined() {
  return false;
}

type::Type* Function::ReturnType() {
  return GetType()->GetFunctionType()->return_type();
}

bool Function::IsVoid() {
  return ReturnType()->IsVoid();
}

std::string Function::GetClass() {
  return "Function";
}

} /* end entity */

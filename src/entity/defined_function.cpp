#include "defined_function.h"

namespace entity {
DefinedFunction::DefinedFunction(bool priv, ast::TypeNode* tn, std::string n, Params* params, ast::BlockNode* body)
  : Function(priv, tn, n), params_(params), body_(body) {}

DefinedFunction::~DefinedFunction() {}

bool DefinedFunction::IsDefined() { 
  return true;
}

std::vector<Parameter*> DefinedFunction::GetParameters() {
  return params_->GetParameters();
}

ast::BlockNode* DefinedFunction::body() {
  return body_;
}

LocalScope* DefinedFunction::scope() {
  return scope_;
}

void DefinedFunction::SetScope(LocalScope* s) {
  scope_ = s;
}

std::vector<DefinedVariable*> DefinedFunction::GetLocalVariables() {
  return scope_->AllLocalVariables();
}

void DefinedFunction::_dump(ast::Dumper* d) {
  // @todo { not implement _dump }
}
} /* end entity */

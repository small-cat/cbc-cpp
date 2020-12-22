#include "defined_function.h"

namespace entity {
DefinedFunction::DefinedFunction(bool priv, ast::TypeNode* tn, std::string n, Params* params, ast::BlockNode* body)
  : Function(priv, tn, n), params_(params), body_(body) {}

DefinedFunction::~DefinedFunction() {
  if (nullptr != params_) {
    delete params_;
  }

  if (nullptr != body_) {
    delete body_;
  }

  params_ = nullptr;
  body_ = nullptr;
}

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

std::string DefinedFunction::GetClass() {
  return "DefinedFunction";
}

void DefinedFunction::_dump(ast::Dumper* d) {
  d->PrintMember("FunctionName", name());
  d->PrintMember("IsPrivate", is_private());
  d->PrintMember("Parameters", params_);
  d->PrintMember("FunctionBody", body_);
}
} /* end entity */

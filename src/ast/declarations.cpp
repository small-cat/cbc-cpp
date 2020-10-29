#include "declarations.hpp"

namespace ast {

Declarations::Declarations() {}
Declarations::~Declarations() {}

std::vector<TypeDefNode*> Declarations::typedefs() {
  return typedefs_;
}

void Declarations::AddDefvar(entity::DefinedVariable* var) {
  defvars_.push_back(var);
}

void Declarations::AddDefvars(std::vector<entity::DefinedVariable*> vars) {
  for (auto v : vars) {
    defvars_.push_back(v);
  }
}

std::vector<entity::DefinedVariable*> Declarations::defvars() {
  return defvars_;
}

void Declarations::AddDefun(entity::DefinedFunction* fun) {
  defuns_.push_back(fun);
}

void Declarations::AddConstant(entity::Constant* cons) {
  constants_.push_back(cons);
}

void Declarations::AddStruct(ast::StructTypeNode* s) {
  def_structs_.push_back(s);
}

void Declarations::AddUnion(ast::UnionTypeNode* u) {
  def_unions_.push_back(u);
}

void Declarations::AddTypedef(TypeDefNode* t) {
  typedefs_.push_back(t);
}

} /* end ast */

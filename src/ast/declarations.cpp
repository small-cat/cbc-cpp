#include "declarations.hpp"

namespace ast {

Declarations::Declarations() {}
Declarations::~Declarations() {}

std::vector<TypedefNode*> Declarations::typedefs() {
  return typedefs_;
}

void Declarations::AddDefvar(DefinedVariable* var) {
  defvars_.push_back(var);
}

void Declarations::AddDefvars(std::vector<DefinedVariable*> vars) {
  for (auto v : vars) {
    defvars_.push_back(v);
  }
}

std::vector<DefinedVariable*> Declarations::defvars() {
  return defvars_;
}

void Declarations::AddDefun(DefinedFunction* fun) {
  defuns_.push_back(fun);
}

void Declarations::AddConstant(Constant* cons) {
  constants_.push_back(cons);
}

void Declarations::AddStruct(StructTypeNode* s) {
  def_structs_.push_back(s);
}

void Declarations::AddUnion(UnionTypeNode* u) {
  def_unions_.push_back(u);
}

void Declarations::AddTypedef(TypedefNode* t) {
  typedefs_.push_back(t);
}

} /* end ast */

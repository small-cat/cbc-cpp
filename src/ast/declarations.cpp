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

std::vector<entity::UndefinedVariable*> Declarations::vardecls() {
  return vardecls_;
}

std::vector<entity::DefinedFunction*> Declarations::defuns() {
  return defuns_;
}

std::vector<entity::UndefinedFunction*> Declarations::funcdecls() {
  return funcdecls_;
}

std::vector<entity::Constant*> Declarations::constants() {
  return constants_;
}

std::vector<StructTypeNode*> Declarations::def_structs() {
  return def_structs_;
}

std::vector<UnionTypeNode*> Declarations::def_unions() {
  return def_unions_;
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

void Declarations::Add(Declarations* decls) {
  auto defined_vars = decls->defvars();
  for (auto& v : defined_vars) {
    defvars_.push_back(v);
  }

  auto undefined_vars = decls->vardecls();
  for (auto& uv : undefined_vars) {
    vardecls_.push_back(uv);
  }

  auto defined_funcs = decls->defuns();
  for (auto& df : defined_funcs) {
    defuns_.push_back(df);
  }

  auto undefined_funcs = decls->funcdecls();
  for (auto& udf : undefined_funcs) {
    funcdecls_.push_back(udf);
  }

  auto cons = decls->constants();
  for (auto& c : cons) {
    constants_.push_back(c);
  }

  auto struct_nodes = decls->def_structs();
  for (auto& stru : struct_nodes) {
    def_structs_.push_back(stru);
  }

  auto union_nodes = decls->def_unions();
  for (auto& un : union_nodes) {
    def_unions_.push_back(un);
  }
}

} /* end ast */

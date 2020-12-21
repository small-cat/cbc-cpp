#include "defined_variable.h"

namespace entity {
long DefinedVariable::TmpSeq = 0;

DefinedVariable::DefinedVariable(bool priv, ast::TypeNode* tn, 
                                 std::string n, ast::ExprNode* init)
  : Variable(priv, tn, n), initializer_(init) {}

DefinedVariable::~DefinedVariable() {}

bool DefinedVariable::IsDefined() {
  return true;
}

void DefinedVariable::SetSequence(long seq) {
  sequence_ = seq;
}

long DefinedVariable::sequence() {
  return sequence_;
}

std::string DefinedVariable::SymbolString() {
  return (sequence_ < 0) ? name() : name() + "." + std::to_string(sequence_);
}

bool DefinedVariable::HasInitializer() {
  return initializer_ != nullptr;
}

bool DefinedVariable::IsInitialized() {
  return initializer_ != nullptr;
}

ast::ExprNode* DefinedVariable::initializer() {
  return initializer_;
}

void DefinedVariable::SetInitializer(ast::ExprNode* init) {
  initializer_ = init;
}

void DefinedVariable::_dump(ast::Dumper* d) {
  d->PrintMember("VariableName", name());
  d->PrintMember("IsPrivate", is_private());
  d->PrintMember("TypeNode", type_node());
  d->PrintMember("Initializer", initializer_);
}

std::string DefinedVariable::GetClass() {
  return "DefinedVariable";
}

// void DefinedVariable::SetIR(ir::Expr* ir) {}
// ir::ExprNode* DefinedVariable::ir() {}

} /* end entity */

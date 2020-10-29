#include "ast.hpp"

namespace ast {

ASTNode::ASTNode(Location* l, Declarations* d) : location_(l), declarations_(d) {
}

ASTNode::ASTNode(Declarations* d) : declarations_(d) {}

ASTNode::~ASTNode() {}

Location* ASTNode::location() {
  return location_;
}

void ASTNode::AddDeclarations(Declarations* decl) {
  // @todo {  things to be done }
  // add defvars defuncs, constants, structs unions typedefs
}

} /* end as */

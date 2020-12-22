#include "ast.hpp"

namespace ast {

ASTNode::ASTNode(Location* l, Declarations* d) : location_(l), declarations_(d) {
}

ASTNode::ASTNode(Declarations* d) : declarations_(d) {}

ASTNode::~ASTNode() {
  if (nullptr != location_) {
    delete location_;
    location_ = nullptr;
  }

  if(nullptr != declarations_) {
    delete declarations_;
    declarations_ = nullptr;
  }

  if (nullptr != scope_) {
    delete scope_;
    scope_ = nullptr;
  }

  if (nullptr != constant_table_) {
    delete constant_table_;
    constant_table_ = nullptr;
  }
}

Location* ASTNode::location() {
  return location_;
}

void ASTNode::AddDeclarations(Declarations* decl) {
  // @todo {  things to be done }
  // add defvars defuncs, constants, structs unions typedefs
}

void ASTNode::SetTokenStrings(std::vector<std::string> sv) {
  token_strings_.swap(sv);
}

void ASTNode::DumpTokens() {
  for (auto& t : token_strings_) {
    std::cout << t << std::endl;
  }
}

void ASTNode::DumpAst(Dumper* d) {
  d->PrintNodeList("variables", declarations_->defvars());
  d->PrintNodeList("functions", declarations_->defuns());
}

std::string ASTNode::GetClass() { return ""; }

} /* end as */

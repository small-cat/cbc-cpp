#include "local_resolver.h"

namespace compiler {
LocalResolver::LocalResolver(utils::ErrorHandler * err) : err_handler_(err) {
  scope_stack_.clear();
  constant_table_ = new entity::ConstantTable();
}

LocalResolver::~LocalResolver() {
  for (auto& s : scope_stack_) {
    delete s;
    s = nullptr;
  }

  if (constant_table_ != nullptr) {
    delete constant_table_;
    constant_table_ = nullptr;
  }
}

void LocalResolver::Resolve(ast::StmtNode * node) {
  node->Accept(this);
}

void LocalResolver::Resolve(ast::ExprNode * expr) {
  expr->Accept(this);
}

void LocalResolver::Resolve(ast::ASTNode * ast) {

}

} /* compiler */
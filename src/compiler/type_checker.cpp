#include "type_checker.h"

namespace compiler {
TypeChecker::TypeChecker(type::TypeTable *tb, utils::ErrorHandler *err) : table_(tb), handler_(err) {}
TypeChecker::~TypeChecker() {}

void TypeChecker::Check(ast::StmtNode *node) {
  VisitStmt(node);
}

void TypeChecker::Check(ast::ExprNode *node) {
  VisitExpr(node);
}

void TypeChecker::Check(ast::ASTNode *ast) {
  for (auto defvar : ast->DefinedVariables()) {
    CheckVariable(defvar);
  }

  for (auto defun : ast->DefinedFunctions()) {
    cur_function_ = defun;
    CheckReturnType(defun);
    CheckParamTypes(defun);
    Check(defun->body());
  }

  if (handler_->ErrorOccured()) {
    handler_->Error("Compile failed in TypeCheck");
    exit(EXIT_FAILURE);
  }
}

void TypeChecker::CheckReturnType(entity::DefinedFunction *defun) {
  if (IsInvalidReturnType(defun->ReturnType())) {
    handler_->Error(defun->GetLocation(), "returns invalid type: " + defun->ReturnType()->ToString());
  }
}

void TypeChecker::CheckParamTypes(entity::DefinedFunction *defun) {
  for (auto param : defun->GetParameters()) {
    if (IsInvalidParameterType(param->GetType())) {
      handler_->Error(param->GetLocation(), "invalid parameter type: " + param->GetType()->ToString());
    }
  }
}

// statements
void TypeChecker::Visit(ast::BlockNode *node) {
  for (auto var : node->variables()) {
    CheckVariable(var);
  }

  for (auto stmt : node->stmts()) {
    Check(stmt);
  }
}

void TypeChecker::CheckVariable(entity::DefinedVariable *defvar) {
  if (IsInvalidVariableType(defvar->GetType())) {
    handler_->Error(defvar->GetLocation(), "invalid variable type: " + defvar->GetType()->ToString());
    return;
  }

  if (defvar->HasInitializer()) {
    if (IsInvalidLHSType(defvar->GetType())) {
      handler_->Error(defvar->GetLocation(), "invalid LHS type: " + defvar->GetType()->ToString());
      return;
    }

    Check(defvar->initializer());

    // 如果左值的类型与初始化的值类型不同，需要进行一次隐式类型转换
    defvar->SetInitializer(ImplicitCast(defvar->GetType(), defvar->initializer()));
  }
}

void TypeChecker::Visit(ast::ExprStmtNode *node) {
  Check(node->expr());
  if (IsInvalidStatementType(node->expr()->type())) {
    handler_->Error(node->location(), "invalid statement type: " + node->expr()->type()->ToString());
  }
}

void TypeChecker::Visit(ast::IfNode *node) {
  Visitor::Visit(node);
  CheckCond(node->cond());
}

void TypeChecker::Visit(ast::WhileNode *node) {
  Visitor::Visit(node);
  CheckCond(node->cond());
}

void TypeChecker::Visit(ast::ForNode *node) {
  Visitor::Visit(node);
  CheckCond(node->cond());
}

void TypeChecker::CheckCond(ast::ExprNode *cond) {
  MustBeScalar(cond, "condition expression");
}

void TypeChecker::Visit(ast::SwitchNode *node) {
  Visitor::Visit(node);
  MustBeInteger(node->cond(), "switch condition expression");
}

void TypeChecker::Visit(ast::ReturnNode *node) {
  Visitor::Visit(node);

  if (cur_function_->IsVoid()) {
    if (node->expr() != nullptr) {
      handler_->Error(node->location(), "returning value from void function");
    }
  } else {
    // non void function
    if (node->expr() == nullptr) {
      handler_->Error(node->location(), "missing return value");
      return;
    }

    if (node->expr()->type()->IsVoid()) {
      handler_->Error(node->location(), "returning void");
      return;
    }

    node->SetExpr(ImplicitCast(cur_function_->ReturnType(), node->expr()));
  }
}

// assignment expressions
void TypeChecker::Visit(ast::AssignNode *node) {
  Visitor::Visit(node);
  if (!CheckLHS(node->lhs())) {
    return;
  }

  if (!CheckRHS(node->rhs())) {
    return;
  }

  node->SetRHS(ImplicitCast(node->lhs()->type(), node->rhs()));
}

} /* compiler */
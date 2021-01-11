#include "expression_checker.h"

namespace compiler {
ExpressionChecker::ExpressionChecker(type::TypeTable *tb, utils::ErrorHandler *err_handler) 
                                    : table_(tb), handler_(err_handler) {}
ExpressionChecker::~ExpressionChecker() {}

void ExpressionChecker::CheckAst(ast::ASTNode *ast) {
  for (auto defvar : ast->DefinedVariables()) {
    CheckTopLevelVariable(defvar);
  }

  for (auto defun : ast->DefinedFunctions()) {
    Check(defun->body());
  }

  if (handler_->ErrorOccured()) {
    handler_->Error("Compiler failed when ExpressionChecker");
  }
}

void ExpressionChecker::CheckTopLevelVariable(entity::DefinedVariable *defvar) {
  CheckVariable(defvar);
  if (defvar->HasInitializer()) {
    CheckConstant(defvar->initializer());
  }
}

void ExpressionChecker::CheckConstant(ast::ExprNode *node) {
  if (!node->IsConstant()) {
    handler_->Error(node->location(), "not a constant");
  }
}

void ExpressionChecker::CheckVariable(entity::DefinedVariable *defvar) {
  if (defvar->HasInitializer()) {
    Check(defvar->initializer());
  }
}

/************************************************************************************
* @fn CheckAssignment
* @brief 检查赋值表达式左边的表达式是否能被赋值，数组和函数是不能被赋值的
* @param
* @author Jona
* @date 2021/01/08
************************************************************************************/
void ExpressionChecker::CheckAssignment(ast::AbstractAssignNode *node) {
  if (! node->lhs()->IsAssignable()) {
    handler_->Error(node->location(), "invalid lhs expression");
  }
}

/************************************************************************************
* @fn CheckMemberRef
* @brief 检查 struct 和 union 成员表达式
* @param
* @author Jona
* @date 2021/01/08
************************************************************************************/
void ExpressionChecker::CheckMemberRef(ast::Location *loc, type::Type *t, std::string mem) {
  if (!t->IsCompositeType()) {
    handler_->Error(loc, "accessing member `" + mem + "` for non-struct/union: " + t->ToString());
    return;
  }

  type::CompositeType *ct = t->GetCompositeType();
  if (!ct->HasMember(mem)) {
    handler_->Error(loc, t->ToString() + " has no member named " + mem);
    return;
  }
}

void ExpressionChecker::Check(ast::StmtNode *node) {
  node->Accept(this);
}

void ExpressionChecker::Check(ast::ExprNode *node) {
  node->Accept(this);
}

void ExpressionChecker::Visit(ast::BlockNode *node) {
  for (auto var : node->variables()) {
    CheckVariable(var);
  }

  for (auto stmt : node->stmts()) {
    Check(stmt);
  }
}

void ExpressionChecker::Visit(ast::AssignNode *node) {
  Visitor::Visit(node);
  CheckAssignment(node);
}

/************************************************************************************
* @fn Visit
* @brief 复合操作符, 比如 a+=b
* @param
* @author Jona
* @date 2021/01/08
************************************************************************************/
void ExpressionChecker::Visit(ast::OpAssignNode *node) {
  Visitor::Visit(node);
  CheckAssignment(node);
}

/************************************************************************************
* @fn Visit
* @brief 自增或者自减操作符，如果表达式不可赋值，出错
* @param
* @author Jona
* @date 2021/01/08
************************************************************************************/
void ExpressionChecker::Visit(ast::PrefixOpNode *node) {
  Visitor::Visit(node);
  if (! node->expr()->IsAssignable()) {
    handler_->Error(node->location(), "can not prefix decrement/increment");
  }
}

void ExpressionChecker::Visit(ast::SuffixOpNode *node) {
  Visitor::Visit(node);
  if (! node->expr()->IsAssignable()) {
    handler_->Error(node->location(), "can not duffix decrement/increment");
  }
}

void ExpressionChecker::Visit(ast::FuncallNode *node) {
  Visitor::Visit(node);
  if (! node->expr()->IsCallable()) {
    // not function
    handler_->Error(node->location(), "calling obj is not a function");
  }
}

void ExpressionChecker::Visit(ast::ARefNode *node) {
  Visitor::Visit(node);
  if (! node->expr()->IsPointer()) {
    handler_->Error(node->location(), "indexing non-array/pointer expression");
    return;
  }

  HandleImplicitAddress(node);
}

void ExpressionChecker::Visit(ast::MemberNode *node) {
  Visitor::Visit(node);
  CheckMemberRef(node->location(), node->expr()->type(), node->member());
  HandleImplicitAddress(node);
}

void ExpressionChecker::Visit(ast::PtrMemberNode *node) {
  Visitor::Visit(node);
  if (!node->expr()->IsPointer()) {
    UndereferableError(node->location());
    return;
  }

  CheckMemberRef(node->location(), node->DereferedType(), node->member());
  HandleImplicitAddress(node);
}

void ExpressionChecker::Visit(ast::DereferenceNode *node) {
  Visitor::Visit(node);
  if (!node->expr()->IsPointer()) {
    UndereferableError(node->location());
    return;
  }
  HandleImplicitAddress(node);
}

/************************************************************************************
* @fn Visit
* @brief 判断 node 是不是左值，只有 LHSNode 及其子类， IsLValue 返回 true
* @param
* @author Jona
* @date 2021/01/08
************************************************************************************/
void ExpressionChecker::Visit(ast::AddressNode *node) {
  Visitor::Visit(node);
  if (!node->expr()->IsLValue()) {
    handler_->Error(node->location(), "invalid expression for &");
    return;
  }

  type::Type *base = node->expr()->type();
  if (!node->expr()->IsLoadable()) {
    // 只有数组或者函数，IsLoadable 返回 false，也就是此时就指针
    node->SetType(base);
  } else {
    // not array or function, convert to pointer type
    node->SetType(table_->PointerTo(base));
  }
}

void ExpressionChecker::Visit(ast::VariableNode *node) {
  Visitor::Visit(node);
  if (node->entity()->IsConstant()) {
    CheckConstant(node->entity()->value());
  }

  HandleImplicitAddress(node);
}

void ExpressionChecker::Visit(ast::CastNode *node) {
  Visitor::Visit(node);
  if (node->type()->IsArray()) {
    // can not cast to array type
    handler_->Error(node->location(), "cast specifies array type");
  }
}

void ExpressionChecker::UndereferableError(ast::Location *loc) {
  handler_->Error(loc, "derefencing non-pointer expression");
}

void ExpressionChecker::HandleImplicitAddress(ast::LHSNode *node) {
  if (!node->IsLoadable()) {
    // array/function
    type::Type *t = node->type();
    if (t->IsArray()) {
      node->SetType(table_->PointerTo(t->base_type()));
    } else {
      // function
      node->SetType(table_->PointerTo(t));
    }
  }
}

} /* compiler */
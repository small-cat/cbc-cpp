/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: type_checker.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/11
 * @brief: 静态类型检查，包括类型检查和隐式类型转换
*/
#ifndef __TYPE_CHECKER_H__
#define __TYPE_CHECKER_H__

#include "visitor.h"
#include "../type/type_table.h"
#include "../utils/error_handler.h"
#include "../entity/defined_function.h"

namespace compiler {
class TypeChecker : public Visitor {
public:
  TypeChecker(type::TypeTable *tb, utils::ErrorHandler *err);
  virtual TypeChecker();

  void Check(ast::StmtNode *node);
  void Check(ast::ExprNode *node);
  void Check(ast::ASTNode *ast);

  void Visit(ast::BlockNode *node);
  void Visit(ast::ExprStmtNode *node);
  void Visit(ast::IfNode *node);
  void Visit(ast::WhileNode *node);
  void Visit(ast::ForNode *node);
  void Visit(ast::ExprNode *node);
  void Visit(ast::SwitchNode *node);
  void Visit(ast::ReturnNode *node);
  void Visit(ast::AssignNode *node);
  void Visit(ast::OpAssignNode *node);
  void Visit(ast::CondExprNode *node);
  void Visit(ast::BinaryOpNode *node);
  void Visit(ast::LogicalAndNode *node);
  void Visit(ast::LogicalOrNode *node);
  void Visit(ast::UnaryOpNode *node);
  void Visit(ast::PrefixOpNode *node);
  void Visit(ast::SuffixOpNode *node);
  void Visit(ast::FuncallNode *node);
  void Visit(ast::ARefNode *node);
  void Visit(ast::CastNode *node);

private:
  void CheckReturnType(entity::DefinedFunction *defun);
  void CheckParamTypes(entity::DefinedFunction *defun);
  void CheckVariable(entity::DefinedVariable *defvar);
  void CheckRHS(ast::ExprNode *rhs);
  void CheckCond(ast::ExprNode *cond);

  bool IsSafeIntegerCast(ast::Node *node, type::Type *t);
  bool CheckLHS(ast::ExprNode *lhs); 
  bool IsInvalidStatementType(type::Type *t);
  bool IsInvalidReturnType(type::Type *t);
  bool IsInvalidParameterType(type::Type *t);
  bool IsInvalidVariableType(type::Type *t);
  bool IsInvalidLHSType(type::Type *t);
  bool IsInvalidRHSType(type::Type *t);
  bool MustBeInteger(ast::ExprNode *expr, std::string op);
  bool MustBeScalar(ast::ExprNode *expr, std::string op);

  void ExpectsSameIntegerOrPointerDiff(ast::BinaryOpNode *node);
  void ExpectsSameInteger(ast::BinaryOpNode *node);
  void ExpectsComparableScalars(ast::BinaryOpNode *node);
  void ExpectsScalarLHS(ast::UnaryArithmeticOpNode *node);
  ast::ExprNode* IntegerPromotedExpr(ast::ExprNode *expr);
  ast::ExprNode* ForcePointerType(ast::ExprNode *master, ast::ExprNode *slave);
  void ArithmeticImplicitCast(ast::BinaryOpNode *node);
  ast::ExprNode* CastOptionalArg(ast::ExprNode *node);
  ast::ExprNode* ImplicitCast(type::Type *target, ast::ExprNode *node);

  type::Type* IntegerPromotion(type::Type *t);
  type::Type* UsualArimeticConversion(type::Type *l, type::Type *r);

private:
  type::TypeTable *table_;
  utils::ErrorHandler *handler_;

  entity::DefinedFunction *cur_function_;
};
} /* compiler */

#endif
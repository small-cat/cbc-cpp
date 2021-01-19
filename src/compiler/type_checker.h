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

#include <map>

#include "visitor.h"
#include "ast/ast.hpp"
#include "type/type_table.h"
#include "utils/error_handler.h"
#include "utils/node_tracker.hpp"
#include "entity/defined_function.h"

namespace compiler {
class TypeChecker : public Visitor {
public:
  TypeChecker(type::TypeTable *tb, utils::ErrorHandler *err);
  virtual ~TypeChecker();

  void Check(ast::StmtNode *node);
  void Check(ast::ExprNode *node);
  void Check(ast::ASTNode *ast);

  void Visit(ast::BlockNode *node);
  void Visit(ast::ExprStmtNode *node);
  void Visit(ast::IfNode *node);
  void Visit(ast::WhileNode *node);
  void Visit(ast::ForNode *node);
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

  static std::map<std::string, int> BinaryOpMaps;
private:
  void CheckReturnType(entity::DefinedFunction *defun);
  void CheckParamTypes(entity::DefinedFunction *defun);
  void CheckVariable(entity::DefinedVariable *defvar);
  void CheckCond(ast::ExprNode *cond);

  bool IsSafeIntegerCast(ast::Node *node, type::Type *t);
  bool CheckLHS(ast::ExprNode *lhs); 
  bool CheckRHS(ast::ExprNode *rhs);
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
  ast::ExprNode* CastOptionalArg(ast::ExprNode *arg);
  ast::ExprNode* ImplicitCast(type::Type *target, ast::ExprNode *expr);

  type::Type* IntegerPromotion(type::Type *t);
  type::Type* UsualArithmeticConversion(type::Type *l, type::Type *r);

  int FindBinaryOp(const std::string &op, std::map<std::string, int> op_map);
  ast::CastNode* GetCastNode(type::Type *t, ast::ExprNode *expr);

private:
  type::TypeTable *table_;
  utils::ErrorHandler *handler_;

  entity::DefinedFunction *cur_function_;

  utils::NodeTracker<ast::Node> ast_node_tracker_;
};
} /* compiler */

#endif
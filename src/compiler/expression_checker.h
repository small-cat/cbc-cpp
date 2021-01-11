/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: expression_checker.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/08
 * @brief: check the validation of expressions
*/
#ifndef __EXPRESSION_CHECKER_H__
#define __EXPRESSION_CHECKER_H__

#include "visitor.h"
#include "../type/type_table.h"
#include "../ast/ast.hpp"

namespace compiler {
class ExpressionChecker : public Visitor {
public:
  ExpressionChecker(type::TypeTable* tb, utils::ErrorHandler *err_handler);
  virtual ~ExpressionChecker();

  void CheckAst(ast::ASTNode *ast);
  void CheckTopLevelVariable(entity::DefinedVariable *defvar);
  void CheckVariable(entity::DefinedVariable *defvar);
  void CheckConstant(ast::ExprNode *expr);
  void CheckAssignment(ast::AbstractAssignNode *node);
  void CheckMemberRef(ast::Location *loc, type::Type *t, std::string mem);

  void Check(ast::StmtNode *node);
  void Check(ast::ExprNode *node);

  void Visit(ast::BlockNode *node);
  void Visit(ast::AssignNode *node);
  void Visit(ast::OpAssignNode *node);
  void Visit(ast::PrefixOpNode *node);
  void Visit(ast::SuffixOpNode *node);
  void Visit(ast::FuncallNode *node);
  void Visit(ast::ARefNode *node);
  void Visit(ast::MemberNode *node);
  void Visit(ast::PtrMemberNode *node);
  void Visit(ast::DereferenceNode *node);
  void Visit(ast::AddressNode *node);
  void Visit(ast::VariableNode *node);
  void Visit(ast::CastNode *node);

  void HandleImplicitAddress(ast::LHSNode *node);
private:
  void UndereferableError(ast::Location *loc);

  type::TypeTable *table_;
  utils::ErrorHandler *handler_;
};
} /* compiler */

#endif
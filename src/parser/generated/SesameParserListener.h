
// Generated from SesameParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SesameParser.h"


namespace parser {

/**
 * This interface defines an abstract listener for a parse tree produced by SesameParser.
 */
class  SesameParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompilation_unit(SesameParser::Compilation_unitContext *ctx) = 0;
  virtual void exitCompilation_unit(SesameParser::Compilation_unitContext *ctx) = 0;

  virtual void enterDeclaration_file(SesameParser::Declaration_fileContext *ctx) = 0;
  virtual void exitDeclaration_file(SesameParser::Declaration_fileContext *ctx) = 0;

  virtual void enterImport_stmt(SesameParser::Import_stmtContext *ctx) = 0;
  virtual void exitImport_stmt(SesameParser::Import_stmtContext *ctx) = 0;

  virtual void enterName(SesameParser::NameContext *ctx) = 0;
  virtual void exitName(SesameParser::NameContext *ctx) = 0;

  virtual void enterTop_def(SesameParser::Top_defContext *ctx) = 0;
  virtual void exitTop_def(SesameParser::Top_defContext *ctx) = 0;

  virtual void enterDef_func(SesameParser::Def_funcContext *ctx) = 0;
  virtual void exitDef_func(SesameParser::Def_funcContext *ctx) = 0;

  virtual void enterStorage(SesameParser::StorageContext *ctx) = 0;
  virtual void exitStorage(SesameParser::StorageContext *ctx) = 0;

  virtual void enterParams(SesameParser::ParamsContext *ctx) = 0;
  virtual void exitParams(SesameParser::ParamsContext *ctx) = 0;

  virtual void enterFixed_params(SesameParser::Fixed_paramsContext *ctx) = 0;
  virtual void exitFixed_params(SesameParser::Fixed_paramsContext *ctx) = 0;

  virtual void enterParam(SesameParser::ParamContext *ctx) = 0;
  virtual void exitParam(SesameParser::ParamContext *ctx) = 0;

  virtual void enterBlock(SesameParser::BlockContext *ctx) = 0;
  virtual void exitBlock(SesameParser::BlockContext *ctx) = 0;

  virtual void enterDef_vars(SesameParser::Def_varsContext *ctx) = 0;
  virtual void exitDef_vars(SesameParser::Def_varsContext *ctx) = 0;

  virtual void enterAssign_expr(SesameParser::Assign_exprContext *ctx) = 0;
  virtual void exitAssign_expr(SesameParser::Assign_exprContext *ctx) = 0;

  virtual void enterDef_const(SesameParser::Def_constContext *ctx) = 0;
  virtual void exitDef_const(SesameParser::Def_constContext *ctx) = 0;

  virtual void enterDef_struct(SesameParser::Def_structContext *ctx) = 0;
  virtual void exitDef_struct(SesameParser::Def_structContext *ctx) = 0;

  virtual void enterDef_union(SesameParser::Def_unionContext *ctx) = 0;
  virtual void exitDef_union(SesameParser::Def_unionContext *ctx) = 0;

  virtual void enterMember_list(SesameParser::Member_listContext *ctx) = 0;
  virtual void exitMember_list(SesameParser::Member_listContext *ctx) = 0;

  virtual void enterSlot(SesameParser::SlotContext *ctx) = 0;
  virtual void exitSlot(SesameParser::SlotContext *ctx) = 0;

  virtual void enterS_typedef(SesameParser::S_typedefContext *ctx) = 0;
  virtual void exitS_typedef(SesameParser::S_typedefContext *ctx) = 0;

  virtual void enterType(SesameParser::TypeContext *ctx) = 0;
  virtual void exitType(SesameParser::TypeContext *ctx) = 0;

  virtual void enterTyperef(SesameParser::TyperefContext *ctx) = 0;
  virtual void exitTyperef(SesameParser::TyperefContext *ctx) = 0;

  virtual void enterTyperef_base(SesameParser::Typeref_baseContext *ctx) = 0;
  virtual void exitTyperef_base(SesameParser::Typeref_baseContext *ctx) = 0;

  virtual void enterParam_typerefs(SesameParser::Param_typerefsContext *ctx) = 0;
  virtual void exitParam_typerefs(SesameParser::Param_typerefsContext *ctx) = 0;

  virtual void enterFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext *ctx) = 0;
  virtual void exitFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext *ctx) = 0;

  virtual void enterStmts(SesameParser::StmtsContext *ctx) = 0;
  virtual void exitStmts(SesameParser::StmtsContext *ctx) = 0;

  virtual void enterStmt(SesameParser::StmtContext *ctx) = 0;
  virtual void exitStmt(SesameParser::StmtContext *ctx) = 0;

  virtual void enterLabeled_stmt(SesameParser::Labeled_stmtContext *ctx) = 0;
  virtual void exitLabeled_stmt(SesameParser::Labeled_stmtContext *ctx) = 0;

  virtual void enterIf_stmt(SesameParser::If_stmtContext *ctx) = 0;
  virtual void exitIf_stmt(SesameParser::If_stmtContext *ctx) = 0;

  virtual void enterWhile_stmt(SesameParser::While_stmtContext *ctx) = 0;
  virtual void exitWhile_stmt(SesameParser::While_stmtContext *ctx) = 0;

  virtual void enterDo_while_stmt(SesameParser::Do_while_stmtContext *ctx) = 0;
  virtual void exitDo_while_stmt(SesameParser::Do_while_stmtContext *ctx) = 0;

  virtual void enterFor_stmt(SesameParser::For_stmtContext *ctx) = 0;
  virtual void exitFor_stmt(SesameParser::For_stmtContext *ctx) = 0;

  virtual void enterSwitch_stmt(SesameParser::Switch_stmtContext *ctx) = 0;
  virtual void exitSwitch_stmt(SesameParser::Switch_stmtContext *ctx) = 0;

  virtual void enterCase_clauses(SesameParser::Case_clausesContext *ctx) = 0;
  virtual void exitCase_clauses(SesameParser::Case_clausesContext *ctx) = 0;

  virtual void enterCase_clause(SesameParser::Case_clauseContext *ctx) = 0;
  virtual void exitCase_clause(SesameParser::Case_clauseContext *ctx) = 0;

  virtual void enterCases(SesameParser::CasesContext *ctx) = 0;
  virtual void exitCases(SesameParser::CasesContext *ctx) = 0;

  virtual void enterDefault_clause(SesameParser::Default_clauseContext *ctx) = 0;
  virtual void exitDefault_clause(SesameParser::Default_clauseContext *ctx) = 0;

  virtual void enterCase_body(SesameParser::Case_bodyContext *ctx) = 0;
  virtual void exitCase_body(SesameParser::Case_bodyContext *ctx) = 0;

  virtual void enterBreak_stmt(SesameParser::Break_stmtContext *ctx) = 0;
  virtual void exitBreak_stmt(SesameParser::Break_stmtContext *ctx) = 0;

  virtual void enterContinue_stmt(SesameParser::Continue_stmtContext *ctx) = 0;
  virtual void exitContinue_stmt(SesameParser::Continue_stmtContext *ctx) = 0;

  virtual void enterGoto_stmt(SesameParser::Goto_stmtContext *ctx) = 0;
  virtual void exitGoto_stmt(SesameParser::Goto_stmtContext *ctx) = 0;

  virtual void enterReturn_stmt(SesameParser::Return_stmtContext *ctx) = 0;
  virtual void exitReturn_stmt(SesameParser::Return_stmtContext *ctx) = 0;

  virtual void enterExpr(SesameParser::ExprContext *ctx) = 0;
  virtual void exitExpr(SesameParser::ExprContext *ctx) = 0;

  virtual void enterOpassign_op(SesameParser::Opassign_opContext *ctx) = 0;
  virtual void exitOpassign_op(SesameParser::Opassign_opContext *ctx) = 0;

  virtual void enterExpr10(SesameParser::Expr10Context *ctx) = 0;
  virtual void exitExpr10(SesameParser::Expr10Context *ctx) = 0;

  virtual void enterExpr8(SesameParser::Expr8Context *ctx) = 0;
  virtual void exitExpr8(SesameParser::Expr8Context *ctx) = 0;

  virtual void enterExpr7(SesameParser::Expr7Context *ctx) = 0;
  virtual void exitExpr7(SesameParser::Expr7Context *ctx) = 0;

  virtual void enterLogical_op(SesameParser::Logical_opContext *ctx) = 0;
  virtual void exitLogical_op(SesameParser::Logical_opContext *ctx) = 0;

  virtual void enterExpr6(SesameParser::Expr6Context *ctx) = 0;
  virtual void exitExpr6(SesameParser::Expr6Context *ctx) = 0;

  virtual void enterExpr5(SesameParser::Expr5Context *ctx) = 0;
  virtual void exitExpr5(SesameParser::Expr5Context *ctx) = 0;

  virtual void enterExpr4(SesameParser::Expr4Context *ctx) = 0;
  virtual void exitExpr4(SesameParser::Expr4Context *ctx) = 0;

  virtual void enterExpr3(SesameParser::Expr3Context *ctx) = 0;
  virtual void exitExpr3(SesameParser::Expr3Context *ctx) = 0;

  virtual void enterExpr2(SesameParser::Expr2Context *ctx) = 0;
  virtual void exitExpr2(SesameParser::Expr2Context *ctx) = 0;

  virtual void enterExpr1(SesameParser::Expr1Context *ctx) = 0;
  virtual void exitExpr1(SesameParser::Expr1Context *ctx) = 0;

  virtual void enterTerm(SesameParser::TermContext *ctx) = 0;
  virtual void exitTerm(SesameParser::TermContext *ctx) = 0;

  virtual void enterUnary(SesameParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(SesameParser::UnaryContext *ctx) = 0;

  virtual void enterPostfix(SesameParser::PostfixContext *ctx) = 0;
  virtual void exitPostfix(SesameParser::PostfixContext *ctx) = 0;

  virtual void enterArgs(SesameParser::ArgsContext *ctx) = 0;
  virtual void exitArgs(SesameParser::ArgsContext *ctx) = 0;

  virtual void enterPrimary(SesameParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(SesameParser::PrimaryContext *ctx) = 0;


};

}  // namespace parser

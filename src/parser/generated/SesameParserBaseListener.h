
// Generated from SesameParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SesameParserListener.h"


namespace parser {

/**
 * This class provides an empty implementation of SesameParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SesameParserBaseListener : public SesameParserListener {
public:

  virtual void enterCompilation_unit(SesameParser::Compilation_unitContext * /*ctx*/) override { }
  virtual void exitCompilation_unit(SesameParser::Compilation_unitContext * /*ctx*/) override { }

  virtual void enterDeclaration_file(SesameParser::Declaration_fileContext * /*ctx*/) override { }
  virtual void exitDeclaration_file(SesameParser::Declaration_fileContext * /*ctx*/) override { }

  virtual void enterImport_stmt(SesameParser::Import_stmtContext * /*ctx*/) override { }
  virtual void exitImport_stmt(SesameParser::Import_stmtContext * /*ctx*/) override { }

  virtual void enterName(SesameParser::NameContext * /*ctx*/) override { }
  virtual void exitName(SesameParser::NameContext * /*ctx*/) override { }

  virtual void enterTop_def(SesameParser::Top_defContext * /*ctx*/) override { }
  virtual void exitTop_def(SesameParser::Top_defContext * /*ctx*/) override { }

  virtual void enterDef_func(SesameParser::Def_funcContext * /*ctx*/) override { }
  virtual void exitDef_func(SesameParser::Def_funcContext * /*ctx*/) override { }

  virtual void enterStorage(SesameParser::StorageContext * /*ctx*/) override { }
  virtual void exitStorage(SesameParser::StorageContext * /*ctx*/) override { }

  virtual void enterParams(SesameParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(SesameParser::ParamsContext * /*ctx*/) override { }

  virtual void enterFixed_params(SesameParser::Fixed_paramsContext * /*ctx*/) override { }
  virtual void exitFixed_params(SesameParser::Fixed_paramsContext * /*ctx*/) override { }

  virtual void enterParam(SesameParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(SesameParser::ParamContext * /*ctx*/) override { }

  virtual void enterBlock(SesameParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(SesameParser::BlockContext * /*ctx*/) override { }

  virtual void enterDef_vars(SesameParser::Def_varsContext * /*ctx*/) override { }
  virtual void exitDef_vars(SesameParser::Def_varsContext * /*ctx*/) override { }

  virtual void enterAssign_expr(SesameParser::Assign_exprContext * /*ctx*/) override { }
  virtual void exitAssign_expr(SesameParser::Assign_exprContext * /*ctx*/) override { }

  virtual void enterDef_const(SesameParser::Def_constContext * /*ctx*/) override { }
  virtual void exitDef_const(SesameParser::Def_constContext * /*ctx*/) override { }

  virtual void enterDef_struct(SesameParser::Def_structContext * /*ctx*/) override { }
  virtual void exitDef_struct(SesameParser::Def_structContext * /*ctx*/) override { }

  virtual void enterDef_union(SesameParser::Def_unionContext * /*ctx*/) override { }
  virtual void exitDef_union(SesameParser::Def_unionContext * /*ctx*/) override { }

  virtual void enterMember_list(SesameParser::Member_listContext * /*ctx*/) override { }
  virtual void exitMember_list(SesameParser::Member_listContext * /*ctx*/) override { }

  virtual void enterSlot(SesameParser::SlotContext * /*ctx*/) override { }
  virtual void exitSlot(SesameParser::SlotContext * /*ctx*/) override { }

  virtual void enterS_typedef(SesameParser::S_typedefContext * /*ctx*/) override { }
  virtual void exitS_typedef(SesameParser::S_typedefContext * /*ctx*/) override { }

  virtual void enterType(SesameParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(SesameParser::TypeContext * /*ctx*/) override { }

  virtual void enterTyperef(SesameParser::TyperefContext * /*ctx*/) override { }
  virtual void exitTyperef(SesameParser::TyperefContext * /*ctx*/) override { }

  virtual void enterTyperef_base(SesameParser::Typeref_baseContext * /*ctx*/) override { }
  virtual void exitTyperef_base(SesameParser::Typeref_baseContext * /*ctx*/) override { }

  virtual void enterParam_typerefs(SesameParser::Param_typerefsContext * /*ctx*/) override { }
  virtual void exitParam_typerefs(SesameParser::Param_typerefsContext * /*ctx*/) override { }

  virtual void enterFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext * /*ctx*/) override { }
  virtual void exitFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext * /*ctx*/) override { }

  virtual void enterStmts(SesameParser::StmtsContext * /*ctx*/) override { }
  virtual void exitStmts(SesameParser::StmtsContext * /*ctx*/) override { }

  virtual void enterStmt(SesameParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(SesameParser::StmtContext * /*ctx*/) override { }

  virtual void enterLabeled_stmt(SesameParser::Labeled_stmtContext * /*ctx*/) override { }
  virtual void exitLabeled_stmt(SesameParser::Labeled_stmtContext * /*ctx*/) override { }

  virtual void enterIf_stmt(SesameParser::If_stmtContext * /*ctx*/) override { }
  virtual void exitIf_stmt(SesameParser::If_stmtContext * /*ctx*/) override { }

  virtual void enterWhile_stmt(SesameParser::While_stmtContext * /*ctx*/) override { }
  virtual void exitWhile_stmt(SesameParser::While_stmtContext * /*ctx*/) override { }

  virtual void enterDo_while_stmt(SesameParser::Do_while_stmtContext * /*ctx*/) override { }
  virtual void exitDo_while_stmt(SesameParser::Do_while_stmtContext * /*ctx*/) override { }

  virtual void enterFor_stmt(SesameParser::For_stmtContext * /*ctx*/) override { }
  virtual void exitFor_stmt(SesameParser::For_stmtContext * /*ctx*/) override { }

  virtual void enterSwitch_stmt(SesameParser::Switch_stmtContext * /*ctx*/) override { }
  virtual void exitSwitch_stmt(SesameParser::Switch_stmtContext * /*ctx*/) override { }

  virtual void enterCase_clauses(SesameParser::Case_clausesContext * /*ctx*/) override { }
  virtual void exitCase_clauses(SesameParser::Case_clausesContext * /*ctx*/) override { }

  virtual void enterCase_clause(SesameParser::Case_clauseContext * /*ctx*/) override { }
  virtual void exitCase_clause(SesameParser::Case_clauseContext * /*ctx*/) override { }

  virtual void enterCases(SesameParser::CasesContext * /*ctx*/) override { }
  virtual void exitCases(SesameParser::CasesContext * /*ctx*/) override { }

  virtual void enterDefault_clause(SesameParser::Default_clauseContext * /*ctx*/) override { }
  virtual void exitDefault_clause(SesameParser::Default_clauseContext * /*ctx*/) override { }

  virtual void enterCase_body(SesameParser::Case_bodyContext * /*ctx*/) override { }
  virtual void exitCase_body(SesameParser::Case_bodyContext * /*ctx*/) override { }

  virtual void enterBreak_stmt(SesameParser::Break_stmtContext * /*ctx*/) override { }
  virtual void exitBreak_stmt(SesameParser::Break_stmtContext * /*ctx*/) override { }

  virtual void enterContinue_stmt(SesameParser::Continue_stmtContext * /*ctx*/) override { }
  virtual void exitContinue_stmt(SesameParser::Continue_stmtContext * /*ctx*/) override { }

  virtual void enterGoto_stmt(SesameParser::Goto_stmtContext * /*ctx*/) override { }
  virtual void exitGoto_stmt(SesameParser::Goto_stmtContext * /*ctx*/) override { }

  virtual void enterReturn_stmt(SesameParser::Return_stmtContext * /*ctx*/) override { }
  virtual void exitReturn_stmt(SesameParser::Return_stmtContext * /*ctx*/) override { }

  virtual void enterExpr(SesameParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(SesameParser::ExprContext * /*ctx*/) override { }

  virtual void enterOpassign_op(SesameParser::Opassign_opContext * /*ctx*/) override { }
  virtual void exitOpassign_op(SesameParser::Opassign_opContext * /*ctx*/) override { }

  virtual void enterExpr10(SesameParser::Expr10Context * /*ctx*/) override { }
  virtual void exitExpr10(SesameParser::Expr10Context * /*ctx*/) override { }

  virtual void enterExpr8(SesameParser::Expr8Context * /*ctx*/) override { }
  virtual void exitExpr8(SesameParser::Expr8Context * /*ctx*/) override { }

  virtual void enterExpr7(SesameParser::Expr7Context * /*ctx*/) override { }
  virtual void exitExpr7(SesameParser::Expr7Context * /*ctx*/) override { }

  virtual void enterLogical_op(SesameParser::Logical_opContext * /*ctx*/) override { }
  virtual void exitLogical_op(SesameParser::Logical_opContext * /*ctx*/) override { }

  virtual void enterExpr6(SesameParser::Expr6Context * /*ctx*/) override { }
  virtual void exitExpr6(SesameParser::Expr6Context * /*ctx*/) override { }

  virtual void enterExpr5(SesameParser::Expr5Context * /*ctx*/) override { }
  virtual void exitExpr5(SesameParser::Expr5Context * /*ctx*/) override { }

  virtual void enterExpr4(SesameParser::Expr4Context * /*ctx*/) override { }
  virtual void exitExpr4(SesameParser::Expr4Context * /*ctx*/) override { }

  virtual void enterExpr3(SesameParser::Expr3Context * /*ctx*/) override { }
  virtual void exitExpr3(SesameParser::Expr3Context * /*ctx*/) override { }

  virtual void enterExpr2(SesameParser::Expr2Context * /*ctx*/) override { }
  virtual void exitExpr2(SesameParser::Expr2Context * /*ctx*/) override { }

  virtual void enterExpr1(SesameParser::Expr1Context * /*ctx*/) override { }
  virtual void exitExpr1(SesameParser::Expr1Context * /*ctx*/) override { }

  virtual void enterTerm(SesameParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(SesameParser::TermContext * /*ctx*/) override { }

  virtual void enterUnary(SesameParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(SesameParser::UnaryContext * /*ctx*/) override { }

  virtual void enterPostfix(SesameParser::PostfixContext * /*ctx*/) override { }
  virtual void exitPostfix(SesameParser::PostfixContext * /*ctx*/) override { }

  virtual void enterArgs(SesameParser::ArgsContext * /*ctx*/) override { }
  virtual void exitArgs(SesameParser::ArgsContext * /*ctx*/) override { }

  virtual void enterPrimary(SesameParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(SesameParser::PrimaryContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace parser

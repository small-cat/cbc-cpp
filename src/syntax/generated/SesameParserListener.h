
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

  virtual void enterDeclaration_stmt(SesameParser::Declaration_stmtContext *ctx) = 0;
  virtual void exitDeclaration_stmt(SesameParser::Declaration_stmtContext *ctx) = 0;

  virtual void enterImport_stmt(SesameParser::Import_stmtContext *ctx) = 0;
  virtual void exitImport_stmt(SesameParser::Import_stmtContext *ctx) = 0;

  virtual void enterImport_name(SesameParser::Import_nameContext *ctx) = 0;
  virtual void exitImport_name(SesameParser::Import_nameContext *ctx) = 0;

  virtual void enterName(SesameParser::NameContext *ctx) = 0;
  virtual void exitName(SesameParser::NameContext *ctx) = 0;

  virtual void enterFunc_decl(SesameParser::Func_declContext *ctx) = 0;
  virtual void exitFunc_decl(SesameParser::Func_declContext *ctx) = 0;

  virtual void enterVar_decl(SesameParser::Var_declContext *ctx) = 0;
  virtual void exitVar_decl(SesameParser::Var_declContext *ctx) = 0;

  virtual void enterTop_defs(SesameParser::Top_defsContext *ctx) = 0;
  virtual void exitTop_defs(SesameParser::Top_defsContext *ctx) = 0;

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

  virtual void enterTyperef_void(SesameParser::Typeref_voidContext *ctx) = 0;
  virtual void exitTyperef_void(SesameParser::Typeref_voidContext *ctx) = 0;

  virtual void enterTyperef_char(SesameParser::Typeref_charContext *ctx) = 0;
  virtual void exitTyperef_char(SesameParser::Typeref_charContext *ctx) = 0;

  virtual void enterTyperef_short(SesameParser::Typeref_shortContext *ctx) = 0;
  virtual void exitTyperef_short(SesameParser::Typeref_shortContext *ctx) = 0;

  virtual void enterTyperef_int(SesameParser::Typeref_intContext *ctx) = 0;
  virtual void exitTyperef_int(SesameParser::Typeref_intContext *ctx) = 0;

  virtual void enterTyperef_long(SesameParser::Typeref_longContext *ctx) = 0;
  virtual void exitTyperef_long(SesameParser::Typeref_longContext *ctx) = 0;

  virtual void enterTyperef_unsigned(SesameParser::Typeref_unsignedContext *ctx) = 0;
  virtual void exitTyperef_unsigned(SesameParser::Typeref_unsignedContext *ctx) = 0;

  virtual void enterTyperef_struct(SesameParser::Typeref_structContext *ctx) = 0;
  virtual void exitTyperef_struct(SesameParser::Typeref_structContext *ctx) = 0;

  virtual void enterTyperef_union(SesameParser::Typeref_unionContext *ctx) = 0;
  virtual void exitTyperef_union(SesameParser::Typeref_unionContext *ctx) = 0;

  virtual void enterTyperef_usertype(SesameParser::Typeref_usertypeContext *ctx) = 0;
  virtual void exitTyperef_usertype(SesameParser::Typeref_usertypeContext *ctx) = 0;

  virtual void enterTyperef_precise(SesameParser::Typeref_preciseContext *ctx) = 0;
  virtual void exitTyperef_precise(SesameParser::Typeref_preciseContext *ctx) = 0;

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

  virtual void enterExpr_stmt(SesameParser::Expr_stmtContext *ctx) = 0;
  virtual void exitExpr_stmt(SesameParser::Expr_stmtContext *ctx) = 0;

  virtual void enterBlock_stmt(SesameParser::Block_stmtContext *ctx) = 0;
  virtual void exitBlock_stmt(SesameParser::Block_stmtContext *ctx) = 0;

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

  virtual void enterAssignment_expr(SesameParser::Assignment_exprContext *ctx) = 0;
  virtual void exitAssignment_expr(SesameParser::Assignment_exprContext *ctx) = 0;

  virtual void enterOp_assign_expr(SesameParser::Op_assign_exprContext *ctx) = 0;
  virtual void exitOp_assign_expr(SesameParser::Op_assign_exprContext *ctx) = 0;

  virtual void enterExpression_10(SesameParser::Expression_10Context *ctx) = 0;
  virtual void exitExpression_10(SesameParser::Expression_10Context *ctx) = 0;

  virtual void enterOpassign_op(SesameParser::Opassign_opContext *ctx) = 0;
  virtual void exitOpassign_op(SesameParser::Opassign_opContext *ctx) = 0;

  virtual void enterExpr10(SesameParser::Expr10Context *ctx) = 0;
  virtual void exitExpr10(SesameParser::Expr10Context *ctx) = 0;

  virtual void enterExpr9(SesameParser::Expr9Context *ctx) = 0;
  virtual void exitExpr9(SesameParser::Expr9Context *ctx) = 0;

  virtual void enterLogic_or_rhs(SesameParser::Logic_or_rhsContext *ctx) = 0;
  virtual void exitLogic_or_rhs(SesameParser::Logic_or_rhsContext *ctx) = 0;

  virtual void enterExpr8(SesameParser::Expr8Context *ctx) = 0;
  virtual void exitExpr8(SesameParser::Expr8Context *ctx) = 0;

  virtual void enterLogic_and_rhs(SesameParser::Logic_and_rhsContext *ctx) = 0;
  virtual void exitLogic_and_rhs(SesameParser::Logic_and_rhsContext *ctx) = 0;

  virtual void enterExpr7(SesameParser::Expr7Context *ctx) = 0;
  virtual void exitExpr7(SesameParser::Expr7Context *ctx) = 0;

  virtual void enterBinary_op_rhs(SesameParser::Binary_op_rhsContext *ctx) = 0;
  virtual void exitBinary_op_rhs(SesameParser::Binary_op_rhsContext *ctx) = 0;

  virtual void enterLogical_op(SesameParser::Logical_opContext *ctx) = 0;
  virtual void exitLogical_op(SesameParser::Logical_opContext *ctx) = 0;

  virtual void enterExpr6(SesameParser::Expr6Context *ctx) = 0;
  virtual void exitExpr6(SesameParser::Expr6Context *ctx) = 0;

  virtual void enterBit_or_rhs(SesameParser::Bit_or_rhsContext *ctx) = 0;
  virtual void exitBit_or_rhs(SesameParser::Bit_or_rhsContext *ctx) = 0;

  virtual void enterExpr5(SesameParser::Expr5Context *ctx) = 0;
  virtual void exitExpr5(SesameParser::Expr5Context *ctx) = 0;

  virtual void enterXor_rhs(SesameParser::Xor_rhsContext *ctx) = 0;
  virtual void exitXor_rhs(SesameParser::Xor_rhsContext *ctx) = 0;

  virtual void enterExpr4(SesameParser::Expr4Context *ctx) = 0;
  virtual void exitExpr4(SesameParser::Expr4Context *ctx) = 0;

  virtual void enterBit_and_rhs(SesameParser::Bit_and_rhsContext *ctx) = 0;
  virtual void exitBit_and_rhs(SesameParser::Bit_and_rhsContext *ctx) = 0;

  virtual void enterExpr3(SesameParser::Expr3Context *ctx) = 0;
  virtual void exitExpr3(SesameParser::Expr3Context *ctx) = 0;

  virtual void enterShift_op_rhs(SesameParser::Shift_op_rhsContext *ctx) = 0;
  virtual void exitShift_op_rhs(SesameParser::Shift_op_rhsContext *ctx) = 0;

  virtual void enterExpr2(SesameParser::Expr2Context *ctx) = 0;
  virtual void exitExpr2(SesameParser::Expr2Context *ctx) = 0;

  virtual void enterAdd_sub_rhs(SesameParser::Add_sub_rhsContext *ctx) = 0;
  virtual void exitAdd_sub_rhs(SesameParser::Add_sub_rhsContext *ctx) = 0;

  virtual void enterExpr1(SesameParser::Expr1Context *ctx) = 0;
  virtual void exitExpr1(SesameParser::Expr1Context *ctx) = 0;

  virtual void enterMulti_div_mod_rhs(SesameParser::Multi_div_mod_rhsContext *ctx) = 0;
  virtual void exitMulti_div_mod_rhs(SesameParser::Multi_div_mod_rhsContext *ctx) = 0;

  virtual void enterTerm(SesameParser::TermContext *ctx) = 0;
  virtual void exitTerm(SesameParser::TermContext *ctx) = 0;

  virtual void enterInc_expr(SesameParser::Inc_exprContext *ctx) = 0;
  virtual void exitInc_expr(SesameParser::Inc_exprContext *ctx) = 0;

  virtual void enterDec_expr(SesameParser::Dec_exprContext *ctx) = 0;
  virtual void exitDec_expr(SesameParser::Dec_exprContext *ctx) = 0;

  virtual void enterPositive_expr(SesameParser::Positive_exprContext *ctx) = 0;
  virtual void exitPositive_expr(SesameParser::Positive_exprContext *ctx) = 0;

  virtual void enterNegative_expr(SesameParser::Negative_exprContext *ctx) = 0;
  virtual void exitNegative_expr(SesameParser::Negative_exprContext *ctx) = 0;

  virtual void enterLogic_not_expr(SesameParser::Logic_not_exprContext *ctx) = 0;
  virtual void exitLogic_not_expr(SesameParser::Logic_not_exprContext *ctx) = 0;

  virtual void enterBit_not_expr(SesameParser::Bit_not_exprContext *ctx) = 0;
  virtual void exitBit_not_expr(SesameParser::Bit_not_exprContext *ctx) = 0;

  virtual void enterDereference_expr(SesameParser::Dereference_exprContext *ctx) = 0;
  virtual void exitDereference_expr(SesameParser::Dereference_exprContext *ctx) = 0;

  virtual void enterAddr_expr(SesameParser::Addr_exprContext *ctx) = 0;
  virtual void exitAddr_expr(SesameParser::Addr_exprContext *ctx) = 0;

  virtual void enterSizeof_type_expr(SesameParser::Sizeof_type_exprContext *ctx) = 0;
  virtual void exitSizeof_type_expr(SesameParser::Sizeof_type_exprContext *ctx) = 0;

  virtual void enterSizeof_expr(SesameParser::Sizeof_exprContext *ctx) = 0;
  virtual void exitSizeof_expr(SesameParser::Sizeof_exprContext *ctx) = 0;

  virtual void enterUnary_postfix_expr(SesameParser::Unary_postfix_exprContext *ctx) = 0;
  virtual void exitUnary_postfix_expr(SesameParser::Unary_postfix_exprContext *ctx) = 0;

  virtual void enterPostfix(SesameParser::PostfixContext *ctx) = 0;
  virtual void exitPostfix(SesameParser::PostfixContext *ctx) = 0;

  virtual void enterPostfix_option(SesameParser::Postfix_optionContext *ctx) = 0;
  virtual void exitPostfix_option(SesameParser::Postfix_optionContext *ctx) = 0;

  virtual void enterArgs(SesameParser::ArgsContext *ctx) = 0;
  virtual void exitArgs(SesameParser::ArgsContext *ctx) = 0;

  virtual void enterPrimary(SesameParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(SesameParser::PrimaryContext *ctx) = 0;


};

}  // namespace parser

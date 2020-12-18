
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

  virtual void enterDeclaration_stmt(SesameParser::Declaration_stmtContext * /*ctx*/) override { }
  virtual void exitDeclaration_stmt(SesameParser::Declaration_stmtContext * /*ctx*/) override { }

  virtual void enterImport_stmt(SesameParser::Import_stmtContext * /*ctx*/) override { }
  virtual void exitImport_stmt(SesameParser::Import_stmtContext * /*ctx*/) override { }

  virtual void enterImport_name(SesameParser::Import_nameContext * /*ctx*/) override { }
  virtual void exitImport_name(SesameParser::Import_nameContext * /*ctx*/) override { }

  virtual void enterName(SesameParser::NameContext * /*ctx*/) override { }
  virtual void exitName(SesameParser::NameContext * /*ctx*/) override { }

  virtual void enterFunc_decl(SesameParser::Func_declContext * /*ctx*/) override { }
  virtual void exitFunc_decl(SesameParser::Func_declContext * /*ctx*/) override { }

  virtual void enterVar_decl(SesameParser::Var_declContext * /*ctx*/) override { }
  virtual void exitVar_decl(SesameParser::Var_declContext * /*ctx*/) override { }

  virtual void enterTop_defs(SesameParser::Top_defsContext * /*ctx*/) override { }
  virtual void exitTop_defs(SesameParser::Top_defsContext * /*ctx*/) override { }

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

  virtual void enterTyperef_void(SesameParser::Typeref_voidContext * /*ctx*/) override { }
  virtual void exitTyperef_void(SesameParser::Typeref_voidContext * /*ctx*/) override { }

  virtual void enterTyperef_char(SesameParser::Typeref_charContext * /*ctx*/) override { }
  virtual void exitTyperef_char(SesameParser::Typeref_charContext * /*ctx*/) override { }

  virtual void enterTyperef_short(SesameParser::Typeref_shortContext * /*ctx*/) override { }
  virtual void exitTyperef_short(SesameParser::Typeref_shortContext * /*ctx*/) override { }

  virtual void enterTyperef_int(SesameParser::Typeref_intContext * /*ctx*/) override { }
  virtual void exitTyperef_int(SesameParser::Typeref_intContext * /*ctx*/) override { }

  virtual void enterTyperef_long(SesameParser::Typeref_longContext * /*ctx*/) override { }
  virtual void exitTyperef_long(SesameParser::Typeref_longContext * /*ctx*/) override { }

  virtual void enterTyperef_unsigned(SesameParser::Typeref_unsignedContext * /*ctx*/) override { }
  virtual void exitTyperef_unsigned(SesameParser::Typeref_unsignedContext * /*ctx*/) override { }

  virtual void enterTyperef_struct(SesameParser::Typeref_structContext * /*ctx*/) override { }
  virtual void exitTyperef_struct(SesameParser::Typeref_structContext * /*ctx*/) override { }

  virtual void enterTyperef_union(SesameParser::Typeref_unionContext * /*ctx*/) override { }
  virtual void exitTyperef_union(SesameParser::Typeref_unionContext * /*ctx*/) override { }

  virtual void enterTyperef_usertype(SesameParser::Typeref_usertypeContext * /*ctx*/) override { }
  virtual void exitTyperef_usertype(SesameParser::Typeref_usertypeContext * /*ctx*/) override { }

  virtual void enterTyperef_precise(SesameParser::Typeref_preciseContext * /*ctx*/) override { }
  virtual void exitTyperef_precise(SesameParser::Typeref_preciseContext * /*ctx*/) override { }

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

  virtual void enterExpr_stmt(SesameParser::Expr_stmtContext * /*ctx*/) override { }
  virtual void exitExpr_stmt(SesameParser::Expr_stmtContext * /*ctx*/) override { }

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

  virtual void enterAssignment_expr(SesameParser::Assignment_exprContext * /*ctx*/) override { }
  virtual void exitAssignment_expr(SesameParser::Assignment_exprContext * /*ctx*/) override { }

  virtual void enterOp_assign_expr(SesameParser::Op_assign_exprContext * /*ctx*/) override { }
  virtual void exitOp_assign_expr(SesameParser::Op_assign_exprContext * /*ctx*/) override { }

  virtual void enterExpression_10(SesameParser::Expression_10Context * /*ctx*/) override { }
  virtual void exitExpression_10(SesameParser::Expression_10Context * /*ctx*/) override { }

  virtual void enterOpassign_op(SesameParser::Opassign_opContext * /*ctx*/) override { }
  virtual void exitOpassign_op(SesameParser::Opassign_opContext * /*ctx*/) override { }

  virtual void enterExpr10(SesameParser::Expr10Context * /*ctx*/) override { }
  virtual void exitExpr10(SesameParser::Expr10Context * /*ctx*/) override { }

  virtual void enterExpr9(SesameParser::Expr9Context * /*ctx*/) override { }
  virtual void exitExpr9(SesameParser::Expr9Context * /*ctx*/) override { }

  virtual void enterLogic_or_rhs(SesameParser::Logic_or_rhsContext * /*ctx*/) override { }
  virtual void exitLogic_or_rhs(SesameParser::Logic_or_rhsContext * /*ctx*/) override { }

  virtual void enterExpr8(SesameParser::Expr8Context * /*ctx*/) override { }
  virtual void exitExpr8(SesameParser::Expr8Context * /*ctx*/) override { }

  virtual void enterLogic_and_rhs(SesameParser::Logic_and_rhsContext * /*ctx*/) override { }
  virtual void exitLogic_and_rhs(SesameParser::Logic_and_rhsContext * /*ctx*/) override { }

  virtual void enterExpr7(SesameParser::Expr7Context * /*ctx*/) override { }
  virtual void exitExpr7(SesameParser::Expr7Context * /*ctx*/) override { }

  virtual void enterBinary_op_rhs(SesameParser::Binary_op_rhsContext * /*ctx*/) override { }
  virtual void exitBinary_op_rhs(SesameParser::Binary_op_rhsContext * /*ctx*/) override { }

  virtual void enterLogical_op(SesameParser::Logical_opContext * /*ctx*/) override { }
  virtual void exitLogical_op(SesameParser::Logical_opContext * /*ctx*/) override { }

  virtual void enterExpr6(SesameParser::Expr6Context * /*ctx*/) override { }
  virtual void exitExpr6(SesameParser::Expr6Context * /*ctx*/) override { }

  virtual void enterBit_or_rhs(SesameParser::Bit_or_rhsContext * /*ctx*/) override { }
  virtual void exitBit_or_rhs(SesameParser::Bit_or_rhsContext * /*ctx*/) override { }

  virtual void enterExpr5(SesameParser::Expr5Context * /*ctx*/) override { }
  virtual void exitExpr5(SesameParser::Expr5Context * /*ctx*/) override { }

  virtual void enterXor_rhs(SesameParser::Xor_rhsContext * /*ctx*/) override { }
  virtual void exitXor_rhs(SesameParser::Xor_rhsContext * /*ctx*/) override { }

  virtual void enterExpr4(SesameParser::Expr4Context * /*ctx*/) override { }
  virtual void exitExpr4(SesameParser::Expr4Context * /*ctx*/) override { }

  virtual void enterBit_and_rhs(SesameParser::Bit_and_rhsContext * /*ctx*/) override { }
  virtual void exitBit_and_rhs(SesameParser::Bit_and_rhsContext * /*ctx*/) override { }

  virtual void enterExpr3(SesameParser::Expr3Context * /*ctx*/) override { }
  virtual void exitExpr3(SesameParser::Expr3Context * /*ctx*/) override { }

  virtual void enterShift_op_rhs(SesameParser::Shift_op_rhsContext * /*ctx*/) override { }
  virtual void exitShift_op_rhs(SesameParser::Shift_op_rhsContext * /*ctx*/) override { }

  virtual void enterExpr2(SesameParser::Expr2Context * /*ctx*/) override { }
  virtual void exitExpr2(SesameParser::Expr2Context * /*ctx*/) override { }

  virtual void enterAdd_sub_rhs(SesameParser::Add_sub_rhsContext * /*ctx*/) override { }
  virtual void exitAdd_sub_rhs(SesameParser::Add_sub_rhsContext * /*ctx*/) override { }

  virtual void enterExpr1(SesameParser::Expr1Context * /*ctx*/) override { }
  virtual void exitExpr1(SesameParser::Expr1Context * /*ctx*/) override { }

  virtual void enterMulti_div_mod_rhs(SesameParser::Multi_div_mod_rhsContext * /*ctx*/) override { }
  virtual void exitMulti_div_mod_rhs(SesameParser::Multi_div_mod_rhsContext * /*ctx*/) override { }

  virtual void enterTerm(SesameParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(SesameParser::TermContext * /*ctx*/) override { }

  virtual void enterInc_expr(SesameParser::Inc_exprContext * /*ctx*/) override { }
  virtual void exitInc_expr(SesameParser::Inc_exprContext * /*ctx*/) override { }

  virtual void enterDec_expr(SesameParser::Dec_exprContext * /*ctx*/) override { }
  virtual void exitDec_expr(SesameParser::Dec_exprContext * /*ctx*/) override { }

  virtual void enterPositive_expr(SesameParser::Positive_exprContext * /*ctx*/) override { }
  virtual void exitPositive_expr(SesameParser::Positive_exprContext * /*ctx*/) override { }

  virtual void enterNegative_expr(SesameParser::Negative_exprContext * /*ctx*/) override { }
  virtual void exitNegative_expr(SesameParser::Negative_exprContext * /*ctx*/) override { }

  virtual void enterLogic_not_expr(SesameParser::Logic_not_exprContext * /*ctx*/) override { }
  virtual void exitLogic_not_expr(SesameParser::Logic_not_exprContext * /*ctx*/) override { }

  virtual void enterBit_not_expr(SesameParser::Bit_not_exprContext * /*ctx*/) override { }
  virtual void exitBit_not_expr(SesameParser::Bit_not_exprContext * /*ctx*/) override { }

  virtual void enterDereference_expr(SesameParser::Dereference_exprContext * /*ctx*/) override { }
  virtual void exitDereference_expr(SesameParser::Dereference_exprContext * /*ctx*/) override { }

  virtual void enterAddr_expr(SesameParser::Addr_exprContext * /*ctx*/) override { }
  virtual void exitAddr_expr(SesameParser::Addr_exprContext * /*ctx*/) override { }

  virtual void enterSizeof_type_expr(SesameParser::Sizeof_type_exprContext * /*ctx*/) override { }
  virtual void exitSizeof_type_expr(SesameParser::Sizeof_type_exprContext * /*ctx*/) override { }

  virtual void enterSizeof_expr(SesameParser::Sizeof_exprContext * /*ctx*/) override { }
  virtual void exitSizeof_expr(SesameParser::Sizeof_exprContext * /*ctx*/) override { }

  virtual void enterUnary_postfix_expr(SesameParser::Unary_postfix_exprContext * /*ctx*/) override { }
  virtual void exitUnary_postfix_expr(SesameParser::Unary_postfix_exprContext * /*ctx*/) override { }

  virtual void enterPostfix(SesameParser::PostfixContext * /*ctx*/) override { }
  virtual void exitPostfix(SesameParser::PostfixContext * /*ctx*/) override { }

  virtual void enterPostfix_option(SesameParser::Postfix_optionContext * /*ctx*/) override { }
  virtual void exitPostfix_option(SesameParser::Postfix_optionContext * /*ctx*/) override { }

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

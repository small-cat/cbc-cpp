
// Generated from SesameParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SesameParserVisitor.h"


namespace parser {

/**
 * This class provides an empty implementation of SesameParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SesameParserBaseVisitor : public SesameParserVisitor {
public:

  virtual antlrcpp::Any visitCompilation_unit(SesameParser::Compilation_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration_file(SesameParser::Declaration_fileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_stmt(SesameParser::Import_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_name(SesameParser::Import_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName(SesameParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_decl(SesameParser::Func_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_decl(SesameParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTop_defs(SesameParser::Top_defsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDef_func(SesameParser::Def_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStorage(SesameParser::StorageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParams(SesameParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFixed_params(SesameParser::Fixed_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam(SesameParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(SesameParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDef_vars(SesameParser::Def_varsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign_expr(SesameParser::Assign_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDef_const(SesameParser::Def_constContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDef_struct(SesameParser::Def_structContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDef_union(SesameParser::Def_unionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMember_list(SesameParser::Member_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSlot(SesameParser::SlotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitS_typedef(SesameParser::S_typedefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(SesameParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTyperef(SesameParser::TyperefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTyperef_base(SesameParser::Typeref_baseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTyperef_precise(SesameParser::Typeref_preciseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_typerefs(SesameParser::Param_typerefsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmts(SesameParser::StmtsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(SesameParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabeled_stmt(SesameParser::Labeled_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_stmt(SesameParser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_stmt(SesameParser::While_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDo_while_stmt(SesameParser::Do_while_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_stmt(SesameParser::For_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitch_stmt(SesameParser::Switch_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_clauses(SesameParser::Case_clausesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_clause(SesameParser::Case_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCases(SesameParser::CasesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefault_clause(SesameParser::Default_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_body(SesameParser::Case_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreak_stmt(SesameParser::Break_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinue_stmt(SesameParser::Continue_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGoto_stmt(SesameParser::Goto_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_stmt(SesameParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_expr(SesameParser::Assignment_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_assign_expr(SesameParser::Op_assign_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_10(SesameParser::Expression_10Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpassign_op(SesameParser::Opassign_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr10(SesameParser::Expr10Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr9(SesameParser::Expr9Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_or_rhs(SesameParser::Logic_or_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr8(SesameParser::Expr8Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_and_rhs(SesameParser::Logic_and_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr7(SesameParser::Expr7Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_op_rhs(SesameParser::Binary_op_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogical_op(SesameParser::Logical_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr6(SesameParser::Expr6Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBit_or_rhs(SesameParser::Bit_or_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr5(SesameParser::Expr5Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXor_rhs(SesameParser::Xor_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr4(SesameParser::Expr4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBit_and_rhs(SesameParser::Bit_and_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr3(SesameParser::Expr3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShift_op_rhs(SesameParser::Shift_op_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr2(SesameParser::Expr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdd_sub_rhs(SesameParser::Add_sub_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr1(SesameParser::Expr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulti_div_mod_rhs(SesameParser::Multi_div_mod_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(SesameParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInc_expr(SesameParser::Inc_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDec_expr(SesameParser::Dec_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPositive_expr(SesameParser::Positive_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNegative_expr(SesameParser::Negative_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_not_expr(SesameParser::Logic_not_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBit_not_expr(SesameParser::Bit_not_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDereference_expr(SesameParser::Dereference_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddr_expr(SesameParser::Addr_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSizeof_type_expr(SesameParser::Sizeof_type_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSizeof_expr(SesameParser::Sizeof_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_postfix_expr(SesameParser::Unary_postfix_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostfix(SesameParser::PostfixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostfix_option(SesameParser::Postfix_optionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgs(SesameParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary(SesameParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace parser


// Generated from SesameParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SesameParser.h"


namespace parser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by SesameParser.
 */
class  SesameParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SesameParser.
   */
    virtual antlrcpp::Any visitCompilation_unit(SesameParser::Compilation_unitContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration_file(SesameParser::Declaration_fileContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration_stmt(SesameParser::Declaration_stmtContext *context) = 0;

    virtual antlrcpp::Any visitImport_stmt(SesameParser::Import_stmtContext *context) = 0;

    virtual antlrcpp::Any visitImport_name(SesameParser::Import_nameContext *context) = 0;

    virtual antlrcpp::Any visitName(SesameParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitFunc_decl(SesameParser::Func_declContext *context) = 0;

    virtual antlrcpp::Any visitVar_decl(SesameParser::Var_declContext *context) = 0;

    virtual antlrcpp::Any visitTop_defs(SesameParser::Top_defsContext *context) = 0;

    virtual antlrcpp::Any visitDef_func(SesameParser::Def_funcContext *context) = 0;

    virtual antlrcpp::Any visitStorage(SesameParser::StorageContext *context) = 0;

    virtual antlrcpp::Any visitParams(SesameParser::ParamsContext *context) = 0;

    virtual antlrcpp::Any visitFixed_params(SesameParser::Fixed_paramsContext *context) = 0;

    virtual antlrcpp::Any visitParam(SesameParser::ParamContext *context) = 0;

    virtual antlrcpp::Any visitBlock(SesameParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitDef_vars(SesameParser::Def_varsContext *context) = 0;

    virtual antlrcpp::Any visitAssign_expr(SesameParser::Assign_exprContext *context) = 0;

    virtual antlrcpp::Any visitDef_const(SesameParser::Def_constContext *context) = 0;

    virtual antlrcpp::Any visitDef_struct(SesameParser::Def_structContext *context) = 0;

    virtual antlrcpp::Any visitDef_union(SesameParser::Def_unionContext *context) = 0;

    virtual antlrcpp::Any visitMember_list(SesameParser::Member_listContext *context) = 0;

    virtual antlrcpp::Any visitSlot(SesameParser::SlotContext *context) = 0;

    virtual antlrcpp::Any visitS_typedef(SesameParser::S_typedefContext *context) = 0;

    virtual antlrcpp::Any visitType(SesameParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitTyperef(SesameParser::TyperefContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_void(SesameParser::Typeref_voidContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_char(SesameParser::Typeref_charContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_short(SesameParser::Typeref_shortContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_int(SesameParser::Typeref_intContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_long(SesameParser::Typeref_longContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_unsigned(SesameParser::Typeref_unsignedContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_struct(SesameParser::Typeref_structContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_union(SesameParser::Typeref_unionContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_usertype(SesameParser::Typeref_usertypeContext *context) = 0;

    virtual antlrcpp::Any visitTyperef_precise(SesameParser::Typeref_preciseContext *context) = 0;

    virtual antlrcpp::Any visitParam_typerefs(SesameParser::Param_typerefsContext *context) = 0;

    virtual antlrcpp::Any visitFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext *context) = 0;

    virtual antlrcpp::Any visitStmts(SesameParser::StmtsContext *context) = 0;

    virtual antlrcpp::Any visitStmt(SesameParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitLabeled_stmt(SesameParser::Labeled_stmtContext *context) = 0;

    virtual antlrcpp::Any visitExpr_stmt(SesameParser::Expr_stmtContext *context) = 0;

    virtual antlrcpp::Any visitBlock_stmt(SesameParser::Block_stmtContext *context) = 0;

    virtual antlrcpp::Any visitIf_stmt(SesameParser::If_stmtContext *context) = 0;

    virtual antlrcpp::Any visitWhile_stmt(SesameParser::While_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDo_while_stmt(SesameParser::Do_while_stmtContext *context) = 0;

    virtual antlrcpp::Any visitFor_stmt(SesameParser::For_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_stmt(SesameParser::Switch_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCase_clauses(SesameParser::Case_clausesContext *context) = 0;

    virtual antlrcpp::Any visitCase_clause(SesameParser::Case_clauseContext *context) = 0;

    virtual antlrcpp::Any visitCases(SesameParser::CasesContext *context) = 0;

    virtual antlrcpp::Any visitDefault_clause(SesameParser::Default_clauseContext *context) = 0;

    virtual antlrcpp::Any visitCase_body(SesameParser::Case_bodyContext *context) = 0;

    virtual antlrcpp::Any visitBreak_stmt(SesameParser::Break_stmtContext *context) = 0;

    virtual antlrcpp::Any visitContinue_stmt(SesameParser::Continue_stmtContext *context) = 0;

    virtual antlrcpp::Any visitGoto_stmt(SesameParser::Goto_stmtContext *context) = 0;

    virtual antlrcpp::Any visitReturn_stmt(SesameParser::Return_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_expr(SesameParser::Assignment_exprContext *context) = 0;

    virtual antlrcpp::Any visitOp_assign_expr(SesameParser::Op_assign_exprContext *context) = 0;

    virtual antlrcpp::Any visitExpression_10(SesameParser::Expression_10Context *context) = 0;

    virtual antlrcpp::Any visitOpassign_op(SesameParser::Opassign_opContext *context) = 0;

    virtual antlrcpp::Any visitExpr10(SesameParser::Expr10Context *context) = 0;

    virtual antlrcpp::Any visitExpr9(SesameParser::Expr9Context *context) = 0;

    virtual antlrcpp::Any visitLogic_or_rhs(SesameParser::Logic_or_rhsContext *context) = 0;

    virtual antlrcpp::Any visitExpr8(SesameParser::Expr8Context *context) = 0;

    virtual antlrcpp::Any visitLogic_and_rhs(SesameParser::Logic_and_rhsContext *context) = 0;

    virtual antlrcpp::Any visitExpr7(SesameParser::Expr7Context *context) = 0;

    virtual antlrcpp::Any visitBinary_op_rhs(SesameParser::Binary_op_rhsContext *context) = 0;

    virtual antlrcpp::Any visitLogical_op(SesameParser::Logical_opContext *context) = 0;

    virtual antlrcpp::Any visitExpr6(SesameParser::Expr6Context *context) = 0;

    virtual antlrcpp::Any visitBit_or_rhs(SesameParser::Bit_or_rhsContext *context) = 0;

    virtual antlrcpp::Any visitExpr5(SesameParser::Expr5Context *context) = 0;

    virtual antlrcpp::Any visitXor_rhs(SesameParser::Xor_rhsContext *context) = 0;

    virtual antlrcpp::Any visitExpr4(SesameParser::Expr4Context *context) = 0;

    virtual antlrcpp::Any visitBit_and_rhs(SesameParser::Bit_and_rhsContext *context) = 0;

    virtual antlrcpp::Any visitExpr3(SesameParser::Expr3Context *context) = 0;

    virtual antlrcpp::Any visitShift_op_rhs(SesameParser::Shift_op_rhsContext *context) = 0;

    virtual antlrcpp::Any visitExpr2(SesameParser::Expr2Context *context) = 0;

    virtual antlrcpp::Any visitAdd_sub_rhs(SesameParser::Add_sub_rhsContext *context) = 0;

    virtual antlrcpp::Any visitExpr1(SesameParser::Expr1Context *context) = 0;

    virtual antlrcpp::Any visitMulti_div_mod_rhs(SesameParser::Multi_div_mod_rhsContext *context) = 0;

    virtual antlrcpp::Any visitTerm(SesameParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitInc_expr(SesameParser::Inc_exprContext *context) = 0;

    virtual antlrcpp::Any visitDec_expr(SesameParser::Dec_exprContext *context) = 0;

    virtual antlrcpp::Any visitPositive_expr(SesameParser::Positive_exprContext *context) = 0;

    virtual antlrcpp::Any visitNegative_expr(SesameParser::Negative_exprContext *context) = 0;

    virtual antlrcpp::Any visitLogic_not_expr(SesameParser::Logic_not_exprContext *context) = 0;

    virtual antlrcpp::Any visitBit_not_expr(SesameParser::Bit_not_exprContext *context) = 0;

    virtual antlrcpp::Any visitDereference_expr(SesameParser::Dereference_exprContext *context) = 0;

    virtual antlrcpp::Any visitAddr_expr(SesameParser::Addr_exprContext *context) = 0;

    virtual antlrcpp::Any visitSizeof_type_expr(SesameParser::Sizeof_type_exprContext *context) = 0;

    virtual antlrcpp::Any visitSizeof_expr(SesameParser::Sizeof_exprContext *context) = 0;

    virtual antlrcpp::Any visitUnary_postfix_expr(SesameParser::Unary_postfix_exprContext *context) = 0;

    virtual antlrcpp::Any visitPostfix(SesameParser::PostfixContext *context) = 0;

    virtual antlrcpp::Any visitPostfix_option(SesameParser::Postfix_optionContext *context) = 0;

    virtual antlrcpp::Any visitArgs(SesameParser::ArgsContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(SesameParser::PrimaryContext *context) = 0;


};

}  // namespace parser

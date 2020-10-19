/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : build_ast_visitor.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-24
 * @brief : build ast from antlr4 cst by visitor
*/

#ifndef __BUILD_AST_VISITOR_H__
#define __BUILD_AST_VISITOR_H__

#include "SesameParser.h"
#include "SesameLexer.h"
#include "SesameParserBaseVisitor.h"

namespace parser {
class BuildAstVistor : public SesameParserBaseVisitor {
public:
  BuildAstVistor(SesameParser* parser, LibraryLoader* loader, const std::string& sname, ErrorHandler* handler);
  virtual ~BuildAstVistor();

  antlrcpp::Any visitCompilation_unit(SesameParser::Compilation_unitContext *context);

  antlrcpp::Any visitDeclaration_file(SesameParser::Declaration_fileContext *context);

  antlrcpp::Any visitImport_stmt(SesameParser::Import_stmtContext *context);

  antlrcpp::Any visitName(SesameParser::NameContext *context);

  antlrcpp::Any visitTop_def(SesameParser::Top_defContext *context);

  antlrcpp::Any visitDef_func(SesameParser::Def_funcContext *context);

  antlrcpp::Any visitStorage(SesameParser::StorageContext *context);

  antlrcpp::Any visitParams(SesameParser::ParamsContext *context);

  antlrcpp::Any visitFixed_params(SesameParser::Fixed_paramsContext *context);

  antlrcpp::Any visitParam(SesameParser::ParamContext *context);

  antlrcpp::Any visitBlock(SesameParser::BlockContext *context);

  antlrcpp::Any visitDef_vars(SesameParser::Def_varsContext *context);

  antlrcpp::Any visitAssign_expr(SesameParser::Assign_exprContext *context);

  antlrcpp::Any visitDef_const(SesameParser::Def_constContext *context);

  antlrcpp::Any visitDef_struct(SesameParser::Def_structContext *context);

  antlrcpp::Any visitDef_union(SesameParser::Def_unionContext *context);

  antlrcpp::Any visitMember_list(SesameParser::Member_listContext *context);

  antlrcpp::Any visitSlot(SesameParser::SlotContext *context);

  antlrcpp::Any visitS_typedef(SesameParser::S_typedefContext *context);

  antlrcpp::Any visitType(SesameParser::TypeContext *context);

  antlrcpp::Any visitTyperef(SesameParser::TyperefContext *context);

  antlrcpp::Any visitTyperef_base(SesameParser::Typeref_baseContext *context);

  antlrcpp::Any visitParam_typerefs(SesameParser::Param_typerefsContext *context);

  antlrcpp::Any visitFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext *context);

  antlrcpp::Any visitStmts(SesameParser::StmtsContext *context);

  antlrcpp::Any visitStmt(SesameParser::StmtContext *context);

  antlrcpp::Any visitLabeled_stmt(SesameParser::Labeled_stmtContext *context);

  antlrcpp::Any visitIf_stmt(SesameParser::If_stmtContext *context);

  antlrcpp::Any visitWhile_stmt(SesameParser::While_stmtContext *context);

  antlrcpp::Any visitDo_while_stmt(SesameParser::Do_while_stmtContext *context);

  antlrcpp::Any visitFor_stmt(SesameParser::For_stmtContext *context);

  antlrcpp::Any visitSwitch_stmt(SesameParser::Switch_stmtContext *context);

  antlrcpp::Any visitCase_clauses(SesameParser::Case_clausesContext *context);

  antlrcpp::Any visitCase_clause(SesameParser::Case_clauseContext *context);

  antlrcpp::Any visitCases(SesameParser::CasesContext *context);

  antlrcpp::Any visitDefault_clause(SesameParser::Default_clauseContext *context);

  antlrcpp::Any visitCase_body(SesameParser::Case_bodyContext *context);

  antlrcpp::Any visitBreak_stmt(SesameParser::Break_stmtContext *context);

  antlrcpp::Any visitContinue_stmt(SesameParser::Continue_stmtContext *context);

  antlrcpp::Any visitGoto_stmt(SesameParser::Goto_stmtContext *context);

  antlrcpp::Any visitReturn_stmt(SesameParser::Return_stmtContext *context);

  antlrcpp::Any visitExpr(SesameParser::ExprContext *context);

  antlrcpp::Any visitOpassign_op(SesameParser::Opassign_opContext *context);

  antlrcpp::Any visitExpr10(SesameParser::Expr10Context *context);

  antlrcpp::Any visitExpr8(SesameParser::Expr8Context *context);

  antlrcpp::Any visitExpr7(SesameParser::Expr7Context *context);

  antlrcpp::Any visitLogical_op(SesameParser::Logical_opContext *context);

  antlrcpp::Any visitExpr6(SesameParser::Expr6Context *context);

  antlrcpp::Any visitExpr5(SesameParser::Expr5Context *context);

  antlrcpp::Any visitExpr4(SesameParser::Expr4Context *context);

  antlrcpp::Any visitExpr3(SesameParser::Expr3Context *context);

  antlrcpp::Any visitExpr2(SesameParser::Expr2Context *context);

  antlrcpp::Any visitExpr1(SesameParser::Expr1Context *context);

  antlrcpp::Any visitTerm(SesameParser::TermContext *context);

  antlrcpp::Any visitUnary(SesameParser::UnaryContext *context);

  antlrcpp::Any visitPostfix(SesameParser::PostfixContext *context);

  antlrcpp::Any visitArgs(SesameParser::ArgsContext *context);

  antlrcpp::Any visitPrimary(SesameParser::PrimaryContext *context);

  void AddKnownTypedefs(std::vector<ast::TypedefNode*> typedefs);
private:
  SesameParser* parser_;
  antlr4::TokenStream* tokens_;

  LibraryLoader* loader_;
  std::string source_name_;
  ErrorHandler* err_handler_;
  std::vector<std::string> known_typedefs_;
};
} /* end parser */

#endif /* __BUILD_AST_VISITOR_H__ */

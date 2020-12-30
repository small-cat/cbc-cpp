/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: build_ast.h
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/15
* @brief: Build ast from antlr4 visitor
*/
#ifndef BUILD_AST_H
#define BUILD_AST_H

#include "syntax/generated/SesameLexer.h"
#include "syntax/generated/SesameParser.h"
#include "syntax/generated/SesameParserBaseVisitor.h"

#include "ast/ast.hpp"
#include "entity/defined_variable.h"
#include "ast/expr/integer_literal_node.hpp"
#include "type/integer_type_ref.h"
#include "type/param_type_ref.hpp"
#include "type/param_types.hpp"
#include "entity/params.h"
#include "ast/import_file_node.h"

#include "ast/location.hpp"
#include "entity/entity.h"
#include "type/type.hpp"

namespace parser {
class BuildAstVisitor : public SesameParserBaseVisitor {
public:
  BuildAstVisitor(SesameParser* parser, std::string fname);
  virtual ~BuildAstVisitor();

  virtual antlrcpp::Any visitCompilation_unit(SesameParser::Compilation_unitContext * ctx);
  virtual antlrcpp::Any visitTop_defs(SesameParser::Top_defsContext * ctx);

  // build defined funtion
  virtual antlrcpp::Any visitDef_func(SesameParser::Def_funcContext * ctx);
  virtual antlrcpp::Any visitTyperef(SesameParser::TyperefContext * ctx);
  virtual antlrcpp::Any visitParam_typerefs(SesameParser::Param_typerefsContext * ctx);
  virtual antlrcpp::Any visitTyperef_void(SesameParser::Typeref_voidContext * ctx);
  virtual antlrcpp::Any visitTyperef_char(SesameParser::Typeref_charContext * ctx);
  virtual antlrcpp::Any visitTyperef_short(SesameParser::Typeref_shortContext * ctx);
  virtual antlrcpp::Any visitTyperef_int(SesameParser::Typeref_intContext * ctx);
  virtual antlrcpp::Any visitTyperef_long(SesameParser::Typeref_longContext * ctx);
  virtual antlrcpp::Any visitTyperef_unsigned(SesameParser::Typeref_unsignedContext * ctx);
  virtual antlrcpp::Any visitTyperef_struct(SesameParser::Typeref_structContext * ctx);
  virtual antlrcpp::Any visitTyperef_union(SesameParser::Typeref_unionContext * ctx);
  virtual antlrcpp::Any visitTyperef_usertype(SesameParser::Typeref_usertypeContext * ctx);

  virtual antlrcpp::Any visitFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext * ctx);
  virtual antlrcpp::Any visitParams(SesameParser::ParamsContext * ctx);
  virtual antlrcpp::Any visitFixed_params(SesameParser::Fixed_paramsContext * ctx);
  virtual antlrcpp::Any visitParam(SesameParser::ParamContext * ctx);
  virtual antlrcpp::Any visitType(SesameParser::TypeContext * ctx);
  virtual antlrcpp::Any visitBlock(SesameParser::BlockContext * ctx);

  // build defined variables
  virtual antlrcpp::Any visitDef_vars(SesameParser::Def_varsContext * ctx);

  // build defined constant
  virtual antlrcpp::Any visitDef_const(SesameParser::Def_constContext * ctx);

  // build defined struct
  virtual antlrcpp::Any visitDef_struct(SesameParser::Def_structContext * ctx);

  // build defined union
  virtual antlrcpp::Any visitDef_union(SesameParser::Def_unionContext * ctx);
  virtual antlrcpp::Any visitMember_list(SesameParser::Member_listContext * ctx);
  virtual antlrcpp::Any visitSlot(SesameParser::SlotContext * ctx);

  // build typedef
  virtual antlrcpp::Any visitS_typedef(SesameParser::S_typedefContext * ctx);

  // build expression
  virtual antlrcpp::Any visitAssignment_expr(SesameParser::Assignment_exprContext * ctx);
  virtual antlrcpp::Any visitOp_assign_expr(SesameParser::Op_assign_exprContext * ctx);
  virtual antlrcpp::Any visitExpression_10(SesameParser::Expression_10Context * ctx);
  virtual antlrcpp::Any visitExpr10(SesameParser::Expr10Context * ctx);
  virtual antlrcpp::Any visitExpr9(SesameParser::Expr9Context * ctx);
  virtual antlrcpp::Any visitExpr8(SesameParser::Expr8Context * ctx);
  virtual antlrcpp::Any visitExpr7(SesameParser::Expr7Context * ctx);
  virtual antlrcpp::Any visitExpr6(SesameParser::Expr6Context * ctx);
  virtual antlrcpp::Any visitExpr5(SesameParser::Expr5Context * ctx);
  virtual antlrcpp::Any visitExpr4(SesameParser::Expr4Context * ctx);
  virtual antlrcpp::Any visitExpr3(SesameParser::Expr3Context * ctx);
  virtual antlrcpp::Any visitExpr2(SesameParser::Expr2Context * ctx);
  virtual antlrcpp::Any visitExpr1(SesameParser::Expr1Context * ctx);
  virtual antlrcpp::Any visitTerm(SesameParser::TermContext * ctx);
  // unary expr
  virtual antlrcpp::Any visitInc_expr(SesameParser::Inc_exprContext * ctx);
  virtual antlrcpp::Any visitDec_expr(SesameParser::Dec_exprContext * ctx);
  virtual antlrcpp::Any visitPositive_expr(SesameParser::Positive_exprContext * ctx);
  virtual antlrcpp::Any visitNegative_expr(SesameParser::Negative_exprContext * ctx);
  virtual antlrcpp::Any visitLogic_not_expr(SesameParser::Logic_not_exprContext * ctx);
  virtual antlrcpp::Any visitBit_not_expr(SesameParser::Bit_not_exprContext * ctx);
  virtual antlrcpp::Any visitDereference_expr(SesameParser::Dereference_exprContext * ctx);
  virtual antlrcpp::Any visitAddr_expr(SesameParser::Addr_exprContext * ctx);
  virtual antlrcpp::Any visitSizeof_type_expr(SesameParser::Sizeof_type_exprContext * ctx);
  virtual antlrcpp::Any visitSizeof_expr(SesameParser::Sizeof_exprContext * ctx);
  virtual antlrcpp::Any visitUnary_postfix_expr(SesameParser::Unary_postfix_exprContext * ctx);
  virtual antlrcpp::Any visitPostfix(SesameParser::PostfixContext * ctx);
  virtual antlrcpp::Any visitPrimary(SesameParser::PrimaryContext * ctx);

  // stmt
  virtual antlrcpp::Any visitExpr_stmt(SesameParser::Expr_stmtContext* ctx);
  virtual antlrcpp::Any visitLabeled_stmt(SesameParser::Labeled_stmtContext * ctx);
  virtual antlrcpp::Any visitIf_stmt(SesameParser::If_stmtContext * ctx);
  virtual antlrcpp::Any visitWhile_stmt(SesameParser::While_stmtContext * ctx);
  virtual antlrcpp::Any visitDo_while_stmt(SesameParser::Do_while_stmtContext * ctx);
  virtual antlrcpp::Any visitFor_stmt(SesameParser::For_stmtContext * ctx);
  virtual antlrcpp::Any visitSwitch_stmt(SesameParser::Switch_stmtContext * ctx);
  virtual antlrcpp::Any visitCase_clause(SesameParser::Case_clauseContext * ctx);
  virtual antlrcpp::Any visitCase_body(SesameParser::Case_bodyContext * ctx);
  virtual antlrcpp::Any visitDefault_clause(SesameParser::Default_clauseContext * ctx);
  virtual antlrcpp::Any visitBreak_stmt(SesameParser::Break_stmtContext * ctx);
  virtual antlrcpp::Any visitContinue_stmt(SesameParser::Continue_stmtContext * ctx);
  virtual antlrcpp::Any visitGoto_stmt(SesameParser::Goto_stmtContext * ctx);
  virtual antlrcpp::Any visitReturn_stmt(SesameParser::Return_stmtContext * ctx);  
  virtual antlrcpp::Any visitBlock_stmt(SesameParser::Block_stmtContext * ctx);
  
  // import declaration
  virtual antlrcpp::Any visitDeclaration_file(SesameParser::Declaration_fileContext *ctx);
  virtual antlrcpp::Any visitFunc_decl(SesameParser::Func_declContext * ctx);
  virtual antlrcpp::Any visitVar_decl(SesameParser::Var_declContext * ctx);

  void AddImportFile(const std::string& fname, ast::Location* loc);
  std::vector<ast::ImportFileNode *> import_files();
  ast::CflatToken* GetCFlatToken(antlr4::Token *t);  ast::IntegerLiteralNode* GetIntegerNode(ast::Location *l, std::string str);
  long GetIntegerValue(std::string str, ast::Location *l);
  long GetCharValue(const std::string& str, ast::Location *l);
  type::TypeRef* GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass cls, ast::Location* loc = nullptr);
  ast::Location* GetLocation(ast::CflatToken* t);
private:
  SesameParser* parser_;
  antlr4::TokenStream* tokens_;
  std::string filename_;
  std::vector<ast::ImportFileNode *> import_files_;

  std::vector<entity::DefinedVariable *> defined_vars_; // for def_vars only
  std::vector<ast::SlotNode *> member_list_;            // for member_list

  ast::NodeTracker node_tracker_;
  entity::EntityTracker entity_tracker_;
  type::TypeRefTracker typeref_tracker_;
  ast::LocationTracker location_tracker_;
  type::ParamSlotsTracker<entity::Params> params_tracker_;
  type::ParamSlotsTracker<type::ParamTypeRefs> param_typeref_tracker_;
  type::ParamSlotsTracker<type::ParamTypes> param_types_tracker_;
};
} /* parser */

#endif

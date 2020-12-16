#include "build_ast.h"

#include "../../type/type_ref.hpp"
#include "../../entity/params.h"
#include "../../ast/stmt/block_node.hpp"
#include "../../type/function_type_ref.hpp"
#include "../../type/array_type_ref.h"
#include "../../type/pointer_type_ref.h"
#include "../../type/struct_type_ref.h"
#include "../../type/union_type_ref.h"
#include "../../type/user_type_ref.hpp"
#include "../../type/integer_type_ref.h"
#include "../../ast/slot.hpp"

// expr
#include "../../ast/expr/assign_node.hpp"
#include "../../ast/expr/op_assign_node.hpp"
#include "../../ast/expr/cond_expr_node.hpp"
#include "../../ast/expr/logical_or_node.hpp"
#include "../../ast/expr/logical_and_node.hpp"
#include "../../ast/expr/binary_op_node.hpp"
#include "../../ast/expr/cast_node.hpp"
#include "../../ast/expr/prefix_op_node.hpp"
#include "../../ast/expr/unary_op_node.hpp"
#include "../../ast/expr/dereference_node.hpp"
#include "../../ast/expr/address_node.hpp"
#include "../../ast/expr/sizeof_expr_node.hpp"
#include "../../ast/expr/sizeof_type_node.hpp"
#include "../../ast/expr/suffix_op_node.hpp"
#include "../../ast/expr/aref_node.hpp"
#include "../../ast/expr/member_node.hpp"
#include "../../ast/expr/ptr_member_node.hpp"
#include "../../ast/expr/funcall_node.hpp"
#include ""
#include "../../ast/expr/integer_literal_node.hpp"
#include "../../ast/expr/string_literal_node.hpp"
#include "../../ast/expr/variable_node.hpp"

namespace parser {
BuildAstVisitor::BuildAstVisitor(SesameParser* parser, std::string fname) 
  : parser_(parser), filename_(fname) {
    tokens_ = parser_->getTokenStream();
  }

BuildAstVisitor::~BuildAstVisitor() {}

void BuildAstVisitor::AddImportFile(const std::string& fname) {
  import_files_.push_back(fname);
}

/************************************************************************************
* @fn GetCFlatToken
* @brief create CflatToken by antlr4 Token
* @param
* @author Jona
* @date 2020/12/15
************************************************************************************/
ast::CflatToken* BuildAstVisitor::GetCFlatToken(antlr4::Token* t) {
  return new ast::CflatToken(t->getText(), t->getTokenIndex(),
  t->getCharPositionInLine(), t->getStartIndex(), t->getStopIndex());
}

/************************************************************************************
* @fn visitCompilation_unit
* @brief the entry of cfg, root the concret syntax tree
* @param
* @author Jona
* @date 2020/12/15
************************************************************************************/
antlrcpp::Any BuildAstVisitor::visitCompilation_unit(SesameParser::Compilation_unitContext * ctx) {
  //ast::ASTNode* ast = new ast::ASTNode();
  auto import_ctx = ctx->import_stmt();
  for (auto& im : import_ctx) {
    auto import_fname_ctx = im->import_name();
    AddImportFile(tokens_->getText(import_fname_ctx));
  }

  auto top_defs_ctx = ctx->top_defs(); // maybe one of function variable strunct constant union
  ast::Declarations* def_decls = (ast::Declarations*)visit(top_defs_ctx);

  ast::CflatToken* token = GetCFlatToken(ctx->start);
  ast::ASTNode* ast = new ast::ASTNode(new ast::Location(filename_, token), def_decls);

  return (antlrcpp::Any)ast;
}

antlrcpp::Any BuildAstVisitor::visitTop_defs(SesameParser::Top_defsContext * ctx) {
  ast::Declarations* decls = new ast::Declarations();

  auto funcs = ctx->def_func();
  for (auto& f : funcs) {
    auto defined_f = (entity::DefinedFunction*)visit(f);
    decls->AddDefun(defined_f);
  }

  // def_vars 得到的是多个申明的变量
  auto vars = ctx->def_vars();
  for (auto& v : vars) {
    visit(v); // get list of defined variables

    for (auto& dv : defined_vars_) {
      decls->AddDefvar(dv);
    }
  }

  auto cons = ctx->def_const();
  for (auto c : cons) {
    auto defined_con = (entity::Constant*)visit(c);
    decls->AddConstant(defined_con);
  }

  auto def_structs_ctx = ctx->def_struct();
  for (auto& def_st : def_structs_ctx) {
    auto struct_node = (ast::StructTypeNode*)visit(def_st);
    decls->AddStruct(struct_node);
  }

  auto def_unions_ctx = ctx->def_union();
  for (auto& def_u : def_unions_ctx) {
    auto union_node = (ast::UnionTypeNode*)visit(def_u);
    decls->AddUnion(union_node);
  }

  auto def_typedef_ctx = ctx->s_typedef();
  for (auto& td : def_typedef_ctx) {
    auto def_td = (ast::TypeDefNode*)visit(td);
    decls->AddTypedef(def_td);
  }

  return (antlrcpp::Any)decls;
}

antlrcpp::Any BuildAstVisitor::visitDef_func(SesameParser::Def_funcContext * ctx) {
  bool priv = false;
  if (ctx->storage()) {
    priv = true;
  }

  std::string func_name = tokens_->getText(ctx->name());
  type::TypeRef* return_type = (type::TypeRef*)visit(ctx->typeref()); 

  entity::Params* func_params = nullptr;
  if (ctx->params()) {
    func_params = (entity::Params*)visit(ctx->params());
  }

  ast::BlockNode* body = (ast::BlockNode*)visit(ctx->block());

  type::TypeRef* tr = new type::FunctionTypeRef(return_type, func_params->GetParameterTypeRefs());
  return (antlrcpp::Any)(new entity::DefinedFunction(priv, new ast::TypeNode(tr), func_name, func_params, body));
}

// get TypeRef recursively
antlrcpp::Any BuildAstVisitor::visitTyperef(SesameParser::TyperefContext * ctx) {
  type::TypeRef* ref = (type::TypeRef*)visit(ctx->typeref_base());
  auto typeref_precise_ctx = ctx->typeref_precise();
  for (auto& tr : typeref_precise_ctx) {
    if (tr->INTEGER()) {
      // int [length]
      auto len_str = tr->INTEGER()->getText();
      long len = std::atol(len_str.c_str());
      ref = new type::ArrayTypeRef(ref, len);
    } else if (tr->ASTERISK()) {
      // pointer
      ref = new type::PointerTypeRef(ref);
    } else if (tr->param_typerefs()) {
      // function pointer, for example, int (char*, int, long [])
      type::ParamTypeRefs* params = (type::ParamTypeRefs*)visit(tr->param_typerefs());
      ref = new type::FunctionTypeRef(ref, params);
    } else {
      // []
      ref = new type::ArrayTypeRef(ref);
    }
  }

  return (antlrcpp::Any)ref;
}

antlrcpp::Any BuildAstVisitor::visitParams(SesameParser::ParamsContext * ctx) {
  if (ctx->S_VOID()) {
    ast::CflatToken* t = GetCFlatToken(ctx->start);
    std::vector<entity::Parameter*> parameters;
    return (antlrcpp::Any)(new entity::Params(new ast::Location(filename_, t), parameters));
  }

  entity::Params* pams = (entity::Params*)visit(ctx->fixed_params());
  if (ctx->CDOTS()) {
    pams->AcceptVararg();
  }

  return (antlrcpp::Any)pams;
}

antlrcpp::Any BuildAstVisitor::visitFixed_params(SesameParser::Fixed_paramsContext * ctx) {
  std::vector<entity::Parameter*> parameters;
  auto t = GetCFlatToken(ctx->start);

  auto params_ctx = ctx->param();
  for (auto& p : params_ctx) {
    entity::Parameter* pam = (entity::Parameter*)visit(p);
    parameters.push_back(pam);
  }

  return (antlrcpp::Any)(new entity::Params(new ast::Location(filename_, t), parameters));
}

antlrcpp::Any BuildAstVisitor::visitParam(SesameParser::ParamContext * ctx) {
  std::string param_name = tokens_->getText(ctx->name());
  ast::TypeNode* tn = (ast::TypeNode*)visit(ctx->type());

  return (antlrcpp::Any)(new entity::Parameter(tn, param_name));
}

antlrcpp::Any BuildAstVisitor::visitParam_typerefs(SesameParser::Param_typerefsContext * ctx) {
  if (ctx->S_VOID()) {
    std::vector<type::TypeRef*> trs;
    return (antlrcpp::Any)(new type::ParamTypeRefs(trs));
  } else {
    type::ParamTypeRefs* param_trs = (type::ParamTypeRefs*)visit(ctx->fixed_param_typerefs());
    if (ctx->CDOTS()) {
      param_trs->AcceptVararg();
    }

    return (antlrcpp::Any)param_trs;
  }
}

antlrcpp::Any BuildAstVisitor::visitType(SesameParser::TypeContext * ctx) {
  type::TypeRef* ref = (type::TypeRef*)visit(ctx->typeref());
  return new ast::TypeNode(ref);
}

antlrcpp::Any BuildAstVisitor::visitFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext * ctx) {
  std::vector<type::TypeRef*> refs;
  auto typerefs = ctx->typeref();
  for (auto& tr : typerefs) {
    type::TypeRef* tref = (type::TypeRef*)visit(tr);
    refs.push_back(tref);
  }
  
  return (antlrcpp::Any)(new type::ParamTypeRefs(refs));
}

antlrcpp::Any BuildAstVisitor::visitBlock(SesameParser::BlockContext * ctx) {
  // @todo[UNIMPLEMENT]/2020/12/16: not implement
}

/************************************************************************************
* @fn visitDef_vars
* @brief build ast for defined variables
* @param
* @author Jona
* @date 2020/12/15
************************************************************************************/
antlrcpp::Any BuildAstVisitor::visitDef_vars(SesameParser::Def_varsContext * ctx) {
  defined_vars_.clear();
  bool priv = false;
  if (ctx->storage()) {
    priv = true;
  }

  ast::TypeNode* var_type_node = (ast::TypeNode*)visit(ctx->type());
  auto assign_exprs_ctx = ctx->assign_expr();
  ast::ExprNode* init = nullptr;
  for (auto& expr : assign_exprs_ctx) {
    std::string var_name = tokens_->getText(expr->name());
    if (expr->expr()) {
      init = (ast::ExprNode*)visit(expr->expr());
    }
    entity::DefinedVariable* ass_expr = new entity::DefinedVariable(priv, var_type_node, var_name, init);
    defined_vars_.push_back(ass_expr);
    init = nullptr;
  }

  return (antlrcpp::Any)(&defined_vars_);
}

antlrcpp::Any BuildAstVisitor::visitDef_const(SesameParser::Def_constContext * ctx) {
  ast::TypeNode* tn = (ast::TypeNode*)visit(ctx->type());
  std::string con_name = tokens_->getText(ctx->name());
  ast::ExprNode* expr = (ast::ExprNode*)visit(ctx->expr());

  return (antlrcpp::Any)(new entity::Constant(tn, con_name, expr));
}

antlrcpp::Any BuildAstVisitor::visitDef_struct(SesameParser::Def_structContext * ctx) {
  ast::CflatToken* t = GetCFlatToken(ctx->start);
  std::string struct_name = tokens_->getText(ctx->name());
  visit(ctx->member_list());

  return (antlrcpp::Any)(new ast::StructTypeNode(new ast::Location(filename_, t), 
                                                 new type::StructTypeRef(struct_name), struct_name, 
                                                 member_list_));
}

antlrcpp::Any BuildAstVisitor::visitDef_union(SesameParser::Def_unionContext * ctx) {
  ast::CflatToken* t = GetCFlatToken(ctx->start);
  std::string union_name = tokens_->getText(ctx->name());
  visit(ctx->member_list());

  return (antlrcpp::Any)(new ast::UnionTypeNode(new ast::Location(filename_, t), 
                                                new type::UnionTypeRef(union_name), union_name, 
                                                member_list_));
}

antlrcpp::Any BuildAstVisitor::visitMember_list(SesameParser::Member_listContext * ctx) {
  member_list_.clear();
  auto slots_ctx = ctx->slot();
  for (auto& sl : slots_ctx) {
    ast::SlotNode* n = (ast::SlotNode*)visit(sl);
    member_list_.push_back(n);
  }

  return (antlrcpp::Any)(&member_list_);
}

antlrcpp::Any BuildAstVisitor::visitSlot(SesameParser::SlotContext * ctx) {
  ast::TypeNode* tn = (ast::TypeNode*)visit(ctx->type());
  std::string slot_name = tokens_->getText(ctx->name());

  return (antlrcpp::Any)(new ast::SlotNode(tn, slot_name));
}

antlrcpp::Any BuildAstVisitor::visitS_typedef(SesameParser::S_typedefContext * ctx) {
  std::string new_type_name = ctx->IDENTIFIER()->getText();
  ast::CflatToken* t = GetCFlatToken(ctx->start);
  type::TypeRef* tr = (type::TypeRef*)visit(ctx->typeref());

  return (antlrcpp::Any)(new ast::TypeDefNode(new ast::Location(filename_, t), tr, 
                                              new type::UserTypeRef(new_type_name), new_type_name));
}

/************************************************************************************
* @fn visitExpr
* @brief build ast for expression
* @param
* @author Jona
* @date 2020/12/15
************************************************************************************/
antlrcpp::Any BuildAstVisitor::visitAssignment_expr(SesameParser::Assignment_exprContext * ctx) {
  ast::ExprNode* lhs = (ast::ExprNode*)visit(ctx->term());
  ast::ExprNode* rhs = (ast::ExprNode*)visit(ctx->expr());;
  
  return (antlrcpp::Any)(new ast::AssignNode(lhs, rhs));
}

antlrcpp::Any BuildAstVisitor::visitOp_assign_expr(SesameParser::Op_assign_exprContext * ctx) {
  // binary expression
  ast::ExprNode *lhs = (ast::ExprNode *)visit(ctx->term());
  ast::ExprNode *rhs = (ast::ExprNode *)visit(ctx->expr());
  std::string op_str = tokens_->getText(ctx->opassign_op());

  return (antlrcpp::Any)(new ast::OpAssignNode(lhs, op_str, rhs));
}

antlrcpp::Any BuildAstVisitor::visitExpression_10(SesameParser::Expression_10Context * ctx) {
  return visit(ctx->expr10());
}

antlrcpp::Any BuildAstVisitor::visitExpr10(SesameParser::Expr10Context * ctx) {
  ast::ExprNode *cond = (ast::ExprNode *)visit(ctx->expr9());
  if (ctx->QUESTION()) {
    // 三目操作符
    ast::ExprNode* then_expr = (ast::ExprNode*)visit(ctx->expr());
    ast::ExprNode* else_expr = (ast::ExprNode*)visit(ctx->expr10());
    return (antlrcpp::Any)(new ast::CondExprNode(cond, then_expr, else_expr));
  }

  return (antlrcpp::Any)cond;
}

antlrcpp::Any BuildAstVisitor::visitExpr9(SesameParser::Expr9Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->logic_or_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr8());
    lhs_expr = new ast::LogicalOrNode(lhs_expr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr8(SesameParser::Expr8Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->logic_and_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr7());
    lhs_expr = new ast::LogicalAndNode(lhs_expr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr7(SesameParser::Expr7Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->binary_op_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr6());
    std::string opstr = tokens_->getText(rhs->logical_op());
    lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr6(SesameParser::Expr6Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->bit_or_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr5());
    std::string opstr = "|";
    lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr5(SesameParser::Expr5Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->xor_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr4());
    std::string opstr = "^";
    lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr4(SesameParser::Expr4Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->bit_and_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr3());
    std::string opstr = "&";
    lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr3(SesameParser::Expr3Context * ctx) {
  ast::ExprNode* lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->shift_op_rhs();
  for (auto& rhs : rhs_exprs) {
    auto r = (ast::ExprNode*)visit(rhs->expr2());
    std::string opstr;
    if (rhs->LSHIFT()) {
      opstr = rhs->LSHIFT()->getText();
    } else if (rhs->RSHIFT()) {
      opstr = rhs->RSHIFT()->getText();
    }

    lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr2(SesameParser::Expr2Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->add_sub_rhs();
  for (auto& rhs : rhs_exprs) {
    auto r = (ast::ExprNode*)visit(rhs->expr1());
    std::string opstr = rhs->tk->getText();
    lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr1(SesameParser::Expr1Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->multi_div_mod_rhs();
  for (auto& rhs : rhs_exprs) {
    auto r = (ast::ExprNode*)visit(rhs->term());
    std::string opstr = rhs->tk->getText();
    lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitTerm(SesameParser::TermContext * ctx) {
  if (ctx->unary()) {
    return visit(ctx->unary());
  }

  ast::TypeNode *tn = (ast::TypeNode *)visit(ctx->type());
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  return (antlrcpp::Any)(new ast::CastNode(tn, expr));
}

antlrcpp::Any BuildAstVisitor::visitInc_expr(SesameParser::Inc_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->unary());
  return (antlrcpp::Any)(new ast::PrefixOpNode("++", expr));
}

antlrcpp::Any BuildAstVisitor::visitDec_expr(SesameParser::Dec_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->unary());
  return (antlrcpp::Any)(new ast::PrefixOpNode("--", expr));
}

antlrcpp::Any BuildAstVisitor::visitPositive_expr(SesameParser::Positive_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  return (antlrcpp::Any)(new ast::UnaryOpNode("+", expr));
}

antlrcpp::Any BuildAstVisitor::visitNegative_expr(SesameParser::Negative_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  return (antlrcpp::Any)(new ast::UnaryOpNode("-", expr));
}

antlrcpp::Any BuildAstVisitor::visitLogic_not_expr(SesameParser::Logic_not_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  return (antlrcpp::Any)(new ast::UnaryOpNode("!", expr));
}

antlrcpp::Any BuildAstVisitor::visitBit_not_expr(SesameParser::Bit_not_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  return (antlrcpp::Any)(new ast::UnaryOpNode("~", expr));
}

antlrcpp::Any BuildAstVisitor::visitDereference_expr(SesameParser::Dereference_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  return (antlrcpp::Any)(new ast::DereferenceNode(expr));
}

antlrcpp::Any BuildAstVisitor::visitAddr_expr(SesameParser::Addr_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  return (antlrcpp::Any)(new ast::AddressNode(expr));
}

antlrcpp::Any BuildAstVisitor::visitSizeof_type_expr(SesameParser::Sizeof_type_exprContext * ctx) {
  ast::TypeNode *tn = (ast::TypeNode *)visit(ctx->type());
  return (antlrcpp::Any)(new ast::SizeofTypeNode(tn, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG)));
}

antlrcpp::Any BuildAstVisitor::visitSizeof_expr(SesameParser::Sizeof_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->unary());
  return (antlrcpp::Any)(new ast::SizeofExprNode(expr, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG)));
}

antlrcpp::Any BuildAstVisitor::visitUnary_postfix_expr(SesameParser::Unary_postfix_exprContext *ctx) {
  return visit(ctx->postfix());
}

antlrcpp::Any BuildAstVisitor::visitPostfix(SesameParser::PostfixContext * ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->primary());
  auto opts_ctx = ctx->postfix_option();

  for (auto& opt : opts_ctx) {
    if (opt->PLUS().size()) {
      // suffix ++
      expr = new ast::SuffixOpNode("++", expr);
    } 
  
    if (opt->MINUS().size()) {
      // suffix --
      expr = new ast::SuffixOpNode("--", expr);
    } 
  
    if (opt->expr()) {
      // array
      ast::ExprNode *idx = (ast::ExprNode *)visit(opt->expr());
      expr = new ast::ARefNode(expr, idx);
    } 
  
    if (opt->PERIOD()) {
      // member: .a
      std::string member_name = tokens_->getText(opt->memb1);
      expr = new ast::MemberNode(expr, member_name);
    } 
  
    if (opt->POINTER_REF()) {
      // member : ->a
      std::string member_name = tokens_->getText(opt->memb2);
      expr = new ast::PtrMemberNode(expr, member_name);
    } 
  
    if (opt->LPAREN() != nullptr) {
      // function args: (a, b, c)
      std::vector<ast::ExprNode *> arg_list;
      if (opt->args()) {
        auto args_ctx = opt->args();
        auto exprs_ctx = args_ctx->expr();
        for (auto& exp : exprs_ctx) {
          ast::ExprNode *e = (ast::ExprNode *)visit(exp);
          arg_list.push_back(e);
        }
      }

      expr = new ast::FuncallNode(expr, arg_list);
    }
  }

  return (antlrcpp::Any)expr;
}

} /* parser */
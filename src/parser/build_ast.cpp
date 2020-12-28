/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: build_ast.cpp
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/18
* @brief: antlrcpp::Any 类型转换，只能转换成同样的类型，有继承关系的类型都不能转换成功
*/
#include "build_ast.h"

#include "type/type_ref.hpp"
#include "ast/stmt/block_node.hpp"
#include "type/function_type_ref.hpp"
#include "type/array_type_ref.h"
#include "type/pointer_type_ref.h"
#include "type/struct_type_ref.h"
#include "type/union_type_ref.h"
#include "type/user_type_ref.hpp"
#include "type/void_type_ref.hpp"
#include "ast/slot.hpp"

// expr
#include "ast/expr/assign_node.hpp"
#include "ast/expr/op_assign_node.hpp"
#include "ast/expr/cond_expr_node.hpp"
#include "ast/expr/logical_or_node.hpp"
#include "ast/expr/logical_and_node.hpp"
#include "ast/expr/binary_op_node.hpp"
#include "ast/expr/cast_node.hpp"
#include "ast/expr/prefix_op_node.hpp"
#include "ast/expr/unary_op_node.hpp"
#include "ast/expr/dereference_node.hpp"
#include "ast/expr/address_node.hpp"
#include "ast/expr/sizeof_expr_node.hpp"
#include "ast/expr/sizeof_type_node.hpp"
#include "ast/expr/suffix_op_node.hpp"
#include "ast/expr/aref_node.hpp"
#include "ast/expr/member_node.hpp"
#include "ast/expr/ptr_member_node.hpp"
#include "ast/expr/funcall_node.hpp"
#include "ast/expr/string_literal_node.hpp"
#include "ast/expr/variable_node.hpp"

// stmt node
#include "ast/stmt/stmt_node.hpp"
#include "ast/stmt/block_node.hpp"
#include "ast/stmt/expr_stmt_node.hpp"
#include "ast/stmt/label_node.hpp"
#include "ast/stmt/if_node.hpp"
#include "ast/stmt/while_node.hpp"
#include "ast/stmt/do_while_node.hpp"
#include "ast/stmt/for_node.hpp"
#include "ast/stmt/switch_node.hpp"
#include "ast/stmt/case_node.hpp"
#include "ast/stmt/break_node.hpp"
#include "ast/stmt/continue_node.hpp"
#include "ast/stmt/goto_node.hpp"
#include "ast/stmt/return_node.hpp"

// import declarations
#include "ast/declarations.hpp"
#include "entity/undefined_function.h"
#include "entity/undefined_variable.h"

// utils
#include "utils/string_utils.hpp"

#include <regex>

namespace parser {
BuildAstVisitor::BuildAstVisitor(SesameParser* parser, std::string fname) 
  : parser_(parser), filename_(fname) {
    tokens_ = parser_->getTokenStream();
  }

BuildAstVisitor::~BuildAstVisitor() {
  node_tracker_.Reset();
  entity_tracker_.Reset();
  type_tracker_.Reset();
  typeref_tracker_.Reset();
  location_tracker_.Reset();
  
  params_tracker_.Reset();
  param_types_tracker_.Reset();
  param_typeref_tracker_.Reset();
}

void BuildAstVisitor::AddImportFile(const std::string& fname) {
  import_files_.push_back(fname);
}

std::vector<std::string> BuildAstVisitor::import_files() {
  return import_files_;
}

/************************************************************************************
* @fn GetIntegerValue
* @brief get long value from string of hex, oct or dec format
* @param str is a format string like dec, hex or oct
* @author Jona
* @date 2020/12/17
************************************************************************************/
long BuildAstVisitor::GetIntegerValue(std::string str, ast::Location *l) {
  // dec: 123UL, 123U, 123L
  // hex: 0x123, 0X123
  // oct: 0123
  if (str.empty() || utils::StringUtils::StrCmp(str, "0")) {
    return 0;
  }

  std::regex int_reg("[^0xX][0-9]*");
  std::smatch int_match;
  if (std::regex_search(str, int_match, int_reg)) {
    if(int_match.size() > 1) {
      std::cout << "Error: at " << l->ToString() << ", " << str << " is not an integer number" << std::endl;
      // exit program directly, because you don't know what will happen next.
      exit(EXIT_FAILURE);
    } else {
      return std::atol(int_match.str().c_str());
    }
  } else {
    std::cout << "Error: at " << l->ToString() << ", " << str << " is not an integer number" << std::endl;
    exit(EXIT_FAILURE);
  }
}

ast::IntegerLiteralNode* BuildAstVisitor::GetIntegerNode(ast::Location *l, std::string str) {
  long val = GetIntegerValue(str, l);
  std::size_t len = str.length();
  if (str.at(len-1) == 'L' || str.at(len-1) == 'l') {
    if (str.at(len-2) == 'U' || str.at(len-2) == 'u') {
      // UL
      // return new ast::IntegerLiteralNode(l, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG), val);
      auto int_type_ref = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG);
      return node_tracker_.CreateInstance<ast::IntegerLiteralNode>(l, int_type_ref, val);
    } else {
      // L
      // return new ast::IntegerLiteralNode(l, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_LONG), val);
      auto int_type_ref = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_LONG);
      return node_tracker_.CreateInstance<ast::IntegerLiteralNode>(l, int_type_ref, val);
    }
  } else if (str.at(len-1) == 'U' || str.at(len-1) == 'u') {
    // U
    // return new ast::IntegerLiteralNode(l, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_UINT), val);
    auto int_type_ref = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT);
    return node_tracker_.CreateInstance<ast::IntegerLiteralNode>(l, int_type_ref, val);
  } else {
    // return new ast::IntegerLiteralNode(l, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT), val);
    auto int_type_ref = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT);
    return node_tracker_.CreateInstance<ast::IntegerLiteralNode>(l, int_type_ref, val);
  }
}

long BuildAstVisitor::GetCharValue(const std::string& str, ast::Location *l) {
  // char is like 'a'
  if (str.length() > 3) {
    std::cout << "Error: at " << l->ToString() << ", " << str << " is not character" << std::endl;
    exit(EXIT_FAILURE);
  }

  return (long)(str.at(1));
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
  t->getLine(), t->getStartIndex(), t->getStopIndex(), t->getCharPositionInLine());
}

type::TypeRef* BuildAstVisitor::GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass cls, ast::Location* loc) {
  type::TypeRef* res;
  if (nullptr == loc) {
    res = type::IntegerTypeRef::GetIntegerTypeClass(cls);
  } else {
    res = type::IntegerTypeRef::GetIntegerTypeClass(cls, loc);
  }

  typeref_tracker_.AddInstance(res);
  return res;
}

ast::Location* BuildAstVisitor::GetLocation(ast::CflatToken* t) {
  return location_tracker_.CreateInstance<ast::Location>(filename_, t);
}

/************************************************************************************
* @fn visitCompilation_unit
* @brief the entry of cfg, root the concret syntax tree
* @param
* @author Jona
* @date 2020/12/15
************************************************************************************/
antlrcpp::Any BuildAstVisitor::visitCompilation_unit(SesameParser::Compilation_unitContext * ctx) {
  auto import_ctx = ctx->import_stmt();
  for (auto& im : import_ctx) {
    auto import_fname_ctx = im->import_name();
    AddImportFile(tokens_->getText(import_fname_ctx));
  }

  auto top_defs_ctx = ctx->top_defs(); // maybe one of function variable strunct constant union
  ast::Declarations* def_decls = (ast::Declarations*)visit(top_defs_ctx);

  ast::CflatToken* token = GetCFlatToken(ctx->start);
  // ast::ASTNode* ast = new ast::ASTNode(new ast::Location(filename_, token), def_decls);
  auto loc = location_tracker_.CreateInstance<ast::Location>(filename_, token);
  ast::ASTNode* ast = node_tracker_.CreateInstance<ast::ASTNode>(loc, def_decls);

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

  // type::TypeRef* tr = new type::FunctionTypeRef(return_type, func_params->GetParameterTypeRefs());
  // return (antlrcpp::Any)(new entity::DefinedFunction(priv, new ast::TypeNode(tr), func_name, func_params, body));
  type::TypeRef* tr = typeref_tracker_.CreateInstance<type::FunctionTypeRef>(return_type, func_params->GetParameterTypeRefs());
  auto tn = node_tracker_.CreateInstance<ast::TypeNode>(tr);
  return (antlrcpp::Any)(entity_tracker_.CreateInstance<entity::DefinedFunction>(priv, tn, func_name, func_params, body));
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
      // ref = new type::ArrayTypeRef(ref, len);
      ref = typeref_tracker_.CreateInstance<type::ArrayTypeRef>(ref, len);
    } else if (tr->ASTERISK()) {
      // pointer
      ref = typeref_tracker_.CreateInstance<type::PointerTypeRef>(ref);
    } else if (tr->param_typerefs()) {
      // function pointer, for example, int (char*, int, long [])
      type::ParamTypeRefs* params = (type::ParamTypeRefs*)visit(tr->param_typerefs());
      ref = typeref_tracker_.CreateInstance<type::FunctionTypeRef>(ref, params);
    } else {
      // []
      ref = typeref_tracker_.CreateInstance<type::ArrayTypeRef>(ref);
    }
  }

  return (antlrcpp::Any)ref;
}

antlrcpp::Any BuildAstVisitor::visitTyperef_void(SesameParser::Typeref_voidContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  type::TypeRef* res = typeref_tracker_.CreateInstance<type::VoidTypeRef>(loc);
  return (antlrcpp::Any)res;
}

antlrcpp::Any BuildAstVisitor::visitTyperef_char(SesameParser::Typeref_charContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  auto res = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_CHAR, loc);
  return (antlrcpp::Any)res;
}

antlrcpp::Any BuildAstVisitor::visitTyperef_short(SesameParser::Typeref_shortContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  // type::TypeRef* res = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_SHORT, new ast::Location(filename_, t));
  auto res = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_SHORT, loc);
  return (antlrcpp::Any)res;
}

antlrcpp::Any BuildAstVisitor::visitTyperef_int(SesameParser::Typeref_intContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  // type::TypeRef* res = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT, new ast::Location(filename_, t));

  auto res = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT, loc);
  return (antlrcpp::Any)res;
}

antlrcpp::Any BuildAstVisitor::visitTyperef_long(SesameParser::Typeref_longContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  // type::TypeRef* res = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_LONG, new ast::Location(filename_, t));

  auto res = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_LONG, loc);
  return (antlrcpp::Any)res;
}

antlrcpp::Any BuildAstVisitor::visitTyperef_unsigned(SesameParser::Typeref_unsignedContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  type::TypeRef* res = nullptr;

  if (ctx->S_CHAR()) {
    // res = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_UCHAR, new ast::Location(filename_, t));
    res = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_UCHAR, loc);
  } else if (ctx->S_SHORT()) {
    // res = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_USHORT, new ast::Location(filename_, t));
    res = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_USHORT, loc);
  } else if (ctx->S_INT()) {
    // res = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_UINT, new ast::Location(filename_, t));
    res = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_UINT, loc);
  } else if (ctx->S_LONG()) {
    // res = type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG, new ast::Location(filename_, t));
    res = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG, loc);
  }

  return (antlrcpp::Any)res;
}

antlrcpp::Any BuildAstVisitor::visitTyperef_struct(SesameParser::Typeref_structContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  std::string name = ctx->IDENTIFIER()->getText();
  // return (antlrcpp::Any)((type::TypeRef *)(new type::StructTypeRef(new ast::Location(filename_, t), name)));
  return (antlrcpp::Any)((type::TypeRef *)(typeref_tracker_.CreateInstance<type::StructTypeRef>(loc, name)));
}

antlrcpp::Any BuildAstVisitor::visitTyperef_union(SesameParser::Typeref_unionContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  std::string name = ctx->IDENTIFIER()->getText();
  // return (antlrcpp::Any)((type::TypeRef *)(new type::UnionTypeRef(new ast::Location(filename_, t), name)));
  return (antlrcpp::Any)((type::TypeRef *)(typeref_tracker_.CreateInstance<type::UnionTypeRef>(loc, name)));
}

antlrcpp::Any BuildAstVisitor::visitTyperef_usertype(SesameParser::Typeref_usertypeContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  std::string user_type_name = ctx->IDENTIFIER()->getText();
  // return (antlrcpp::Any)((type::TypeRef *)(new type::UserTypeRef(new ast::Location(filename_, t), user_type_name)));
  return (antlrcpp::Any)((type::TypeRef *)(typeref_tracker_.CreateInstance<type::UserTypeRef>(loc, user_type_name)));
}

antlrcpp::Any BuildAstVisitor::visitParams(SesameParser::ParamsContext * ctx) {
  if (ctx->S_VOID()) {
    auto loc = GetLocation(GetCFlatToken(ctx->start));
    std::vector<entity::Parameter*> parameters;
    // return (antlrcpp::Any)(new entity::Params(new ast::Location(filename_, t), parameters));
    return (antlrcpp::Any)(params_tracker_.CreateInstance<entity::Params>(loc, parameters));
  }

  entity::Params* pams = (entity::Params*)visit(ctx->fixed_params());
  if (ctx->CDOTS()) {
    pams->AcceptVararg();
  }

  return (antlrcpp::Any)pams;
}

antlrcpp::Any BuildAstVisitor::visitFixed_params(SesameParser::Fixed_paramsContext * ctx) {
  std::vector<entity::Parameter*> parameters;
  auto loc = GetLocation(GetCFlatToken(ctx->start));

  auto params_ctx = ctx->param();
  for (auto& p : params_ctx) {
    entity::Parameter* pam = (entity::Parameter*)visit(p);
    parameters.push_back(pam);
  }

  // return (antlrcpp::Any)(new entity::Params(new ast::Location(filename_, t), parameters));
  return (antlrcpp::Any)(params_tracker_.CreateInstance<entity::Params>(loc, parameters));
}

antlrcpp::Any BuildAstVisitor::visitParam(SesameParser::ParamContext * ctx) {
  std::string param_name = tokens_->getText(ctx->name());
  ast::TypeNode* tn = (ast::TypeNode*)visit(ctx->type());

  // return (antlrcpp::Any)(new entity::Parameter(tn, param_name));
  return (antlrcpp::Any)(entity_tracker_.CreateInstance<entity::Parameter>(tn, param_name));
}

antlrcpp::Any BuildAstVisitor::visitParam_typerefs(SesameParser::Param_typerefsContext * ctx) {
  if (ctx->S_VOID()) {
    std::vector<type::TypeRef*> trs;
    // return (antlrcpp::Any)(new type::ParamTypeRefs(trs));
    return (antlrcpp::Any)(param_typeref_tracker_.CreateInstance<type::ParamTypeRefs>(trs));
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
  // return (antlrcpp::Any)(new ast::TypeNode(ref));
  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::TypeNode>(ref));
}

antlrcpp::Any BuildAstVisitor::visitFixed_param_typerefs(SesameParser::Fixed_param_typerefsContext * ctx) {
  std::vector<type::TypeRef*> refs;
  auto typerefs = ctx->typeref();
  for (auto& tr : typerefs) {
    type::TypeRef* tref = (type::TypeRef*)visit(tr);
    refs.push_back(tref);
  }
  
  // return (antlrcpp::Any)(new type::ParamTypeRefs(refs));
  return (antlrcpp::Any)(param_typeref_tracker_.CreateInstance<type::ParamTypeRefs>(refs));
}

antlrcpp::Any BuildAstVisitor::visitBlock(SesameParser::BlockContext * ctx) {
  std::vector<entity::DefinedVariable *> defined_var_list; 
  auto def_vars_list = ctx->def_vars();
  for (auto& def_var : def_vars_list) {
    visit(def_var);
    for (auto& var : defined_vars_) {
      defined_var_list.push_back(var);
    }
  }

  auto stmts_ctx = ctx->stmts();
  std::vector<ast::StmtNode *> stmt_list;
  auto stmt_list_ctx = stmts_ctx->stmt();
  for (auto& st : stmt_list_ctx) {
    if (utils::StringUtils::StrCmp(st->getText(), ";")) {
      // empty statement
      continue;
    }
    ast::StmtNode* s = (ast::StmtNode *)visit(st);
    stmt_list.push_back(s);
  }

  ast::CflatToken* t = GetCFlatToken(ctx->start);
  auto loc = location_tracker_.CreateInstance<ast::Location>(filename_, t);
  // return (antlrcpp::Any)(new ast::BlockNode(new ast::Location(filename_, t), defined_var_list, stmt_list));
  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::BlockNode>(loc, defined_var_list, stmt_list));
}

antlrcpp::Any BuildAstVisitor::visitBlock_stmt(SesameParser::Block_stmtContext * ctx) {
  ast::BlockNode* bn = (ast::BlockNode *)visit(ctx->block());
  return (antlrcpp::Any)((ast::StmtNode *)bn);
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
    // entity::DefinedVariable* ass_expr = new entity::DefinedVariable(priv, var_type_node, var_name, init);
    entity::DefinedVariable* ass_expr = entity_tracker_.CreateInstance<entity::DefinedVariable>(priv, var_type_node, var_name, init);
    defined_vars_.push_back(ass_expr);
    init = nullptr;
  }

  return (antlrcpp::Any)(&defined_vars_);
}

antlrcpp::Any BuildAstVisitor::visitDef_const(SesameParser::Def_constContext * ctx) {
  ast::TypeNode* tn = (ast::TypeNode*)visit(ctx->type());
  std::string con_name = tokens_->getText(ctx->name());
  ast::ExprNode* expr = (ast::ExprNode*)visit(ctx->expr());

  // return (antlrcpp::Any)(new entity::Constant(tn, con_name, expr));
  return (antlrcpp::Any)(entity_tracker_.CreateInstance<entity::Constant>(tn, con_name, expr));
}

antlrcpp::Any BuildAstVisitor::visitDef_struct(SesameParser::Def_structContext * ctx) {
  ast::CflatToken* t = GetCFlatToken(ctx->start);
  auto loc = location_tracker_.CreateInstance<ast::Location>(filename_, t);
  std::string struct_name = tokens_->getText(ctx->name());
  auto struct_type_ref = typeref_tracker_.CreateInstance<type::StructTypeRef>(struct_name);
  visit(ctx->member_list());

  // return (antlrcpp::Any)(new ast::StructTypeNode(new ast::Location(filename_, t), 
  //                                                new type::StructTypeRef(struct_name), struct_name, 
  //                                                member_list_));
  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::StructTypeNode>(loc, struct_type_ref, struct_name, member_list_));
}

antlrcpp::Any BuildAstVisitor::visitDef_union(SesameParser::Def_unionContext * ctx) {
  ast::CflatToken* t = GetCFlatToken(ctx->start);
  auto loc = location_tracker_.CreateInstance<ast::Location>(filename_, t);
  std::string union_name = tokens_->getText(ctx->name());
  auto union_type_ref = typeref_tracker_.CreateInstance<type::UnionTypeRef>(union_name);
  visit(ctx->member_list());

  // return (antlrcpp::Any)(new ast::UnionTypeNode(new ast::Location(filename_, t), 
  //                                               new type::UnionTypeRef(union_name), union_name, 
  //                                               member_list_));
  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::UnionTypeNode>(loc, union_type_ref, union_name, member_list_));
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

  // return (antlrcpp::Any)(new ast::SlotNode(tn, slot_name));
  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::SlotNode>(tn, slot_name));
}

antlrcpp::Any BuildAstVisitor::visitS_typedef(SesameParser::S_typedefContext * ctx) {
  std::string new_type_name = ctx->IDENTIFIER()->getText();
  ast::CflatToken* t = GetCFlatToken(ctx->start);
  auto loc = location_tracker_.CreateInstance<ast::Location>(filename_, t);
  type::TypeRef* tr = (type::TypeRef*)visit(ctx->typeref());
  auto user_type_ref = typeref_tracker_.CreateInstance<type::UserTypeRef>(new_type_name);

  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::TypeDefNode>(loc, tr, user_type_ref, new_type_name));

  // return (antlrcpp::Any)(new ast::TypeDefNode(new ast::Location(filename_, t), tr, 
  //                                             new type::UserTypeRef(new_type_name), new_type_name));
}

/************************************************************************************
* @fn 
* @brief build ast for expression
* @param
* @author Jona
* @date 2020/12/15
************************************************************************************/
antlrcpp::Any BuildAstVisitor::visitAssignment_expr(SesameParser::Assignment_exprContext * ctx) {
  ast::ExprNode* lhs = (ast::ExprNode*)visit(ctx->term());
  ast::ExprNode* rhs = (ast::ExprNode*)visit(ctx->expr());;
  
  // ast::ExprNode* res = new ast::AssignNode(lhs, rhs);
  ast::ExprNode* res = node_tracker_.CreateInstance<ast::AssignNode>(lhs, rhs);
  return (antlrcpp::Any)res;
}

antlrcpp::Any BuildAstVisitor::visitOp_assign_expr(SesameParser::Op_assign_exprContext * ctx) {
  // binary expression
  ast::ExprNode *lhs = (ast::ExprNode *)visit(ctx->term());
  ast::ExprNode *rhs = (ast::ExprNode *)visit(ctx->expr());
  std::string op_str = tokens_->getText(ctx->opassign_op());

  // ast::ExprNode* res = new ast::OpAssignNode(lhs, op_str, rhs);
  ast::ExprNode* res = node_tracker_.CreateInstance<ast::OpAssignNode>(lhs, op_str, rhs);
  return (antlrcpp::Any)res;
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
    // return (antlrcpp::Any)((ast::ExprNode *)(new ast::CondExprNode(cond, then_expr, else_expr)));
    return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::CondExprNode>(cond, then_expr, else_expr)));
  }

  return (antlrcpp::Any)cond;
}

antlrcpp::Any BuildAstVisitor::visitExpr9(SesameParser::Expr9Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->logic_or_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr8());
    // lhs_expr = new ast::LogicalOrNode(lhs_expr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::LogicalOrNode>(lhs_expr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr8(SesameParser::Expr8Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->logic_and_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr7());
    // lhs_expr = new ast::LogicalAndNode(lhs_expr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::LogicalAndNode>(lhs_expr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr7(SesameParser::Expr7Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->binary_op_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr6());
    std::string opstr = tokens_->getText(rhs->logical_op());
    // lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::BinaryOpNode>(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr6(SesameParser::Expr6Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->bit_or_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr5());
    std::string opstr = "|";
    // lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::BinaryOpNode>(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr5(SesameParser::Expr5Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->xor_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr4());
    std::string opstr = "^";
    // lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::BinaryOpNode>(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr4(SesameParser::Expr4Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->bit_and_rhs();
  for (auto& rhs : rhs_exprs) {
    ast::ExprNode* r = (ast::ExprNode*)visit(rhs->expr3());
    std::string opstr = "&";
    // lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::BinaryOpNode>(lhs_expr, opstr, r);
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

    // lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::BinaryOpNode>(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr2(SesameParser::Expr2Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->add_sub_rhs();
  for (auto& rhs : rhs_exprs) {
    auto r = (ast::ExprNode*)visit(rhs->expr1());
    std::string opstr = rhs->tk->getText();
    // lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::BinaryOpNode>(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitExpr1(SesameParser::Expr1Context * ctx) {
  ast::ExprNode *lhs_expr = (ast::ExprNode *)visit(ctx->lhs);
  auto rhs_exprs = ctx->multi_div_mod_rhs();
  for (auto& rhs : rhs_exprs) {
    auto r = (ast::ExprNode*)visit(rhs->term());
    std::string opstr = rhs->tk->getText();
    // lhs_expr = new ast::BinaryOpNode(lhs_expr, opstr, r);
    lhs_expr = node_tracker_.CreateInstance<ast::BinaryOpNode>(lhs_expr, opstr, r);
  }

  return (antlrcpp::Any)lhs_expr;
}

antlrcpp::Any BuildAstVisitor::visitTerm(SesameParser::TermContext * ctx) {
  if (ctx->unary()) {
    return visit(ctx->unary());
  }

  ast::TypeNode *tn = (ast::TypeNode *)visit(ctx->type());
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  // return (antlrcpp::Any)((ast::ExprNode *)(new ast::CastNode(tn, expr)));
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::CastNode>(tn, expr)));
}

antlrcpp::Any BuildAstVisitor::visitInc_expr(SesameParser::Inc_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->unary());
  // return (antlrcpp::Any)((ast::ExprNode *)(new ast::PrefixOpNode("++", expr)));
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::PrefixOpNode>("++", expr)));
}

antlrcpp::Any BuildAstVisitor::visitDec_expr(SesameParser::Dec_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->unary());
  // return (antlrcpp::Any)((ast::ExprNode *)(new ast::PrefixOpNode("--", expr)));
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::PrefixOpNode>("--", expr)));
}

antlrcpp::Any BuildAstVisitor::visitPositive_expr(SesameParser::Positive_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  // return (antlrcpp::Any)((ast::ExprNode *)(new ast::UnaryOpNode("+", expr)));
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::UnaryOpNode>("+", expr)));
}

antlrcpp::Any BuildAstVisitor::visitNegative_expr(SesameParser::Negative_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  // return (antlrcpp::Any)((ast::ExprNode *)(new ast::UnaryOpNode("-", expr)));
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::UnaryOpNode>("-", expr)));
}

antlrcpp::Any BuildAstVisitor::visitLogic_not_expr(SesameParser::Logic_not_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::UnaryOpNode>("!", expr)));
}

antlrcpp::Any BuildAstVisitor::visitBit_not_expr(SesameParser::Bit_not_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  // return (antlrcpp::Any)((ast::ExprNode *)(new ast::UnaryOpNode("~", expr)));
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::UnaryOpNode>("~", expr)));
}

antlrcpp::Any BuildAstVisitor::visitDereference_expr(SesameParser::Dereference_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  // return (antlrcpp::Any)((ast::ExprNode *)(new ast::DereferenceNode(expr)));
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::DereferenceNode>(expr)));
}

antlrcpp::Any BuildAstVisitor::visitAddr_expr(SesameParser::Addr_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->term());
  // return (antlrcpp::Any)((ast::ExprNode *)(new ast::AddressNode(expr)));
  return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::AddressNode>(expr)));
}

antlrcpp::Any BuildAstVisitor::visitSizeof_type_expr(SesameParser::Sizeof_type_exprContext * ctx) {
  ast::TypeNode *tn = (ast::TypeNode *)visit(ctx->type());
  // ast::ExprNode* res = new ast::SizeofTypeNode(tn, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG));
  type::TypeRef* int_type_ref = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG);
  ast::ExprNode* res = node_tracker_.CreateInstance<ast::SizeofTypeNode>(tn, int_type_ref);
  return (antlrcpp::Any)res;
}

antlrcpp::Any BuildAstVisitor::visitSizeof_expr(SesameParser::Sizeof_exprContext *ctx) {
  ast::ExprNode *expr = (ast::ExprNode *)visit(ctx->unary());
  // ast::ExprNode* res = new ast::SizeofExprNode(expr, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG));
  type::TypeRef* int_type_ref = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG);
  ast::ExprNode* res = node_tracker_.CreateInstance<ast::SizeofExprNode>(expr, int_type_ref);
  return (antlrcpp::Any)res;
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
      // expr = new ast::SuffixOpNode("++", expr);
      expr = node_tracker_.CreateInstance<ast::SuffixOpNode>("++", expr);
    } 
  
    if (opt->MINUS().size()) {
      // suffix --
      // expr = new ast::SuffixOpNode("--", expr);
      expr = node_tracker_.CreateInstance<ast::SuffixOpNode>("--", expr);
    } 
  
    if (opt->expr()) {
      // array
      ast::ExprNode *idx = (ast::ExprNode *)visit(opt->expr());
      // expr = new ast::ARefNode(expr, idx);
      expr = node_tracker_.CreateInstance<ast::ARefNode>(expr, idx);
    } 
  
    if (opt->PERIOD()) {
      // member: .a
      std::string member_name = tokens_->getText(opt->memb1);
      // expr = new ast::MemberNode(expr, member_name);
      expr = node_tracker_.CreateInstance<ast::MemberNode>(expr, member_name);
    } 
  
    if (opt->POINTER_REF()) {
      // member : ->a
      std::string member_name = tokens_->getText(opt->memb2);
      // expr = new ast::PtrMemberNode(expr, member_name);
      expr = node_tracker_.CreateInstance<ast::PtrMemberNode>(expr, member_name);
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

      // expr = new ast::FuncallNode(expr, arg_list);
      expr = node_tracker_.CreateInstance<ast::FuncallNode>(expr, arg_list);
    }
  }

  return (antlrcpp::Any)expr;
}

antlrcpp::Any BuildAstVisitor::visitPrimary(SesameParser::PrimaryContext * ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));

  if (ctx->S_CHARACTER()) {
    // return (antlrcpp::Any)((ast::ExprNode *)(new ast::IntegerLiteralNode(l, type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_CHAR), GetCharValue(ctx->S_CHARACTER()->getText(), l))));
    auto int_type_ref = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_CHAR);
    return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::IntegerLiteralNode>(loc, int_type_ref, GetCharValue(ctx->S_CHARACTER()->getText(), loc))));
  }

  if (ctx->S_STRING()) {
    // return (antlrcpp::Any)((ast::ExprNode *)(new ast::StringLiteralNode(loc, new type::PointerTypeRef(type::IntegerTypeRef::GetIntegerTypeClass(type::IntegerTypeRef::IntegerTypeClass::SESAME_CHAR)), ctx->S_STRING()->getText())));
    auto int_type_ref = GetIntegerTypeRef(type::IntegerTypeRef::IntegerTypeClass::SESAME_CHAR);
    return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::StringLiteralNode>(loc, int_type_ref, ctx->S_STRING()->getText())));
  }

  if (ctx->IDENTIFIER()) {
    // return (antlrcpp::Any)((ast::ExprNode *)(new ast::VariableNode(loc, ctx->IDENTIFIER()->getText())));
    return (antlrcpp::Any)((ast::ExprNode *)(node_tracker_.CreateInstance<ast::VariableNode>(loc, ctx->IDENTIFIER()->getText())));
  }

  if (ctx->expr()) {
    return visit(ctx->expr());
  }

  // INTEGER, HEX, OCT
  return (antlrcpp::Any)((ast::ExprNode *)GetIntegerNode(loc, tokens_->getText(ctx)));
}

/************************************************************************************
* @fn 
* @brief build ast for statement
* @param
* @author Jona
* @date 2020/12/17
************************************************************************************/
antlrcpp::Any BuildAstVisitor::visitExpr_stmt(SesameParser::Expr_stmtContext* ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  ast::ExprNode *e = (ast::ExprNode *)visit(ctx->expr());
  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::ExprStmtNode(new ast::Location(filename_, t), e)));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::ExprStmtNode>(loc, e)));
}

antlrcpp::Any BuildAstVisitor::visitLabeled_stmt(SesameParser::Labeled_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  auto stmt_node = (ast::StmtNode *)visit(ctx->stmt());
  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::LabelNode(new ast::Location(filename_, t), ctx->label_name->getText(), stmt_node)));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::LabelNode>(loc, ctx->label_name->getText(), stmt_node)));
}

antlrcpp::Any BuildAstVisitor::visitIf_stmt(SesameParser::If_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  ast::ExprNode* cond = (ast::ExprNode *)visit(ctx->expr());
  ast::StmtNode* then_body = (ast::StmtNode *)visit(ctx->then_stmt);
  ast::StmtNode* else_body = nullptr;

  if (ctx->else_stmt) {
    else_body = (ast::StmtNode *)visit(ctx->else_stmt);
  }

  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::IfNode(new ast::Location(filename_, t), cond, then_body, else_body)));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::IfNode>(loc, cond, then_body, else_body)));
}

antlrcpp::Any BuildAstVisitor::visitWhile_stmt(SesameParser::While_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  ast::ExprNode* cond = (ast::ExprNode *)visit(ctx->expr());
  ast::StmtNode* st = (ast::StmtNode *)visit(ctx->stmt());

  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::WhileNode(new ast::Location(filename_, t), cond, st)));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::WhileNode>(loc, cond, st)));
}

antlrcpp::Any BuildAstVisitor::visitDo_while_stmt(SesameParser::Do_while_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  auto e = (ast::ExprNode *)visit(ctx->cond);
  auto st = (ast::StmtNode *)visit(ctx->body);

  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::DoWhileNode(new ast::Location(filename_, t), st, e)));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::DoWhileNode>(loc, st, e)));
}

antlrcpp::Any BuildAstVisitor::visitFor_stmt(SesameParser::For_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  ast::ExprNode* init_expr = nullptr;
  ast::ExprNode* cond_expr = nullptr;

  if (ctx->init) {
    init_expr = (ast::ExprNode *)visit(ctx->init);
  }

  if (ctx->cond) {
    cond_expr = (ast::ExprNode *)visit(ctx->cond);
  }

  ast::ExprNode* incr_expr = (ast::ExprNode *)visit(ctx->incr);
  ast::StmtNode* st = (ast::StmtNode *)visit(ctx->body);

  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::ForNode(new ast::Location(filename_, t), init_expr, cond_expr, incr_expr, st)));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::ForNode>(loc, init_expr, cond_expr, incr_expr, st)));
}

antlrcpp::Any BuildAstVisitor::visitSwitch_stmt(SesameParser::Switch_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  ast::ExprNode* cond_expr = (ast::ExprNode *)visit(ctx->cond);

  auto case_clauses_ctx = ctx->case_clauses();
  auto case_list_ctx = case_clauses_ctx->case_clause();
  auto default_case_ctx = case_clauses_ctx->default_clause();

  std::vector<ast::CaseNode *> case_node_list;
  for (auto& c : case_list_ctx) {
    ast::CaseNode* cn = (ast::CaseNode *)visit(c);
    case_node_list.push_back(cn);
  }

  if (default_case_ctx) {
    ast::CaseNode* cn = (ast::CaseNode *)visit(default_case_ctx);
    case_node_list.push_back(cn);
  }

  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::SwitchNode(new ast::Location(filename_, t), cond_expr, case_node_list)));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::SwitchNode>(loc, cond_expr, case_node_list)));
}

antlrcpp::Any BuildAstVisitor::visitCase_clause(SesameParser::Case_clauseContext * ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  auto cases_ctx = ctx->cases();
  auto primary_ctx = cases_ctx->primary();

  std::vector<ast::ExprNode *> expr_list;
  for (auto& p : primary_ctx) {
    ast::ExprNode* e = (ast::ExprNode *)visit(p);
    expr_list.push_back(e);
  }

  ast::BlockNode* bn = (ast::BlockNode *)visit(ctx->body);
  // return (antlrcpp::Any)(new ast::CaseNode(new ast::Location(filename_, t), expr_list, bn));
  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::CaseNode>(loc, expr_list, bn));
}

antlrcpp::Any BuildAstVisitor::visitCase_body(SesameParser::Case_bodyContext * ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  auto stmts_ctx = ctx->stmt();
  std::vector<ast::StmtNode *> stmt_list;
  std::vector<entity::DefinedVariable *> def_vars;

  for (auto& st : stmts_ctx) {
    ast::StmtNode* s = (ast::StmtNode *)visit(st);
    stmt_list.push_back(s);
  }

  // return (antlrcpp::Any)(new ast::BlockNode(new ast::Location(filename_, t), def_vars, stmt_list));
  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::BlockNode>(loc, def_vars, stmt_list));
}

antlrcpp::Any BuildAstVisitor::visitDefault_clause(SesameParser::Default_clauseContext * ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  std::vector<ast::ExprNode *> expr_list;
  auto bn = (ast::BlockNode *)visit(ctx->body);
  // return (antlrcpp::Any)(new ast::CaseNode(new ast::Location(filename_, t), expr_list, bn));
  return (antlrcpp::Any)(node_tracker_.CreateInstance<ast::CaseNode>(loc, expr_list, bn));
}

antlrcpp::Any BuildAstVisitor::visitBreak_stmt(SesameParser::Break_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::BreakNode(new ast::Location(filename_, t))));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::BreakNode>(loc)));
}

antlrcpp::Any BuildAstVisitor::visitContinue_stmt(SesameParser::Continue_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::ContinueNode(new ast::Location(filename_, t))));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::ContinueNode>(loc)));
}

antlrcpp::Any BuildAstVisitor::visitGoto_stmt(SesameParser::Goto_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::GotoNode(new ast::Location(filename_, t), ctx->label_name->getText())));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::GotoNode>(loc, ctx->label_name->getText())));
}

antlrcpp::Any BuildAstVisitor::visitReturn_stmt(SesameParser::Return_stmtContext *ctx) {
  auto loc = GetLocation(GetCFlatToken(ctx->start));
  ast::ExprNode* e = nullptr;

  if (ctx->expr()) {
    e = (ast::ExprNode *)visit(ctx->expr());
  }

  // return (antlrcpp::Any)((ast::StmtNode *)(new ast::ReturnNode(new ast::Location(filename_, t), e)));
  return (antlrcpp::Any)((ast::StmtNode *)(node_tracker_.CreateInstance<ast::ReturnNode>(loc, e)));
}

antlrcpp::Any BuildAstVisitor::visitDeclaration_file(SesameParser::Declaration_fileContext * ctx) {
  auto imports_ctx = ctx->import_stmt();
  for (auto& imp : imports_ctx) {
    std::string fname = tokens_->getText(imp->import_name());
    AddImportFile(fname);
  }

  ast::Declarations* decls_node = new ast::Declarations();
  auto decls_stmt = ctx->declaration_stmt();
  for (auto& decl : decls_stmt) {
    if (decl->func_decl()) {
      auto decl_fun = (entity::UndefinedFunction *)visit(decl->func_decl());
      decls_node->AddDeclFun(decl_fun);
    } else if (decl->var_decl()) {
      auto decl_var = (entity::UndefinedVariable *)visit(decl->var_decl());
      decls_node->AddDeclVar(decl_var);
    } else if (decl->def_const()) {
      auto def_con = (entity::Constant *)visit(decl->def_const());
      decls_node->AddConstant(def_con);
    } else if (decl->def_struct()) {
      auto def_struct_node = (ast::StructTypeNode *)visit(decl->def_struct());
      decls_node->AddStruct(def_struct_node);
    } else if (decl->def_union()) {
      auto def_union_node = (ast::UnionTypeNode *)visit(decl->def_union());
      decls_node->AddUnion(def_union_node);
    } else if (decl->s_typedef()) {
      auto typedef_node = (ast::TypeDefNode *)visit(decl->s_typedef());
      decls_node->AddTypedef(typedef_node);
    }
  }

  return (antlrcpp::Any)decls_node;
}

antlrcpp::Any BuildAstVisitor::visitFunc_decl(SesameParser::Func_declContext * ctx) {
  std::string func_name = tokens_->getText(ctx->name());
  type::TypeRef* ref = (type::TypeRef *)visit(ctx->typeref());
  auto pams = (entity::Params *)visit(ctx->params());

  // type::TypeRef* tr = new type::FunctionTypeRef(ref, pams->GetParameterTypeRefs());
  // return (antlrcpp::Any)(new entity::UndefinedFunction(new ast::TypeNode(tr), func_name, pams));
  type::TypeRef* tr = typeref_tracker_.CreateInstance<type::FunctionTypeRef>(ref, pams->GetParameterTypeRefs());
  ast::TypeNode* tn = node_tracker_.CreateInstance<ast::TypeNode>(tr);
  return (antlrcpp::Any)(entity_tracker_.CreateInstance<entity::UndefinedFunction>(tn, func_name, pams));
}

antlrcpp::Any BuildAstVisitor::visitVar_decl(SesameParser::Var_declContext * ctx) {
  auto tn = (ast::TypeNode *)visit(ctx->type());
  std::string var_name = tokens_->getText(ctx->name());
  // return (antlrcpp::Any)(new entity::UndefinedVariable(tn, var_name));
  return (antlrcpp::Any)(entity_tracker_.CreateInstance<entity::UndefinedVariable>(tn, var_name));
}

} /* parser */
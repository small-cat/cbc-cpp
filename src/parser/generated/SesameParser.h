
// Generated from SesameParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


#include <string.h>


namespace parser {


class  SesameParser : public antlr4::Parser {
public:
  enum {
    S_VOID = 1, S_CHAR = 2, S_SHORT = 3, S_INT = 4, S_LONG = 5, S_STRUCT = 6, 
    S_UNION = 7, S_ENUM = 8, S_STATIC = 9, S_EXTERN = 10, S_CONST = 11, 
    S_SIGNED = 12, S_UNSIGNED = 13, S_IF = 14, S_ELSE = 15, S_SWITCH = 16, 
    S_CASE = 17, S_DEFAULT = 18, S_WHILE = 19, S_DO = 20, S_FOR = 21, S_RETURN = 22, 
    S_BREAK = 23, S_CONTINUE = 24, S_GOTO = 25, S_TYPEDEF = 26, S_IMPORT = 27, 
    S_SIZEOF = 28, SEMI = 29, COLON = 30, PLUS = 31, MINUS = 32, ASTERISK = 33, 
    SOLIDUS = 34, PERCENT = 35, AMPERSAND = 36, LPAREN = 37, RPAREN = 38, 
    COMMA = 39, EQUAL = 40, LBRACE = 41, RBRACE = 42, LBRACKET = 43, RBRACKET = 44, 
    LESS = 45, LESS_EQ = 46, GREATER = 47, GREATER_EQ = 48, NOT_EQ = 49, 
    EQ_SIGN = 50, LOGIC_AND = 51, LOGIC_OR = 52, LSHIFT = 53, RSHIFT = 54, 
    PERIOD = 55, CDOTS = 56, BAR = 57, QUESTION = 58, EXCLAMATION_OPERATOR = 59, 
    CARRET_OPERATOR_PART = 60, TILDE_OPERATOR = 61, POINTER_REF = 62, SINGLE_LINE_COMM = 63, 
    MULTI_LINE_COMM = 64, S_CHARACTER = 65, S_STRING = 66, IDENTIFIER = 67, 
    INTEGER = 68, HEX = 69, OCT = 70, SPACES = 71
  };

  enum {
    RuleCompilation_unit = 0, RuleDeclaration_file = 1, RuleImport_stmt = 2, 
    RuleImport_name = 3, RuleName = 4, RuleFunc_decl = 5, RuleVar_decl = 6, 
    RuleTop_defs = 7, RuleDef_func = 8, RuleStorage = 9, RuleParams = 10, 
    RuleFixed_params = 11, RuleParam = 12, RuleBlock = 13, RuleDef_vars = 14, 
    RuleAssign_expr = 15, RuleDef_const = 16, RuleDef_struct = 17, RuleDef_union = 18, 
    RuleMember_list = 19, RuleSlot = 20, RuleS_typedef = 21, RuleType = 22, 
    RuleTyperef = 23, RuleTyperef_base = 24, RuleTyperef_precise = 25, RuleParam_typerefs = 26, 
    RuleFixed_param_typerefs = 27, RuleStmts = 28, RuleStmt = 29, RuleLabeled_stmt = 30, 
    RuleIf_stmt = 31, RuleWhile_stmt = 32, RuleDo_while_stmt = 33, RuleFor_stmt = 34, 
    RuleSwitch_stmt = 35, RuleCase_clauses = 36, RuleCase_clause = 37, RuleCases = 38, 
    RuleDefault_clause = 39, RuleCase_body = 40, RuleBreak_stmt = 41, RuleContinue_stmt = 42, 
    RuleGoto_stmt = 43, RuleReturn_stmt = 44, RuleExpr = 45, RuleOpassign_op = 46, 
    RuleExpr10 = 47, RuleExpr9 = 48, RuleLogic_or_rhs = 49, RuleExpr8 = 50, 
    RuleLogic_and_rhs = 51, RuleExpr7 = 52, RuleBinary_op_rhs = 53, RuleLogical_op = 54, 
    RuleExpr6 = 55, RuleBit_or_rhs = 56, RuleExpr5 = 57, RuleXor_rhs = 58, 
    RuleExpr4 = 59, RuleBit_and_rhs = 60, RuleExpr3 = 61, RuleShift_op_rhs = 62, 
    RuleExpr2 = 63, RuleAdd_sub_rhs = 64, RuleExpr1 = 65, RuleMulti_div_mod_rhs = 66, 
    RuleTerm = 67, RuleUnary = 68, RulePostfix = 69, RulePostfix_option = 70, 
    RuleArgs = 71, RulePrimary = 72
  };

  SesameParser(antlr4::TokenStream *input);
  ~SesameParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Compilation_unitContext;
  class Declaration_fileContext;
  class Import_stmtContext;
  class Import_nameContext;
  class NameContext;
  class Func_declContext;
  class Var_declContext;
  class Top_defsContext;
  class Def_funcContext;
  class StorageContext;
  class ParamsContext;
  class Fixed_paramsContext;
  class ParamContext;
  class BlockContext;
  class Def_varsContext;
  class Assign_exprContext;
  class Def_constContext;
  class Def_structContext;
  class Def_unionContext;
  class Member_listContext;
  class SlotContext;
  class S_typedefContext;
  class TypeContext;
  class TyperefContext;
  class Typeref_baseContext;
  class Typeref_preciseContext;
  class Param_typerefsContext;
  class Fixed_param_typerefsContext;
  class StmtsContext;
  class StmtContext;
  class Labeled_stmtContext;
  class If_stmtContext;
  class While_stmtContext;
  class Do_while_stmtContext;
  class For_stmtContext;
  class Switch_stmtContext;
  class Case_clausesContext;
  class Case_clauseContext;
  class CasesContext;
  class Default_clauseContext;
  class Case_bodyContext;
  class Break_stmtContext;
  class Continue_stmtContext;
  class Goto_stmtContext;
  class Return_stmtContext;
  class ExprContext;
  class Opassign_opContext;
  class Expr10Context;
  class Expr9Context;
  class Logic_or_rhsContext;
  class Expr8Context;
  class Logic_and_rhsContext;
  class Expr7Context;
  class Binary_op_rhsContext;
  class Logical_opContext;
  class Expr6Context;
  class Bit_or_rhsContext;
  class Expr5Context;
  class Xor_rhsContext;
  class Expr4Context;
  class Bit_and_rhsContext;
  class Expr3Context;
  class Shift_op_rhsContext;
  class Expr2Context;
  class Add_sub_rhsContext;
  class Expr1Context;
  class Multi_div_mod_rhsContext;
  class TermContext;
  class UnaryContext;
  class PostfixContext;
  class Postfix_optionContext;
  class ArgsContext;
  class PrimaryContext; 

  class  Compilation_unitContext : public antlr4::ParserRuleContext {
  public:
    Compilation_unitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Top_defsContext *top_defs();
    std::vector<Import_stmtContext *> import_stmt();
    Import_stmtContext* import_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compilation_unitContext* compilation_unit();

  class  Declaration_fileContext : public antlr4::ParserRuleContext {
  public:
    Declaration_fileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Import_stmtContext *> import_stmt();
    Import_stmtContext* import_stmt(size_t i);
    std::vector<Func_declContext *> func_decl();
    Func_declContext* func_decl(size_t i);
    std::vector<Var_declContext *> var_decl();
    Var_declContext* var_decl(size_t i);
    std::vector<Def_constContext *> def_const();
    Def_constContext* def_const(size_t i);
    std::vector<Def_structContext *> def_struct();
    Def_structContext* def_struct(size_t i);
    std::vector<Def_unionContext *> def_union();
    Def_unionContext* def_union(size_t i);
    std::vector<S_typedefContext *> s_typedef();
    S_typedefContext* s_typedef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaration_fileContext* declaration_file();

  class  Import_stmtContext : public antlr4::ParserRuleContext {
  public:
    Import_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_IMPORT();
    Import_nameContext *import_name();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_stmtContext* import_stmt();

  class  Import_nameContext : public antlr4::ParserRuleContext {
  public:
    Import_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PERIOD();
    antlr4::tree::TerminalNode* PERIOD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_nameContext* import_name();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

  class  Func_declContext : public antlr4::ParserRuleContext {
  public:
    Func_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_EXTERN();
    TyperefContext *typeref();
    NameContext *name();
    antlr4::tree::TerminalNode *LPAREN();
    ParamsContext *params();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_declContext* func_decl();

  class  Var_declContext : public antlr4::ParserRuleContext {
  public:
    Var_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_EXTERN();
    TypeContext *type();
    NameContext *name();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declContext* var_decl();

  class  Top_defsContext : public antlr4::ParserRuleContext {
  public:
    Top_defsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Def_funcContext *> def_func();
    Def_funcContext* def_func(size_t i);
    std::vector<Def_varsContext *> def_vars();
    Def_varsContext* def_vars(size_t i);
    std::vector<Def_constContext *> def_const();
    Def_constContext* def_const(size_t i);
    std::vector<Def_structContext *> def_struct();
    Def_structContext* def_struct(size_t i);
    std::vector<Def_unionContext *> def_union();
    Def_unionContext* def_union(size_t i);
    std::vector<S_typedefContext *> s_typedef();
    S_typedefContext* s_typedef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Top_defsContext* top_defs();

  class  Def_funcContext : public antlr4::ParserRuleContext {
  public:
    Def_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TyperefContext *typeref();
    NameContext *name();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    BlockContext *block();
    StorageContext *storage();
    ParamsContext *params();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Def_funcContext* def_func();

  class  StorageContext : public antlr4::ParserRuleContext {
  public:
    StorageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_STATIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StorageContext* storage();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_VOID();
    Fixed_paramsContext *fixed_params();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *CDOTS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  Fixed_paramsContext : public antlr4::ParserRuleContext {
  public:
    Fixed_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fixed_paramsContext* fixed_params();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    StmtsContext *stmts();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<Def_varsContext *> def_vars();
    Def_varsContext* def_vars(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  Def_varsContext : public antlr4::ParserRuleContext {
  public:
    Def_varsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<Assign_exprContext *> assign_expr();
    Assign_exprContext* assign_expr(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    StorageContext *storage();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Def_varsContext* def_vars();

  class  Assign_exprContext : public antlr4::ParserRuleContext {
  public:
    Assign_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_exprContext* assign_expr();

  class  Def_constContext : public antlr4::ParserRuleContext {
  public:
    Def_constContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_CONST();
    TypeContext *type();
    NameContext *name();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Def_constContext* def_const();

  class  Def_structContext : public antlr4::ParserRuleContext {
  public:
    Def_structContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_STRUCT();
    NameContext *name();
    Member_listContext *member_list();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Def_structContext* def_struct();

  class  Def_unionContext : public antlr4::ParserRuleContext {
  public:
    Def_unionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_UNION();
    NameContext *name();
    Member_listContext *member_list();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Def_unionContext* def_union();

  class  Member_listContext : public antlr4::ParserRuleContext {
  public:
    Member_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<SlotContext *> slot();
    SlotContext* slot(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Member_listContext* member_list();

  class  SlotContext : public antlr4::ParserRuleContext {
  public:
    SlotContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SlotContext* slot();

  class  S_typedefContext : public antlr4::ParserRuleContext {
  public:
    S_typedefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_TYPEDEF();
    TyperefContext *typeref();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  S_typedefContext* s_typedef();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TyperefContext *typeref();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  TyperefContext : public antlr4::ParserRuleContext {
  public:
    TyperefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Typeref_baseContext *typeref_base();
    std::vector<Typeref_preciseContext *> typeref_precise();
    Typeref_preciseContext* typeref_precise(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TyperefContext* typeref();

  class  Typeref_baseContext : public antlr4::ParserRuleContext {
  public:
    Typeref_baseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_VOID();
    antlr4::tree::TerminalNode *S_CHAR();
    antlr4::tree::TerminalNode *S_SHORT();
    antlr4::tree::TerminalNode *S_INT();
    antlr4::tree::TerminalNode *S_LONG();
    antlr4::tree::TerminalNode *S_UNSIGNED();
    antlr4::tree::TerminalNode *S_STRUCT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *S_UNION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Typeref_baseContext* typeref_base();

  class  Typeref_preciseContext : public antlr4::ParserRuleContext {
  public:
    Typeref_preciseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *LPAREN();
    Param_typerefsContext *param_typerefs();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Typeref_preciseContext* typeref_precise();

  class  Param_typerefsContext : public antlr4::ParserRuleContext {
  public:
    Param_typerefsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_VOID();
    Fixed_param_typerefsContext *fixed_param_typerefs();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *CDOTS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Param_typerefsContext* param_typerefs();

  class  Fixed_param_typerefsContext : public antlr4::ParserRuleContext {
  public:
    Fixed_param_typerefsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TyperefContext *> typeref();
    TyperefContext* typeref(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fixed_param_typerefsContext* fixed_param_typerefs();

  class  StmtsContext : public antlr4::ParserRuleContext {
  public:
    StmtsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtsContext* stmts();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    Labeled_stmtContext *labeled_stmt();
    ExprContext *expr();
    BlockContext *block();
    If_stmtContext *if_stmt();
    While_stmtContext *while_stmt();
    Do_while_stmtContext *do_while_stmt();
    For_stmtContext *for_stmt();
    Switch_stmtContext *switch_stmt();
    Break_stmtContext *break_stmt();
    Continue_stmtContext *continue_stmt();
    Goto_stmtContext *goto_stmt();
    Return_stmtContext *return_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  Labeled_stmtContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *label_name = nullptr;
    Labeled_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    StmtContext *stmt();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Labeled_stmtContext* labeled_stmt();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_IF();
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    antlr4::tree::TerminalNode *S_ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_stmtContext* if_stmt();

  class  While_stmtContext : public antlr4::ParserRuleContext {
  public:
    While_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();
    StmtContext *stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_stmtContext* while_stmt();

  class  Do_while_stmtContext : public antlr4::ParserRuleContext {
  public:
    SesameParser::StmtContext *body = nullptr;
    SesameParser::ExprContext *cond = nullptr;
    Do_while_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_DO();
    antlr4::tree::TerminalNode *S_WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMI();
    StmtContext *stmt();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_while_stmtContext* do_while_stmt();

  class  For_stmtContext : public antlr4::ParserRuleContext {
  public:
    SesameParser::ExprContext *init = nullptr;
    SesameParser::ExprContext *cond = nullptr;
    SesameParser::ExprContext *incr = nullptr;
    SesameParser::StmtContext *body = nullptr;
    For_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_FOR();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    StmtContext *stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_stmtContext* for_stmt();

  class  Switch_stmtContext : public antlr4::ParserRuleContext {
  public:
    SesameParser::ExprContext *cond = nullptr;
    SesameParser::Case_clausesContext *body = nullptr;
    Switch_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_SWITCH();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    ExprContext *expr();
    Case_clausesContext *case_clauses();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_stmtContext* switch_stmt();

  class  Case_clausesContext : public antlr4::ParserRuleContext {
  public:
    Case_clausesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Case_clauseContext *> case_clause();
    Case_clauseContext* case_clause(size_t i);
    Default_clauseContext *default_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_clausesContext* case_clauses();

  class  Case_clauseContext : public antlr4::ParserRuleContext {
  public:
    SesameParser::CasesContext *values = nullptr;
    SesameParser::Case_bodyContext *body = nullptr;
    Case_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CasesContext *cases();
    Case_bodyContext *case_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_clauseContext* case_clause();

  class  CasesContext : public antlr4::ParserRuleContext {
  public:
    CasesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> S_CASE();
    antlr4::tree::TerminalNode* S_CASE(size_t i);
    std::vector<PrimaryContext *> primary();
    PrimaryContext* primary(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CasesContext* cases();

  class  Default_clauseContext : public antlr4::ParserRuleContext {
  public:
    SesameParser::Case_bodyContext *body = nullptr;
    Default_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_DEFAULT();
    antlr4::tree::TerminalNode *COLON();
    Case_bodyContext *case_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Default_clauseContext* default_clause();

  class  Case_bodyContext : public antlr4::ParserRuleContext {
  public:
    Case_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_bodyContext* case_body();

  class  Break_stmtContext : public antlr4::ParserRuleContext {
  public:
    Break_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_BREAK();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Break_stmtContext* break_stmt();

  class  Continue_stmtContext : public antlr4::ParserRuleContext {
  public:
    Continue_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_CONTINUE();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Continue_stmtContext* continue_stmt();

  class  Goto_stmtContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *label_name = nullptr;
    Goto_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_GOTO();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Goto_stmtContext* goto_stmt();

  class  Return_stmtContext : public antlr4::ParserRuleContext {
  public:
    Return_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *S_RETURN();
    antlr4::tree::TerminalNode *SEMI();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_stmtContext* return_stmt();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Assignment_exprContext : public ExprContext {
  public:
    Assignment_exprContext(ExprContext *ctx);

    TermContext *term();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Op_assign_exprContext : public ExprContext {
  public:
    Op_assign_exprContext(ExprContext *ctx);

    TermContext *term();
    Opassign_opContext *opassign_op();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expression_10Context : public ExprContext {
  public:
    Expression_10Context(ExprContext *ctx);

    Expr10Context *expr10();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();

  class  Opassign_opContext : public antlr4::ParserRuleContext {
  public:
    Opassign_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *SOLIDUS();
    antlr4::tree::TerminalNode *PERCENT();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *BAR();
    antlr4::tree::TerminalNode *CARRET_OPERATOR_PART();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opassign_opContext* opassign_op();

  class  Expr10Context : public antlr4::ParserRuleContext {
  public:
    Expr10Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr9Context *expr9();
    antlr4::tree::TerminalNode *QUESTION();
    ExprContext *expr();
    antlr4::tree::TerminalNode *COLON();
    Expr10Context *expr10();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr10Context* expr10();

  class  Expr9Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::Expr8Context *lhs = nullptr;
    Expr9Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr8Context *expr8();
    std::vector<antlr4::tree::TerminalNode *> LOGIC_OR();
    antlr4::tree::TerminalNode* LOGIC_OR(size_t i);
    std::vector<Logic_or_rhsContext *> logic_or_rhs();
    Logic_or_rhsContext* logic_or_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr9Context* expr9();

  class  Logic_or_rhsContext : public antlr4::ParserRuleContext {
  public:
    Logic_or_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr8Context *expr8();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_or_rhsContext* logic_or_rhs();

  class  Expr8Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::Expr7Context *lhs = nullptr;
    Expr8Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr7Context *expr7();
    std::vector<antlr4::tree::TerminalNode *> LOGIC_AND();
    antlr4::tree::TerminalNode* LOGIC_AND(size_t i);
    std::vector<Logic_and_rhsContext *> logic_and_rhs();
    Logic_and_rhsContext* logic_and_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr8Context* expr8();

  class  Logic_and_rhsContext : public antlr4::ParserRuleContext {
  public:
    Logic_and_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr7Context *expr7();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_and_rhsContext* logic_and_rhs();

  class  Expr7Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::Expr6Context *lhs = nullptr;
    Expr7Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr6Context *expr6();
    std::vector<Binary_op_rhsContext *> binary_op_rhs();
    Binary_op_rhsContext* binary_op_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr7Context* expr7();

  class  Binary_op_rhsContext : public antlr4::ParserRuleContext {
  public:
    Binary_op_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logical_opContext *logical_op();
    Expr6Context *expr6();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_op_rhsContext* binary_op_rhs();

  class  Logical_opContext : public antlr4::ParserRuleContext {
  public:
    Logical_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *LESS_EQ();
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *GREATER_EQ();
    antlr4::tree::TerminalNode *NOT_EQ();
    antlr4::tree::TerminalNode *EQ_SIGN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_opContext* logical_op();

  class  Expr6Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::Expr5Context *lhs = nullptr;
    Expr6Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr5Context *expr5();
    std::vector<antlr4::tree::TerminalNode *> BAR();
    antlr4::tree::TerminalNode* BAR(size_t i);
    std::vector<Bit_or_rhsContext *> bit_or_rhs();
    Bit_or_rhsContext* bit_or_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr6Context* expr6();

  class  Bit_or_rhsContext : public antlr4::ParserRuleContext {
  public:
    Bit_or_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr5Context *expr5();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bit_or_rhsContext* bit_or_rhs();

  class  Expr5Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::Expr4Context *lhs = nullptr;
    Expr5Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr4Context *expr4();
    std::vector<antlr4::tree::TerminalNode *> CARRET_OPERATOR_PART();
    antlr4::tree::TerminalNode* CARRET_OPERATOR_PART(size_t i);
    std::vector<Xor_rhsContext *> xor_rhs();
    Xor_rhsContext* xor_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr5Context* expr5();

  class  Xor_rhsContext : public antlr4::ParserRuleContext {
  public:
    Xor_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr4Context *expr4();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Xor_rhsContext* xor_rhs();

  class  Expr4Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::Expr3Context *lhs = nullptr;
    Expr4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr3Context *expr3();
    std::vector<antlr4::tree::TerminalNode *> AMPERSAND();
    antlr4::tree::TerminalNode* AMPERSAND(size_t i);
    std::vector<Bit_and_rhsContext *> bit_and_rhs();
    Bit_and_rhsContext* bit_and_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr4Context* expr4();

  class  Bit_and_rhsContext : public antlr4::ParserRuleContext {
  public:
    Bit_and_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr3Context *expr3();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bit_and_rhsContext* bit_and_rhs();

  class  Expr3Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::Expr2Context *lhs = nullptr;
    Expr3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr2Context *expr2();
    std::vector<Shift_op_rhsContext *> shift_op_rhs();
    Shift_op_rhsContext* shift_op_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr3Context* expr3();

  class  Shift_op_rhsContext : public antlr4::ParserRuleContext {
  public:
    Shift_op_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr2Context *expr2();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Shift_op_rhsContext* shift_op_rhs();

  class  Expr2Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::Expr1Context *lhs = nullptr;
    Expr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr1Context *expr1();
    std::vector<Add_sub_rhsContext *> add_sub_rhs();
    Add_sub_rhsContext* add_sub_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr2Context* expr2();

  class  Add_sub_rhsContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *tk = nullptr;
    Add_sub_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr1Context *expr1();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Add_sub_rhsContext* add_sub_rhs();

  class  Expr1Context : public antlr4::ParserRuleContext {
  public:
    SesameParser::TermContext *lhs = nullptr;
    Expr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    std::vector<Multi_div_mod_rhsContext *> multi_div_mod_rhs();
    Multi_div_mod_rhsContext* multi_div_mod_rhs(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr1Context* expr1();

  class  Multi_div_mod_rhsContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *tk = nullptr;
    Multi_div_mod_rhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *SOLIDUS();
    antlr4::tree::TerminalNode *PERCENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Multi_div_mod_rhsContext* multi_div_mod_rhs();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    TypeContext *type();
    antlr4::tree::TerminalNode *RPAREN();
    TermContext *term();
    UnaryContext *unary();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  UnaryContext : public antlr4::ParserRuleContext {
  public:
    UnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryContext() : antlr4::ParserRuleContext() { }
    void copyFrom(UnaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Unary_postfix_exprContext : public UnaryContext {
  public:
    Unary_postfix_exprContext(UnaryContext *ctx);

    PostfixContext *postfix();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Negative_exprContext : public UnaryContext {
  public:
    Negative_exprContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *MINUS();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Inc_exprContext : public UnaryContext {
  public:
    Inc_exprContext(UnaryContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    UnaryContext *unary();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Addr_exprContext : public UnaryContext {
  public:
    Addr_exprContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *AMPERSAND();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dec_exprContext : public UnaryContext {
  public:
    Dec_exprContext(UnaryContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    UnaryContext *unary();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Logic_not_exprContext : public UnaryContext {
  public:
    Logic_not_exprContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *EXCLAMATION_OPERATOR();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Sizeof_exprContext : public UnaryContext {
  public:
    Sizeof_exprContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *S_SIZEOF();
    UnaryContext *unary();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Positive_exprContext : public UnaryContext {
  public:
    Positive_exprContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *PLUS();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Sizeof_type_exprContext : public UnaryContext {
  public:
    Sizeof_type_exprContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *S_SIZEOF();
    antlr4::tree::TerminalNode *LPAREN();
    TypeContext *type();
    antlr4::tree::TerminalNode *RPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bit_not_exprContext : public UnaryContext {
  public:
    Bit_not_exprContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *TILDE_OPERATOR();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dereference_exprContext : public UnaryContext {
  public:
    Dereference_exprContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *ASTERISK();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnaryContext* unary();

  class  PostfixContext : public antlr4::ParserRuleContext {
  public:
    PostfixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    std::vector<Postfix_optionContext *> postfix_option();
    Postfix_optionContext* postfix_option(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PostfixContext* postfix();

  class  Postfix_optionContext : public antlr4::ParserRuleContext {
  public:
    SesameParser::NameContext *memb1 = nullptr;
    SesameParser::NameContext *memb2 = nullptr;
    Postfix_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    antlr4::tree::TerminalNode *LBRACKET();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *PERIOD();
    NameContext *name();
    antlr4::tree::TerminalNode *POINTER_REF();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ArgsContext *args();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Postfix_optionContext* postfix_option();

  class  ArgsContext : public antlr4::ParserRuleContext {
  public:
    ArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsContext* args();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *HEX();
    antlr4::tree::TerminalNode *OCT();
    antlr4::tree::TerminalNode *S_CHARACTER();
    antlr4::tree::TerminalNode *S_STRING();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace parser

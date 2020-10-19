
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
    RuleName = 3, RuleTop_def = 4, RuleDef_func = 5, RuleStorage = 6, RuleParams = 7, 
    RuleFixed_params = 8, RuleParam = 9, RuleBlock = 10, RuleDef_vars = 11, 
    RuleAssign_expr = 12, RuleDef_const = 13, RuleDef_struct = 14, RuleDef_union = 15, 
    RuleMember_list = 16, RuleSlot = 17, RuleS_typedef = 18, RuleType = 19, 
    RuleTyperef = 20, RuleTyperef_base = 21, RuleParam_typerefs = 22, RuleFixed_param_typerefs = 23, 
    RuleStmts = 24, RuleStmt = 25, RuleLabeled_stmt = 26, RuleIf_stmt = 27, 
    RuleWhile_stmt = 28, RuleDo_while_stmt = 29, RuleFor_stmt = 30, RuleSwitch_stmt = 31, 
    RuleCase_clauses = 32, RuleCase_clause = 33, RuleCases = 34, RuleDefault_clause = 35, 
    RuleCase_body = 36, RuleBreak_stmt = 37, RuleContinue_stmt = 38, RuleGoto_stmt = 39, 
    RuleReturn_stmt = 40, RuleExpr = 41, RuleOpassign_op = 42, RuleExpr10 = 43, 
    RuleExpr8 = 44, RuleExpr7 = 45, RuleLogical_op = 46, RuleExpr6 = 47, 
    RuleExpr5 = 48, RuleExpr4 = 49, RuleExpr3 = 50, RuleExpr2 = 51, RuleExpr1 = 52, 
    RuleTerm = 53, RuleUnary = 54, RulePostfix = 55, RuleArgs = 56, RulePrimary = 57
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
  class NameContext;
  class Top_defContext;
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
  class Expr8Context;
  class Expr7Context;
  class Logical_opContext;
  class Expr6Context;
  class Expr5Context;
  class Expr4Context;
  class Expr3Context;
  class Expr2Context;
  class Expr1Context;
  class TermContext;
  class UnaryContext;
  class PostfixContext;
  class ArgsContext;
  class PrimaryContext; 

  class  Compilation_unitContext : public antlr4::ParserRuleContext {
  public:
    Compilation_unitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Import_stmtContext *> import_stmt();
    Import_stmtContext* import_stmt(size_t i);
    std::vector<Top_defContext *> top_def();
    Top_defContext* top_def(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compilation_unitContext* compilation_unit();

  class  Declaration_fileContext : public antlr4::ParserRuleContext {
  public:
    Declaration_fileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

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
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> PERIOD();
    antlr4::tree::TerminalNode* PERIOD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_stmtContext* import_stmt();

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

  class  Top_defContext : public antlr4::ParserRuleContext {
  public:
    Top_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Def_funcContext *def_func();
    Def_varsContext *def_vars();
    Def_constContext *def_const();
    Def_structContext *def_struct();
    Def_unionContext *def_union();
    S_typedefContext *s_typedef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Top_defContext* top_def();

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
    std::vector<antlr4::tree::TerminalNode *> LBRACKET();
    antlr4::tree::TerminalNode* LBRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACKET();
    antlr4::tree::TerminalNode* RBRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ASTERISK();
    antlr4::tree::TerminalNode* ASTERISK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LPAREN();
    antlr4::tree::TerminalNode* LPAREN(size_t i);
    std::vector<Param_typerefsContext *> param_typerefs();
    Param_typerefsContext* param_typerefs(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAREN();
    antlr4::tree::TerminalNode* RPAREN(size_t i);

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
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    Opassign_opContext *opassign_op();
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
    Expr8Context *expr8();
    antlr4::tree::TerminalNode *QUESTION();
    ExprContext *expr();
    antlr4::tree::TerminalNode *COLON();
    Expr10Context *expr10();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr10Context* expr10();

  class  Expr8Context : public antlr4::ParserRuleContext {
  public:
    Expr8Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr7Context *> expr7();
    Expr7Context* expr7(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOGIC_OR();
    antlr4::tree::TerminalNode* LOGIC_OR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOGIC_AND();
    antlr4::tree::TerminalNode* LOGIC_AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr8Context* expr8();

  class  Expr7Context : public antlr4::ParserRuleContext {
  public:
    Expr7Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr6Context *> expr6();
    Expr6Context* expr6(size_t i);
    std::vector<Logical_opContext *> logical_op();
    Logical_opContext* logical_op(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr7Context* expr7();

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
    Expr6Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr5Context *> expr5();
    Expr5Context* expr5(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BAR();
    antlr4::tree::TerminalNode* BAR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr6Context* expr6();

  class  Expr5Context : public antlr4::ParserRuleContext {
  public:
    Expr5Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr4Context *> expr4();
    Expr4Context* expr4(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CARRET_OPERATOR_PART();
    antlr4::tree::TerminalNode* CARRET_OPERATOR_PART(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr5Context* expr5();

  class  Expr4Context : public antlr4::ParserRuleContext {
  public:
    Expr4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr3Context *> expr3();
    Expr3Context* expr3(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AMPERSAND();
    antlr4::tree::TerminalNode* AMPERSAND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr4Context* expr4();

  class  Expr3Context : public antlr4::ParserRuleContext {
  public:
    Expr3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr2Context *> expr2();
    Expr2Context* expr2(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LSHIFT();
    antlr4::tree::TerminalNode* LSHIFT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RSHIFT();
    antlr4::tree::TerminalNode* RSHIFT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr3Context* expr3();

  class  Expr2Context : public antlr4::ParserRuleContext {
  public:
    Expr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr1Context *> expr1();
    Expr1Context* expr1(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr2Context* expr2();

  class  Expr1Context : public antlr4::ParserRuleContext {
  public:
    Expr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ASTERISK();
    antlr4::tree::TerminalNode* ASTERISK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SOLIDUS();
    antlr4::tree::TerminalNode* SOLIDUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PERCENT();
    antlr4::tree::TerminalNode* PERCENT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr1Context* expr1();

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
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    UnaryContext *unary();
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    TermContext *term();
    antlr4::tree::TerminalNode *EXCLAMATION_OPERATOR();
    antlr4::tree::TerminalNode *TILDE_OPERATOR();
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *S_SIZEOF();
    antlr4::tree::TerminalNode *LPAREN();
    TypeContext *type();
    antlr4::tree::TerminalNode *RPAREN();
    PostfixContext *postfix();

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
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LBRACKET();
    antlr4::tree::TerminalNode* LBRACKET(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACKET();
    antlr4::tree::TerminalNode* RBRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PERIOD();
    antlr4::tree::TerminalNode* PERIOD(size_t i);
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> POINTER_REF();
    antlr4::tree::TerminalNode* POINTER_REF(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LPAREN();
    antlr4::tree::TerminalNode* LPAREN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAREN();
    antlr4::tree::TerminalNode* RPAREN(size_t i);
    std::vector<ArgsContext *> args();
    ArgsContext* args(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PostfixContext* postfix();

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

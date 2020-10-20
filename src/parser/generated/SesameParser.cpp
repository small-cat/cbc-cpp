
// Generated from SesameParser.g4 by ANTLR 4.7.1


#include "SesameParserListener.h"
#include "SesameParserVisitor.h"

#include "SesameParser.h"


#include <string.h>


using namespace antlrcpp;
using namespace parser;
using namespace antlr4;

SesameParser::SesameParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SesameParser::~SesameParser() {
  delete _interpreter;
}

std::string SesameParser::getGrammarFileName() const {
  return "SesameParser.g4";
}

const std::vector<std::string>& SesameParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SesameParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Compilation_unitContext ------------------------------------------------------------------

SesameParser::Compilation_unitContext::Compilation_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Import_stmtContext *> SesameParser::Compilation_unitContext::import_stmt() {
  return getRuleContexts<SesameParser::Import_stmtContext>();
}

SesameParser::Import_stmtContext* SesameParser::Compilation_unitContext::import_stmt(size_t i) {
  return getRuleContext<SesameParser::Import_stmtContext>(i);
}

std::vector<SesameParser::Top_defContext *> SesameParser::Compilation_unitContext::top_def() {
  return getRuleContexts<SesameParser::Top_defContext>();
}

SesameParser::Top_defContext* SesameParser::Compilation_unitContext::top_def(size_t i) {
  return getRuleContext<SesameParser::Top_defContext>(i);
}


size_t SesameParser::Compilation_unitContext::getRuleIndex() const {
  return SesameParser::RuleCompilation_unit;
}

void SesameParser::Compilation_unitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilation_unit(this);
}

void SesameParser::Compilation_unitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilation_unit(this);
}


antlrcpp::Any SesameParser::Compilation_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitCompilation_unit(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Compilation_unitContext* SesameParser::compilation_unit() {
  Compilation_unitContext *_localctx = _tracker.createInstance<Compilation_unitContext>(_ctx, getState());
  enterRule(_localctx, 0, SesameParser::RuleCompilation_unit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::S_IMPORT) {
      setState(122);
      import_stmt();
      setState(127);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(129); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(128);
      top_def();
      setState(131); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::S_VOID)
      | (1ULL << SesameParser::S_CHAR)
      | (1ULL << SesameParser::S_SHORT)
      | (1ULL << SesameParser::S_INT)
      | (1ULL << SesameParser::S_LONG)
      | (1ULL << SesameParser::S_STRUCT)
      | (1ULL << SesameParser::S_UNION)
      | (1ULL << SesameParser::S_STATIC)
      | (1ULL << SesameParser::S_CONST)
      | (1ULL << SesameParser::S_UNSIGNED)
      | (1ULL << SesameParser::S_TYPEDEF))) != 0) || _la == SesameParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_fileContext ------------------------------------------------------------------

SesameParser::Declaration_fileContext::Declaration_fileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Import_stmtContext *> SesameParser::Declaration_fileContext::import_stmt() {
  return getRuleContexts<SesameParser::Import_stmtContext>();
}

SesameParser::Import_stmtContext* SesameParser::Declaration_fileContext::import_stmt(size_t i) {
  return getRuleContext<SesameParser::Import_stmtContext>(i);
}

std::vector<SesameParser::Func_declContext *> SesameParser::Declaration_fileContext::func_decl() {
  return getRuleContexts<SesameParser::Func_declContext>();
}

SesameParser::Func_declContext* SesameParser::Declaration_fileContext::func_decl(size_t i) {
  return getRuleContext<SesameParser::Func_declContext>(i);
}

std::vector<SesameParser::Var_declContext *> SesameParser::Declaration_fileContext::var_decl() {
  return getRuleContexts<SesameParser::Var_declContext>();
}

SesameParser::Var_declContext* SesameParser::Declaration_fileContext::var_decl(size_t i) {
  return getRuleContext<SesameParser::Var_declContext>(i);
}

std::vector<SesameParser::Def_constContext *> SesameParser::Declaration_fileContext::def_const() {
  return getRuleContexts<SesameParser::Def_constContext>();
}

SesameParser::Def_constContext* SesameParser::Declaration_fileContext::def_const(size_t i) {
  return getRuleContext<SesameParser::Def_constContext>(i);
}

std::vector<SesameParser::Def_structContext *> SesameParser::Declaration_fileContext::def_struct() {
  return getRuleContexts<SesameParser::Def_structContext>();
}

SesameParser::Def_structContext* SesameParser::Declaration_fileContext::def_struct(size_t i) {
  return getRuleContext<SesameParser::Def_structContext>(i);
}

std::vector<SesameParser::Def_unionContext *> SesameParser::Declaration_fileContext::def_union() {
  return getRuleContexts<SesameParser::Def_unionContext>();
}

SesameParser::Def_unionContext* SesameParser::Declaration_fileContext::def_union(size_t i) {
  return getRuleContext<SesameParser::Def_unionContext>(i);
}

std::vector<SesameParser::S_typedefContext *> SesameParser::Declaration_fileContext::s_typedef() {
  return getRuleContexts<SesameParser::S_typedefContext>();
}

SesameParser::S_typedefContext* SesameParser::Declaration_fileContext::s_typedef(size_t i) {
  return getRuleContext<SesameParser::S_typedefContext>(i);
}


size_t SesameParser::Declaration_fileContext::getRuleIndex() const {
  return SesameParser::RuleDeclaration_file;
}

void SesameParser::Declaration_fileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_file(this);
}

void SesameParser::Declaration_fileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_file(this);
}


antlrcpp::Any SesameParser::Declaration_fileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration_file(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Declaration_fileContext* SesameParser::declaration_file() {
  Declaration_fileContext *_localctx = _tracker.createInstance<Declaration_fileContext>(_ctx, getState());
  enterRule(_localctx, 2, SesameParser::RuleDeclaration_file);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::S_IMPORT) {
      setState(133);
      import_stmt();
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(147);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::S_STRUCT)
      | (1ULL << SesameParser::S_UNION)
      | (1ULL << SesameParser::S_EXTERN)
      | (1ULL << SesameParser::S_CONST)
      | (1ULL << SesameParser::S_TYPEDEF))) != 0)) {
      setState(145);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(139);
        func_decl();
        break;
      }

      case 2: {
        setState(140);
        var_decl();
        break;
      }

      case 3: {
        setState(141);
        def_const();
        break;
      }

      case 4: {
        setState(142);
        def_struct();
        break;
      }

      case 5: {
        setState(143);
        def_union();
        break;
      }

      case 6: {
        setState(144);
        s_typedef();
        break;
      }

      }
      setState(149);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_stmtContext ------------------------------------------------------------------

SesameParser::Import_stmtContext::Import_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Import_stmtContext::S_IMPORT() {
  return getToken(SesameParser::S_IMPORT, 0);
}

SesameParser::Import_nameContext* SesameParser::Import_stmtContext::import_name() {
  return getRuleContext<SesameParser::Import_nameContext>(0);
}

tree::TerminalNode* SesameParser::Import_stmtContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Import_stmtContext::getRuleIndex() const {
  return SesameParser::RuleImport_stmt;
}

void SesameParser::Import_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImport_stmt(this);
}

void SesameParser::Import_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImport_stmt(this);
}


antlrcpp::Any SesameParser::Import_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitImport_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Import_stmtContext* SesameParser::import_stmt() {
  Import_stmtContext *_localctx = _tracker.createInstance<Import_stmtContext>(_ctx, getState());
  enterRule(_localctx, 4, SesameParser::RuleImport_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(SesameParser::S_IMPORT);
    setState(151);
    import_name();
    setState(152);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_nameContext ------------------------------------------------------------------

SesameParser::Import_nameContext::Import_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::NameContext *> SesameParser::Import_nameContext::name() {
  return getRuleContexts<SesameParser::NameContext>();
}

SesameParser::NameContext* SesameParser::Import_nameContext::name(size_t i) {
  return getRuleContext<SesameParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Import_nameContext::PERIOD() {
  return getTokens(SesameParser::PERIOD);
}

tree::TerminalNode* SesameParser::Import_nameContext::PERIOD(size_t i) {
  return getToken(SesameParser::PERIOD, i);
}


size_t SesameParser::Import_nameContext::getRuleIndex() const {
  return SesameParser::RuleImport_name;
}

void SesameParser::Import_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImport_name(this);
}

void SesameParser::Import_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImport_name(this);
}


antlrcpp::Any SesameParser::Import_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitImport_name(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Import_nameContext* SesameParser::import_name() {
  Import_nameContext *_localctx = _tracker.createInstance<Import_nameContext>(_ctx, getState());
  enterRule(_localctx, 6, SesameParser::RuleImport_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    name();
    setState(159);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::PERIOD) {
      setState(155);
      match(SesameParser::PERIOD);
      setState(156);
      name();
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

SesameParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::NameContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}


size_t SesameParser::NameContext::getRuleIndex() const {
  return SesameParser::RuleName;
}

void SesameParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void SesameParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}


antlrcpp::Any SesameParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::NameContext* SesameParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 8, SesameParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(SesameParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declContext ------------------------------------------------------------------

SesameParser::Func_declContext::Func_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Func_declContext::S_EXTERN() {
  return getToken(SesameParser::S_EXTERN, 0);
}

SesameParser::TyperefContext* SesameParser::Func_declContext::typeref() {
  return getRuleContext<SesameParser::TyperefContext>(0);
}

SesameParser::NameContext* SesameParser::Func_declContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}

tree::TerminalNode* SesameParser::Func_declContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

SesameParser::ParamsContext* SesameParser::Func_declContext::params() {
  return getRuleContext<SesameParser::ParamsContext>(0);
}

tree::TerminalNode* SesameParser::Func_declContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

tree::TerminalNode* SesameParser::Func_declContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Func_declContext::getRuleIndex() const {
  return SesameParser::RuleFunc_decl;
}

void SesameParser::Func_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_decl(this);
}

void SesameParser::Func_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_decl(this);
}


antlrcpp::Any SesameParser::Func_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitFunc_decl(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Func_declContext* SesameParser::func_decl() {
  Func_declContext *_localctx = _tracker.createInstance<Func_declContext>(_ctx, getState());
  enterRule(_localctx, 10, SesameParser::RuleFunc_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(SesameParser::S_EXTERN);
    setState(165);
    typeref();
    setState(166);
    name();
    setState(167);
    match(SesameParser::LPAREN);
    setState(168);
    params();
    setState(169);
    match(SesameParser::RPAREN);
    setState(170);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declContext ------------------------------------------------------------------

SesameParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Var_declContext::S_EXTERN() {
  return getToken(SesameParser::S_EXTERN, 0);
}

SesameParser::TypeContext* SesameParser::Var_declContext::type() {
  return getRuleContext<SesameParser::TypeContext>(0);
}

SesameParser::NameContext* SesameParser::Var_declContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}

tree::TerminalNode* SesameParser::Var_declContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Var_declContext::getRuleIndex() const {
  return SesameParser::RuleVar_decl;
}

void SesameParser::Var_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_decl(this);
}

void SesameParser::Var_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_decl(this);
}


antlrcpp::Any SesameParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Var_declContext* SesameParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 12, SesameParser::RuleVar_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(SesameParser::S_EXTERN);
    setState(173);
    type();
    setState(174);
    name();
    setState(175);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Top_defContext ------------------------------------------------------------------

SesameParser::Top_defContext::Top_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Def_funcContext* SesameParser::Top_defContext::def_func() {
  return getRuleContext<SesameParser::Def_funcContext>(0);
}

SesameParser::Def_varsContext* SesameParser::Top_defContext::def_vars() {
  return getRuleContext<SesameParser::Def_varsContext>(0);
}

SesameParser::Def_constContext* SesameParser::Top_defContext::def_const() {
  return getRuleContext<SesameParser::Def_constContext>(0);
}

SesameParser::Def_structContext* SesameParser::Top_defContext::def_struct() {
  return getRuleContext<SesameParser::Def_structContext>(0);
}

SesameParser::Def_unionContext* SesameParser::Top_defContext::def_union() {
  return getRuleContext<SesameParser::Def_unionContext>(0);
}

SesameParser::S_typedefContext* SesameParser::Top_defContext::s_typedef() {
  return getRuleContext<SesameParser::S_typedefContext>(0);
}


size_t SesameParser::Top_defContext::getRuleIndex() const {
  return SesameParser::RuleTop_def;
}

void SesameParser::Top_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTop_def(this);
}

void SesameParser::Top_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTop_def(this);
}


antlrcpp::Any SesameParser::Top_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTop_def(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Top_defContext* SesameParser::top_def() {
  Top_defContext *_localctx = _tracker.createInstance<Top_defContext>(_ctx, getState());
  enterRule(_localctx, 14, SesameParser::RuleTop_def);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(177);
      def_func();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(178);
      def_vars();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(179);
      def_const();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(180);
      def_struct();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(181);
      def_union();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(182);
      s_typedef();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Def_funcContext ------------------------------------------------------------------

SesameParser::Def_funcContext::Def_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::TyperefContext* SesameParser::Def_funcContext::typeref() {
  return getRuleContext<SesameParser::TyperefContext>(0);
}

SesameParser::NameContext* SesameParser::Def_funcContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}

tree::TerminalNode* SesameParser::Def_funcContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

tree::TerminalNode* SesameParser::Def_funcContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

SesameParser::BlockContext* SesameParser::Def_funcContext::block() {
  return getRuleContext<SesameParser::BlockContext>(0);
}

SesameParser::StorageContext* SesameParser::Def_funcContext::storage() {
  return getRuleContext<SesameParser::StorageContext>(0);
}

SesameParser::ParamsContext* SesameParser::Def_funcContext::params() {
  return getRuleContext<SesameParser::ParamsContext>(0);
}


size_t SesameParser::Def_funcContext::getRuleIndex() const {
  return SesameParser::RuleDef_func;
}

void SesameParser::Def_funcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDef_func(this);
}

void SesameParser::Def_funcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDef_func(this);
}


antlrcpp::Any SesameParser::Def_funcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDef_func(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Def_funcContext* SesameParser::def_func() {
  Def_funcContext *_localctx = _tracker.createInstance<Def_funcContext>(_ctx, getState());
  enterRule(_localctx, 16, SesameParser::RuleDef_func);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::S_STATIC) {
      setState(185);
      storage();
    }
    setState(188);
    typeref();
    setState(189);
    name();
    setState(190);
    match(SesameParser::LPAREN);
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::S_VOID)
      | (1ULL << SesameParser::S_CHAR)
      | (1ULL << SesameParser::S_SHORT)
      | (1ULL << SesameParser::S_INT)
      | (1ULL << SesameParser::S_LONG)
      | (1ULL << SesameParser::S_STRUCT)
      | (1ULL << SesameParser::S_UNION)
      | (1ULL << SesameParser::S_UNSIGNED))) != 0) || _la == SesameParser::IDENTIFIER) {
      setState(191);
      params();
    }
    setState(194);
    match(SesameParser::RPAREN);
    setState(195);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StorageContext ------------------------------------------------------------------

SesameParser::StorageContext::StorageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::StorageContext::S_STATIC() {
  return getToken(SesameParser::S_STATIC, 0);
}


size_t SesameParser::StorageContext::getRuleIndex() const {
  return SesameParser::RuleStorage;
}

void SesameParser::StorageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStorage(this);
}

void SesameParser::StorageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStorage(this);
}


antlrcpp::Any SesameParser::StorageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitStorage(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::StorageContext* SesameParser::storage() {
  StorageContext *_localctx = _tracker.createInstance<StorageContext>(_ctx, getState());
  enterRule(_localctx, 18, SesameParser::RuleStorage);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    match(SesameParser::S_STATIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

SesameParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::ParamsContext::S_VOID() {
  return getToken(SesameParser::S_VOID, 0);
}

SesameParser::Fixed_paramsContext* SesameParser::ParamsContext::fixed_params() {
  return getRuleContext<SesameParser::Fixed_paramsContext>(0);
}

tree::TerminalNode* SesameParser::ParamsContext::COMMA() {
  return getToken(SesameParser::COMMA, 0);
}

tree::TerminalNode* SesameParser::ParamsContext::CDOTS() {
  return getToken(SesameParser::CDOTS, 0);
}


size_t SesameParser::ParamsContext::getRuleIndex() const {
  return SesameParser::RuleParams;
}

void SesameParser::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void SesameParser::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}


antlrcpp::Any SesameParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::ParamsContext* SesameParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 20, SesameParser::RuleParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(205);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(199);
      match(SesameParser::S_VOID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(200);
      fixed_params();
      setState(203);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SesameParser::COMMA) {
        setState(201);
        match(SesameParser::COMMA);
        setState(202);
        match(SesameParser::CDOTS);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fixed_paramsContext ------------------------------------------------------------------

SesameParser::Fixed_paramsContext::Fixed_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::ParamContext *> SesameParser::Fixed_paramsContext::param() {
  return getRuleContexts<SesameParser::ParamContext>();
}

SesameParser::ParamContext* SesameParser::Fixed_paramsContext::param(size_t i) {
  return getRuleContext<SesameParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Fixed_paramsContext::COMMA() {
  return getTokens(SesameParser::COMMA);
}

tree::TerminalNode* SesameParser::Fixed_paramsContext::COMMA(size_t i) {
  return getToken(SesameParser::COMMA, i);
}


size_t SesameParser::Fixed_paramsContext::getRuleIndex() const {
  return SesameParser::RuleFixed_params;
}

void SesameParser::Fixed_paramsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFixed_params(this);
}

void SesameParser::Fixed_paramsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFixed_params(this);
}


antlrcpp::Any SesameParser::Fixed_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitFixed_params(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Fixed_paramsContext* SesameParser::fixed_params() {
  Fixed_paramsContext *_localctx = _tracker.createInstance<Fixed_paramsContext>(_ctx, getState());
  enterRule(_localctx, 22, SesameParser::RuleFixed_params);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(207);
    param();
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(208);
        match(SesameParser::COMMA);
        setState(209);
        param(); 
      }
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

SesameParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::TypeContext* SesameParser::ParamContext::type() {
  return getRuleContext<SesameParser::TypeContext>(0);
}

SesameParser::NameContext* SesameParser::ParamContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}


size_t SesameParser::ParamContext::getRuleIndex() const {
  return SesameParser::RuleParam;
}

void SesameParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void SesameParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}


antlrcpp::Any SesameParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::ParamContext* SesameParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 24, SesameParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    type();
    setState(216);
    name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SesameParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::BlockContext::LBRACE() {
  return getToken(SesameParser::LBRACE, 0);
}

SesameParser::StmtsContext* SesameParser::BlockContext::stmts() {
  return getRuleContext<SesameParser::StmtsContext>(0);
}

tree::TerminalNode* SesameParser::BlockContext::RBRACE() {
  return getToken(SesameParser::RBRACE, 0);
}

std::vector<SesameParser::Def_varsContext *> SesameParser::BlockContext::def_vars() {
  return getRuleContexts<SesameParser::Def_varsContext>();
}

SesameParser::Def_varsContext* SesameParser::BlockContext::def_vars(size_t i) {
  return getRuleContext<SesameParser::Def_varsContext>(i);
}


size_t SesameParser::BlockContext::getRuleIndex() const {
  return SesameParser::RuleBlock;
}

void SesameParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void SesameParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any SesameParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::BlockContext* SesameParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, SesameParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(SesameParser::LBRACE);
    setState(222);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(219);
        def_vars(); 
      }
      setState(224);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(225);
    stmts();
    setState(226);
    match(SesameParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Def_varsContext ------------------------------------------------------------------

SesameParser::Def_varsContext::Def_varsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::TypeContext* SesameParser::Def_varsContext::type() {
  return getRuleContext<SesameParser::TypeContext>(0);
}

std::vector<SesameParser::Assign_exprContext *> SesameParser::Def_varsContext::assign_expr() {
  return getRuleContexts<SesameParser::Assign_exprContext>();
}

SesameParser::Assign_exprContext* SesameParser::Def_varsContext::assign_expr(size_t i) {
  return getRuleContext<SesameParser::Assign_exprContext>(i);
}

tree::TerminalNode* SesameParser::Def_varsContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}

SesameParser::StorageContext* SesameParser::Def_varsContext::storage() {
  return getRuleContext<SesameParser::StorageContext>(0);
}

std::vector<tree::TerminalNode *> SesameParser::Def_varsContext::COMMA() {
  return getTokens(SesameParser::COMMA);
}

tree::TerminalNode* SesameParser::Def_varsContext::COMMA(size_t i) {
  return getToken(SesameParser::COMMA, i);
}


size_t SesameParser::Def_varsContext::getRuleIndex() const {
  return SesameParser::RuleDef_vars;
}

void SesameParser::Def_varsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDef_vars(this);
}

void SesameParser::Def_varsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDef_vars(this);
}


antlrcpp::Any SesameParser::Def_varsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDef_vars(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Def_varsContext* SesameParser::def_vars() {
  Def_varsContext *_localctx = _tracker.createInstance<Def_varsContext>(_ctx, getState());
  enterRule(_localctx, 28, SesameParser::RuleDef_vars);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::S_STATIC) {
      setState(228);
      storage();
    }
    setState(231);
    type();
    setState(232);
    assign_expr();
    setState(237);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::COMMA) {
      setState(233);
      match(SesameParser::COMMA);
      setState(234);
      assign_expr();
      setState(239);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(240);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_exprContext ------------------------------------------------------------------

SesameParser::Assign_exprContext::Assign_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::NameContext* SesameParser::Assign_exprContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}

tree::TerminalNode* SesameParser::Assign_exprContext::EQUAL() {
  return getToken(SesameParser::EQUAL, 0);
}

SesameParser::ExprContext* SesameParser::Assign_exprContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}


size_t SesameParser::Assign_exprContext::getRuleIndex() const {
  return SesameParser::RuleAssign_expr;
}

void SesameParser::Assign_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign_expr(this);
}

void SesameParser::Assign_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign_expr(this);
}


antlrcpp::Any SesameParser::Assign_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitAssign_expr(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Assign_exprContext* SesameParser::assign_expr() {
  Assign_exprContext *_localctx = _tracker.createInstance<Assign_exprContext>(_ctx, getState());
  enterRule(_localctx, 30, SesameParser::RuleAssign_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    name();
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::EQUAL) {
      setState(243);
      match(SesameParser::EQUAL);
      setState(244);
      expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Def_constContext ------------------------------------------------------------------

SesameParser::Def_constContext::Def_constContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Def_constContext::S_CONST() {
  return getToken(SesameParser::S_CONST, 0);
}

SesameParser::TypeContext* SesameParser::Def_constContext::type() {
  return getRuleContext<SesameParser::TypeContext>(0);
}

SesameParser::NameContext* SesameParser::Def_constContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}

tree::TerminalNode* SesameParser::Def_constContext::EQUAL() {
  return getToken(SesameParser::EQUAL, 0);
}

SesameParser::ExprContext* SesameParser::Def_constContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

tree::TerminalNode* SesameParser::Def_constContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Def_constContext::getRuleIndex() const {
  return SesameParser::RuleDef_const;
}

void SesameParser::Def_constContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDef_const(this);
}

void SesameParser::Def_constContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDef_const(this);
}


antlrcpp::Any SesameParser::Def_constContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDef_const(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Def_constContext* SesameParser::def_const() {
  Def_constContext *_localctx = _tracker.createInstance<Def_constContext>(_ctx, getState());
  enterRule(_localctx, 32, SesameParser::RuleDef_const);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(SesameParser::S_CONST);
    setState(248);
    type();
    setState(249);
    name();
    setState(250);
    match(SesameParser::EQUAL);
    setState(251);
    expr();
    setState(252);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Def_structContext ------------------------------------------------------------------

SesameParser::Def_structContext::Def_structContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Def_structContext::S_STRUCT() {
  return getToken(SesameParser::S_STRUCT, 0);
}

SesameParser::NameContext* SesameParser::Def_structContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}

SesameParser::Member_listContext* SesameParser::Def_structContext::member_list() {
  return getRuleContext<SesameParser::Member_listContext>(0);
}

tree::TerminalNode* SesameParser::Def_structContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Def_structContext::getRuleIndex() const {
  return SesameParser::RuleDef_struct;
}

void SesameParser::Def_structContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDef_struct(this);
}

void SesameParser::Def_structContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDef_struct(this);
}


antlrcpp::Any SesameParser::Def_structContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDef_struct(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Def_structContext* SesameParser::def_struct() {
  Def_structContext *_localctx = _tracker.createInstance<Def_structContext>(_ctx, getState());
  enterRule(_localctx, 34, SesameParser::RuleDef_struct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(SesameParser::S_STRUCT);
    setState(255);
    name();
    setState(256);
    member_list();
    setState(257);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Def_unionContext ------------------------------------------------------------------

SesameParser::Def_unionContext::Def_unionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Def_unionContext::S_UNION() {
  return getToken(SesameParser::S_UNION, 0);
}

SesameParser::NameContext* SesameParser::Def_unionContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}

SesameParser::Member_listContext* SesameParser::Def_unionContext::member_list() {
  return getRuleContext<SesameParser::Member_listContext>(0);
}

tree::TerminalNode* SesameParser::Def_unionContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Def_unionContext::getRuleIndex() const {
  return SesameParser::RuleDef_union;
}

void SesameParser::Def_unionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDef_union(this);
}

void SesameParser::Def_unionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDef_union(this);
}


antlrcpp::Any SesameParser::Def_unionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDef_union(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Def_unionContext* SesameParser::def_union() {
  Def_unionContext *_localctx = _tracker.createInstance<Def_unionContext>(_ctx, getState());
  enterRule(_localctx, 36, SesameParser::RuleDef_union);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(SesameParser::S_UNION);
    setState(260);
    name();
    setState(261);
    member_list();
    setState(262);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Member_listContext ------------------------------------------------------------------

SesameParser::Member_listContext::Member_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Member_listContext::LBRACE() {
  return getToken(SesameParser::LBRACE, 0);
}

tree::TerminalNode* SesameParser::Member_listContext::RBRACE() {
  return getToken(SesameParser::RBRACE, 0);
}

std::vector<SesameParser::SlotContext *> SesameParser::Member_listContext::slot() {
  return getRuleContexts<SesameParser::SlotContext>();
}

SesameParser::SlotContext* SesameParser::Member_listContext::slot(size_t i) {
  return getRuleContext<SesameParser::SlotContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Member_listContext::SEMI() {
  return getTokens(SesameParser::SEMI);
}

tree::TerminalNode* SesameParser::Member_listContext::SEMI(size_t i) {
  return getToken(SesameParser::SEMI, i);
}


size_t SesameParser::Member_listContext::getRuleIndex() const {
  return SesameParser::RuleMember_list;
}

void SesameParser::Member_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMember_list(this);
}

void SesameParser::Member_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMember_list(this);
}


antlrcpp::Any SesameParser::Member_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitMember_list(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Member_listContext* SesameParser::member_list() {
  Member_listContext *_localctx = _tracker.createInstance<Member_listContext>(_ctx, getState());
  enterRule(_localctx, 38, SesameParser::RuleMember_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(SesameParser::LBRACE);
    setState(270);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::S_VOID)
      | (1ULL << SesameParser::S_CHAR)
      | (1ULL << SesameParser::S_SHORT)
      | (1ULL << SesameParser::S_INT)
      | (1ULL << SesameParser::S_LONG)
      | (1ULL << SesameParser::S_STRUCT)
      | (1ULL << SesameParser::S_UNION)
      | (1ULL << SesameParser::S_UNSIGNED))) != 0) || _la == SesameParser::IDENTIFIER) {
      setState(265);
      slot();
      setState(266);
      match(SesameParser::SEMI);
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(273);
    match(SesameParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SlotContext ------------------------------------------------------------------

SesameParser::SlotContext::SlotContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::TypeContext* SesameParser::SlotContext::type() {
  return getRuleContext<SesameParser::TypeContext>(0);
}

SesameParser::NameContext* SesameParser::SlotContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}


size_t SesameParser::SlotContext::getRuleIndex() const {
  return SesameParser::RuleSlot;
}

void SesameParser::SlotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSlot(this);
}

void SesameParser::SlotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSlot(this);
}


antlrcpp::Any SesameParser::SlotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitSlot(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::SlotContext* SesameParser::slot() {
  SlotContext *_localctx = _tracker.createInstance<SlotContext>(_ctx, getState());
  enterRule(_localctx, 40, SesameParser::RuleSlot);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    type();
    setState(276);
    name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- S_typedefContext ------------------------------------------------------------------

SesameParser::S_typedefContext::S_typedefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::S_typedefContext::S_TYPEDEF() {
  return getToken(SesameParser::S_TYPEDEF, 0);
}

SesameParser::TyperefContext* SesameParser::S_typedefContext::typeref() {
  return getRuleContext<SesameParser::TyperefContext>(0);
}

tree::TerminalNode* SesameParser::S_typedefContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}

tree::TerminalNode* SesameParser::S_typedefContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::S_typedefContext::getRuleIndex() const {
  return SesameParser::RuleS_typedef;
}

void SesameParser::S_typedefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterS_typedef(this);
}

void SesameParser::S_typedefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitS_typedef(this);
}


antlrcpp::Any SesameParser::S_typedefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitS_typedef(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::S_typedefContext* SesameParser::s_typedef() {
  S_typedefContext *_localctx = _tracker.createInstance<S_typedefContext>(_ctx, getState());
  enterRule(_localctx, 42, SesameParser::RuleS_typedef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    match(SesameParser::S_TYPEDEF);
    setState(279);
    typeref();
    setState(280);
    match(SesameParser::IDENTIFIER);
    setState(281);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

SesameParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::TyperefContext* SesameParser::TypeContext::typeref() {
  return getRuleContext<SesameParser::TyperefContext>(0);
}


size_t SesameParser::TypeContext::getRuleIndex() const {
  return SesameParser::RuleType;
}

void SesameParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void SesameParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any SesameParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::TypeContext* SesameParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 44, SesameParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    typeref();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TyperefContext ------------------------------------------------------------------

SesameParser::TyperefContext::TyperefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Typeref_baseContext* SesameParser::TyperefContext::typeref_base() {
  return getRuleContext<SesameParser::Typeref_baseContext>(0);
}

std::vector<tree::TerminalNode *> SesameParser::TyperefContext::LBRACKET() {
  return getTokens(SesameParser::LBRACKET);
}

tree::TerminalNode* SesameParser::TyperefContext::LBRACKET(size_t i) {
  return getToken(SesameParser::LBRACKET, i);
}

std::vector<tree::TerminalNode *> SesameParser::TyperefContext::RBRACKET() {
  return getTokens(SesameParser::RBRACKET);
}

tree::TerminalNode* SesameParser::TyperefContext::RBRACKET(size_t i) {
  return getToken(SesameParser::RBRACKET, i);
}

std::vector<tree::TerminalNode *> SesameParser::TyperefContext::INTEGER() {
  return getTokens(SesameParser::INTEGER);
}

tree::TerminalNode* SesameParser::TyperefContext::INTEGER(size_t i) {
  return getToken(SesameParser::INTEGER, i);
}

std::vector<tree::TerminalNode *> SesameParser::TyperefContext::ASTERISK() {
  return getTokens(SesameParser::ASTERISK);
}

tree::TerminalNode* SesameParser::TyperefContext::ASTERISK(size_t i) {
  return getToken(SesameParser::ASTERISK, i);
}

std::vector<tree::TerminalNode *> SesameParser::TyperefContext::LPAREN() {
  return getTokens(SesameParser::LPAREN);
}

tree::TerminalNode* SesameParser::TyperefContext::LPAREN(size_t i) {
  return getToken(SesameParser::LPAREN, i);
}

std::vector<SesameParser::Param_typerefsContext *> SesameParser::TyperefContext::param_typerefs() {
  return getRuleContexts<SesameParser::Param_typerefsContext>();
}

SesameParser::Param_typerefsContext* SesameParser::TyperefContext::param_typerefs(size_t i) {
  return getRuleContext<SesameParser::Param_typerefsContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::TyperefContext::RPAREN() {
  return getTokens(SesameParser::RPAREN);
}

tree::TerminalNode* SesameParser::TyperefContext::RPAREN(size_t i) {
  return getToken(SesameParser::RPAREN, i);
}


size_t SesameParser::TyperefContext::getRuleIndex() const {
  return SesameParser::RuleTyperef;
}

void SesameParser::TyperefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef(this);
}

void SesameParser::TyperefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef(this);
}


antlrcpp::Any SesameParser::TyperefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::TyperefContext* SesameParser::typeref() {
  TyperefContext *_localctx = _tracker.createInstance<TyperefContext>(_ctx, getState());
  enterRule(_localctx, 46, SesameParser::RuleTyperef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    typeref_base();
    setState(298);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::ASTERISK)
      | (1ULL << SesameParser::LPAREN)
      | (1ULL << SesameParser::LBRACKET))) != 0)) {
      setState(296);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(286);
        match(SesameParser::LBRACKET);
        setState(287);
        match(SesameParser::RBRACKET);
        break;
      }

      case 2: {
        setState(288);
        match(SesameParser::LBRACKET);
        setState(289);
        match(SesameParser::INTEGER);
        setState(290);
        match(SesameParser::RBRACKET);
        break;
      }

      case 3: {
        setState(291);
        match(SesameParser::ASTERISK);
        break;
      }

      case 4: {
        setState(292);
        match(SesameParser::LPAREN);
        setState(293);
        param_typerefs();
        setState(294);
        match(SesameParser::RPAREN);
        break;
      }

      }
      setState(300);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Typeref_baseContext ------------------------------------------------------------------

SesameParser::Typeref_baseContext::Typeref_baseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Typeref_baseContext::S_VOID() {
  return getToken(SesameParser::S_VOID, 0);
}

tree::TerminalNode* SesameParser::Typeref_baseContext::S_CHAR() {
  return getToken(SesameParser::S_CHAR, 0);
}

tree::TerminalNode* SesameParser::Typeref_baseContext::S_SHORT() {
  return getToken(SesameParser::S_SHORT, 0);
}

tree::TerminalNode* SesameParser::Typeref_baseContext::S_INT() {
  return getToken(SesameParser::S_INT, 0);
}

tree::TerminalNode* SesameParser::Typeref_baseContext::S_LONG() {
  return getToken(SesameParser::S_LONG, 0);
}

tree::TerminalNode* SesameParser::Typeref_baseContext::S_UNSIGNED() {
  return getToken(SesameParser::S_UNSIGNED, 0);
}

tree::TerminalNode* SesameParser::Typeref_baseContext::S_STRUCT() {
  return getToken(SesameParser::S_STRUCT, 0);
}

tree::TerminalNode* SesameParser::Typeref_baseContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}

tree::TerminalNode* SesameParser::Typeref_baseContext::S_UNION() {
  return getToken(SesameParser::S_UNION, 0);
}


size_t SesameParser::Typeref_baseContext::getRuleIndex() const {
  return SesameParser::RuleTyperef_base;
}

void SesameParser::Typeref_baseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_base(this);
}

void SesameParser::Typeref_baseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_base(this);
}


antlrcpp::Any SesameParser::Typeref_baseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_base(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Typeref_baseContext* SesameParser::typeref_base() {
  Typeref_baseContext *_localctx = _tracker.createInstance<Typeref_baseContext>(_ctx, getState());
  enterRule(_localctx, 48, SesameParser::RuleTyperef_base);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(301);
      match(SesameParser::S_VOID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(302);
      match(SesameParser::S_CHAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(303);
      match(SesameParser::S_SHORT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(304);
      match(SesameParser::S_INT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(305);
      match(SesameParser::S_LONG);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(306);
      match(SesameParser::S_UNSIGNED);
      setState(307);
      match(SesameParser::S_CHAR);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(308);
      match(SesameParser::S_UNSIGNED);
      setState(309);
      match(SesameParser::S_SHORT);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(310);
      match(SesameParser::S_UNSIGNED);
      setState(311);
      match(SesameParser::S_INT);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(312);
      match(SesameParser::S_UNSIGNED);
      setState(313);
      match(SesameParser::S_LONG);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(314);
      match(SesameParser::S_STRUCT);
      setState(315);
      match(SesameParser::IDENTIFIER);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(316);
      match(SesameParser::S_UNION);
      setState(317);
      match(SesameParser::IDENTIFIER);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(318);
      match(SesameParser::IDENTIFIER);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_typerefsContext ------------------------------------------------------------------

SesameParser::Param_typerefsContext::Param_typerefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Param_typerefsContext::S_VOID() {
  return getToken(SesameParser::S_VOID, 0);
}

SesameParser::Fixed_param_typerefsContext* SesameParser::Param_typerefsContext::fixed_param_typerefs() {
  return getRuleContext<SesameParser::Fixed_param_typerefsContext>(0);
}

tree::TerminalNode* SesameParser::Param_typerefsContext::COMMA() {
  return getToken(SesameParser::COMMA, 0);
}

tree::TerminalNode* SesameParser::Param_typerefsContext::CDOTS() {
  return getToken(SesameParser::CDOTS, 0);
}


size_t SesameParser::Param_typerefsContext::getRuleIndex() const {
  return SesameParser::RuleParam_typerefs;
}

void SesameParser::Param_typerefsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam_typerefs(this);
}

void SesameParser::Param_typerefsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam_typerefs(this);
}


antlrcpp::Any SesameParser::Param_typerefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitParam_typerefs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Param_typerefsContext* SesameParser::param_typerefs() {
  Param_typerefsContext *_localctx = _tracker.createInstance<Param_typerefsContext>(_ctx, getState());
  enterRule(_localctx, 50, SesameParser::RuleParam_typerefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(327);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(321);
      match(SesameParser::S_VOID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(322);
      fixed_param_typerefs();
      setState(325);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SesameParser::COMMA) {
        setState(323);
        match(SesameParser::COMMA);
        setState(324);
        match(SesameParser::CDOTS);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fixed_param_typerefsContext ------------------------------------------------------------------

SesameParser::Fixed_param_typerefsContext::Fixed_param_typerefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::TyperefContext *> SesameParser::Fixed_param_typerefsContext::typeref() {
  return getRuleContexts<SesameParser::TyperefContext>();
}

SesameParser::TyperefContext* SesameParser::Fixed_param_typerefsContext::typeref(size_t i) {
  return getRuleContext<SesameParser::TyperefContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Fixed_param_typerefsContext::COMMA() {
  return getTokens(SesameParser::COMMA);
}

tree::TerminalNode* SesameParser::Fixed_param_typerefsContext::COMMA(size_t i) {
  return getToken(SesameParser::COMMA, i);
}


size_t SesameParser::Fixed_param_typerefsContext::getRuleIndex() const {
  return SesameParser::RuleFixed_param_typerefs;
}

void SesameParser::Fixed_param_typerefsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFixed_param_typerefs(this);
}

void SesameParser::Fixed_param_typerefsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFixed_param_typerefs(this);
}


antlrcpp::Any SesameParser::Fixed_param_typerefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitFixed_param_typerefs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Fixed_param_typerefsContext* SesameParser::fixed_param_typerefs() {
  Fixed_param_typerefsContext *_localctx = _tracker.createInstance<Fixed_param_typerefsContext>(_ctx, getState());
  enterRule(_localctx, 52, SesameParser::RuleFixed_param_typerefs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(329);
    typeref();
    setState(334);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(330);
        match(SesameParser::COMMA);
        setState(331);
        typeref(); 
      }
      setState(336);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtsContext ------------------------------------------------------------------

SesameParser::StmtsContext::StmtsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::StmtContext *> SesameParser::StmtsContext::stmt() {
  return getRuleContexts<SesameParser::StmtContext>();
}

SesameParser::StmtContext* SesameParser::StmtsContext::stmt(size_t i) {
  return getRuleContext<SesameParser::StmtContext>(i);
}


size_t SesameParser::StmtsContext::getRuleIndex() const {
  return SesameParser::RuleStmts;
}

void SesameParser::StmtsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmts(this);
}

void SesameParser::StmtsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmts(this);
}


antlrcpp::Any SesameParser::StmtsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitStmts(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::StmtsContext* SesameParser::stmts() {
  StmtsContext *_localctx = _tracker.createInstance<StmtsContext>(_ctx, getState());
  enterRule(_localctx, 54, SesameParser::RuleStmts);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & ((1ULL << (SesameParser::S_IF - 14))
      | (1ULL << (SesameParser::S_SWITCH - 14))
      | (1ULL << (SesameParser::S_WHILE - 14))
      | (1ULL << (SesameParser::S_DO - 14))
      | (1ULL << (SesameParser::S_FOR - 14))
      | (1ULL << (SesameParser::S_RETURN - 14))
      | (1ULL << (SesameParser::S_BREAK - 14))
      | (1ULL << (SesameParser::S_CONTINUE - 14))
      | (1ULL << (SesameParser::S_GOTO - 14))
      | (1ULL << (SesameParser::S_SIZEOF - 14))
      | (1ULL << (SesameParser::SEMI - 14))
      | (1ULL << (SesameParser::PLUS - 14))
      | (1ULL << (SesameParser::MINUS - 14))
      | (1ULL << (SesameParser::ASTERISK - 14))
      | (1ULL << (SesameParser::AMPERSAND - 14))
      | (1ULL << (SesameParser::LPAREN - 14))
      | (1ULL << (SesameParser::LBRACE - 14))
      | (1ULL << (SesameParser::EXCLAMATION_OPERATOR - 14))
      | (1ULL << (SesameParser::TILDE_OPERATOR - 14))
      | (1ULL << (SesameParser::S_CHARACTER - 14))
      | (1ULL << (SesameParser::S_STRING - 14))
      | (1ULL << (SesameParser::IDENTIFIER - 14))
      | (1ULL << (SesameParser::INTEGER - 14))
      | (1ULL << (SesameParser::HEX - 14))
      | (1ULL << (SesameParser::OCT - 14)))) != 0)) {
      setState(337);
      stmt();
      setState(342);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

SesameParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::StmtContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}

SesameParser::Labeled_stmtContext* SesameParser::StmtContext::labeled_stmt() {
  return getRuleContext<SesameParser::Labeled_stmtContext>(0);
}

SesameParser::ExprContext* SesameParser::StmtContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

SesameParser::BlockContext* SesameParser::StmtContext::block() {
  return getRuleContext<SesameParser::BlockContext>(0);
}

SesameParser::If_stmtContext* SesameParser::StmtContext::if_stmt() {
  return getRuleContext<SesameParser::If_stmtContext>(0);
}

SesameParser::While_stmtContext* SesameParser::StmtContext::while_stmt() {
  return getRuleContext<SesameParser::While_stmtContext>(0);
}

SesameParser::Do_while_stmtContext* SesameParser::StmtContext::do_while_stmt() {
  return getRuleContext<SesameParser::Do_while_stmtContext>(0);
}

SesameParser::For_stmtContext* SesameParser::StmtContext::for_stmt() {
  return getRuleContext<SesameParser::For_stmtContext>(0);
}

SesameParser::Switch_stmtContext* SesameParser::StmtContext::switch_stmt() {
  return getRuleContext<SesameParser::Switch_stmtContext>(0);
}

SesameParser::Break_stmtContext* SesameParser::StmtContext::break_stmt() {
  return getRuleContext<SesameParser::Break_stmtContext>(0);
}

SesameParser::Continue_stmtContext* SesameParser::StmtContext::continue_stmt() {
  return getRuleContext<SesameParser::Continue_stmtContext>(0);
}

SesameParser::Goto_stmtContext* SesameParser::StmtContext::goto_stmt() {
  return getRuleContext<SesameParser::Goto_stmtContext>(0);
}

SesameParser::Return_stmtContext* SesameParser::StmtContext::return_stmt() {
  return getRuleContext<SesameParser::Return_stmtContext>(0);
}


size_t SesameParser::StmtContext::getRuleIndex() const {
  return SesameParser::RuleStmt;
}

void SesameParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void SesameParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any SesameParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::StmtContext* SesameParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 56, SesameParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(358);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(343);
      match(SesameParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(344);
      labeled_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(345);
      expr();
      setState(346);
      match(SesameParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(348);
      block();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(349);
      if_stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(350);
      while_stmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(351);
      do_while_stmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(352);
      for_stmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(353);
      switch_stmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(354);
      break_stmt();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(355);
      continue_stmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(356);
      goto_stmt();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(357);
      return_stmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Labeled_stmtContext ------------------------------------------------------------------

SesameParser::Labeled_stmtContext::Labeled_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Labeled_stmtContext::COLON() {
  return getToken(SesameParser::COLON, 0);
}

SesameParser::StmtContext* SesameParser::Labeled_stmtContext::stmt() {
  return getRuleContext<SesameParser::StmtContext>(0);
}

tree::TerminalNode* SesameParser::Labeled_stmtContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}


size_t SesameParser::Labeled_stmtContext::getRuleIndex() const {
  return SesameParser::RuleLabeled_stmt;
}

void SesameParser::Labeled_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabeled_stmt(this);
}

void SesameParser::Labeled_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabeled_stmt(this);
}


antlrcpp::Any SesameParser::Labeled_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitLabeled_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Labeled_stmtContext* SesameParser::labeled_stmt() {
  Labeled_stmtContext *_localctx = _tracker.createInstance<Labeled_stmtContext>(_ctx, getState());
  enterRule(_localctx, 58, SesameParser::RuleLabeled_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    dynamic_cast<Labeled_stmtContext *>(_localctx)->label_name = match(SesameParser::IDENTIFIER);
    setState(361);
    match(SesameParser::COLON);
    setState(362);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stmtContext ------------------------------------------------------------------

SesameParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::If_stmtContext::S_IF() {
  return getToken(SesameParser::S_IF, 0);
}

tree::TerminalNode* SesameParser::If_stmtContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

SesameParser::ExprContext* SesameParser::If_stmtContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

tree::TerminalNode* SesameParser::If_stmtContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

std::vector<SesameParser::StmtContext *> SesameParser::If_stmtContext::stmt() {
  return getRuleContexts<SesameParser::StmtContext>();
}

SesameParser::StmtContext* SesameParser::If_stmtContext::stmt(size_t i) {
  return getRuleContext<SesameParser::StmtContext>(i);
}

tree::TerminalNode* SesameParser::If_stmtContext::S_ELSE() {
  return getToken(SesameParser::S_ELSE, 0);
}


size_t SesameParser::If_stmtContext::getRuleIndex() const {
  return SesameParser::RuleIf_stmt;
}

void SesameParser::If_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_stmt(this);
}

void SesameParser::If_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_stmt(this);
}


antlrcpp::Any SesameParser::If_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitIf_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::If_stmtContext* SesameParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 60, SesameParser::RuleIf_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    match(SesameParser::S_IF);
    setState(365);
    match(SesameParser::LPAREN);
    setState(366);
    expr();
    setState(367);
    match(SesameParser::RPAREN);
    setState(368);
    stmt();
    setState(371);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(369);
      match(SesameParser::S_ELSE);
      setState(370);
      stmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_stmtContext ------------------------------------------------------------------

SesameParser::While_stmtContext::While_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::While_stmtContext::S_WHILE() {
  return getToken(SesameParser::S_WHILE, 0);
}

tree::TerminalNode* SesameParser::While_stmtContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

SesameParser::ExprContext* SesameParser::While_stmtContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

tree::TerminalNode* SesameParser::While_stmtContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

SesameParser::StmtContext* SesameParser::While_stmtContext::stmt() {
  return getRuleContext<SesameParser::StmtContext>(0);
}


size_t SesameParser::While_stmtContext::getRuleIndex() const {
  return SesameParser::RuleWhile_stmt;
}

void SesameParser::While_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_stmt(this);
}

void SesameParser::While_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_stmt(this);
}


antlrcpp::Any SesameParser::While_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitWhile_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::While_stmtContext* SesameParser::while_stmt() {
  While_stmtContext *_localctx = _tracker.createInstance<While_stmtContext>(_ctx, getState());
  enterRule(_localctx, 62, SesameParser::RuleWhile_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    match(SesameParser::S_WHILE);
    setState(374);
    match(SesameParser::LPAREN);
    setState(375);
    expr();
    setState(376);
    match(SesameParser::RPAREN);
    setState(377);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Do_while_stmtContext ------------------------------------------------------------------

SesameParser::Do_while_stmtContext::Do_while_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Do_while_stmtContext::S_DO() {
  return getToken(SesameParser::S_DO, 0);
}

tree::TerminalNode* SesameParser::Do_while_stmtContext::S_WHILE() {
  return getToken(SesameParser::S_WHILE, 0);
}

tree::TerminalNode* SesameParser::Do_while_stmtContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

tree::TerminalNode* SesameParser::Do_while_stmtContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

tree::TerminalNode* SesameParser::Do_while_stmtContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}

SesameParser::StmtContext* SesameParser::Do_while_stmtContext::stmt() {
  return getRuleContext<SesameParser::StmtContext>(0);
}

SesameParser::ExprContext* SesameParser::Do_while_stmtContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}


size_t SesameParser::Do_while_stmtContext::getRuleIndex() const {
  return SesameParser::RuleDo_while_stmt;
}

void SesameParser::Do_while_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDo_while_stmt(this);
}

void SesameParser::Do_while_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDo_while_stmt(this);
}


antlrcpp::Any SesameParser::Do_while_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDo_while_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Do_while_stmtContext* SesameParser::do_while_stmt() {
  Do_while_stmtContext *_localctx = _tracker.createInstance<Do_while_stmtContext>(_ctx, getState());
  enterRule(_localctx, 64, SesameParser::RuleDo_while_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    match(SesameParser::S_DO);
    setState(380);
    dynamic_cast<Do_while_stmtContext *>(_localctx)->body = stmt();
    setState(381);
    match(SesameParser::S_WHILE);
    setState(382);
    match(SesameParser::LPAREN);
    setState(383);
    dynamic_cast<Do_while_stmtContext *>(_localctx)->cond = expr();
    setState(384);
    match(SesameParser::RPAREN);
    setState(385);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_stmtContext ------------------------------------------------------------------

SesameParser::For_stmtContext::For_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::For_stmtContext::S_FOR() {
  return getToken(SesameParser::S_FOR, 0);
}

tree::TerminalNode* SesameParser::For_stmtContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> SesameParser::For_stmtContext::SEMI() {
  return getTokens(SesameParser::SEMI);
}

tree::TerminalNode* SesameParser::For_stmtContext::SEMI(size_t i) {
  return getToken(SesameParser::SEMI, i);
}

tree::TerminalNode* SesameParser::For_stmtContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

std::vector<SesameParser::ExprContext *> SesameParser::For_stmtContext::expr() {
  return getRuleContexts<SesameParser::ExprContext>();
}

SesameParser::ExprContext* SesameParser::For_stmtContext::expr(size_t i) {
  return getRuleContext<SesameParser::ExprContext>(i);
}

SesameParser::StmtContext* SesameParser::For_stmtContext::stmt() {
  return getRuleContext<SesameParser::StmtContext>(0);
}


size_t SesameParser::For_stmtContext::getRuleIndex() const {
  return SesameParser::RuleFor_stmt;
}

void SesameParser::For_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_stmt(this);
}

void SesameParser::For_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_stmt(this);
}


antlrcpp::Any SesameParser::For_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitFor_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::For_stmtContext* SesameParser::for_stmt() {
  For_stmtContext *_localctx = _tracker.createInstance<For_stmtContext>(_ctx, getState());
  enterRule(_localctx, 66, SesameParser::RuleFor_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    match(SesameParser::S_FOR);
    setState(388);
    match(SesameParser::LPAREN);
    setState(390);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 28) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 28)) & ((1ULL << (SesameParser::S_SIZEOF - 28))
      | (1ULL << (SesameParser::PLUS - 28))
      | (1ULL << (SesameParser::MINUS - 28))
      | (1ULL << (SesameParser::ASTERISK - 28))
      | (1ULL << (SesameParser::AMPERSAND - 28))
      | (1ULL << (SesameParser::LPAREN - 28))
      | (1ULL << (SesameParser::EXCLAMATION_OPERATOR - 28))
      | (1ULL << (SesameParser::TILDE_OPERATOR - 28))
      | (1ULL << (SesameParser::S_CHARACTER - 28))
      | (1ULL << (SesameParser::S_STRING - 28))
      | (1ULL << (SesameParser::IDENTIFIER - 28))
      | (1ULL << (SesameParser::INTEGER - 28))
      | (1ULL << (SesameParser::HEX - 28))
      | (1ULL << (SesameParser::OCT - 28)))) != 0)) {
      setState(389);
      dynamic_cast<For_stmtContext *>(_localctx)->init = expr();
    }
    setState(392);
    match(SesameParser::SEMI);
    setState(394);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 28) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 28)) & ((1ULL << (SesameParser::S_SIZEOF - 28))
      | (1ULL << (SesameParser::PLUS - 28))
      | (1ULL << (SesameParser::MINUS - 28))
      | (1ULL << (SesameParser::ASTERISK - 28))
      | (1ULL << (SesameParser::AMPERSAND - 28))
      | (1ULL << (SesameParser::LPAREN - 28))
      | (1ULL << (SesameParser::EXCLAMATION_OPERATOR - 28))
      | (1ULL << (SesameParser::TILDE_OPERATOR - 28))
      | (1ULL << (SesameParser::S_CHARACTER - 28))
      | (1ULL << (SesameParser::S_STRING - 28))
      | (1ULL << (SesameParser::IDENTIFIER - 28))
      | (1ULL << (SesameParser::INTEGER - 28))
      | (1ULL << (SesameParser::HEX - 28))
      | (1ULL << (SesameParser::OCT - 28)))) != 0)) {
      setState(393);
      dynamic_cast<For_stmtContext *>(_localctx)->cond = expr();
    }
    setState(396);
    match(SesameParser::SEMI);
    setState(397);
    dynamic_cast<For_stmtContext *>(_localctx)->incr = expr();
    setState(398);
    match(SesameParser::RPAREN);
    setState(399);
    dynamic_cast<For_stmtContext *>(_localctx)->body = stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_stmtContext ------------------------------------------------------------------

SesameParser::Switch_stmtContext::Switch_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Switch_stmtContext::S_SWITCH() {
  return getToken(SesameParser::S_SWITCH, 0);
}

tree::TerminalNode* SesameParser::Switch_stmtContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

tree::TerminalNode* SesameParser::Switch_stmtContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

tree::TerminalNode* SesameParser::Switch_stmtContext::LBRACE() {
  return getToken(SesameParser::LBRACE, 0);
}

tree::TerminalNode* SesameParser::Switch_stmtContext::RBRACE() {
  return getToken(SesameParser::RBRACE, 0);
}

SesameParser::ExprContext* SesameParser::Switch_stmtContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

SesameParser::Case_clausesContext* SesameParser::Switch_stmtContext::case_clauses() {
  return getRuleContext<SesameParser::Case_clausesContext>(0);
}


size_t SesameParser::Switch_stmtContext::getRuleIndex() const {
  return SesameParser::RuleSwitch_stmt;
}

void SesameParser::Switch_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_stmt(this);
}

void SesameParser::Switch_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_stmt(this);
}


antlrcpp::Any SesameParser::Switch_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Switch_stmtContext* SesameParser::switch_stmt() {
  Switch_stmtContext *_localctx = _tracker.createInstance<Switch_stmtContext>(_ctx, getState());
  enterRule(_localctx, 68, SesameParser::RuleSwitch_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(SesameParser::S_SWITCH);
    setState(402);
    match(SesameParser::LPAREN);
    setState(403);
    dynamic_cast<Switch_stmtContext *>(_localctx)->cond = expr();
    setState(404);
    match(SesameParser::RPAREN);
    setState(405);
    match(SesameParser::LBRACE);
    setState(406);
    dynamic_cast<Switch_stmtContext *>(_localctx)->body = case_clauses();
    setState(407);
    match(SesameParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_clausesContext ------------------------------------------------------------------

SesameParser::Case_clausesContext::Case_clausesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Case_clauseContext *> SesameParser::Case_clausesContext::case_clause() {
  return getRuleContexts<SesameParser::Case_clauseContext>();
}

SesameParser::Case_clauseContext* SesameParser::Case_clausesContext::case_clause(size_t i) {
  return getRuleContext<SesameParser::Case_clauseContext>(i);
}

SesameParser::Default_clauseContext* SesameParser::Case_clausesContext::default_clause() {
  return getRuleContext<SesameParser::Default_clauseContext>(0);
}


size_t SesameParser::Case_clausesContext::getRuleIndex() const {
  return SesameParser::RuleCase_clauses;
}

void SesameParser::Case_clausesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_clauses(this);
}

void SesameParser::Case_clausesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_clauses(this);
}


antlrcpp::Any SesameParser::Case_clausesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitCase_clauses(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Case_clausesContext* SesameParser::case_clauses() {
  Case_clausesContext *_localctx = _tracker.createInstance<Case_clausesContext>(_ctx, getState());
  enterRule(_localctx, 70, SesameParser::RuleCase_clauses);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::S_CASE) {
      setState(409);
      case_clause();
      setState(414);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(416);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::S_DEFAULT) {
      setState(415);
      default_clause();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_clauseContext ------------------------------------------------------------------

SesameParser::Case_clauseContext::Case_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::CasesContext* SesameParser::Case_clauseContext::cases() {
  return getRuleContext<SesameParser::CasesContext>(0);
}

SesameParser::Case_bodyContext* SesameParser::Case_clauseContext::case_body() {
  return getRuleContext<SesameParser::Case_bodyContext>(0);
}


size_t SesameParser::Case_clauseContext::getRuleIndex() const {
  return SesameParser::RuleCase_clause;
}

void SesameParser::Case_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_clause(this);
}

void SesameParser::Case_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_clause(this);
}


antlrcpp::Any SesameParser::Case_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitCase_clause(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Case_clauseContext* SesameParser::case_clause() {
  Case_clauseContext *_localctx = _tracker.createInstance<Case_clauseContext>(_ctx, getState());
  enterRule(_localctx, 72, SesameParser::RuleCase_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    dynamic_cast<Case_clauseContext *>(_localctx)->values = cases();
    setState(419);
    dynamic_cast<Case_clauseContext *>(_localctx)->body = case_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CasesContext ------------------------------------------------------------------

SesameParser::CasesContext::CasesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SesameParser::CasesContext::S_CASE() {
  return getTokens(SesameParser::S_CASE);
}

tree::TerminalNode* SesameParser::CasesContext::S_CASE(size_t i) {
  return getToken(SesameParser::S_CASE, i);
}

std::vector<SesameParser::PrimaryContext *> SesameParser::CasesContext::primary() {
  return getRuleContexts<SesameParser::PrimaryContext>();
}

SesameParser::PrimaryContext* SesameParser::CasesContext::primary(size_t i) {
  return getRuleContext<SesameParser::PrimaryContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::CasesContext::COLON() {
  return getTokens(SesameParser::COLON);
}

tree::TerminalNode* SesameParser::CasesContext::COLON(size_t i) {
  return getToken(SesameParser::COLON, i);
}


size_t SesameParser::CasesContext::getRuleIndex() const {
  return SesameParser::RuleCases;
}

void SesameParser::CasesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCases(this);
}

void SesameParser::CasesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCases(this);
}


antlrcpp::Any SesameParser::CasesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitCases(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::CasesContext* SesameParser::cases() {
  CasesContext *_localctx = _tracker.createInstance<CasesContext>(_ctx, getState());
  enterRule(_localctx, 74, SesameParser::RuleCases);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(421);
      match(SesameParser::S_CASE);
      setState(422);
      primary();
      setState(423);
      match(SesameParser::COLON);
      setState(427); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SesameParser::S_CASE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Default_clauseContext ------------------------------------------------------------------

SesameParser::Default_clauseContext::Default_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Default_clauseContext::S_DEFAULT() {
  return getToken(SesameParser::S_DEFAULT, 0);
}

tree::TerminalNode* SesameParser::Default_clauseContext::COLON() {
  return getToken(SesameParser::COLON, 0);
}

SesameParser::Case_bodyContext* SesameParser::Default_clauseContext::case_body() {
  return getRuleContext<SesameParser::Case_bodyContext>(0);
}


size_t SesameParser::Default_clauseContext::getRuleIndex() const {
  return SesameParser::RuleDefault_clause;
}

void SesameParser::Default_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefault_clause(this);
}

void SesameParser::Default_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefault_clause(this);
}


antlrcpp::Any SesameParser::Default_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDefault_clause(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Default_clauseContext* SesameParser::default_clause() {
  Default_clauseContext *_localctx = _tracker.createInstance<Default_clauseContext>(_ctx, getState());
  enterRule(_localctx, 76, SesameParser::RuleDefault_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    match(SesameParser::S_DEFAULT);
    setState(430);
    match(SesameParser::COLON);
    setState(431);
    dynamic_cast<Default_clauseContext *>(_localctx)->body = case_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_bodyContext ------------------------------------------------------------------

SesameParser::Case_bodyContext::Case_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::StmtContext *> SesameParser::Case_bodyContext::stmt() {
  return getRuleContexts<SesameParser::StmtContext>();
}

SesameParser::StmtContext* SesameParser::Case_bodyContext::stmt(size_t i) {
  return getRuleContext<SesameParser::StmtContext>(i);
}


size_t SesameParser::Case_bodyContext::getRuleIndex() const {
  return SesameParser::RuleCase_body;
}

void SesameParser::Case_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_body(this);
}

void SesameParser::Case_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_body(this);
}


antlrcpp::Any SesameParser::Case_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitCase_body(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Case_bodyContext* SesameParser::case_body() {
  Case_bodyContext *_localctx = _tracker.createInstance<Case_bodyContext>(_ctx, getState());
  enterRule(_localctx, 78, SesameParser::RuleCase_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(433);
      stmt();
      setState(436); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & ((1ULL << (SesameParser::S_IF - 14))
      | (1ULL << (SesameParser::S_SWITCH - 14))
      | (1ULL << (SesameParser::S_WHILE - 14))
      | (1ULL << (SesameParser::S_DO - 14))
      | (1ULL << (SesameParser::S_FOR - 14))
      | (1ULL << (SesameParser::S_RETURN - 14))
      | (1ULL << (SesameParser::S_BREAK - 14))
      | (1ULL << (SesameParser::S_CONTINUE - 14))
      | (1ULL << (SesameParser::S_GOTO - 14))
      | (1ULL << (SesameParser::S_SIZEOF - 14))
      | (1ULL << (SesameParser::SEMI - 14))
      | (1ULL << (SesameParser::PLUS - 14))
      | (1ULL << (SesameParser::MINUS - 14))
      | (1ULL << (SesameParser::ASTERISK - 14))
      | (1ULL << (SesameParser::AMPERSAND - 14))
      | (1ULL << (SesameParser::LPAREN - 14))
      | (1ULL << (SesameParser::LBRACE - 14))
      | (1ULL << (SesameParser::EXCLAMATION_OPERATOR - 14))
      | (1ULL << (SesameParser::TILDE_OPERATOR - 14))
      | (1ULL << (SesameParser::S_CHARACTER - 14))
      | (1ULL << (SesameParser::S_STRING - 14))
      | (1ULL << (SesameParser::IDENTIFIER - 14))
      | (1ULL << (SesameParser::INTEGER - 14))
      | (1ULL << (SesameParser::HEX - 14))
      | (1ULL << (SesameParser::OCT - 14)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_stmtContext ------------------------------------------------------------------

SesameParser::Break_stmtContext::Break_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Break_stmtContext::S_BREAK() {
  return getToken(SesameParser::S_BREAK, 0);
}

tree::TerminalNode* SesameParser::Break_stmtContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Break_stmtContext::getRuleIndex() const {
  return SesameParser::RuleBreak_stmt;
}

void SesameParser::Break_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreak_stmt(this);
}

void SesameParser::Break_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreak_stmt(this);
}


antlrcpp::Any SesameParser::Break_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitBreak_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Break_stmtContext* SesameParser::break_stmt() {
  Break_stmtContext *_localctx = _tracker.createInstance<Break_stmtContext>(_ctx, getState());
  enterRule(_localctx, 80, SesameParser::RuleBreak_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    match(SesameParser::S_BREAK);
    setState(439);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Continue_stmtContext ------------------------------------------------------------------

SesameParser::Continue_stmtContext::Continue_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Continue_stmtContext::S_CONTINUE() {
  return getToken(SesameParser::S_CONTINUE, 0);
}

tree::TerminalNode* SesameParser::Continue_stmtContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Continue_stmtContext::getRuleIndex() const {
  return SesameParser::RuleContinue_stmt;
}

void SesameParser::Continue_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinue_stmt(this);
}

void SesameParser::Continue_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinue_stmt(this);
}


antlrcpp::Any SesameParser::Continue_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitContinue_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Continue_stmtContext* SesameParser::continue_stmt() {
  Continue_stmtContext *_localctx = _tracker.createInstance<Continue_stmtContext>(_ctx, getState());
  enterRule(_localctx, 82, SesameParser::RuleContinue_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(441);
    match(SesameParser::S_CONTINUE);
    setState(442);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Goto_stmtContext ------------------------------------------------------------------

SesameParser::Goto_stmtContext::Goto_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Goto_stmtContext::S_GOTO() {
  return getToken(SesameParser::S_GOTO, 0);
}

tree::TerminalNode* SesameParser::Goto_stmtContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}

tree::TerminalNode* SesameParser::Goto_stmtContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}


size_t SesameParser::Goto_stmtContext::getRuleIndex() const {
  return SesameParser::RuleGoto_stmt;
}

void SesameParser::Goto_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoto_stmt(this);
}

void SesameParser::Goto_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoto_stmt(this);
}


antlrcpp::Any SesameParser::Goto_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitGoto_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Goto_stmtContext* SesameParser::goto_stmt() {
  Goto_stmtContext *_localctx = _tracker.createInstance<Goto_stmtContext>(_ctx, getState());
  enterRule(_localctx, 84, SesameParser::RuleGoto_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    match(SesameParser::S_GOTO);
    setState(445);
    dynamic_cast<Goto_stmtContext *>(_localctx)->label_name = match(SesameParser::IDENTIFIER);
    setState(446);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

SesameParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Return_stmtContext::S_RETURN() {
  return getToken(SesameParser::S_RETURN, 0);
}

tree::TerminalNode* SesameParser::Return_stmtContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}

SesameParser::ExprContext* SesameParser::Return_stmtContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}


size_t SesameParser::Return_stmtContext::getRuleIndex() const {
  return SesameParser::RuleReturn_stmt;
}

void SesameParser::Return_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_stmt(this);
}

void SesameParser::Return_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_stmt(this);
}


antlrcpp::Any SesameParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Return_stmtContext* SesameParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 86, SesameParser::RuleReturn_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(448);
    match(SesameParser::S_RETURN);
    setState(450);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 28) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 28)) & ((1ULL << (SesameParser::S_SIZEOF - 28))
      | (1ULL << (SesameParser::PLUS - 28))
      | (1ULL << (SesameParser::MINUS - 28))
      | (1ULL << (SesameParser::ASTERISK - 28))
      | (1ULL << (SesameParser::AMPERSAND - 28))
      | (1ULL << (SesameParser::LPAREN - 28))
      | (1ULL << (SesameParser::EXCLAMATION_OPERATOR - 28))
      | (1ULL << (SesameParser::TILDE_OPERATOR - 28))
      | (1ULL << (SesameParser::S_CHARACTER - 28))
      | (1ULL << (SesameParser::S_STRING - 28))
      | (1ULL << (SesameParser::IDENTIFIER - 28))
      | (1ULL << (SesameParser::INTEGER - 28))
      | (1ULL << (SesameParser::HEX - 28))
      | (1ULL << (SesameParser::OCT - 28)))) != 0)) {
      setState(449);
      expr();
    }
    setState(452);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

SesameParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::TermContext* SesameParser::ExprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

tree::TerminalNode* SesameParser::ExprContext::EQUAL() {
  return getToken(SesameParser::EQUAL, 0);
}

SesameParser::ExprContext* SesameParser::ExprContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

SesameParser::Opassign_opContext* SesameParser::ExprContext::opassign_op() {
  return getRuleContext<SesameParser::Opassign_opContext>(0);
}

SesameParser::Expr10Context* SesameParser::ExprContext::expr10() {
  return getRuleContext<SesameParser::Expr10Context>(0);
}


size_t SesameParser::ExprContext::getRuleIndex() const {
  return SesameParser::RuleExpr;
}

void SesameParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void SesameParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any SesameParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::ExprContext* SesameParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 88, SesameParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(463);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(454);
      term();
      setState(455);
      match(SesameParser::EQUAL);
      setState(456);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(458);
      term();
      setState(459);
      opassign_op();
      setState(460);
      expr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(462);
      expr10();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opassign_opContext ------------------------------------------------------------------

SesameParser::Opassign_opContext::Opassign_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Opassign_opContext::PLUS() {
  return getToken(SesameParser::PLUS, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::EQUAL() {
  return getToken(SesameParser::EQUAL, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::MINUS() {
  return getToken(SesameParser::MINUS, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::ASTERISK() {
  return getToken(SesameParser::ASTERISK, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::SOLIDUS() {
  return getToken(SesameParser::SOLIDUS, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::PERCENT() {
  return getToken(SesameParser::PERCENT, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::AMPERSAND() {
  return getToken(SesameParser::AMPERSAND, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::BAR() {
  return getToken(SesameParser::BAR, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::CARRET_OPERATOR_PART() {
  return getToken(SesameParser::CARRET_OPERATOR_PART, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::LSHIFT() {
  return getToken(SesameParser::LSHIFT, 0);
}

tree::TerminalNode* SesameParser::Opassign_opContext::RSHIFT() {
  return getToken(SesameParser::RSHIFT, 0);
}


size_t SesameParser::Opassign_opContext::getRuleIndex() const {
  return SesameParser::RuleOpassign_op;
}

void SesameParser::Opassign_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpassign_op(this);
}

void SesameParser::Opassign_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpassign_op(this);
}


antlrcpp::Any SesameParser::Opassign_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitOpassign_op(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Opassign_opContext* SesameParser::opassign_op() {
  Opassign_opContext *_localctx = _tracker.createInstance<Opassign_opContext>(_ctx, getState());
  enterRule(_localctx, 90, SesameParser::RuleOpassign_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(485);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SesameParser::PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(465);
        match(SesameParser::PLUS);
        setState(466);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(467);
        match(SesameParser::MINUS);
        setState(468);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::ASTERISK: {
        enterOuterAlt(_localctx, 3);
        setState(469);
        match(SesameParser::ASTERISK);
        setState(470);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::SOLIDUS: {
        enterOuterAlt(_localctx, 4);
        setState(471);
        match(SesameParser::SOLIDUS);
        setState(472);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::PERCENT: {
        enterOuterAlt(_localctx, 5);
        setState(473);
        match(SesameParser::PERCENT);
        setState(474);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::AMPERSAND: {
        enterOuterAlt(_localctx, 6);
        setState(475);
        match(SesameParser::AMPERSAND);
        setState(476);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::BAR: {
        enterOuterAlt(_localctx, 7);
        setState(477);
        match(SesameParser::BAR);
        setState(478);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::CARRET_OPERATOR_PART: {
        enterOuterAlt(_localctx, 8);
        setState(479);
        match(SesameParser::CARRET_OPERATOR_PART);
        setState(480);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::LSHIFT: {
        enterOuterAlt(_localctx, 9);
        setState(481);
        match(SesameParser::LSHIFT);
        setState(482);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::RSHIFT: {
        enterOuterAlt(_localctx, 10);
        setState(483);
        match(SesameParser::RSHIFT);
        setState(484);
        match(SesameParser::EQUAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr10Context ------------------------------------------------------------------

SesameParser::Expr10Context::Expr10Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr8Context* SesameParser::Expr10Context::expr8() {
  return getRuleContext<SesameParser::Expr8Context>(0);
}

tree::TerminalNode* SesameParser::Expr10Context::QUESTION() {
  return getToken(SesameParser::QUESTION, 0);
}

SesameParser::ExprContext* SesameParser::Expr10Context::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

tree::TerminalNode* SesameParser::Expr10Context::COLON() {
  return getToken(SesameParser::COLON, 0);
}

SesameParser::Expr10Context* SesameParser::Expr10Context::expr10() {
  return getRuleContext<SesameParser::Expr10Context>(0);
}


size_t SesameParser::Expr10Context::getRuleIndex() const {
  return SesameParser::RuleExpr10;
}

void SesameParser::Expr10Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr10(this);
}

void SesameParser::Expr10Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr10(this);
}


antlrcpp::Any SesameParser::Expr10Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr10(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr10Context* SesameParser::expr10() {
  Expr10Context *_localctx = _tracker.createInstance<Expr10Context>(_ctx, getState());
  enterRule(_localctx, 92, SesameParser::RuleExpr10);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    expr8();
    setState(493);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::QUESTION) {
      setState(488);
      match(SesameParser::QUESTION);
      setState(489);
      expr();
      setState(490);
      match(SesameParser::COLON);
      setState(491);
      expr10();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr8Context ------------------------------------------------------------------

SesameParser::Expr8Context::Expr8Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Expr7Context *> SesameParser::Expr8Context::expr7() {
  return getRuleContexts<SesameParser::Expr7Context>();
}

SesameParser::Expr7Context* SesameParser::Expr8Context::expr7(size_t i) {
  return getRuleContext<SesameParser::Expr7Context>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr8Context::LOGIC_OR() {
  return getTokens(SesameParser::LOGIC_OR);
}

tree::TerminalNode* SesameParser::Expr8Context::LOGIC_OR(size_t i) {
  return getToken(SesameParser::LOGIC_OR, i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr8Context::LOGIC_AND() {
  return getTokens(SesameParser::LOGIC_AND);
}

tree::TerminalNode* SesameParser::Expr8Context::LOGIC_AND(size_t i) {
  return getToken(SesameParser::LOGIC_AND, i);
}


size_t SesameParser::Expr8Context::getRuleIndex() const {
  return SesameParser::RuleExpr8;
}

void SesameParser::Expr8Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr8(this);
}

void SesameParser::Expr8Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr8(this);
}


antlrcpp::Any SesameParser::Expr8Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr8(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr8Context* SesameParser::expr8() {
  Expr8Context *_localctx = _tracker.createInstance<Expr8Context>(_ctx, getState());
  enterRule(_localctx, 94, SesameParser::RuleExpr8);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(495);
    expr7();
    setState(500);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::LOGIC_AND

    || _la == SesameParser::LOGIC_OR) {
      setState(496);
      _la = _input->LA(1);
      if (!(_la == SesameParser::LOGIC_AND

      || _la == SesameParser::LOGIC_OR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(497);
      expr7();
      setState(502);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr7Context ------------------------------------------------------------------

SesameParser::Expr7Context::Expr7Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Expr6Context *> SesameParser::Expr7Context::expr6() {
  return getRuleContexts<SesameParser::Expr6Context>();
}

SesameParser::Expr6Context* SesameParser::Expr7Context::expr6(size_t i) {
  return getRuleContext<SesameParser::Expr6Context>(i);
}

std::vector<SesameParser::Logical_opContext *> SesameParser::Expr7Context::logical_op() {
  return getRuleContexts<SesameParser::Logical_opContext>();
}

SesameParser::Logical_opContext* SesameParser::Expr7Context::logical_op(size_t i) {
  return getRuleContext<SesameParser::Logical_opContext>(i);
}


size_t SesameParser::Expr7Context::getRuleIndex() const {
  return SesameParser::RuleExpr7;
}

void SesameParser::Expr7Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr7(this);
}

void SesameParser::Expr7Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr7(this);
}


antlrcpp::Any SesameParser::Expr7Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr7(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr7Context* SesameParser::expr7() {
  Expr7Context *_localctx = _tracker.createInstance<Expr7Context>(_ctx, getState());
  enterRule(_localctx, 96, SesameParser::RuleExpr7);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    expr6();
    setState(509);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::LESS)
      | (1ULL << SesameParser::LESS_EQ)
      | (1ULL << SesameParser::GREATER)
      | (1ULL << SesameParser::GREATER_EQ)
      | (1ULL << SesameParser::NOT_EQ)
      | (1ULL << SesameParser::EQ_SIGN))) != 0)) {
      setState(504);
      logical_op();
      setState(505);
      expr6();
      setState(511);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_opContext ------------------------------------------------------------------

SesameParser::Logical_opContext::Logical_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Logical_opContext::LESS() {
  return getToken(SesameParser::LESS, 0);
}

tree::TerminalNode* SesameParser::Logical_opContext::LESS_EQ() {
  return getToken(SesameParser::LESS_EQ, 0);
}

tree::TerminalNode* SesameParser::Logical_opContext::GREATER() {
  return getToken(SesameParser::GREATER, 0);
}

tree::TerminalNode* SesameParser::Logical_opContext::GREATER_EQ() {
  return getToken(SesameParser::GREATER_EQ, 0);
}

tree::TerminalNode* SesameParser::Logical_opContext::NOT_EQ() {
  return getToken(SesameParser::NOT_EQ, 0);
}

tree::TerminalNode* SesameParser::Logical_opContext::EQ_SIGN() {
  return getToken(SesameParser::EQ_SIGN, 0);
}


size_t SesameParser::Logical_opContext::getRuleIndex() const {
  return SesameParser::RuleLogical_op;
}

void SesameParser::Logical_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_op(this);
}

void SesameParser::Logical_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_op(this);
}


antlrcpp::Any SesameParser::Logical_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitLogical_op(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Logical_opContext* SesameParser::logical_op() {
  Logical_opContext *_localctx = _tracker.createInstance<Logical_opContext>(_ctx, getState());
  enterRule(_localctx, 98, SesameParser::RuleLogical_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::LESS)
      | (1ULL << SesameParser::LESS_EQ)
      | (1ULL << SesameParser::GREATER)
      | (1ULL << SesameParser::GREATER_EQ)
      | (1ULL << SesameParser::NOT_EQ)
      | (1ULL << SesameParser::EQ_SIGN))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr6Context ------------------------------------------------------------------

SesameParser::Expr6Context::Expr6Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Expr5Context *> SesameParser::Expr6Context::expr5() {
  return getRuleContexts<SesameParser::Expr5Context>();
}

SesameParser::Expr5Context* SesameParser::Expr6Context::expr5(size_t i) {
  return getRuleContext<SesameParser::Expr5Context>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr6Context::BAR() {
  return getTokens(SesameParser::BAR);
}

tree::TerminalNode* SesameParser::Expr6Context::BAR(size_t i) {
  return getToken(SesameParser::BAR, i);
}


size_t SesameParser::Expr6Context::getRuleIndex() const {
  return SesameParser::RuleExpr6;
}

void SesameParser::Expr6Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr6(this);
}

void SesameParser::Expr6Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr6(this);
}


antlrcpp::Any SesameParser::Expr6Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr6(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr6Context* SesameParser::expr6() {
  Expr6Context *_localctx = _tracker.createInstance<Expr6Context>(_ctx, getState());
  enterRule(_localctx, 100, SesameParser::RuleExpr6);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(514);
    expr5();
    setState(519);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::BAR) {
      setState(515);
      match(SesameParser::BAR);
      setState(516);
      expr5();
      setState(521);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr5Context ------------------------------------------------------------------

SesameParser::Expr5Context::Expr5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Expr4Context *> SesameParser::Expr5Context::expr4() {
  return getRuleContexts<SesameParser::Expr4Context>();
}

SesameParser::Expr4Context* SesameParser::Expr5Context::expr4(size_t i) {
  return getRuleContext<SesameParser::Expr4Context>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr5Context::CARRET_OPERATOR_PART() {
  return getTokens(SesameParser::CARRET_OPERATOR_PART);
}

tree::TerminalNode* SesameParser::Expr5Context::CARRET_OPERATOR_PART(size_t i) {
  return getToken(SesameParser::CARRET_OPERATOR_PART, i);
}


size_t SesameParser::Expr5Context::getRuleIndex() const {
  return SesameParser::RuleExpr5;
}

void SesameParser::Expr5Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr5(this);
}

void SesameParser::Expr5Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr5(this);
}


antlrcpp::Any SesameParser::Expr5Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr5(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr5Context* SesameParser::expr5() {
  Expr5Context *_localctx = _tracker.createInstance<Expr5Context>(_ctx, getState());
  enterRule(_localctx, 102, SesameParser::RuleExpr5);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(522);
    expr4();
    setState(527);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::CARRET_OPERATOR_PART) {
      setState(523);
      match(SesameParser::CARRET_OPERATOR_PART);
      setState(524);
      expr4();
      setState(529);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr4Context ------------------------------------------------------------------

SesameParser::Expr4Context::Expr4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Expr3Context *> SesameParser::Expr4Context::expr3() {
  return getRuleContexts<SesameParser::Expr3Context>();
}

SesameParser::Expr3Context* SesameParser::Expr4Context::expr3(size_t i) {
  return getRuleContext<SesameParser::Expr3Context>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr4Context::AMPERSAND() {
  return getTokens(SesameParser::AMPERSAND);
}

tree::TerminalNode* SesameParser::Expr4Context::AMPERSAND(size_t i) {
  return getToken(SesameParser::AMPERSAND, i);
}


size_t SesameParser::Expr4Context::getRuleIndex() const {
  return SesameParser::RuleExpr4;
}

void SesameParser::Expr4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr4(this);
}

void SesameParser::Expr4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr4(this);
}


antlrcpp::Any SesameParser::Expr4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr4(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr4Context* SesameParser::expr4() {
  Expr4Context *_localctx = _tracker.createInstance<Expr4Context>(_ctx, getState());
  enterRule(_localctx, 104, SesameParser::RuleExpr4);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(530);
    expr3();
    setState(535);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::AMPERSAND) {
      setState(531);
      match(SesameParser::AMPERSAND);
      setState(532);
      expr3();
      setState(537);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr3Context ------------------------------------------------------------------

SesameParser::Expr3Context::Expr3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Expr2Context *> SesameParser::Expr3Context::expr2() {
  return getRuleContexts<SesameParser::Expr2Context>();
}

SesameParser::Expr2Context* SesameParser::Expr3Context::expr2(size_t i) {
  return getRuleContext<SesameParser::Expr2Context>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr3Context::LSHIFT() {
  return getTokens(SesameParser::LSHIFT);
}

tree::TerminalNode* SesameParser::Expr3Context::LSHIFT(size_t i) {
  return getToken(SesameParser::LSHIFT, i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr3Context::RSHIFT() {
  return getTokens(SesameParser::RSHIFT);
}

tree::TerminalNode* SesameParser::Expr3Context::RSHIFT(size_t i) {
  return getToken(SesameParser::RSHIFT, i);
}


size_t SesameParser::Expr3Context::getRuleIndex() const {
  return SesameParser::RuleExpr3;
}

void SesameParser::Expr3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr3(this);
}

void SesameParser::Expr3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr3(this);
}


antlrcpp::Any SesameParser::Expr3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr3(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr3Context* SesameParser::expr3() {
  Expr3Context *_localctx = _tracker.createInstance<Expr3Context>(_ctx, getState());
  enterRule(_localctx, 106, SesameParser::RuleExpr3);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    expr2();
    setState(543);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::LSHIFT

    || _la == SesameParser::RSHIFT) {
      setState(539);
      _la = _input->LA(1);
      if (!(_la == SesameParser::LSHIFT

      || _la == SesameParser::RSHIFT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(540);
      expr2();
      setState(545);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr2Context ------------------------------------------------------------------

SesameParser::Expr2Context::Expr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Expr1Context *> SesameParser::Expr2Context::expr1() {
  return getRuleContexts<SesameParser::Expr1Context>();
}

SesameParser::Expr1Context* SesameParser::Expr2Context::expr1(size_t i) {
  return getRuleContext<SesameParser::Expr1Context>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr2Context::PLUS() {
  return getTokens(SesameParser::PLUS);
}

tree::TerminalNode* SesameParser::Expr2Context::PLUS(size_t i) {
  return getToken(SesameParser::PLUS, i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr2Context::MINUS() {
  return getTokens(SesameParser::MINUS);
}

tree::TerminalNode* SesameParser::Expr2Context::MINUS(size_t i) {
  return getToken(SesameParser::MINUS, i);
}


size_t SesameParser::Expr2Context::getRuleIndex() const {
  return SesameParser::RuleExpr2;
}

void SesameParser::Expr2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr2(this);
}

void SesameParser::Expr2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr2(this);
}


antlrcpp::Any SesameParser::Expr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr2(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr2Context* SesameParser::expr2() {
  Expr2Context *_localctx = _tracker.createInstance<Expr2Context>(_ctx, getState());
  enterRule(_localctx, 108, SesameParser::RuleExpr2);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(546);
    expr1();
    setState(551);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::PLUS

    || _la == SesameParser::MINUS) {
      setState(547);
      _la = _input->LA(1);
      if (!(_la == SesameParser::PLUS

      || _la == SesameParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(548);
      expr1();
      setState(553);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1Context ------------------------------------------------------------------

SesameParser::Expr1Context::Expr1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::TermContext *> SesameParser::Expr1Context::term() {
  return getRuleContexts<SesameParser::TermContext>();
}

SesameParser::TermContext* SesameParser::Expr1Context::term(size_t i) {
  return getRuleContext<SesameParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr1Context::ASTERISK() {
  return getTokens(SesameParser::ASTERISK);
}

tree::TerminalNode* SesameParser::Expr1Context::ASTERISK(size_t i) {
  return getToken(SesameParser::ASTERISK, i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr1Context::SOLIDUS() {
  return getTokens(SesameParser::SOLIDUS);
}

tree::TerminalNode* SesameParser::Expr1Context::SOLIDUS(size_t i) {
  return getToken(SesameParser::SOLIDUS, i);
}

std::vector<tree::TerminalNode *> SesameParser::Expr1Context::PERCENT() {
  return getTokens(SesameParser::PERCENT);
}

tree::TerminalNode* SesameParser::Expr1Context::PERCENT(size_t i) {
  return getToken(SesameParser::PERCENT, i);
}


size_t SesameParser::Expr1Context::getRuleIndex() const {
  return SesameParser::RuleExpr1;
}

void SesameParser::Expr1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1(this);
}

void SesameParser::Expr1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1(this);
}


antlrcpp::Any SesameParser::Expr1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr1(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr1Context* SesameParser::expr1() {
  Expr1Context *_localctx = _tracker.createInstance<Expr1Context>(_ctx, getState());
  enterRule(_localctx, 110, SesameParser::RuleExpr1);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(554);
    term();
    setState(559);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::ASTERISK)
      | (1ULL << SesameParser::SOLIDUS)
      | (1ULL << SesameParser::PERCENT))) != 0)) {
      setState(555);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SesameParser::ASTERISK)
        | (1ULL << SesameParser::SOLIDUS)
        | (1ULL << SesameParser::PERCENT))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(556);
      term();
      setState(561);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

SesameParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::TermContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

SesameParser::TypeContext* SesameParser::TermContext::type() {
  return getRuleContext<SesameParser::TypeContext>(0);
}

tree::TerminalNode* SesameParser::TermContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

SesameParser::TermContext* SesameParser::TermContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

SesameParser::UnaryContext* SesameParser::TermContext::unary() {
  return getRuleContext<SesameParser::UnaryContext>(0);
}


size_t SesameParser::TermContext::getRuleIndex() const {
  return SesameParser::RuleTerm;
}

void SesameParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void SesameParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


antlrcpp::Any SesameParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::TermContext* SesameParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 112, SesameParser::RuleTerm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(568);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(562);
      match(SesameParser::LPAREN);
      setState(563);
      type();
      setState(564);
      match(SesameParser::RPAREN);
      setState(565);
      term();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(567);
      unary();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryContext ------------------------------------------------------------------

SesameParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SesameParser::UnaryContext::PLUS() {
  return getTokens(SesameParser::PLUS);
}

tree::TerminalNode* SesameParser::UnaryContext::PLUS(size_t i) {
  return getToken(SesameParser::PLUS, i);
}

SesameParser::UnaryContext* SesameParser::UnaryContext::unary() {
  return getRuleContext<SesameParser::UnaryContext>(0);
}

std::vector<tree::TerminalNode *> SesameParser::UnaryContext::MINUS() {
  return getTokens(SesameParser::MINUS);
}

tree::TerminalNode* SesameParser::UnaryContext::MINUS(size_t i) {
  return getToken(SesameParser::MINUS, i);
}

SesameParser::TermContext* SesameParser::UnaryContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

tree::TerminalNode* SesameParser::UnaryContext::EXCLAMATION_OPERATOR() {
  return getToken(SesameParser::EXCLAMATION_OPERATOR, 0);
}

tree::TerminalNode* SesameParser::UnaryContext::TILDE_OPERATOR() {
  return getToken(SesameParser::TILDE_OPERATOR, 0);
}

tree::TerminalNode* SesameParser::UnaryContext::ASTERISK() {
  return getToken(SesameParser::ASTERISK, 0);
}

tree::TerminalNode* SesameParser::UnaryContext::AMPERSAND() {
  return getToken(SesameParser::AMPERSAND, 0);
}

tree::TerminalNode* SesameParser::UnaryContext::S_SIZEOF() {
  return getToken(SesameParser::S_SIZEOF, 0);
}

tree::TerminalNode* SesameParser::UnaryContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

SesameParser::TypeContext* SesameParser::UnaryContext::type() {
  return getRuleContext<SesameParser::TypeContext>(0);
}

tree::TerminalNode* SesameParser::UnaryContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

SesameParser::PostfixContext* SesameParser::UnaryContext::postfix() {
  return getRuleContext<SesameParser::PostfixContext>(0);
}


size_t SesameParser::UnaryContext::getRuleIndex() const {
  return SesameParser::RuleUnary;
}

void SesameParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}

void SesameParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}


antlrcpp::Any SesameParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::UnaryContext* SesameParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 114, SesameParser::RuleUnary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(596);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(570);
      match(SesameParser::PLUS);
      setState(571);
      match(SesameParser::PLUS);
      setState(572);
      unary();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(573);
      match(SesameParser::MINUS);
      setState(574);
      match(SesameParser::MINUS);
      setState(575);
      unary();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(576);
      match(SesameParser::PLUS);
      setState(577);
      term();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(578);
      match(SesameParser::MINUS);
      setState(579);
      term();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(580);
      match(SesameParser::EXCLAMATION_OPERATOR);
      setState(581);
      term();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(582);
      match(SesameParser::TILDE_OPERATOR);
      setState(583);
      term();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(584);
      match(SesameParser::ASTERISK);
      setState(585);
      term();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(586);
      match(SesameParser::AMPERSAND);
      setState(587);
      term();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(588);
      match(SesameParser::S_SIZEOF);
      setState(589);
      match(SesameParser::LPAREN);
      setState(590);
      type();
      setState(591);
      match(SesameParser::RPAREN);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(593);
      match(SesameParser::S_SIZEOF);
      setState(594);
      unary();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(595);
      postfix();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixContext ------------------------------------------------------------------

SesameParser::PostfixContext::PostfixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::PrimaryContext* SesameParser::PostfixContext::primary() {
  return getRuleContext<SesameParser::PrimaryContext>(0);
}

std::vector<tree::TerminalNode *> SesameParser::PostfixContext::PLUS() {
  return getTokens(SesameParser::PLUS);
}

tree::TerminalNode* SesameParser::PostfixContext::PLUS(size_t i) {
  return getToken(SesameParser::PLUS, i);
}

std::vector<tree::TerminalNode *> SesameParser::PostfixContext::MINUS() {
  return getTokens(SesameParser::MINUS);
}

tree::TerminalNode* SesameParser::PostfixContext::MINUS(size_t i) {
  return getToken(SesameParser::MINUS, i);
}

std::vector<tree::TerminalNode *> SesameParser::PostfixContext::LBRACKET() {
  return getTokens(SesameParser::LBRACKET);
}

tree::TerminalNode* SesameParser::PostfixContext::LBRACKET(size_t i) {
  return getToken(SesameParser::LBRACKET, i);
}

std::vector<SesameParser::ExprContext *> SesameParser::PostfixContext::expr() {
  return getRuleContexts<SesameParser::ExprContext>();
}

SesameParser::ExprContext* SesameParser::PostfixContext::expr(size_t i) {
  return getRuleContext<SesameParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::PostfixContext::RBRACKET() {
  return getTokens(SesameParser::RBRACKET);
}

tree::TerminalNode* SesameParser::PostfixContext::RBRACKET(size_t i) {
  return getToken(SesameParser::RBRACKET, i);
}

std::vector<tree::TerminalNode *> SesameParser::PostfixContext::PERIOD() {
  return getTokens(SesameParser::PERIOD);
}

tree::TerminalNode* SesameParser::PostfixContext::PERIOD(size_t i) {
  return getToken(SesameParser::PERIOD, i);
}

std::vector<SesameParser::NameContext *> SesameParser::PostfixContext::name() {
  return getRuleContexts<SesameParser::NameContext>();
}

SesameParser::NameContext* SesameParser::PostfixContext::name(size_t i) {
  return getRuleContext<SesameParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::PostfixContext::POINTER_REF() {
  return getTokens(SesameParser::POINTER_REF);
}

tree::TerminalNode* SesameParser::PostfixContext::POINTER_REF(size_t i) {
  return getToken(SesameParser::POINTER_REF, i);
}

std::vector<tree::TerminalNode *> SesameParser::PostfixContext::LPAREN() {
  return getTokens(SesameParser::LPAREN);
}

tree::TerminalNode* SesameParser::PostfixContext::LPAREN(size_t i) {
  return getToken(SesameParser::LPAREN, i);
}

std::vector<tree::TerminalNode *> SesameParser::PostfixContext::RPAREN() {
  return getTokens(SesameParser::RPAREN);
}

tree::TerminalNode* SesameParser::PostfixContext::RPAREN(size_t i) {
  return getToken(SesameParser::RPAREN, i);
}

std::vector<SesameParser::ArgsContext *> SesameParser::PostfixContext::args() {
  return getRuleContexts<SesameParser::ArgsContext>();
}

SesameParser::ArgsContext* SesameParser::PostfixContext::args(size_t i) {
  return getRuleContext<SesameParser::ArgsContext>(i);
}


size_t SesameParser::PostfixContext::getRuleIndex() const {
  return SesameParser::RulePostfix;
}

void SesameParser::PostfixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfix(this);
}

void SesameParser::PostfixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfix(this);
}


antlrcpp::Any SesameParser::PostfixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitPostfix(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::PostfixContext* SesameParser::postfix() {
  PostfixContext *_localctx = _tracker.createInstance<PostfixContext>(_ctx, getState());
  enterRule(_localctx, 116, SesameParser::RulePostfix);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(598);
    primary();
    setState(618);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(616);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SesameParser::PLUS: {
            setState(599);
            match(SesameParser::PLUS);
            setState(600);
            match(SesameParser::PLUS);
            break;
          }

          case SesameParser::MINUS: {
            setState(601);
            match(SesameParser::MINUS);
            setState(602);
            match(SesameParser::MINUS);
            break;
          }

          case SesameParser::LBRACKET: {
            setState(603);
            match(SesameParser::LBRACKET);
            setState(604);
            expr();
            setState(605);
            match(SesameParser::RBRACKET);
            break;
          }

          case SesameParser::PERIOD: {
            setState(607);
            match(SesameParser::PERIOD);
            setState(608);
            name();
            break;
          }

          case SesameParser::POINTER_REF: {
            setState(609);
            match(SesameParser::POINTER_REF);
            setState(610);
            name();
            break;
          }

          case SesameParser::LPAREN: {
            setState(611);
            match(SesameParser::LPAREN);
            setState(613);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (((((_la - 28) & ~ 0x3fULL) == 0) &&
              ((1ULL << (_la - 28)) & ((1ULL << (SesameParser::S_SIZEOF - 28))
              | (1ULL << (SesameParser::PLUS - 28))
              | (1ULL << (SesameParser::MINUS - 28))
              | (1ULL << (SesameParser::ASTERISK - 28))
              | (1ULL << (SesameParser::AMPERSAND - 28))
              | (1ULL << (SesameParser::LPAREN - 28))
              | (1ULL << (SesameParser::EXCLAMATION_OPERATOR - 28))
              | (1ULL << (SesameParser::TILDE_OPERATOR - 28))
              | (1ULL << (SesameParser::S_CHARACTER - 28))
              | (1ULL << (SesameParser::S_STRING - 28))
              | (1ULL << (SesameParser::IDENTIFIER - 28))
              | (1ULL << (SesameParser::INTEGER - 28))
              | (1ULL << (SesameParser::HEX - 28))
              | (1ULL << (SesameParser::OCT - 28)))) != 0)) {
              setState(612);
              args();
            }
            setState(615);
            match(SesameParser::RPAREN);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(620);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

SesameParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::ExprContext *> SesameParser::ArgsContext::expr() {
  return getRuleContexts<SesameParser::ExprContext>();
}

SesameParser::ExprContext* SesameParser::ArgsContext::expr(size_t i) {
  return getRuleContext<SesameParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SesameParser::ArgsContext::COMMA() {
  return getTokens(SesameParser::COMMA);
}

tree::TerminalNode* SesameParser::ArgsContext::COMMA(size_t i) {
  return getToken(SesameParser::COMMA, i);
}


size_t SesameParser::ArgsContext::getRuleIndex() const {
  return SesameParser::RuleArgs;
}

void SesameParser::ArgsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgs(this);
}

void SesameParser::ArgsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgs(this);
}


antlrcpp::Any SesameParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::ArgsContext* SesameParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 118, SesameParser::RuleArgs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(621);
    expr();
    setState(626);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::COMMA) {
      setState(622);
      match(SesameParser::COMMA);
      setState(623);
      expr();
      setState(628);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

SesameParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::PrimaryContext::INTEGER() {
  return getToken(SesameParser::INTEGER, 0);
}

tree::TerminalNode* SesameParser::PrimaryContext::HEX() {
  return getToken(SesameParser::HEX, 0);
}

tree::TerminalNode* SesameParser::PrimaryContext::OCT() {
  return getToken(SesameParser::OCT, 0);
}

tree::TerminalNode* SesameParser::PrimaryContext::S_CHARACTER() {
  return getToken(SesameParser::S_CHARACTER, 0);
}

tree::TerminalNode* SesameParser::PrimaryContext::S_STRING() {
  return getToken(SesameParser::S_STRING, 0);
}

tree::TerminalNode* SesameParser::PrimaryContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}

tree::TerminalNode* SesameParser::PrimaryContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

SesameParser::ExprContext* SesameParser::PrimaryContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

tree::TerminalNode* SesameParser::PrimaryContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}


size_t SesameParser::PrimaryContext::getRuleIndex() const {
  return SesameParser::RulePrimary;
}

void SesameParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void SesameParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


antlrcpp::Any SesameParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::PrimaryContext* SesameParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 120, SesameParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(639);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SesameParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(629);
        match(SesameParser::INTEGER);
        break;
      }

      case SesameParser::HEX: {
        enterOuterAlt(_localctx, 2);
        setState(630);
        match(SesameParser::HEX);
        break;
      }

      case SesameParser::OCT: {
        enterOuterAlt(_localctx, 3);
        setState(631);
        match(SesameParser::OCT);
        break;
      }

      case SesameParser::S_CHARACTER: {
        enterOuterAlt(_localctx, 4);
        setState(632);
        match(SesameParser::S_CHARACTER);
        break;
      }

      case SesameParser::S_STRING: {
        enterOuterAlt(_localctx, 5);
        setState(633);
        match(SesameParser::S_STRING);
        break;
      }

      case SesameParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 6);
        setState(634);
        match(SesameParser::IDENTIFIER);
        break;
      }

      case SesameParser::LPAREN: {
        enterOuterAlt(_localctx, 7);
        setState(635);
        match(SesameParser::LPAREN);
        setState(636);
        expr();
        setState(637);
        match(SesameParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SesameParser::_decisionToDFA;
atn::PredictionContextCache SesameParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SesameParser::_atn;
std::vector<uint16_t> SesameParser::_serializedATN;

std::vector<std::string> SesameParser::_ruleNames = {
  "compilation_unit", "declaration_file", "import_stmt", "import_name", 
  "name", "func_decl", "var_decl", "top_def", "def_func", "storage", "params", 
  "fixed_params", "param", "block", "def_vars", "assign_expr", "def_const", 
  "def_struct", "def_union", "member_list", "slot", "s_typedef", "type", 
  "typeref", "typeref_base", "param_typerefs", "fixed_param_typerefs", "stmts", 
  "stmt", "labeled_stmt", "if_stmt", "while_stmt", "do_while_stmt", "for_stmt", 
  "switch_stmt", "case_clauses", "case_clause", "cases", "default_clause", 
  "case_body", "break_stmt", "continue_stmt", "goto_stmt", "return_stmt", 
  "expr", "opassign_op", "expr10", "expr8", "expr7", "logical_op", "expr6", 
  "expr5", "expr4", "expr3", "expr2", "expr1", "term", "unary", "postfix", 
  "args", "primary"
};

std::vector<std::string> SesameParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "';'", "':'", "'+'", "'-'", 
  "'*'", "'/'", "'%'", "'&'", "'('", "')'", "','", "'='", "'{'", "'}'", 
  "'['", "']'", "'<'", "'<='", "'>'", "'>='", "'!='", "'=='", "'&&'", "'||'", 
  "'<<'", "'>>'", "'.'", "'...'", "'|'", "'?'", "'!'", "'^'", "'~'", "'->'"
};

std::vector<std::string> SesameParser::_symbolicNames = {
  "", "S_VOID", "S_CHAR", "S_SHORT", "S_INT", "S_LONG", "S_STRUCT", "S_UNION", 
  "S_ENUM", "S_STATIC", "S_EXTERN", "S_CONST", "S_SIGNED", "S_UNSIGNED", 
  "S_IF", "S_ELSE", "S_SWITCH", "S_CASE", "S_DEFAULT", "S_WHILE", "S_DO", 
  "S_FOR", "S_RETURN", "S_BREAK", "S_CONTINUE", "S_GOTO", "S_TYPEDEF", "S_IMPORT", 
  "S_SIZEOF", "SEMI", "COLON", "PLUS", "MINUS", "ASTERISK", "SOLIDUS", "PERCENT", 
  "AMPERSAND", "LPAREN", "RPAREN", "COMMA", "EQUAL", "LBRACE", "RBRACE", 
  "LBRACKET", "RBRACKET", "LESS", "LESS_EQ", "GREATER", "GREATER_EQ", "NOT_EQ", 
  "EQ_SIGN", "LOGIC_AND", "LOGIC_OR", "LSHIFT", "RSHIFT", "PERIOD", "CDOTS", 
  "BAR", "QUESTION", "EXCLAMATION_OPERATOR", "CARRET_OPERATOR_PART", "TILDE_OPERATOR", 
  "POINTER_REF", "SINGLE_LINE_COMM", "MULTI_LINE_COMM", "S_CHARACTER", "S_STRING", 
  "IDENTIFIER", "INTEGER", "HEX", "OCT", "SPACES"
};

dfa::Vocabulary SesameParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SesameParser::_tokenNames;

SesameParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x49, 0x284, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x3, 0x2, 0x7, 
    0x2, 0x7e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x81, 0xb, 0x2, 0x3, 0x2, 0x6, 
    0x2, 0x84, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x85, 0x3, 0x3, 0x7, 0x3, 0x89, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x8c, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x94, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x97, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0xa0, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0xa3, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0xba, 0xa, 0x9, 0x3, 0xa, 0x5, 0xa, 0xbd, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xc3, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xce, 0xa, 0xc, 0x5, 0xc, 0xd0, 0xa, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xd5, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xd8, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x7, 0xf, 0xdf, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xe2, 0xb, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x5, 0x10, 0xe8, 0xa, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xee, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0xf1, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0xf8, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x10f, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x112, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x7, 0x19, 0x12b, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
    0x12e, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x142, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x5, 0x1b, 0x148, 0xa, 0x1b, 0x5, 0x1b, 0x14a, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x14f, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
    0x152, 0xb, 0x1c, 0x3, 0x1d, 0x7, 0x1d, 0x155, 0xa, 0x1d, 0xc, 0x1d, 
    0xe, 0x1d, 0x158, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x169, 
    0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 
    0x176, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 
    0x189, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x18d, 0xa, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x25, 0x7, 0x25, 0x19d, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x1a0, 
    0xb, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1a3, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x6, 0x27, 0x1ac, 
    0xa, 0x27, 0xd, 0x27, 0xe, 0x27, 0x1ad, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x29, 0x6, 0x29, 0x1b5, 0xa, 0x29, 0xd, 0x29, 0xe, 0x29, 
    0x1b6, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x5, 
    0x2d, 0x1c5, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x5, 0x2e, 0x1d2, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x1e8, 0xa, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 
    0x30, 0x1f0, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 
    0x1f5, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x1f8, 0xb, 0x31, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x1fe, 0xa, 0x32, 0xc, 0x32, 
    0xe, 0x32, 0x201, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x7, 0x34, 0x208, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x20b, 
    0xb, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x210, 0xa, 0x35, 
    0xc, 0x35, 0xe, 0x35, 0x213, 0xb, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x7, 0x36, 0x218, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x21b, 0xb, 0x36, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x220, 0xa, 0x37, 0xc, 0x37, 
    0xe, 0x37, 0x223, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 
    0x228, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x22b, 0xb, 0x38, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x230, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 
    0x233, 0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x5, 0x3a, 0x23b, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x257, 0xa, 0x3b, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x268, 0xa, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 
    0x26b, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x26e, 0xb, 0x3c, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x273, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 
    0x276, 0xb, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x282, 
    0xa, 0x3e, 0x3, 0x3e, 0x2, 0x2, 0x3f, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 
    0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
    0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x2, 0x7, 0x3, 0x2, 0x35, 
    0x36, 0x3, 0x2, 0x2f, 0x34, 0x3, 0x2, 0x37, 0x38, 0x3, 0x2, 0x21, 0x22, 
    0x3, 0x2, 0x23, 0x25, 0x2, 0x2b3, 0x2, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x8a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x98, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9c, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xc, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xae, 0x3, 0x2, 0x2, 0x2, 0x10, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x14, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe7, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x22, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x100, 0x3, 0x2, 0x2, 0x2, 0x26, 0x105, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x118, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x11d, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x141, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x149, 0x3, 0x2, 0x2, 0x2, 0x36, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x38, 0x156, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x177, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x44, 0x185, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x193, 0x3, 0x2, 0x2, 0x2, 0x48, 0x19e, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x1af, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1b8, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1be, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1d1, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1e9, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x202, 0x3, 0x2, 0x2, 0x2, 0x66, 0x204, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x20c, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x214, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x21c, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x224, 0x3, 0x2, 0x2, 0x2, 0x70, 0x22c, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x74, 0x256, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x258, 0x3, 0x2, 0x2, 0x2, 0x78, 0x26f, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x281, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x6, 0x4, 0x2, 
    0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x84, 0x5, 
    0x10, 0x9, 0x2, 0x83, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x3, 0x3, 0x2, 0x2, 0x2, 0x87, 0x89, 0x5, 0x6, 0x4, 0x2, 
    0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x94, 0x5, 
    0xc, 0x7, 0x2, 0x8e, 0x94, 0x5, 0xe, 0x8, 0x2, 0x8f, 0x94, 0x5, 0x22, 
    0x12, 0x2, 0x90, 0x94, 0x5, 0x24, 0x13, 0x2, 0x91, 0x94, 0x5, 0x26, 
    0x14, 0x2, 0x92, 0x94, 0x5, 0x2c, 0x17, 0x2, 0x93, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x93, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x93, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0x93, 0x90, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x1d, 
    0x2, 0x2, 0x99, 0x9a, 0x5, 0x8, 0x5, 0x2, 0x9a, 0x9b, 0x7, 0x1f, 0x2, 
    0x2, 0x9b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x9c, 0xa1, 0x5, 0xa, 0x6, 0x2, 
    0x9d, 0x9e, 0x7, 0x39, 0x2, 0x2, 0x9e, 0xa0, 0x5, 0xa, 0x6, 0x2, 0x9f, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x45, 
    0x2, 0x2, 0xa5, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0xc, 0x2, 
    0x2, 0xa7, 0xa8, 0x5, 0x30, 0x19, 0x2, 0xa8, 0xa9, 0x5, 0xa, 0x6, 0x2, 
    0xa9, 0xaa, 0x7, 0x27, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x16, 0xc, 0x2, 0xab, 
    0xac, 0x7, 0x28, 0x2, 0x2, 0xac, 0xad, 0x7, 0x1f, 0x2, 0x2, 0xad, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0xc, 0x2, 0x2, 0xaf, 0xb0, 0x5, 
    0x2e, 0x18, 0x2, 0xb0, 0xb1, 0x5, 0xa, 0x6, 0x2, 0xb1, 0xb2, 0x7, 0x1f, 
    0x2, 0x2, 0xb2, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xba, 0x5, 0x12, 0xa, 
    0x2, 0xb4, 0xba, 0x5, 0x1e, 0x10, 0x2, 0xb5, 0xba, 0x5, 0x22, 0x12, 
    0x2, 0xb6, 0xba, 0x5, 0x24, 0x13, 0x2, 0xb7, 0xba, 0x5, 0x26, 0x14, 
    0x2, 0xb8, 0xba, 0x5, 0x2c, 0x17, 0x2, 0xb9, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb8, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0x11, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x5, 
    0x14, 0xb, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x30, 0x19, 
    0x2, 0xbf, 0xc0, 0x5, 0xa, 0x6, 0x2, 0xc0, 0xc2, 0x7, 0x27, 0x2, 0x2, 
    0xc1, 0xc3, 0x5, 0x16, 0xc, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 
    0x7, 0x28, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x1c, 0xf, 0x2, 0xc6, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0xb, 0x2, 0x2, 0xc8, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xd0, 0x7, 0x3, 0x2, 0x2, 0xca, 0xcd, 0x5, 0x18, 0xd, 
    0x2, 0xcb, 0xcc, 0x7, 0x29, 0x2, 0x2, 0xcc, 0xce, 0x7, 0x3a, 0x2, 0x2, 
    0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd6, 0x5, 
    0x1a, 0xe, 0x2, 0xd2, 0xd3, 0x7, 0x29, 0x2, 0x2, 0xd3, 0xd5, 0x5, 0x1a, 
    0xe, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xda, 0x5, 0x2e, 0x18, 0x2, 0xda, 0xdb, 0x5, 0xa, 0x6, 0x2, 0xdb, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0xe0, 0x7, 0x2b, 0x2, 0x2, 0xdd, 0xdf, 0x5, 
    0x1e, 0x10, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xe4, 0x5, 0x38, 0x1d, 0x2, 0xe4, 0xe5, 0x7, 0x2c, 0x2, 0x2, 0xe5, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe8, 0x5, 0x14, 0xb, 0x2, 0xe7, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 
    0x2, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x2e, 0x18, 0x2, 0xea, 0xef, 0x5, 0x20, 
    0x11, 0x2, 0xeb, 0xec, 0x7, 0x29, 0x2, 0x2, 0xec, 0xee, 0x5, 0x20, 0x11, 
    0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xf2, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 
    0x7, 0x1f, 0x2, 0x2, 0xf3, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x5, 
    0xa, 0x6, 0x2, 0xf5, 0xf6, 0x7, 0x2a, 0x2, 0x2, 0xf6, 0xf8, 0x5, 0x5a, 
    0x2e, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xf8, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0xd, 0x2, 0x2, 
    0xfa, 0xfb, 0x5, 0x2e, 0x18, 0x2, 0xfb, 0xfc, 0x5, 0xa, 0x6, 0x2, 0xfc, 
    0xfd, 0x7, 0x2a, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x5a, 0x2e, 0x2, 0xfe, 0xff, 
    0x7, 0x1f, 0x2, 0x2, 0xff, 0x23, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 
    0x8, 0x2, 0x2, 0x101, 0x102, 0x5, 0xa, 0x6, 0x2, 0x102, 0x103, 0x5, 
    0x28, 0x15, 0x2, 0x103, 0x104, 0x7, 0x1f, 0x2, 0x2, 0x104, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x9, 0x2, 0x2, 0x106, 0x107, 0x5, 
    0xa, 0x6, 0x2, 0x107, 0x108, 0x5, 0x28, 0x15, 0x2, 0x108, 0x109, 0x7, 
    0x1f, 0x2, 0x2, 0x109, 0x27, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x110, 0x7, 
    0x2b, 0x2, 0x2, 0x10b, 0x10c, 0x5, 0x2a, 0x16, 0x2, 0x10c, 0x10d, 0x7, 
    0x1f, 0x2, 0x2, 0x10d, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x10f, 0x112, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 0x113, 0x3, 
    0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x7, 
    0x2c, 0x2, 0x2, 0x114, 0x29, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x5, 
    0x2e, 0x18, 0x2, 0x116, 0x117, 0x5, 0xa, 0x6, 0x2, 0x117, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x118, 0x119, 0x7, 0x1c, 0x2, 0x2, 0x119, 0x11a, 0x5, 
    0x30, 0x19, 0x2, 0x11a, 0x11b, 0x7, 0x45, 0x2, 0x2, 0x11b, 0x11c, 0x7, 
    0x1f, 0x2, 0x2, 0x11c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x5, 
    0x30, 0x19, 0x2, 0x11e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x12c, 0x5, 
    0x32, 0x1a, 0x2, 0x120, 0x121, 0x7, 0x2d, 0x2, 0x2, 0x121, 0x12b, 0x7, 
    0x2e, 0x2, 0x2, 0x122, 0x123, 0x7, 0x2d, 0x2, 0x2, 0x123, 0x124, 0x7, 
    0x46, 0x2, 0x2, 0x124, 0x12b, 0x7, 0x2e, 0x2, 0x2, 0x125, 0x12b, 0x7, 
    0x23, 0x2, 0x2, 0x126, 0x127, 0x7, 0x27, 0x2, 0x2, 0x127, 0x128, 0x5, 
    0x34, 0x1b, 0x2, 0x128, 0x129, 0x7, 0x28, 0x2, 0x2, 0x129, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x120, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x122, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x125, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x142, 0x7, 0x3, 
    0x2, 0x2, 0x130, 0x142, 0x7, 0x4, 0x2, 0x2, 0x131, 0x142, 0x7, 0x5, 
    0x2, 0x2, 0x132, 0x142, 0x7, 0x6, 0x2, 0x2, 0x133, 0x142, 0x7, 0x7, 
    0x2, 0x2, 0x134, 0x135, 0x7, 0xf, 0x2, 0x2, 0x135, 0x142, 0x7, 0x4, 
    0x2, 0x2, 0x136, 0x137, 0x7, 0xf, 0x2, 0x2, 0x137, 0x142, 0x7, 0x5, 
    0x2, 0x2, 0x138, 0x139, 0x7, 0xf, 0x2, 0x2, 0x139, 0x142, 0x7, 0x6, 
    0x2, 0x2, 0x13a, 0x13b, 0x7, 0xf, 0x2, 0x2, 0x13b, 0x142, 0x7, 0x7, 
    0x2, 0x2, 0x13c, 0x13d, 0x7, 0x8, 0x2, 0x2, 0x13d, 0x142, 0x7, 0x45, 
    0x2, 0x2, 0x13e, 0x13f, 0x7, 0x9, 0x2, 0x2, 0x13f, 0x142, 0x7, 0x45, 
    0x2, 0x2, 0x140, 0x142, 0x7, 0x45, 0x2, 0x2, 0x141, 0x12f, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x130, 0x3, 0x2, 0x2, 0x2, 0x141, 0x131, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x132, 0x3, 0x2, 0x2, 0x2, 0x141, 0x133, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x134, 0x3, 0x2, 0x2, 0x2, 0x141, 0x136, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x138, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13e, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x143, 0x14a, 0x7, 0x3, 0x2, 0x2, 0x144, 0x147, 0x5, 0x36, 0x1c, 
    0x2, 0x145, 0x146, 0x7, 0x29, 0x2, 0x2, 0x146, 0x148, 0x7, 0x3a, 0x2, 
    0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x3, 0x2, 0x2, 
    0x2, 0x148, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x149, 0x143, 0x3, 0x2, 0x2, 
    0x2, 0x149, 0x144, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x14b, 0x150, 0x5, 0x30, 0x19, 0x2, 0x14c, 0x14d, 0x7, 0x29, 0x2, 0x2, 
    0x14d, 0x14f, 0x5, 0x30, 0x19, 0x2, 0x14e, 0x14c, 0x3, 0x2, 0x2, 0x2, 
    0x14f, 0x152, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x37, 0x3, 0x2, 0x2, 0x2, 0x152, 
    0x150, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 0x5, 0x3a, 0x1e, 0x2, 0x154, 
    0x153, 0x3, 0x2, 0x2, 0x2, 0x155, 0x158, 0x3, 0x2, 0x2, 0x2, 0x156, 
    0x154, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 0x169, 
    0x7, 0x1f, 0x2, 0x2, 0x15a, 0x169, 0x5, 0x3c, 0x1f, 0x2, 0x15b, 0x15c, 
    0x5, 0x5a, 0x2e, 0x2, 0x15c, 0x15d, 0x7, 0x1f, 0x2, 0x2, 0x15d, 0x169, 
    0x3, 0x2, 0x2, 0x2, 0x15e, 0x169, 0x5, 0x1c, 0xf, 0x2, 0x15f, 0x169, 
    0x5, 0x3e, 0x20, 0x2, 0x160, 0x169, 0x5, 0x40, 0x21, 0x2, 0x161, 0x169, 
    0x5, 0x42, 0x22, 0x2, 0x162, 0x169, 0x5, 0x44, 0x23, 0x2, 0x163, 0x169, 
    0x5, 0x46, 0x24, 0x2, 0x164, 0x169, 0x5, 0x52, 0x2a, 0x2, 0x165, 0x169, 
    0x5, 0x54, 0x2b, 0x2, 0x166, 0x169, 0x5, 0x56, 0x2c, 0x2, 0x167, 0x169, 
    0x5, 0x58, 0x2d, 0x2, 0x168, 0x159, 0x3, 0x2, 0x2, 0x2, 0x168, 0x15a, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x168, 0x15e, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x168, 0x160, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x161, 0x3, 0x2, 0x2, 0x2, 0x168, 0x162, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x163, 0x3, 0x2, 0x2, 0x2, 0x168, 0x164, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x165, 0x3, 0x2, 0x2, 0x2, 0x168, 0x166, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x167, 0x3, 0x2, 0x2, 0x2, 0x169, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x45, 0x2, 0x2, 0x16b, 0x16c, 0x7, 
    0x20, 0x2, 0x2, 0x16c, 0x16d, 0x5, 0x3a, 0x1e, 0x2, 0x16d, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x16e, 0x16f, 0x7, 0x10, 0x2, 0x2, 0x16f, 0x170, 0x7, 
    0x27, 0x2, 0x2, 0x170, 0x171, 0x5, 0x5a, 0x2e, 0x2, 0x171, 0x172, 0x7, 
    0x28, 0x2, 0x2, 0x172, 0x175, 0x5, 0x3a, 0x1e, 0x2, 0x173, 0x174, 0x7, 
    0x11, 0x2, 0x2, 0x174, 0x176, 0x5, 0x3a, 0x1e, 0x2, 0x175, 0x173, 0x3, 
    0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 0x2, 0x2, 0x176, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x177, 0x178, 0x7, 0x15, 0x2, 0x2, 0x178, 0x179, 0x7, 0x27, 
    0x2, 0x2, 0x179, 0x17a, 0x5, 0x5a, 0x2e, 0x2, 0x17a, 0x17b, 0x7, 0x28, 
    0x2, 0x2, 0x17b, 0x17c, 0x5, 0x3a, 0x1e, 0x2, 0x17c, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x17e, 0x7, 0x16, 0x2, 0x2, 0x17e, 0x17f, 0x5, 0x3a, 
    0x1e, 0x2, 0x17f, 0x180, 0x7, 0x15, 0x2, 0x2, 0x180, 0x181, 0x7, 0x27, 
    0x2, 0x2, 0x181, 0x182, 0x5, 0x5a, 0x2e, 0x2, 0x182, 0x183, 0x7, 0x28, 
    0x2, 0x2, 0x183, 0x184, 0x7, 0x1f, 0x2, 0x2, 0x184, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x185, 0x186, 0x7, 0x17, 0x2, 0x2, 0x186, 0x188, 0x7, 0x27, 
    0x2, 0x2, 0x187, 0x189, 0x5, 0x5a, 0x2e, 0x2, 0x188, 0x187, 0x3, 0x2, 
    0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x18a, 0x18c, 0x7, 0x1f, 0x2, 0x2, 0x18b, 0x18d, 0x5, 0x5a, 
    0x2e, 0x2, 0x18c, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 
    0x2, 0x2, 0x18d, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x7, 0x1f, 
    0x2, 0x2, 0x18f, 0x190, 0x5, 0x5a, 0x2e, 0x2, 0x190, 0x191, 0x7, 0x28, 
    0x2, 0x2, 0x191, 0x192, 0x5, 0x3a, 0x1e, 0x2, 0x192, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x193, 0x194, 0x7, 0x12, 0x2, 0x2, 0x194, 0x195, 0x7, 0x27, 
    0x2, 0x2, 0x195, 0x196, 0x5, 0x5a, 0x2e, 0x2, 0x196, 0x197, 0x7, 0x28, 
    0x2, 0x2, 0x197, 0x198, 0x7, 0x2b, 0x2, 0x2, 0x198, 0x199, 0x5, 0x48, 
    0x25, 0x2, 0x199, 0x19a, 0x7, 0x2c, 0x2, 0x2, 0x19a, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x19b, 0x19d, 0x5, 0x4a, 0x26, 0x2, 0x19c, 0x19b, 0x3, 0x2, 
    0x2, 0x2, 0x19d, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a2, 0x3, 0x2, 
    0x2, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a3, 0x5, 0x4e, 
    0x28, 0x2, 0x1a2, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 
    0x2, 0x2, 0x1a3, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x5, 0x4c, 
    0x27, 0x2, 0x1a5, 0x1a6, 0x5, 0x50, 0x29, 0x2, 0x1a6, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x13, 0x2, 0x2, 0x1a8, 0x1a9, 0x5, 0x7a, 
    0x3e, 0x2, 0x1a9, 0x1aa, 0x7, 0x20, 0x2, 0x2, 0x1aa, 0x1ac, 0x3, 0x2, 
    0x2, 0x2, 0x1ab, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x3, 0x2, 
    0x2, 0x2, 0x1ad, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 
    0x2, 0x2, 0x1ae, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x7, 0x14, 
    0x2, 0x2, 0x1b0, 0x1b1, 0x7, 0x20, 0x2, 0x2, 0x1b1, 0x1b2, 0x5, 0x50, 
    0x29, 0x2, 0x1b2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b5, 0x5, 0x3a, 
    0x1e, 0x2, 0x1b4, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x3, 0x2, 
    0x2, 0x2, 0x1b6, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 
    0x2, 0x2, 0x1b7, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x19, 
    0x2, 0x2, 0x1b9, 0x1ba, 0x7, 0x1f, 0x2, 0x2, 0x1ba, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x1bb, 0x1bc, 0x7, 0x1a, 0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x1f, 
    0x2, 0x2, 0x1bd, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x7, 0x1b, 
    0x2, 0x2, 0x1bf, 0x1c0, 0x7, 0x45, 0x2, 0x2, 0x1c0, 0x1c1, 0x7, 0x1f, 
    0x2, 0x2, 0x1c1, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c4, 0x7, 0x18, 
    0x2, 0x2, 0x1c3, 0x1c5, 0x5, 0x5a, 0x2e, 0x2, 0x1c4, 0x1c3, 0x3, 0x2, 
    0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x3, 0x2, 
    0x2, 0x2, 0x1c6, 0x1c7, 0x7, 0x1f, 0x2, 0x2, 0x1c7, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x1c8, 0x1c9, 0x5, 0x72, 0x3a, 0x2, 0x1c9, 0x1ca, 0x7, 0x2a, 
    0x2, 0x2, 0x1ca, 0x1cb, 0x5, 0x5a, 0x2e, 0x2, 0x1cb, 0x1d2, 0x3, 0x2, 
    0x2, 0x2, 0x1cc, 0x1cd, 0x5, 0x72, 0x3a, 0x2, 0x1cd, 0x1ce, 0x5, 0x5c, 
    0x2f, 0x2, 0x1ce, 0x1cf, 0x5, 0x5a, 0x2e, 0x2, 0x1cf, 0x1d2, 0x3, 0x2, 
    0x2, 0x2, 0x1d0, 0x1d2, 0x5, 0x5e, 0x30, 0x2, 0x1d1, 0x1c8, 0x3, 0x2, 
    0x2, 0x2, 0x1d1, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d0, 0x3, 0x2, 
    0x2, 0x2, 0x1d2, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x7, 0x21, 
    0x2, 0x2, 0x1d4, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1d5, 0x1d6, 0x7, 0x22, 
    0x2, 0x2, 0x1d6, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1d7, 0x1d8, 0x7, 0x23, 
    0x2, 0x2, 0x1d8, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1d9, 0x1da, 0x7, 0x24, 
    0x2, 0x2, 0x1da, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0x25, 
    0x2, 0x2, 0x1dc, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1dd, 0x1de, 0x7, 0x26, 
    0x2, 0x2, 0x1de, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1df, 0x1e0, 0x7, 0x3b, 
    0x2, 0x2, 0x1e0, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1e1, 0x1e2, 0x7, 0x3e, 
    0x2, 0x2, 0x1e2, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x37, 
    0x2, 0x2, 0x1e4, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1e5, 0x1e6, 0x7, 0x38, 
    0x2, 0x2, 0x1e6, 0x1e8, 0x7, 0x2a, 0x2, 0x2, 0x1e7, 0x1d3, 0x3, 0x2, 
    0x2, 0x2, 0x1e7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1d7, 0x3, 0x2, 
    0x2, 0x2, 0x1e7, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1db, 0x3, 0x2, 
    0x2, 0x2, 0x1e7, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1df, 0x3, 0x2, 
    0x2, 0x2, 0x1e7, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e3, 0x3, 0x2, 
    0x2, 0x2, 0x1e7, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x1e9, 0x1ef, 0x5, 0x60, 0x31, 0x2, 0x1ea, 0x1eb, 0x7, 0x3c, 0x2, 
    0x2, 0x1eb, 0x1ec, 0x5, 0x5a, 0x2e, 0x2, 0x1ec, 0x1ed, 0x7, 0x20, 0x2, 
    0x2, 0x1ed, 0x1ee, 0x5, 0x5e, 0x30, 0x2, 0x1ee, 0x1f0, 0x3, 0x2, 0x2, 
    0x2, 0x1ef, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 0x3, 0x2, 0x2, 
    0x2, 0x1f0, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f6, 0x5, 0x62, 0x32, 
    0x2, 0x1f2, 0x1f3, 0x9, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x5, 0x62, 0x32, 
    0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f8, 0x3, 0x2, 0x2, 
    0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x3, 0x2, 0x2, 
    0x2, 0x1f7, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f6, 0x3, 0x2, 0x2, 0x2, 
    0x1f9, 0x1ff, 0x5, 0x66, 0x34, 0x2, 0x1fa, 0x1fb, 0x5, 0x64, 0x33, 0x2, 
    0x1fb, 0x1fc, 0x5, 0x66, 0x34, 0x2, 0x1fc, 0x1fe, 0x3, 0x2, 0x2, 0x2, 
    0x1fd, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x201, 0x3, 0x2, 0x2, 0x2, 
    0x1ff, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 0x3, 0x2, 0x2, 0x2, 
    0x200, 0x63, 0x3, 0x2, 0x2, 0x2, 0x201, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x202, 
    0x203, 0x9, 0x3, 0x2, 0x2, 0x203, 0x65, 0x3, 0x2, 0x2, 0x2, 0x204, 0x209, 
    0x5, 0x68, 0x35, 0x2, 0x205, 0x206, 0x7, 0x3b, 0x2, 0x2, 0x206, 0x208, 
    0x5, 0x68, 0x35, 0x2, 0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 0x208, 0x20b, 
    0x3, 0x2, 0x2, 0x2, 0x209, 0x207, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 
    0x3, 0x2, 0x2, 0x2, 0x20a, 0x67, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x209, 0x3, 
    0x2, 0x2, 0x2, 0x20c, 0x211, 0x5, 0x6a, 0x36, 0x2, 0x20d, 0x20e, 0x7, 
    0x3e, 0x2, 0x2, 0x20e, 0x210, 0x5, 0x6a, 0x36, 0x2, 0x20f, 0x20d, 0x3, 
    0x2, 0x2, 0x2, 0x210, 0x213, 0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 0x3, 
    0x2, 0x2, 0x2, 0x211, 0x212, 0x3, 0x2, 0x2, 0x2, 0x212, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x213, 0x211, 0x3, 0x2, 0x2, 0x2, 0x214, 0x219, 0x5, 0x6c, 
    0x37, 0x2, 0x215, 0x216, 0x7, 0x26, 0x2, 0x2, 0x216, 0x218, 0x5, 0x6c, 
    0x37, 0x2, 0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21b, 0x3, 0x2, 
    0x2, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 
    0x2, 0x2, 0x21a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x219, 0x3, 0x2, 0x2, 
    0x2, 0x21c, 0x221, 0x5, 0x6e, 0x38, 0x2, 0x21d, 0x21e, 0x9, 0x4, 0x2, 
    0x2, 0x21e, 0x220, 0x5, 0x6e, 0x38, 0x2, 0x21f, 0x21d, 0x3, 0x2, 0x2, 
    0x2, 0x220, 0x223, 0x3, 0x2, 0x2, 0x2, 0x221, 0x21f, 0x3, 0x2, 0x2, 
    0x2, 0x221, 0x222, 0x3, 0x2, 0x2, 0x2, 0x222, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x221, 0x3, 0x2, 0x2, 0x2, 0x224, 0x229, 0x5, 0x70, 0x39, 0x2, 
    0x225, 0x226, 0x9, 0x5, 0x2, 0x2, 0x226, 0x228, 0x5, 0x70, 0x39, 0x2, 
    0x227, 0x225, 0x3, 0x2, 0x2, 0x2, 0x228, 0x22b, 0x3, 0x2, 0x2, 0x2, 
    0x229, 0x227, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22a, 0x3, 0x2, 0x2, 0x2, 
    0x22a, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x229, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0x231, 0x5, 0x72, 0x3a, 0x2, 0x22d, 0x22e, 0x9, 0x6, 0x2, 0x2, 0x22e, 
    0x230, 0x5, 0x72, 0x3a, 0x2, 0x22f, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x230, 
    0x233, 0x3, 0x2, 0x2, 0x2, 0x231, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 
    0x232, 0x3, 0x2, 0x2, 0x2, 0x232, 0x71, 0x3, 0x2, 0x2, 0x2, 0x233, 0x231, 
    0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x7, 0x27, 0x2, 0x2, 0x235, 0x236, 
    0x5, 0x2e, 0x18, 0x2, 0x236, 0x237, 0x7, 0x28, 0x2, 0x2, 0x237, 0x238, 
    0x5, 0x72, 0x3a, 0x2, 0x238, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23b, 
    0x5, 0x74, 0x3b, 0x2, 0x23a, 0x234, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x239, 
    0x3, 0x2, 0x2, 0x2, 0x23b, 0x73, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 0x7, 
    0x21, 0x2, 0x2, 0x23d, 0x23e, 0x7, 0x21, 0x2, 0x2, 0x23e, 0x257, 0x5, 
    0x74, 0x3b, 0x2, 0x23f, 0x240, 0x7, 0x22, 0x2, 0x2, 0x240, 0x241, 0x7, 
    0x22, 0x2, 0x2, 0x241, 0x257, 0x5, 0x74, 0x3b, 0x2, 0x242, 0x243, 0x7, 
    0x21, 0x2, 0x2, 0x243, 0x257, 0x5, 0x72, 0x3a, 0x2, 0x244, 0x245, 0x7, 
    0x22, 0x2, 0x2, 0x245, 0x257, 0x5, 0x72, 0x3a, 0x2, 0x246, 0x247, 0x7, 
    0x3d, 0x2, 0x2, 0x247, 0x257, 0x5, 0x72, 0x3a, 0x2, 0x248, 0x249, 0x7, 
    0x3f, 0x2, 0x2, 0x249, 0x257, 0x5, 0x72, 0x3a, 0x2, 0x24a, 0x24b, 0x7, 
    0x23, 0x2, 0x2, 0x24b, 0x257, 0x5, 0x72, 0x3a, 0x2, 0x24c, 0x24d, 0x7, 
    0x26, 0x2, 0x2, 0x24d, 0x257, 0x5, 0x72, 0x3a, 0x2, 0x24e, 0x24f, 0x7, 
    0x1e, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x27, 0x2, 0x2, 0x250, 0x251, 0x5, 
    0x2e, 0x18, 0x2, 0x251, 0x252, 0x7, 0x28, 0x2, 0x2, 0x252, 0x257, 0x3, 
    0x2, 0x2, 0x2, 0x253, 0x254, 0x7, 0x1e, 0x2, 0x2, 0x254, 0x257, 0x5, 
    0x74, 0x3b, 0x2, 0x255, 0x257, 0x5, 0x76, 0x3c, 0x2, 0x256, 0x23c, 0x3, 
    0x2, 0x2, 0x2, 0x256, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x256, 0x242, 0x3, 
    0x2, 0x2, 0x2, 0x256, 0x244, 0x3, 0x2, 0x2, 0x2, 0x256, 0x246, 0x3, 
    0x2, 0x2, 0x2, 0x256, 0x248, 0x3, 0x2, 0x2, 0x2, 0x256, 0x24a, 0x3, 
    0x2, 0x2, 0x2, 0x256, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x256, 0x24e, 0x3, 
    0x2, 0x2, 0x2, 0x256, 0x253, 0x3, 0x2, 0x2, 0x2, 0x256, 0x255, 0x3, 
    0x2, 0x2, 0x2, 0x257, 0x75, 0x3, 0x2, 0x2, 0x2, 0x258, 0x26c, 0x5, 0x7a, 
    0x3e, 0x2, 0x259, 0x25a, 0x7, 0x21, 0x2, 0x2, 0x25a, 0x26b, 0x7, 0x21, 
    0x2, 0x2, 0x25b, 0x25c, 0x7, 0x22, 0x2, 0x2, 0x25c, 0x26b, 0x7, 0x22, 
    0x2, 0x2, 0x25d, 0x25e, 0x7, 0x2d, 0x2, 0x2, 0x25e, 0x25f, 0x5, 0x5a, 
    0x2e, 0x2, 0x25f, 0x260, 0x7, 0x2e, 0x2, 0x2, 0x260, 0x26b, 0x3, 0x2, 
    0x2, 0x2, 0x261, 0x262, 0x7, 0x39, 0x2, 0x2, 0x262, 0x26b, 0x5, 0xa, 
    0x6, 0x2, 0x263, 0x264, 0x7, 0x40, 0x2, 0x2, 0x264, 0x26b, 0x5, 0xa, 
    0x6, 0x2, 0x265, 0x267, 0x7, 0x27, 0x2, 0x2, 0x266, 0x268, 0x5, 0x78, 
    0x3d, 0x2, 0x267, 0x266, 0x3, 0x2, 0x2, 0x2, 0x267, 0x268, 0x3, 0x2, 
    0x2, 0x2, 0x268, 0x269, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26b, 0x7, 0x28, 
    0x2, 0x2, 0x26a, 0x259, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x25b, 0x3, 0x2, 
    0x2, 0x2, 0x26a, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x261, 0x3, 0x2, 
    0x2, 0x2, 0x26a, 0x263, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x265, 0x3, 0x2, 
    0x2, 0x2, 0x26b, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26a, 0x3, 0x2, 
    0x2, 0x2, 0x26c, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x26e, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x274, 0x5, 0x5a, 0x2e, 
    0x2, 0x270, 0x271, 0x7, 0x29, 0x2, 0x2, 0x271, 0x273, 0x5, 0x5a, 0x2e, 
    0x2, 0x272, 0x270, 0x3, 0x2, 0x2, 0x2, 0x273, 0x276, 0x3, 0x2, 0x2, 
    0x2, 0x274, 0x272, 0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 
    0x2, 0x275, 0x79, 0x3, 0x2, 0x2, 0x2, 0x276, 0x274, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x282, 0x7, 0x46, 0x2, 0x2, 0x278, 0x282, 0x7, 0x47, 0x2, 0x2, 
    0x279, 0x282, 0x7, 0x48, 0x2, 0x2, 0x27a, 0x282, 0x7, 0x43, 0x2, 0x2, 
    0x27b, 0x282, 0x7, 0x44, 0x2, 0x2, 0x27c, 0x282, 0x7, 0x45, 0x2, 0x2, 
    0x27d, 0x27e, 0x7, 0x27, 0x2, 0x2, 0x27e, 0x27f, 0x5, 0x5a, 0x2e, 0x2, 
    0x27f, 0x280, 0x7, 0x28, 0x2, 0x2, 0x280, 0x282, 0x3, 0x2, 0x2, 0x2, 
    0x281, 0x277, 0x3, 0x2, 0x2, 0x2, 0x281, 0x278, 0x3, 0x2, 0x2, 0x2, 
    0x281, 0x279, 0x3, 0x2, 0x2, 0x2, 0x281, 0x27a, 0x3, 0x2, 0x2, 0x2, 
    0x281, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x281, 0x27c, 0x3, 0x2, 0x2, 0x2, 
    0x281, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x282, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x7f, 0x85, 0x8a, 0x93, 0x95, 0xa1, 0xb9, 0xbc, 0xc2, 0xcd, 0xcf, 0xd6, 
    0xe0, 0xe7, 0xef, 0xf7, 0x110, 0x12a, 0x12c, 0x141, 0x147, 0x149, 0x150, 
    0x156, 0x168, 0x175, 0x188, 0x18c, 0x19e, 0x1a2, 0x1ad, 0x1b6, 0x1c4, 
    0x1d1, 0x1e7, 0x1ef, 0x1f6, 0x1ff, 0x209, 0x211, 0x219, 0x221, 0x229, 
    0x231, 0x23a, 0x256, 0x267, 0x26a, 0x26c, 0x274, 0x281, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SesameParser::Initializer SesameParser::_init;

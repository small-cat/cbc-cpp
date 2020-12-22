
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

SesameParser::Top_defsContext* SesameParser::Compilation_unitContext::top_defs() {
  return getRuleContext<SesameParser::Top_defsContext>(0);
}

std::vector<SesameParser::Import_stmtContext *> SesameParser::Compilation_unitContext::import_stmt() {
  return getRuleContexts<SesameParser::Import_stmtContext>();
}

SesameParser::Import_stmtContext* SesameParser::Compilation_unitContext::import_stmt(size_t i) {
  return getRuleContext<SesameParser::Import_stmtContext>(i);
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
    setState(155);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::S_IMPORT) {
      setState(152);
      import_stmt();
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(158);
    top_defs();
   
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

std::vector<SesameParser::Declaration_stmtContext *> SesameParser::Declaration_fileContext::declaration_stmt() {
  return getRuleContexts<SesameParser::Declaration_stmtContext>();
}

SesameParser::Declaration_stmtContext* SesameParser::Declaration_fileContext::declaration_stmt(size_t i) {
  return getRuleContext<SesameParser::Declaration_stmtContext>(i);
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
    setState(163);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::S_IMPORT) {
      setState(160);
      import_stmt();
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::S_STRUCT)
      | (1ULL << SesameParser::S_UNION)
      | (1ULL << SesameParser::S_EXTERN)
      | (1ULL << SesameParser::S_CONST)
      | (1ULL << SesameParser::S_TYPEDEF))) != 0)) {
      setState(166);
      declaration_stmt();
      setState(171);
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

//----------------- Declaration_stmtContext ------------------------------------------------------------------

SesameParser::Declaration_stmtContext::Declaration_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Func_declContext* SesameParser::Declaration_stmtContext::func_decl() {
  return getRuleContext<SesameParser::Func_declContext>(0);
}

SesameParser::Var_declContext* SesameParser::Declaration_stmtContext::var_decl() {
  return getRuleContext<SesameParser::Var_declContext>(0);
}

SesameParser::Def_constContext* SesameParser::Declaration_stmtContext::def_const() {
  return getRuleContext<SesameParser::Def_constContext>(0);
}

SesameParser::Def_structContext* SesameParser::Declaration_stmtContext::def_struct() {
  return getRuleContext<SesameParser::Def_structContext>(0);
}

SesameParser::Def_unionContext* SesameParser::Declaration_stmtContext::def_union() {
  return getRuleContext<SesameParser::Def_unionContext>(0);
}

SesameParser::S_typedefContext* SesameParser::Declaration_stmtContext::s_typedef() {
  return getRuleContext<SesameParser::S_typedefContext>(0);
}


size_t SesameParser::Declaration_stmtContext::getRuleIndex() const {
  return SesameParser::RuleDeclaration_stmt;
}

void SesameParser::Declaration_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_stmt(this);
}

void SesameParser::Declaration_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_stmt(this);
}


antlrcpp::Any SesameParser::Declaration_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Declaration_stmtContext* SesameParser::declaration_stmt() {
  Declaration_stmtContext *_localctx = _tracker.createInstance<Declaration_stmtContext>(_ctx, getState());
  enterRule(_localctx, 4, SesameParser::RuleDeclaration_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(172);
      func_decl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(173);
      var_decl();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(174);
      def_const();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(175);
      def_struct();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(176);
      def_union();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(177);
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
  enterRule(_localctx, 6, SesameParser::RuleImport_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(SesameParser::S_IMPORT);
    setState(181);
    import_name();
    setState(182);
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
  enterRule(_localctx, 8, SesameParser::RuleImport_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    name();
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::PERIOD) {
      setState(185);
      match(SesameParser::PERIOD);
      setState(186);
      name();
      setState(191);
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
  enterRule(_localctx, 10, SesameParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
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
  enterRule(_localctx, 12, SesameParser::RuleFunc_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(SesameParser::S_EXTERN);
    setState(195);
    typeref();
    setState(196);
    name();
    setState(197);
    match(SesameParser::LPAREN);
    setState(198);
    params();
    setState(199);
    match(SesameParser::RPAREN);
    setState(200);
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
  enterRule(_localctx, 14, SesameParser::RuleVar_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(SesameParser::S_EXTERN);
    setState(203);
    type();
    setState(204);
    name();
    setState(205);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Top_defsContext ------------------------------------------------------------------

SesameParser::Top_defsContext::Top_defsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SesameParser::Def_funcContext *> SesameParser::Top_defsContext::def_func() {
  return getRuleContexts<SesameParser::Def_funcContext>();
}

SesameParser::Def_funcContext* SesameParser::Top_defsContext::def_func(size_t i) {
  return getRuleContext<SesameParser::Def_funcContext>(i);
}

std::vector<SesameParser::Def_varsContext *> SesameParser::Top_defsContext::def_vars() {
  return getRuleContexts<SesameParser::Def_varsContext>();
}

SesameParser::Def_varsContext* SesameParser::Top_defsContext::def_vars(size_t i) {
  return getRuleContext<SesameParser::Def_varsContext>(i);
}

std::vector<SesameParser::Def_constContext *> SesameParser::Top_defsContext::def_const() {
  return getRuleContexts<SesameParser::Def_constContext>();
}

SesameParser::Def_constContext* SesameParser::Top_defsContext::def_const(size_t i) {
  return getRuleContext<SesameParser::Def_constContext>(i);
}

std::vector<SesameParser::Def_structContext *> SesameParser::Top_defsContext::def_struct() {
  return getRuleContexts<SesameParser::Def_structContext>();
}

SesameParser::Def_structContext* SesameParser::Top_defsContext::def_struct(size_t i) {
  return getRuleContext<SesameParser::Def_structContext>(i);
}

std::vector<SesameParser::Def_unionContext *> SesameParser::Top_defsContext::def_union() {
  return getRuleContexts<SesameParser::Def_unionContext>();
}

SesameParser::Def_unionContext* SesameParser::Top_defsContext::def_union(size_t i) {
  return getRuleContext<SesameParser::Def_unionContext>(i);
}

std::vector<SesameParser::S_typedefContext *> SesameParser::Top_defsContext::s_typedef() {
  return getRuleContexts<SesameParser::S_typedefContext>();
}

SesameParser::S_typedefContext* SesameParser::Top_defsContext::s_typedef(size_t i) {
  return getRuleContext<SesameParser::S_typedefContext>(i);
}


size_t SesameParser::Top_defsContext::getRuleIndex() const {
  return SesameParser::RuleTop_defs;
}

void SesameParser::Top_defsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTop_defs(this);
}

void SesameParser::Top_defsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTop_defs(this);
}


antlrcpp::Any SesameParser::Top_defsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTop_defs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Top_defsContext* SesameParser::top_defs() {
  Top_defsContext *_localctx = _tracker.createInstance<Top_defsContext>(_ctx, getState());
  enterRule(_localctx, 16, SesameParser::RuleTop_defs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
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
      | (1ULL << SesameParser::S_STATIC)
      | (1ULL << SesameParser::S_CONST)
      | (1ULL << SesameParser::S_UNSIGNED)
      | (1ULL << SesameParser::S_TYPEDEF))) != 0) || _la == SesameParser::IDENTIFIER) {
      setState(213);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(207);
        def_func();
        break;
      }

      case 2: {
        setState(208);
        def_vars();
        break;
      }

      case 3: {
        setState(209);
        def_const();
        break;
      }

      case 4: {
        setState(210);
        def_struct();
        break;
      }

      case 5: {
        setState(211);
        def_union();
        break;
      }

      case 6: {
        setState(212);
        s_typedef();
        break;
      }

      }
      setState(217);
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
  enterRule(_localctx, 18, SesameParser::RuleDef_func);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::S_STATIC) {
      setState(218);
      storage();
    }
    setState(221);
    typeref();
    setState(222);
    name();
    setState(223);
    match(SesameParser::LPAREN);
    setState(225);
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
      setState(224);
      params();
    }
    setState(227);
    match(SesameParser::RPAREN);
    setState(228);
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
  enterRule(_localctx, 20, SesameParser::RuleStorage);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
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
  enterRule(_localctx, 22, SesameParser::RuleParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(232);
      match(SesameParser::S_VOID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(233);
      fixed_params();
      setState(236);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SesameParser::COMMA) {
        setState(234);
        match(SesameParser::COMMA);
        setState(235);
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
  enterRule(_localctx, 24, SesameParser::RuleFixed_params);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(240);
    param();
    setState(245);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(241);
        match(SesameParser::COMMA);
        setState(242);
        param(); 
      }
      setState(247);
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
  enterRule(_localctx, 26, SesameParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    type();
    setState(249);
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
  enterRule(_localctx, 28, SesameParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(SesameParser::LBRACE);
    setState(255);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(252);
        def_vars(); 
      }
      setState(257);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(258);
    stmts();
    setState(259);
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
  enterRule(_localctx, 30, SesameParser::RuleDef_vars);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::S_STATIC) {
      setState(261);
      storage();
    }
    setState(264);
    type();
    setState(265);
    assign_expr();
    setState(270);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::COMMA) {
      setState(266);
      match(SesameParser::COMMA);
      setState(267);
      assign_expr();
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(273);
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
  enterRule(_localctx, 32, SesameParser::RuleAssign_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    name();
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::EQUAL) {
      setState(276);
      match(SesameParser::EQUAL);
      setState(277);
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
  enterRule(_localctx, 34, SesameParser::RuleDef_const);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(SesameParser::S_CONST);
    setState(281);
    type();
    setState(282);
    name();
    setState(283);
    match(SesameParser::EQUAL);
    setState(284);
    expr();
    setState(285);
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
  enterRule(_localctx, 36, SesameParser::RuleDef_struct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(SesameParser::S_STRUCT);
    setState(288);
    name();
    setState(289);
    member_list();
    setState(290);
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
  enterRule(_localctx, 38, SesameParser::RuleDef_union);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(SesameParser::S_UNION);
    setState(293);
    name();
    setState(294);
    member_list();
    setState(295);
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
  enterRule(_localctx, 40, SesameParser::RuleMember_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(SesameParser::LBRACE);
    setState(303);
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
      setState(298);
      slot();
      setState(299);
      match(SesameParser::SEMI);
      setState(305);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(306);
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
  enterRule(_localctx, 42, SesameParser::RuleSlot);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    type();
    setState(309);
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
  enterRule(_localctx, 44, SesameParser::RuleS_typedef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    match(SesameParser::S_TYPEDEF);
    setState(312);
    typeref();
    setState(313);
    match(SesameParser::IDENTIFIER);
    setState(314);
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
  enterRule(_localctx, 46, SesameParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
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

std::vector<SesameParser::Typeref_preciseContext *> SesameParser::TyperefContext::typeref_precise() {
  return getRuleContexts<SesameParser::Typeref_preciseContext>();
}

SesameParser::Typeref_preciseContext* SesameParser::TyperefContext::typeref_precise(size_t i) {
  return getRuleContext<SesameParser::Typeref_preciseContext>(i);
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
  enterRule(_localctx, 48, SesameParser::RuleTyperef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    typeref_base();
    setState(322);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::ASTERISK)
      | (1ULL << SesameParser::LPAREN)
      | (1ULL << SesameParser::LBRACKET))) != 0)) {
      setState(319);
      typeref_precise();
      setState(324);
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


size_t SesameParser::Typeref_baseContext::getRuleIndex() const {
  return SesameParser::RuleTyperef_base;
}

void SesameParser::Typeref_baseContext::copyFrom(Typeref_baseContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Typeref_intContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_intContext::S_INT() {
  return getToken(SesameParser::S_INT, 0);
}

SesameParser::Typeref_intContext::Typeref_intContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_intContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_int(this);
}
void SesameParser::Typeref_intContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_int(this);
}

antlrcpp::Any SesameParser::Typeref_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_int(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Typeref_unionContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_unionContext::S_UNION() {
  return getToken(SesameParser::S_UNION, 0);
}

tree::TerminalNode* SesameParser::Typeref_unionContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}

SesameParser::Typeref_unionContext::Typeref_unionContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_unionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_union(this);
}
void SesameParser::Typeref_unionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_union(this);
}

antlrcpp::Any SesameParser::Typeref_unionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_union(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Typeref_charContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_charContext::S_CHAR() {
  return getToken(SesameParser::S_CHAR, 0);
}

SesameParser::Typeref_charContext::Typeref_charContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_charContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_char(this);
}
void SesameParser::Typeref_charContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_char(this);
}

antlrcpp::Any SesameParser::Typeref_charContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_char(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Typeref_unsignedContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_unsignedContext::S_UNSIGNED() {
  return getToken(SesameParser::S_UNSIGNED, 0);
}

tree::TerminalNode* SesameParser::Typeref_unsignedContext::S_CHAR() {
  return getToken(SesameParser::S_CHAR, 0);
}

tree::TerminalNode* SesameParser::Typeref_unsignedContext::S_SHORT() {
  return getToken(SesameParser::S_SHORT, 0);
}

tree::TerminalNode* SesameParser::Typeref_unsignedContext::S_INT() {
  return getToken(SesameParser::S_INT, 0);
}

tree::TerminalNode* SesameParser::Typeref_unsignedContext::S_LONG() {
  return getToken(SesameParser::S_LONG, 0);
}

SesameParser::Typeref_unsignedContext::Typeref_unsignedContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_unsignedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_unsigned(this);
}
void SesameParser::Typeref_unsignedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_unsigned(this);
}

antlrcpp::Any SesameParser::Typeref_unsignedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_unsigned(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Typeref_usertypeContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_usertypeContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}

SesameParser::Typeref_usertypeContext::Typeref_usertypeContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_usertypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_usertype(this);
}
void SesameParser::Typeref_usertypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_usertype(this);
}

antlrcpp::Any SesameParser::Typeref_usertypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_usertype(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Typeref_structContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_structContext::S_STRUCT() {
  return getToken(SesameParser::S_STRUCT, 0);
}

tree::TerminalNode* SesameParser::Typeref_structContext::IDENTIFIER() {
  return getToken(SesameParser::IDENTIFIER, 0);
}

SesameParser::Typeref_structContext::Typeref_structContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_structContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_struct(this);
}
void SesameParser::Typeref_structContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_struct(this);
}

antlrcpp::Any SesameParser::Typeref_structContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_struct(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Typeref_shortContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_shortContext::S_SHORT() {
  return getToken(SesameParser::S_SHORT, 0);
}

SesameParser::Typeref_shortContext::Typeref_shortContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_shortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_short(this);
}
void SesameParser::Typeref_shortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_short(this);
}

antlrcpp::Any SesameParser::Typeref_shortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_short(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Typeref_longContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_longContext::S_LONG() {
  return getToken(SesameParser::S_LONG, 0);
}

SesameParser::Typeref_longContext::Typeref_longContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_longContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_long(this);
}
void SesameParser::Typeref_longContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_long(this);
}

antlrcpp::Any SesameParser::Typeref_longContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_long(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Typeref_voidContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Typeref_voidContext::S_VOID() {
  return getToken(SesameParser::S_VOID, 0);
}

SesameParser::Typeref_voidContext::Typeref_voidContext(Typeref_baseContext *ctx) { copyFrom(ctx); }

void SesameParser::Typeref_voidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_void(this);
}
void SesameParser::Typeref_voidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_void(this);
}

antlrcpp::Any SesameParser::Typeref_voidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_void(this);
  else
    return visitor->visitChildren(this);
}
SesameParser::Typeref_baseContext* SesameParser::typeref_base() {
  Typeref_baseContext *_localctx = _tracker.createInstance<Typeref_baseContext>(_ctx, getState());
  enterRule(_localctx, 50, SesameParser::RuleTyperef_base);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(337);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SesameParser::S_VOID: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_voidContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(325);
        match(SesameParser::S_VOID);
        break;
      }

      case SesameParser::S_CHAR: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_charContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(326);
        match(SesameParser::S_CHAR);
        break;
      }

      case SesameParser::S_SHORT: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_shortContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(327);
        match(SesameParser::S_SHORT);
        break;
      }

      case SesameParser::S_INT: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_intContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(328);
        match(SesameParser::S_INT);
        break;
      }

      case SesameParser::S_LONG: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_longContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(329);
        match(SesameParser::S_LONG);
        break;
      }

      case SesameParser::S_UNSIGNED: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_unsignedContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(330);
        match(SesameParser::S_UNSIGNED);
        setState(331);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SesameParser::S_CHAR)
          | (1ULL << SesameParser::S_SHORT)
          | (1ULL << SesameParser::S_INT)
          | (1ULL << SesameParser::S_LONG))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case SesameParser::S_STRUCT: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_structContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(332);
        match(SesameParser::S_STRUCT);
        setState(333);
        match(SesameParser::IDENTIFIER);
        break;
      }

      case SesameParser::S_UNION: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_unionContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(334);
        match(SesameParser::S_UNION);
        setState(335);
        match(SesameParser::IDENTIFIER);
        break;
      }

      case SesameParser::IDENTIFIER: {
        _localctx = dynamic_cast<Typeref_baseContext *>(_tracker.createInstance<SesameParser::Typeref_usertypeContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(336);
        match(SesameParser::IDENTIFIER);
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

//----------------- Typeref_preciseContext ------------------------------------------------------------------

SesameParser::Typeref_preciseContext::Typeref_preciseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SesameParser::Typeref_preciseContext::LBRACKET() {
  return getToken(SesameParser::LBRACKET, 0);
}

tree::TerminalNode* SesameParser::Typeref_preciseContext::RBRACKET() {
  return getToken(SesameParser::RBRACKET, 0);
}

tree::TerminalNode* SesameParser::Typeref_preciseContext::INTEGER() {
  return getToken(SesameParser::INTEGER, 0);
}

tree::TerminalNode* SesameParser::Typeref_preciseContext::ASTERISK() {
  return getToken(SesameParser::ASTERISK, 0);
}

tree::TerminalNode* SesameParser::Typeref_preciseContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

SesameParser::Param_typerefsContext* SesameParser::Typeref_preciseContext::param_typerefs() {
  return getRuleContext<SesameParser::Param_typerefsContext>(0);
}

tree::TerminalNode* SesameParser::Typeref_preciseContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}


size_t SesameParser::Typeref_preciseContext::getRuleIndex() const {
  return SesameParser::RuleTyperef_precise;
}

void SesameParser::Typeref_preciseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyperef_precise(this);
}

void SesameParser::Typeref_preciseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyperef_precise(this);
}


antlrcpp::Any SesameParser::Typeref_preciseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitTyperef_precise(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Typeref_preciseContext* SesameParser::typeref_precise() {
  Typeref_preciseContext *_localctx = _tracker.createInstance<Typeref_preciseContext>(_ctx, getState());
  enterRule(_localctx, 52, SesameParser::RuleTyperef_precise);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SesameParser::LBRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(339);
        match(SesameParser::LBRACKET);
        setState(341);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SesameParser::INTEGER) {
          setState(340);
          match(SesameParser::INTEGER);
        }
        setState(343);
        match(SesameParser::RBRACKET);
        break;
      }

      case SesameParser::ASTERISK: {
        enterOuterAlt(_localctx, 2);
        setState(344);
        match(SesameParser::ASTERISK);
        break;
      }

      case SesameParser::LPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(345);
        match(SesameParser::LPAREN);
        setState(346);
        param_typerefs();
        setState(347);
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
  enterRule(_localctx, 54, SesameParser::RuleParam_typerefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(357);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(351);
      match(SesameParser::S_VOID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(352);
      fixed_param_typerefs();
      setState(355);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SesameParser::COMMA) {
        setState(353);
        match(SesameParser::COMMA);
        setState(354);
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
  enterRule(_localctx, 56, SesameParser::RuleFixed_param_typerefs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(359);
    typeref();
    setState(364);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(360);
        match(SesameParser::COMMA);
        setState(361);
        typeref(); 
      }
      setState(366);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
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
  enterRule(_localctx, 58, SesameParser::RuleStmts);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
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
      setState(367);
      stmt();
      setState(372);
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

SesameParser::Expr_stmtContext* SesameParser::StmtContext::expr_stmt() {
  return getRuleContext<SesameParser::Expr_stmtContext>(0);
}

SesameParser::Block_stmtContext* SesameParser::StmtContext::block_stmt() {
  return getRuleContext<SesameParser::Block_stmtContext>(0);
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
  enterRule(_localctx, 60, SesameParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(373);
      match(SesameParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(374);
      labeled_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(375);
      expr_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(376);
      block_stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(377);
      if_stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(378);
      while_stmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(379);
      do_while_stmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(380);
      for_stmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(381);
      switch_stmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(382);
      break_stmt();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(383);
      continue_stmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(384);
      goto_stmt();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(385);
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
  enterRule(_localctx, 62, SesameParser::RuleLabeled_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    dynamic_cast<Labeled_stmtContext *>(_localctx)->label_name = match(SesameParser::IDENTIFIER);
    setState(389);
    match(SesameParser::COLON);
    setState(390);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_stmtContext ------------------------------------------------------------------

SesameParser::Expr_stmtContext::Expr_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::ExprContext* SesameParser::Expr_stmtContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

tree::TerminalNode* SesameParser::Expr_stmtContext::SEMI() {
  return getToken(SesameParser::SEMI, 0);
}


size_t SesameParser::Expr_stmtContext::getRuleIndex() const {
  return SesameParser::RuleExpr_stmt;
}

void SesameParser::Expr_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_stmt(this);
}

void SesameParser::Expr_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_stmt(this);
}


antlrcpp::Any SesameParser::Expr_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr_stmtContext* SesameParser::expr_stmt() {
  Expr_stmtContext *_localctx = _tracker.createInstance<Expr_stmtContext>(_ctx, getState());
  enterRule(_localctx, 64, SesameParser::RuleExpr_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(392);
    expr();
    setState(393);
    match(SesameParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_stmtContext ------------------------------------------------------------------

SesameParser::Block_stmtContext::Block_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::BlockContext* SesameParser::Block_stmtContext::block() {
  return getRuleContext<SesameParser::BlockContext>(0);
}


size_t SesameParser::Block_stmtContext::getRuleIndex() const {
  return SesameParser::RuleBlock_stmt;
}

void SesameParser::Block_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_stmt(this);
}

void SesameParser::Block_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_stmt(this);
}


antlrcpp::Any SesameParser::Block_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitBlock_stmt(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Block_stmtContext* SesameParser::block_stmt() {
  Block_stmtContext *_localctx = _tracker.createInstance<Block_stmtContext>(_ctx, getState());
  enterRule(_localctx, 66, SesameParser::RuleBlock_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    block();
   
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
  enterRule(_localctx, 68, SesameParser::RuleIf_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    match(SesameParser::S_IF);
    setState(398);
    match(SesameParser::LPAREN);
    setState(399);
    expr();
    setState(400);
    match(SesameParser::RPAREN);
    setState(401);
    dynamic_cast<If_stmtContext *>(_localctx)->then_stmt = stmt();
    setState(404);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(402);
      match(SesameParser::S_ELSE);
      setState(403);
      dynamic_cast<If_stmtContext *>(_localctx)->else_stmt = stmt();
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
  enterRule(_localctx, 70, SesameParser::RuleWhile_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    match(SesameParser::S_WHILE);
    setState(407);
    match(SesameParser::LPAREN);
    setState(408);
    expr();
    setState(409);
    match(SesameParser::RPAREN);
    setState(410);
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
  enterRule(_localctx, 72, SesameParser::RuleDo_while_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(SesameParser::S_DO);
    setState(413);
    dynamic_cast<Do_while_stmtContext *>(_localctx)->body = stmt();
    setState(414);
    match(SesameParser::S_WHILE);
    setState(415);
    match(SesameParser::LPAREN);
    setState(416);
    dynamic_cast<Do_while_stmtContext *>(_localctx)->cond = expr();
    setState(417);
    match(SesameParser::RPAREN);
    setState(418);
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
  enterRule(_localctx, 74, SesameParser::RuleFor_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(420);
    match(SesameParser::S_FOR);
    setState(421);
    match(SesameParser::LPAREN);
    setState(423);
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
      setState(422);
      dynamic_cast<For_stmtContext *>(_localctx)->init = expr();
    }
    setState(425);
    match(SesameParser::SEMI);
    setState(427);
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
      setState(426);
      dynamic_cast<For_stmtContext *>(_localctx)->cond = expr();
    }
    setState(429);
    match(SesameParser::SEMI);
    setState(430);
    dynamic_cast<For_stmtContext *>(_localctx)->incr = expr();
    setState(431);
    match(SesameParser::RPAREN);
    setState(432);
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
  enterRule(_localctx, 76, SesameParser::RuleSwitch_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    match(SesameParser::S_SWITCH);
    setState(435);
    match(SesameParser::LPAREN);
    setState(436);
    dynamic_cast<Switch_stmtContext *>(_localctx)->cond = expr();
    setState(437);
    match(SesameParser::RPAREN);
    setState(438);
    match(SesameParser::LBRACE);
    setState(439);
    dynamic_cast<Switch_stmtContext *>(_localctx)->body = case_clauses();
    setState(440);
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
  enterRule(_localctx, 78, SesameParser::RuleCase_clauses);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::S_CASE) {
      setState(442);
      case_clause();
      setState(447);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(449);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::S_DEFAULT) {
      setState(448);
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
  enterRule(_localctx, 80, SesameParser::RuleCase_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    dynamic_cast<Case_clauseContext *>(_localctx)->values = cases();
    setState(452);
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
  enterRule(_localctx, 82, SesameParser::RuleCases);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(454);
      match(SesameParser::S_CASE);
      setState(455);
      primary();
      setState(456);
      match(SesameParser::COLON);
      setState(460); 
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
  enterRule(_localctx, 84, SesameParser::RuleDefault_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    match(SesameParser::S_DEFAULT);
    setState(463);
    match(SesameParser::COLON);
    setState(464);
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
  enterRule(_localctx, 86, SesameParser::RuleCase_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(466);
      stmt();
      setState(469); 
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
  enterRule(_localctx, 88, SesameParser::RuleBreak_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(471);
    match(SesameParser::S_BREAK);
    setState(472);
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
  enterRule(_localctx, 90, SesameParser::RuleContinue_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(474);
    match(SesameParser::S_CONTINUE);
    setState(475);
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
  enterRule(_localctx, 92, SesameParser::RuleGoto_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(477);
    match(SesameParser::S_GOTO);
    setState(478);
    dynamic_cast<Goto_stmtContext *>(_localctx)->label_name = match(SesameParser::IDENTIFIER);
    setState(479);
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
  enterRule(_localctx, 94, SesameParser::RuleReturn_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(481);
    match(SesameParser::S_RETURN);
    setState(483);
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
      setState(482);
      expr();
    }
    setState(485);
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


size_t SesameParser::ExprContext::getRuleIndex() const {
  return SesameParser::RuleExpr;
}

void SesameParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Assignment_exprContext ------------------------------------------------------------------

SesameParser::TermContext* SesameParser::Assignment_exprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

tree::TerminalNode* SesameParser::Assignment_exprContext::EQUAL() {
  return getToken(SesameParser::EQUAL, 0);
}

SesameParser::ExprContext* SesameParser::Assignment_exprContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

SesameParser::Assignment_exprContext::Assignment_exprContext(ExprContext *ctx) { copyFrom(ctx); }

void SesameParser::Assignment_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_expr(this);
}
void SesameParser::Assignment_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_expr(this);
}

antlrcpp::Any SesameParser::Assignment_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitAssignment_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Op_assign_exprContext ------------------------------------------------------------------

SesameParser::TermContext* SesameParser::Op_assign_exprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

SesameParser::Opassign_opContext* SesameParser::Op_assign_exprContext::opassign_op() {
  return getRuleContext<SesameParser::Opassign_opContext>(0);
}

SesameParser::ExprContext* SesameParser::Op_assign_exprContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

SesameParser::Op_assign_exprContext::Op_assign_exprContext(ExprContext *ctx) { copyFrom(ctx); }

void SesameParser::Op_assign_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_assign_expr(this);
}
void SesameParser::Op_assign_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_assign_expr(this);
}

antlrcpp::Any SesameParser::Op_assign_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitOp_assign_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expression_10Context ------------------------------------------------------------------

SesameParser::Expr10Context* SesameParser::Expression_10Context::expr10() {
  return getRuleContext<SesameParser::Expr10Context>(0);
}

SesameParser::Expression_10Context::Expression_10Context(ExprContext *ctx) { copyFrom(ctx); }

void SesameParser::Expression_10Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_10(this);
}
void SesameParser::Expression_10Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_10(this);
}

antlrcpp::Any SesameParser::Expression_10Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpression_10(this);
  else
    return visitor->visitChildren(this);
}
SesameParser::ExprContext* SesameParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 96, SesameParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(496);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<SesameParser::Assignment_exprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(487);
      term();
      setState(488);
      match(SesameParser::EQUAL);
      setState(489);
      expr();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<SesameParser::Op_assign_exprContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(491);
      term();
      setState(492);
      opassign_op();
      setState(493);
      expr();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<SesameParser::Expression_10Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(495);
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
  enterRule(_localctx, 98, SesameParser::RuleOpassign_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(518);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SesameParser::PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(498);
        match(SesameParser::PLUS);
        setState(499);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(500);
        match(SesameParser::MINUS);
        setState(501);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::ASTERISK: {
        enterOuterAlt(_localctx, 3);
        setState(502);
        match(SesameParser::ASTERISK);
        setState(503);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::SOLIDUS: {
        enterOuterAlt(_localctx, 4);
        setState(504);
        match(SesameParser::SOLIDUS);
        setState(505);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::PERCENT: {
        enterOuterAlt(_localctx, 5);
        setState(506);
        match(SesameParser::PERCENT);
        setState(507);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::AMPERSAND: {
        enterOuterAlt(_localctx, 6);
        setState(508);
        match(SesameParser::AMPERSAND);
        setState(509);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::BAR: {
        enterOuterAlt(_localctx, 7);
        setState(510);
        match(SesameParser::BAR);
        setState(511);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::CARRET_OPERATOR_PART: {
        enterOuterAlt(_localctx, 8);
        setState(512);
        match(SesameParser::CARRET_OPERATOR_PART);
        setState(513);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::LSHIFT: {
        enterOuterAlt(_localctx, 9);
        setState(514);
        match(SesameParser::LSHIFT);
        setState(515);
        match(SesameParser::EQUAL);
        break;
      }

      case SesameParser::RSHIFT: {
        enterOuterAlt(_localctx, 10);
        setState(516);
        match(SesameParser::RSHIFT);
        setState(517);
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

SesameParser::Expr9Context* SesameParser::Expr10Context::expr9() {
  return getRuleContext<SesameParser::Expr9Context>(0);
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
  enterRule(_localctx, 100, SesameParser::RuleExpr10);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    expr9();
    setState(526);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SesameParser::QUESTION) {
      setState(521);
      match(SesameParser::QUESTION);
      setState(522);
      expr();
      setState(523);
      match(SesameParser::COLON);
      setState(524);
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

//----------------- Expr9Context ------------------------------------------------------------------

SesameParser::Expr9Context::Expr9Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr8Context* SesameParser::Expr9Context::expr8() {
  return getRuleContext<SesameParser::Expr8Context>(0);
}

std::vector<tree::TerminalNode *> SesameParser::Expr9Context::LOGIC_OR() {
  return getTokens(SesameParser::LOGIC_OR);
}

tree::TerminalNode* SesameParser::Expr9Context::LOGIC_OR(size_t i) {
  return getToken(SesameParser::LOGIC_OR, i);
}

std::vector<SesameParser::Logic_or_rhsContext *> SesameParser::Expr9Context::logic_or_rhs() {
  return getRuleContexts<SesameParser::Logic_or_rhsContext>();
}

SesameParser::Logic_or_rhsContext* SesameParser::Expr9Context::logic_or_rhs(size_t i) {
  return getRuleContext<SesameParser::Logic_or_rhsContext>(i);
}


size_t SesameParser::Expr9Context::getRuleIndex() const {
  return SesameParser::RuleExpr9;
}

void SesameParser::Expr9Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr9(this);
}

void SesameParser::Expr9Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr9(this);
}


antlrcpp::Any SesameParser::Expr9Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitExpr9(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Expr9Context* SesameParser::expr9() {
  Expr9Context *_localctx = _tracker.createInstance<Expr9Context>(_ctx, getState());
  enterRule(_localctx, 102, SesameParser::RuleExpr9);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(528);
    dynamic_cast<Expr9Context *>(_localctx)->lhs = expr8();
    setState(533);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::LOGIC_OR) {
      setState(529);
      match(SesameParser::LOGIC_OR);
      setState(530);
      logic_or_rhs();
      setState(535);
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

//----------------- Logic_or_rhsContext ------------------------------------------------------------------

SesameParser::Logic_or_rhsContext::Logic_or_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr8Context* SesameParser::Logic_or_rhsContext::expr8() {
  return getRuleContext<SesameParser::Expr8Context>(0);
}


size_t SesameParser::Logic_or_rhsContext::getRuleIndex() const {
  return SesameParser::RuleLogic_or_rhs;
}

void SesameParser::Logic_or_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_or_rhs(this);
}

void SesameParser::Logic_or_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_or_rhs(this);
}


antlrcpp::Any SesameParser::Logic_or_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitLogic_or_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Logic_or_rhsContext* SesameParser::logic_or_rhs() {
  Logic_or_rhsContext *_localctx = _tracker.createInstance<Logic_or_rhsContext>(_ctx, getState());
  enterRule(_localctx, 104, SesameParser::RuleLogic_or_rhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(536);
    expr8();
   
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

SesameParser::Expr7Context* SesameParser::Expr8Context::expr7() {
  return getRuleContext<SesameParser::Expr7Context>(0);
}

std::vector<tree::TerminalNode *> SesameParser::Expr8Context::LOGIC_AND() {
  return getTokens(SesameParser::LOGIC_AND);
}

tree::TerminalNode* SesameParser::Expr8Context::LOGIC_AND(size_t i) {
  return getToken(SesameParser::LOGIC_AND, i);
}

std::vector<SesameParser::Logic_and_rhsContext *> SesameParser::Expr8Context::logic_and_rhs() {
  return getRuleContexts<SesameParser::Logic_and_rhsContext>();
}

SesameParser::Logic_and_rhsContext* SesameParser::Expr8Context::logic_and_rhs(size_t i) {
  return getRuleContext<SesameParser::Logic_and_rhsContext>(i);
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
  enterRule(_localctx, 106, SesameParser::RuleExpr8);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    dynamic_cast<Expr8Context *>(_localctx)->lhs = expr7();
    setState(543);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::LOGIC_AND) {
      setState(539);
      match(SesameParser::LOGIC_AND);
      setState(540);
      logic_and_rhs();
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

//----------------- Logic_and_rhsContext ------------------------------------------------------------------

SesameParser::Logic_and_rhsContext::Logic_and_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr7Context* SesameParser::Logic_and_rhsContext::expr7() {
  return getRuleContext<SesameParser::Expr7Context>(0);
}


size_t SesameParser::Logic_and_rhsContext::getRuleIndex() const {
  return SesameParser::RuleLogic_and_rhs;
}

void SesameParser::Logic_and_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_and_rhs(this);
}

void SesameParser::Logic_and_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_and_rhs(this);
}


antlrcpp::Any SesameParser::Logic_and_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitLogic_and_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Logic_and_rhsContext* SesameParser::logic_and_rhs() {
  Logic_and_rhsContext *_localctx = _tracker.createInstance<Logic_and_rhsContext>(_ctx, getState());
  enterRule(_localctx, 108, SesameParser::RuleLogic_and_rhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(546);
    expr7();
   
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

SesameParser::Expr6Context* SesameParser::Expr7Context::expr6() {
  return getRuleContext<SesameParser::Expr6Context>(0);
}

std::vector<SesameParser::Binary_op_rhsContext *> SesameParser::Expr7Context::binary_op_rhs() {
  return getRuleContexts<SesameParser::Binary_op_rhsContext>();
}

SesameParser::Binary_op_rhsContext* SesameParser::Expr7Context::binary_op_rhs(size_t i) {
  return getRuleContext<SesameParser::Binary_op_rhsContext>(i);
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
  enterRule(_localctx, 110, SesameParser::RuleExpr7);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(548);
    dynamic_cast<Expr7Context *>(_localctx)->lhs = expr6();
    setState(552);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::LESS)
      | (1ULL << SesameParser::LESS_EQ)
      | (1ULL << SesameParser::GREATER)
      | (1ULL << SesameParser::GREATER_EQ)
      | (1ULL << SesameParser::NOT_EQ)
      | (1ULL << SesameParser::EQ_SIGN))) != 0)) {
      setState(549);
      binary_op_rhs();
      setState(554);
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

//----------------- Binary_op_rhsContext ------------------------------------------------------------------

SesameParser::Binary_op_rhsContext::Binary_op_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Logical_opContext* SesameParser::Binary_op_rhsContext::logical_op() {
  return getRuleContext<SesameParser::Logical_opContext>(0);
}

SesameParser::Expr6Context* SesameParser::Binary_op_rhsContext::expr6() {
  return getRuleContext<SesameParser::Expr6Context>(0);
}


size_t SesameParser::Binary_op_rhsContext::getRuleIndex() const {
  return SesameParser::RuleBinary_op_rhs;
}

void SesameParser::Binary_op_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_op_rhs(this);
}

void SesameParser::Binary_op_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_op_rhs(this);
}


antlrcpp::Any SesameParser::Binary_op_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitBinary_op_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Binary_op_rhsContext* SesameParser::binary_op_rhs() {
  Binary_op_rhsContext *_localctx = _tracker.createInstance<Binary_op_rhsContext>(_ctx, getState());
  enterRule(_localctx, 112, SesameParser::RuleBinary_op_rhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    logical_op();
    setState(556);
    expr6();
   
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
  enterRule(_localctx, 114, SesameParser::RuleLogical_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(558);
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

SesameParser::Expr5Context* SesameParser::Expr6Context::expr5() {
  return getRuleContext<SesameParser::Expr5Context>(0);
}

std::vector<tree::TerminalNode *> SesameParser::Expr6Context::BAR() {
  return getTokens(SesameParser::BAR);
}

tree::TerminalNode* SesameParser::Expr6Context::BAR(size_t i) {
  return getToken(SesameParser::BAR, i);
}

std::vector<SesameParser::Bit_or_rhsContext *> SesameParser::Expr6Context::bit_or_rhs() {
  return getRuleContexts<SesameParser::Bit_or_rhsContext>();
}

SesameParser::Bit_or_rhsContext* SesameParser::Expr6Context::bit_or_rhs(size_t i) {
  return getRuleContext<SesameParser::Bit_or_rhsContext>(i);
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
  enterRule(_localctx, 116, SesameParser::RuleExpr6);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(560);
    dynamic_cast<Expr6Context *>(_localctx)->lhs = expr5();
    setState(565);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::BAR) {
      setState(561);
      match(SesameParser::BAR);
      setState(562);
      bit_or_rhs();
      setState(567);
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

//----------------- Bit_or_rhsContext ------------------------------------------------------------------

SesameParser::Bit_or_rhsContext::Bit_or_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr5Context* SesameParser::Bit_or_rhsContext::expr5() {
  return getRuleContext<SesameParser::Expr5Context>(0);
}


size_t SesameParser::Bit_or_rhsContext::getRuleIndex() const {
  return SesameParser::RuleBit_or_rhs;
}

void SesameParser::Bit_or_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBit_or_rhs(this);
}

void SesameParser::Bit_or_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBit_or_rhs(this);
}


antlrcpp::Any SesameParser::Bit_or_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitBit_or_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Bit_or_rhsContext* SesameParser::bit_or_rhs() {
  Bit_or_rhsContext *_localctx = _tracker.createInstance<Bit_or_rhsContext>(_ctx, getState());
  enterRule(_localctx, 118, SesameParser::RuleBit_or_rhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    expr5();
   
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

SesameParser::Expr4Context* SesameParser::Expr5Context::expr4() {
  return getRuleContext<SesameParser::Expr4Context>(0);
}

std::vector<tree::TerminalNode *> SesameParser::Expr5Context::CARRET_OPERATOR_PART() {
  return getTokens(SesameParser::CARRET_OPERATOR_PART);
}

tree::TerminalNode* SesameParser::Expr5Context::CARRET_OPERATOR_PART(size_t i) {
  return getToken(SesameParser::CARRET_OPERATOR_PART, i);
}

std::vector<SesameParser::Xor_rhsContext *> SesameParser::Expr5Context::xor_rhs() {
  return getRuleContexts<SesameParser::Xor_rhsContext>();
}

SesameParser::Xor_rhsContext* SesameParser::Expr5Context::xor_rhs(size_t i) {
  return getRuleContext<SesameParser::Xor_rhsContext>(i);
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
  enterRule(_localctx, 120, SesameParser::RuleExpr5);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
    dynamic_cast<Expr5Context *>(_localctx)->lhs = expr4();
    setState(575);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::CARRET_OPERATOR_PART) {
      setState(571);
      match(SesameParser::CARRET_OPERATOR_PART);
      setState(572);
      xor_rhs();
      setState(577);
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

//----------------- Xor_rhsContext ------------------------------------------------------------------

SesameParser::Xor_rhsContext::Xor_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr4Context* SesameParser::Xor_rhsContext::expr4() {
  return getRuleContext<SesameParser::Expr4Context>(0);
}


size_t SesameParser::Xor_rhsContext::getRuleIndex() const {
  return SesameParser::RuleXor_rhs;
}

void SesameParser::Xor_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXor_rhs(this);
}

void SesameParser::Xor_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXor_rhs(this);
}


antlrcpp::Any SesameParser::Xor_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitXor_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Xor_rhsContext* SesameParser::xor_rhs() {
  Xor_rhsContext *_localctx = _tracker.createInstance<Xor_rhsContext>(_ctx, getState());
  enterRule(_localctx, 122, SesameParser::RuleXor_rhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(578);
    expr4();
   
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

SesameParser::Expr3Context* SesameParser::Expr4Context::expr3() {
  return getRuleContext<SesameParser::Expr3Context>(0);
}

std::vector<tree::TerminalNode *> SesameParser::Expr4Context::AMPERSAND() {
  return getTokens(SesameParser::AMPERSAND);
}

tree::TerminalNode* SesameParser::Expr4Context::AMPERSAND(size_t i) {
  return getToken(SesameParser::AMPERSAND, i);
}

std::vector<SesameParser::Bit_and_rhsContext *> SesameParser::Expr4Context::bit_and_rhs() {
  return getRuleContexts<SesameParser::Bit_and_rhsContext>();
}

SesameParser::Bit_and_rhsContext* SesameParser::Expr4Context::bit_and_rhs(size_t i) {
  return getRuleContext<SesameParser::Bit_and_rhsContext>(i);
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
  enterRule(_localctx, 124, SesameParser::RuleExpr4);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(580);
    dynamic_cast<Expr4Context *>(_localctx)->lhs = expr3();
    setState(585);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::AMPERSAND) {
      setState(581);
      match(SesameParser::AMPERSAND);
      setState(582);
      bit_and_rhs();
      setState(587);
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

//----------------- Bit_and_rhsContext ------------------------------------------------------------------

SesameParser::Bit_and_rhsContext::Bit_and_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr3Context* SesameParser::Bit_and_rhsContext::expr3() {
  return getRuleContext<SesameParser::Expr3Context>(0);
}


size_t SesameParser::Bit_and_rhsContext::getRuleIndex() const {
  return SesameParser::RuleBit_and_rhs;
}

void SesameParser::Bit_and_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBit_and_rhs(this);
}

void SesameParser::Bit_and_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBit_and_rhs(this);
}


antlrcpp::Any SesameParser::Bit_and_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitBit_and_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Bit_and_rhsContext* SesameParser::bit_and_rhs() {
  Bit_and_rhsContext *_localctx = _tracker.createInstance<Bit_and_rhsContext>(_ctx, getState());
  enterRule(_localctx, 126, SesameParser::RuleBit_and_rhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(588);
    expr3();
   
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

SesameParser::Expr2Context* SesameParser::Expr3Context::expr2() {
  return getRuleContext<SesameParser::Expr2Context>(0);
}

std::vector<SesameParser::Shift_op_rhsContext *> SesameParser::Expr3Context::shift_op_rhs() {
  return getRuleContexts<SesameParser::Shift_op_rhsContext>();
}

SesameParser::Shift_op_rhsContext* SesameParser::Expr3Context::shift_op_rhs(size_t i) {
  return getRuleContext<SesameParser::Shift_op_rhsContext>(i);
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
  enterRule(_localctx, 128, SesameParser::RuleExpr3);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(590);
    dynamic_cast<Expr3Context *>(_localctx)->lhs = expr2();
    setState(594);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::LSHIFT

    || _la == SesameParser::RSHIFT) {
      setState(591);
      shift_op_rhs();
      setState(596);
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

//----------------- Shift_op_rhsContext ------------------------------------------------------------------

SesameParser::Shift_op_rhsContext::Shift_op_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr2Context* SesameParser::Shift_op_rhsContext::expr2() {
  return getRuleContext<SesameParser::Expr2Context>(0);
}

tree::TerminalNode* SesameParser::Shift_op_rhsContext::LSHIFT() {
  return getToken(SesameParser::LSHIFT, 0);
}

tree::TerminalNode* SesameParser::Shift_op_rhsContext::RSHIFT() {
  return getToken(SesameParser::RSHIFT, 0);
}


size_t SesameParser::Shift_op_rhsContext::getRuleIndex() const {
  return SesameParser::RuleShift_op_rhs;
}

void SesameParser::Shift_op_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShift_op_rhs(this);
}

void SesameParser::Shift_op_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShift_op_rhs(this);
}


antlrcpp::Any SesameParser::Shift_op_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitShift_op_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Shift_op_rhsContext* SesameParser::shift_op_rhs() {
  Shift_op_rhsContext *_localctx = _tracker.createInstance<Shift_op_rhsContext>(_ctx, getState());
  enterRule(_localctx, 130, SesameParser::RuleShift_op_rhs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    _la = _input->LA(1);
    if (!(_la == SesameParser::LSHIFT

    || _la == SesameParser::RSHIFT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(598);
    expr2();
   
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

SesameParser::Expr1Context* SesameParser::Expr2Context::expr1() {
  return getRuleContext<SesameParser::Expr1Context>(0);
}

std::vector<SesameParser::Add_sub_rhsContext *> SesameParser::Expr2Context::add_sub_rhs() {
  return getRuleContexts<SesameParser::Add_sub_rhsContext>();
}

SesameParser::Add_sub_rhsContext* SesameParser::Expr2Context::add_sub_rhs(size_t i) {
  return getRuleContext<SesameParser::Add_sub_rhsContext>(i);
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
  enterRule(_localctx, 132, SesameParser::RuleExpr2);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(600);
    dynamic_cast<Expr2Context *>(_localctx)->lhs = expr1();
    setState(604);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::PLUS

    || _la == SesameParser::MINUS) {
      setState(601);
      add_sub_rhs();
      setState(606);
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

//----------------- Add_sub_rhsContext ------------------------------------------------------------------

SesameParser::Add_sub_rhsContext::Add_sub_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::Expr1Context* SesameParser::Add_sub_rhsContext::expr1() {
  return getRuleContext<SesameParser::Expr1Context>(0);
}

tree::TerminalNode* SesameParser::Add_sub_rhsContext::PLUS() {
  return getToken(SesameParser::PLUS, 0);
}

tree::TerminalNode* SesameParser::Add_sub_rhsContext::MINUS() {
  return getToken(SesameParser::MINUS, 0);
}


size_t SesameParser::Add_sub_rhsContext::getRuleIndex() const {
  return SesameParser::RuleAdd_sub_rhs;
}

void SesameParser::Add_sub_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd_sub_rhs(this);
}

void SesameParser::Add_sub_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd_sub_rhs(this);
}


antlrcpp::Any SesameParser::Add_sub_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitAdd_sub_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Add_sub_rhsContext* SesameParser::add_sub_rhs() {
  Add_sub_rhsContext *_localctx = _tracker.createInstance<Add_sub_rhsContext>(_ctx, getState());
  enterRule(_localctx, 134, SesameParser::RuleAdd_sub_rhs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    dynamic_cast<Add_sub_rhsContext *>(_localctx)->tk = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == SesameParser::PLUS

    || _la == SesameParser::MINUS)) {
      dynamic_cast<Add_sub_rhsContext *>(_localctx)->tk = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(608);
    expr1();
   
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

SesameParser::TermContext* SesameParser::Expr1Context::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

std::vector<SesameParser::Multi_div_mod_rhsContext *> SesameParser::Expr1Context::multi_div_mod_rhs() {
  return getRuleContexts<SesameParser::Multi_div_mod_rhsContext>();
}

SesameParser::Multi_div_mod_rhsContext* SesameParser::Expr1Context::multi_div_mod_rhs(size_t i) {
  return getRuleContext<SesameParser::Multi_div_mod_rhsContext>(i);
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
  enterRule(_localctx, 136, SesameParser::RuleExpr1);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(610);
    dynamic_cast<Expr1Context *>(_localctx)->lhs = term();
    setState(614);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::ASTERISK)
      | (1ULL << SesameParser::SOLIDUS)
      | (1ULL << SesameParser::PERCENT))) != 0)) {
      setState(611);
      multi_div_mod_rhs();
      setState(616);
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

//----------------- Multi_div_mod_rhsContext ------------------------------------------------------------------

SesameParser::Multi_div_mod_rhsContext::Multi_div_mod_rhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SesameParser::TermContext* SesameParser::Multi_div_mod_rhsContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

tree::TerminalNode* SesameParser::Multi_div_mod_rhsContext::ASTERISK() {
  return getToken(SesameParser::ASTERISK, 0);
}

tree::TerminalNode* SesameParser::Multi_div_mod_rhsContext::SOLIDUS() {
  return getToken(SesameParser::SOLIDUS, 0);
}

tree::TerminalNode* SesameParser::Multi_div_mod_rhsContext::PERCENT() {
  return getToken(SesameParser::PERCENT, 0);
}


size_t SesameParser::Multi_div_mod_rhsContext::getRuleIndex() const {
  return SesameParser::RuleMulti_div_mod_rhs;
}

void SesameParser::Multi_div_mod_rhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulti_div_mod_rhs(this);
}

void SesameParser::Multi_div_mod_rhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulti_div_mod_rhs(this);
}


antlrcpp::Any SesameParser::Multi_div_mod_rhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitMulti_div_mod_rhs(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Multi_div_mod_rhsContext* SesameParser::multi_div_mod_rhs() {
  Multi_div_mod_rhsContext *_localctx = _tracker.createInstance<Multi_div_mod_rhsContext>(_ctx, getState());
  enterRule(_localctx, 138, SesameParser::RuleMulti_div_mod_rhs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(617);
    dynamic_cast<Multi_div_mod_rhsContext *>(_localctx)->tk = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SesameParser::ASTERISK)
      | (1ULL << SesameParser::SOLIDUS)
      | (1ULL << SesameParser::PERCENT))) != 0))) {
      dynamic_cast<Multi_div_mod_rhsContext *>(_localctx)->tk = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(618);
    term();
   
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
  enterRule(_localctx, 140, SesameParser::RuleTerm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(626);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(620);
      match(SesameParser::LPAREN);
      setState(621);
      type();
      setState(622);
      match(SesameParser::RPAREN);
      setState(623);
      term();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(625);
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


size_t SesameParser::UnaryContext::getRuleIndex() const {
  return SesameParser::RuleUnary;
}

void SesameParser::UnaryContext::copyFrom(UnaryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Unary_postfix_exprContext ------------------------------------------------------------------

SesameParser::PostfixContext* SesameParser::Unary_postfix_exprContext::postfix() {
  return getRuleContext<SesameParser::PostfixContext>(0);
}

SesameParser::Unary_postfix_exprContext::Unary_postfix_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Unary_postfix_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_postfix_expr(this);
}
void SesameParser::Unary_postfix_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_postfix_expr(this);
}

antlrcpp::Any SesameParser::Unary_postfix_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitUnary_postfix_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Negative_exprContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Negative_exprContext::MINUS() {
  return getToken(SesameParser::MINUS, 0);
}

SesameParser::TermContext* SesameParser::Negative_exprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

SesameParser::Negative_exprContext::Negative_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Negative_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegative_expr(this);
}
void SesameParser::Negative_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegative_expr(this);
}

antlrcpp::Any SesameParser::Negative_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitNegative_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Inc_exprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> SesameParser::Inc_exprContext::PLUS() {
  return getTokens(SesameParser::PLUS);
}

tree::TerminalNode* SesameParser::Inc_exprContext::PLUS(size_t i) {
  return getToken(SesameParser::PLUS, i);
}

SesameParser::UnaryContext* SesameParser::Inc_exprContext::unary() {
  return getRuleContext<SesameParser::UnaryContext>(0);
}

SesameParser::Inc_exprContext::Inc_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Inc_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInc_expr(this);
}
void SesameParser::Inc_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInc_expr(this);
}

antlrcpp::Any SesameParser::Inc_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitInc_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Addr_exprContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Addr_exprContext::AMPERSAND() {
  return getToken(SesameParser::AMPERSAND, 0);
}

SesameParser::TermContext* SesameParser::Addr_exprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

SesameParser::Addr_exprContext::Addr_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Addr_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddr_expr(this);
}
void SesameParser::Addr_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddr_expr(this);
}

antlrcpp::Any SesameParser::Addr_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitAddr_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dec_exprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> SesameParser::Dec_exprContext::MINUS() {
  return getTokens(SesameParser::MINUS);
}

tree::TerminalNode* SesameParser::Dec_exprContext::MINUS(size_t i) {
  return getToken(SesameParser::MINUS, i);
}

SesameParser::UnaryContext* SesameParser::Dec_exprContext::unary() {
  return getRuleContext<SesameParser::UnaryContext>(0);
}

SesameParser::Dec_exprContext::Dec_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Dec_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDec_expr(this);
}
void SesameParser::Dec_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDec_expr(this);
}

antlrcpp::Any SesameParser::Dec_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDec_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Logic_not_exprContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Logic_not_exprContext::EXCLAMATION_OPERATOR() {
  return getToken(SesameParser::EXCLAMATION_OPERATOR, 0);
}

SesameParser::TermContext* SesameParser::Logic_not_exprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

SesameParser::Logic_not_exprContext::Logic_not_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Logic_not_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_not_expr(this);
}
void SesameParser::Logic_not_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_not_expr(this);
}

antlrcpp::Any SesameParser::Logic_not_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitLogic_not_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Sizeof_exprContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Sizeof_exprContext::S_SIZEOF() {
  return getToken(SesameParser::S_SIZEOF, 0);
}

SesameParser::UnaryContext* SesameParser::Sizeof_exprContext::unary() {
  return getRuleContext<SesameParser::UnaryContext>(0);
}

SesameParser::Sizeof_exprContext::Sizeof_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Sizeof_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSizeof_expr(this);
}
void SesameParser::Sizeof_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSizeof_expr(this);
}

antlrcpp::Any SesameParser::Sizeof_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitSizeof_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Positive_exprContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Positive_exprContext::PLUS() {
  return getToken(SesameParser::PLUS, 0);
}

SesameParser::TermContext* SesameParser::Positive_exprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

SesameParser::Positive_exprContext::Positive_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Positive_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPositive_expr(this);
}
void SesameParser::Positive_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPositive_expr(this);
}

antlrcpp::Any SesameParser::Positive_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitPositive_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Sizeof_type_exprContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Sizeof_type_exprContext::S_SIZEOF() {
  return getToken(SesameParser::S_SIZEOF, 0);
}

tree::TerminalNode* SesameParser::Sizeof_type_exprContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

SesameParser::TypeContext* SesameParser::Sizeof_type_exprContext::type() {
  return getRuleContext<SesameParser::TypeContext>(0);
}

tree::TerminalNode* SesameParser::Sizeof_type_exprContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

SesameParser::Sizeof_type_exprContext::Sizeof_type_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Sizeof_type_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSizeof_type_expr(this);
}
void SesameParser::Sizeof_type_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSizeof_type_expr(this);
}

antlrcpp::Any SesameParser::Sizeof_type_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitSizeof_type_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Bit_not_exprContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Bit_not_exprContext::TILDE_OPERATOR() {
  return getToken(SesameParser::TILDE_OPERATOR, 0);
}

SesameParser::TermContext* SesameParser::Bit_not_exprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

SesameParser::Bit_not_exprContext::Bit_not_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Bit_not_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBit_not_expr(this);
}
void SesameParser::Bit_not_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBit_not_expr(this);
}

antlrcpp::Any SesameParser::Bit_not_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitBit_not_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dereference_exprContext ------------------------------------------------------------------

tree::TerminalNode* SesameParser::Dereference_exprContext::ASTERISK() {
  return getToken(SesameParser::ASTERISK, 0);
}

SesameParser::TermContext* SesameParser::Dereference_exprContext::term() {
  return getRuleContext<SesameParser::TermContext>(0);
}

SesameParser::Dereference_exprContext::Dereference_exprContext(UnaryContext *ctx) { copyFrom(ctx); }

void SesameParser::Dereference_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDereference_expr(this);
}
void SesameParser::Dereference_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDereference_expr(this);
}

antlrcpp::Any SesameParser::Dereference_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitDereference_expr(this);
  else
    return visitor->visitChildren(this);
}
SesameParser::UnaryContext* SesameParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 142, SesameParser::RuleUnary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(654);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Inc_exprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(628);
      match(SesameParser::PLUS);
      setState(629);
      match(SesameParser::PLUS);
      setState(630);
      unary();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Dec_exprContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(631);
      match(SesameParser::MINUS);
      setState(632);
      match(SesameParser::MINUS);
      setState(633);
      unary();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Positive_exprContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(634);
      match(SesameParser::PLUS);
      setState(635);
      term();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Negative_exprContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(636);
      match(SesameParser::MINUS);
      setState(637);
      term();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Logic_not_exprContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(638);
      match(SesameParser::EXCLAMATION_OPERATOR);
      setState(639);
      term();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Bit_not_exprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(640);
      match(SesameParser::TILDE_OPERATOR);
      setState(641);
      term();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Dereference_exprContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(642);
      match(SesameParser::ASTERISK);
      setState(643);
      term();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Addr_exprContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(644);
      match(SesameParser::AMPERSAND);
      setState(645);
      term();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Sizeof_type_exprContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(646);
      match(SesameParser::S_SIZEOF);
      setState(647);
      match(SesameParser::LPAREN);
      setState(648);
      type();
      setState(649);
      match(SesameParser::RPAREN);
      break;
    }

    case 10: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Sizeof_exprContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(651);
      match(SesameParser::S_SIZEOF);
      setState(652);
      unary();
      break;
    }

    case 11: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<SesameParser::Unary_postfix_exprContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(653);
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

std::vector<SesameParser::Postfix_optionContext *> SesameParser::PostfixContext::postfix_option() {
  return getRuleContexts<SesameParser::Postfix_optionContext>();
}

SesameParser::Postfix_optionContext* SesameParser::PostfixContext::postfix_option(size_t i) {
  return getRuleContext<SesameParser::Postfix_optionContext>(i);
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
  enterRule(_localctx, 144, SesameParser::RulePostfix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(656);
    primary();
    setState(660);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(657);
        postfix_option(); 
      }
      setState(662);
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

//----------------- Postfix_optionContext ------------------------------------------------------------------

SesameParser::Postfix_optionContext::Postfix_optionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SesameParser::Postfix_optionContext::PLUS() {
  return getTokens(SesameParser::PLUS);
}

tree::TerminalNode* SesameParser::Postfix_optionContext::PLUS(size_t i) {
  return getToken(SesameParser::PLUS, i);
}

std::vector<tree::TerminalNode *> SesameParser::Postfix_optionContext::MINUS() {
  return getTokens(SesameParser::MINUS);
}

tree::TerminalNode* SesameParser::Postfix_optionContext::MINUS(size_t i) {
  return getToken(SesameParser::MINUS, i);
}

tree::TerminalNode* SesameParser::Postfix_optionContext::LBRACKET() {
  return getToken(SesameParser::LBRACKET, 0);
}

SesameParser::ExprContext* SesameParser::Postfix_optionContext::expr() {
  return getRuleContext<SesameParser::ExprContext>(0);
}

tree::TerminalNode* SesameParser::Postfix_optionContext::RBRACKET() {
  return getToken(SesameParser::RBRACKET, 0);
}

tree::TerminalNode* SesameParser::Postfix_optionContext::PERIOD() {
  return getToken(SesameParser::PERIOD, 0);
}

SesameParser::NameContext* SesameParser::Postfix_optionContext::name() {
  return getRuleContext<SesameParser::NameContext>(0);
}

tree::TerminalNode* SesameParser::Postfix_optionContext::POINTER_REF() {
  return getToken(SesameParser::POINTER_REF, 0);
}

tree::TerminalNode* SesameParser::Postfix_optionContext::LPAREN() {
  return getToken(SesameParser::LPAREN, 0);
}

tree::TerminalNode* SesameParser::Postfix_optionContext::RPAREN() {
  return getToken(SesameParser::RPAREN, 0);
}

SesameParser::ArgsContext* SesameParser::Postfix_optionContext::args() {
  return getRuleContext<SesameParser::ArgsContext>(0);
}


size_t SesameParser::Postfix_optionContext::getRuleIndex() const {
  return SesameParser::RulePostfix_option;
}

void SesameParser::Postfix_optionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfix_option(this);
}

void SesameParser::Postfix_optionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SesameParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfix_option(this);
}


antlrcpp::Any SesameParser::Postfix_optionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SesameParserVisitor*>(visitor))
    return parserVisitor->visitPostfix_option(this);
  else
    return visitor->visitChildren(this);
}

SesameParser::Postfix_optionContext* SesameParser::postfix_option() {
  Postfix_optionContext *_localctx = _tracker.createInstance<Postfix_optionContext>(_ctx, getState());
  enterRule(_localctx, 146, SesameParser::RulePostfix_option);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(680);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SesameParser::PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(663);
        match(SesameParser::PLUS);
        setState(664);
        match(SesameParser::PLUS);
        break;
      }

      case SesameParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(665);
        match(SesameParser::MINUS);
        setState(666);
        match(SesameParser::MINUS);
        break;
      }

      case SesameParser::LBRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(667);
        match(SesameParser::LBRACKET);
        setState(668);
        expr();
        setState(669);
        match(SesameParser::RBRACKET);
        break;
      }

      case SesameParser::PERIOD: {
        enterOuterAlt(_localctx, 4);
        setState(671);
        match(SesameParser::PERIOD);
        setState(672);
        dynamic_cast<Postfix_optionContext *>(_localctx)->memb1 = name();
        break;
      }

      case SesameParser::POINTER_REF: {
        enterOuterAlt(_localctx, 5);
        setState(673);
        match(SesameParser::POINTER_REF);
        setState(674);
        dynamic_cast<Postfix_optionContext *>(_localctx)->memb2 = name();
        break;
      }

      case SesameParser::LPAREN: {
        enterOuterAlt(_localctx, 6);
        setState(675);
        match(SesameParser::LPAREN);
        setState(677);
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
          setState(676);
          args();
        }
        setState(679);
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
  enterRule(_localctx, 148, SesameParser::RuleArgs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(682);
    expr();
    setState(687);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SesameParser::COMMA) {
      setState(683);
      match(SesameParser::COMMA);
      setState(684);
      expr();
      setState(689);
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
  enterRule(_localctx, 150, SesameParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(700);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SesameParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(690);
        match(SesameParser::INTEGER);
        break;
      }

      case SesameParser::HEX: {
        enterOuterAlt(_localctx, 2);
        setState(691);
        match(SesameParser::HEX);
        break;
      }

      case SesameParser::OCT: {
        enterOuterAlt(_localctx, 3);
        setState(692);
        match(SesameParser::OCT);
        break;
      }

      case SesameParser::S_CHARACTER: {
        enterOuterAlt(_localctx, 4);
        setState(693);
        match(SesameParser::S_CHARACTER);
        break;
      }

      case SesameParser::S_STRING: {
        enterOuterAlt(_localctx, 5);
        setState(694);
        match(SesameParser::S_STRING);
        break;
      }

      case SesameParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 6);
        setState(695);
        match(SesameParser::IDENTIFIER);
        break;
      }

      case SesameParser::LPAREN: {
        enterOuterAlt(_localctx, 7);
        setState(696);
        match(SesameParser::LPAREN);
        setState(697);
        expr();
        setState(698);
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
  "compilation_unit", "declaration_file", "declaration_stmt", "import_stmt", 
  "import_name", "name", "func_decl", "var_decl", "top_defs", "def_func", 
  "storage", "params", "fixed_params", "param", "block", "def_vars", "assign_expr", 
  "def_const", "def_struct", "def_union", "member_list", "slot", "s_typedef", 
  "type", "typeref", "typeref_base", "typeref_precise", "param_typerefs", 
  "fixed_param_typerefs", "stmts", "stmt", "labeled_stmt", "expr_stmt", 
  "block_stmt", "if_stmt", "while_stmt", "do_while_stmt", "for_stmt", "switch_stmt", 
  "case_clauses", "case_clause", "cases", "default_clause", "case_body", 
  "break_stmt", "continue_stmt", "goto_stmt", "return_stmt", "expr", "opassign_op", 
  "expr10", "expr9", "logic_or_rhs", "expr8", "logic_and_rhs", "expr7", 
  "binary_op_rhs", "logical_op", "expr6", "bit_or_rhs", "expr5", "xor_rhs", 
  "expr4", "bit_and_rhs", "expr3", "shift_op_rhs", "expr2", "add_sub_rhs", 
  "expr1", "multi_div_mod_rhs", "term", "unary", "postfix", "postfix_option", 
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
    0x3, 0x49, 0x2c1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x3, 0x2, 0x7, 0x2, 0x9c, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x9f, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 
    0xa4, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0xa7, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0xaa, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0xad, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xb5, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0xbe, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xc1, 0xb, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xd8, 
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xdb, 0xb, 0xa, 0x3, 0xb, 0x5, 0xb, 0xde, 
    0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xe4, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xef, 0xa, 0xd, 0x5, 0xd, 0xf1, 0xa, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xf6, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0xf9, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x7, 0x10, 0x100, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x103, 0xb, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x5, 0x11, 0x109, 
    0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x10f, 
    0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x112, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x119, 0xa, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x7, 0x16, 0x130, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x133, 0xb, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x143, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 
    0x146, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x5, 0x1b, 0x154, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 
    0x158, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x160, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x5, 0x1d, 0x166, 0xa, 0x1d, 0x5, 0x1d, 0x168, 0xa, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x16d, 0xa, 0x1e, 0xc, 0x1e, 
    0xe, 0x1e, 0x170, 0xb, 0x1e, 0x3, 0x1f, 0x7, 0x1f, 0x173, 0xa, 0x1f, 
    0xc, 0x1f, 0xe, 0x1f, 0x176, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x185, 0xa, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x197, 0xa, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1aa, 0xa, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x5, 0x27, 0x1ae, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x7, 0x29, 0x1be, 
    0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x1c1, 0xb, 0x29, 0x3, 0x29, 0x5, 0x29, 
    0x1c4, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x6, 0x2b, 0x1cd, 0xa, 0x2b, 0xd, 0x2b, 0xe, 0x2b, 
    0x1ce, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x6, 0x2d, 
    0x1d6, 0xa, 0x2d, 0xd, 0x2d, 0xe, 0x2d, 0x1d7, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x1e6, 0xa, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x1f3, 
    0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x5, 0x33, 0x209, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x211, 0xa, 0x34, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x216, 0xa, 0x35, 0xc, 0x35, 
    0xe, 0x35, 0x219, 0xb, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x7, 0x37, 0x220, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x223, 
    0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x229, 
    0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x22c, 0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 
    0x3c, 0x236, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x239, 0xb, 0x3c, 0x3, 
    0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x240, 
    0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x243, 0xb, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x24a, 0xa, 0x40, 0xc, 0x40, 
    0xe, 0x40, 0x24d, 0xb, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 
    0x7, 0x42, 0x253, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x256, 0xb, 0x42, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x25d, 
    0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x260, 0xb, 0x44, 0x3, 0x45, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x267, 0xa, 0x46, 0xc, 0x46, 
    0xe, 0x46, 0x26a, 0xb, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x275, 
    0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x5, 0x49, 0x291, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 
    0x295, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x298, 0xb, 0x4a, 0x3, 0x4b, 
    0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
    0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 
    0x5, 0x4b, 0x2a8, 0xa, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x2ab, 0xa, 0x4b, 
    0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x7, 0x4c, 0x2b0, 0xa, 0x4c, 0xc, 0x4c, 
    0xe, 0x4c, 0x2b3, 0xb, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 
    0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x5, 
    0x4d, 0x2bf, 0xa, 0x4d, 0x3, 0x4d, 0x2, 0x2, 0x4e, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
    0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
    0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 
    0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 
    0x2, 0x7, 0x3, 0x2, 0x4, 0x7, 0x3, 0x2, 0x2f, 0x34, 0x3, 0x2, 0x37, 
    0x38, 0x3, 0x2, 0x21, 0x22, 0x3, 0x2, 0x23, 0x25, 0x2, 0x2df, 0x2, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x6, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xa, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xe, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0x12, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x14, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xf0, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x20, 0x108, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x115, 0x3, 0x2, 0x2, 0x2, 0x24, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x121, 0x3, 0x2, 0x2, 0x2, 0x28, 0x126, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x136, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x32, 0x140, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x153, 0x3, 0x2, 0x2, 0x2, 0x36, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x167, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x174, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x184, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x186, 0x3, 0x2, 0x2, 0x2, 0x42, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x18d, 0x3, 0x2, 0x2, 0x2, 0x46, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x48, 0x198, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1a6, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1bf, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1cc, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1d5, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x1df, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1f2, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x208, 0x3, 0x2, 0x2, 0x2, 0x66, 0x20a, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x212, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x21a, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x224, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x226, 0x3, 0x2, 0x2, 0x2, 0x72, 0x22d, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x230, 0x3, 0x2, 0x2, 0x2, 0x76, 0x232, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x23a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x244, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x246, 0x3, 0x2, 0x2, 0x2, 0x80, 0x24e, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x250, 0x3, 0x2, 0x2, 0x2, 0x84, 0x257, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x261, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x264, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x26b, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x274, 0x3, 0x2, 0x2, 0x2, 0x90, 0x290, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x292, 0x3, 0x2, 0x2, 0x2, 0x94, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x96, 0x2ac, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x5, 
    0x8, 0x5, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0xa1, 0x5, 0x12, 0xa, 0x2, 0xa1, 0x3, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0xa4, 0x5, 0x8, 0x5, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0xaa, 0x5, 0x6, 0x4, 0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0x5, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb5, 0x5, 0xe, 0x8, 0x2, 0xaf, 0xb5, 
    0x5, 0x10, 0x9, 0x2, 0xb0, 0xb5, 0x5, 0x24, 0x13, 0x2, 0xb1, 0xb5, 0x5, 
    0x26, 0x14, 0x2, 0xb2, 0xb5, 0x5, 0x28, 0x15, 0x2, 0xb3, 0xb5, 0x5, 
    0x2e, 0x18, 0x2, 0xb4, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0x7, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x1d, 0x2, 0x2, 0xb7, 
    0xb8, 0x5, 0xa, 0x6, 0x2, 0xb8, 0xb9, 0x7, 0x1f, 0x2, 0x2, 0xb9, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0xbf, 0x5, 0xc, 0x7, 0x2, 0xbb, 0xbc, 0x7, 
    0x39, 0x2, 0x2, 0xbc, 0xbe, 0x5, 0xc, 0x7, 0x2, 0xbd, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x45, 0x2, 0x2, 0xc3, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0xc, 0x2, 0x2, 0xc5, 0xc6, 
    0x5, 0x32, 0x1a, 0x2, 0xc6, 0xc7, 0x5, 0xc, 0x7, 0x2, 0xc7, 0xc8, 0x7, 
    0x27, 0x2, 0x2, 0xc8, 0xc9, 0x5, 0x18, 0xd, 0x2, 0xc9, 0xca, 0x7, 0x28, 
    0x2, 0x2, 0xca, 0xcb, 0x7, 0x1f, 0x2, 0x2, 0xcb, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xcd, 0x7, 0xc, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x30, 0x19, 0x2, 
    0xce, 0xcf, 0x5, 0xc, 0x7, 0x2, 0xcf, 0xd0, 0x7, 0x1f, 0x2, 0x2, 0xd0, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd8, 0x5, 0x14, 0xb, 0x2, 0xd2, 0xd8, 
    0x5, 0x20, 0x11, 0x2, 0xd3, 0xd8, 0x5, 0x24, 0x13, 0x2, 0xd4, 0xd8, 
    0x5, 0x26, 0x14, 0x2, 0xd5, 0xd8, 0x5, 0x28, 0x15, 0x2, 0xd6, 0xd8, 
    0x5, 0x2e, 0x18, 0x2, 0xd7, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 
    0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0x13, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xde, 0x5, 0x16, 0xc, 0x2, 0xdd, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0x32, 0x1a, 0x2, 0xe0, 0xe1, 0x5, 0xc, 
    0x7, 0x2, 0xe1, 0xe3, 0x7, 0x27, 0x2, 0x2, 0xe2, 0xe4, 0x5, 0x18, 0xd, 
    0x2, 0xe3, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x28, 0x2, 0x2, 0xe6, 
    0xe7, 0x5, 0x1e, 0x10, 0x2, 0xe7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 
    0x7, 0xb, 0x2, 0x2, 0xe9, 0x17, 0x3, 0x2, 0x2, 0x2, 0xea, 0xf1, 0x7, 
    0x3, 0x2, 0x2, 0xeb, 0xee, 0x5, 0x1a, 0xe, 0x2, 0xec, 0xed, 0x7, 0x29, 
    0x2, 0x2, 0xed, 0xef, 0x7, 0x3a, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xea, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf1, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf7, 0x5, 0x1c, 0xf, 0x2, 0xf3, 0xf4, 
    0x7, 0x29, 0x2, 0x2, 0xf4, 0xf6, 0x5, 0x1c, 0xf, 0x2, 0xf5, 0xf3, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x30, 0x19, 0x2, 
    0xfb, 0xfc, 0x5, 0xc, 0x7, 0x2, 0xfc, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xfd, 
    0x101, 0x7, 0x2b, 0x2, 0x2, 0xfe, 0x100, 0x5, 0x20, 0x11, 0x2, 0xff, 
    0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0x103, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 
    0x5, 0x3c, 0x1f, 0x2, 0x105, 0x106, 0x7, 0x2c, 0x2, 0x2, 0x106, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 0x5, 0x16, 0xc, 0x2, 0x108, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 
    0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x5, 0x30, 0x19, 0x2, 0x10b, 0x110, 
    0x5, 0x22, 0x12, 0x2, 0x10c, 0x10d, 0x7, 0x29, 0x2, 0x2, 0x10d, 0x10f, 
    0x5, 0x22, 0x12, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x111, 0x113, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 
    0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x7, 0x1f, 0x2, 0x2, 0x114, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x115, 0x118, 0x5, 0xc, 0x7, 0x2, 0x116, 0x117, 
    0x7, 0x2a, 0x2, 0x2, 0x117, 0x119, 0x5, 0x62, 0x32, 0x2, 0x118, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0xd, 0x2, 0x2, 0x11b, 0x11c, 0x5, 
    0x30, 0x19, 0x2, 0x11c, 0x11d, 0x5, 0xc, 0x7, 0x2, 0x11d, 0x11e, 0x7, 
    0x2a, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0x62, 0x32, 0x2, 0x11f, 0x120, 0x7, 
    0x1f, 0x2, 0x2, 0x120, 0x25, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 
    0x8, 0x2, 0x2, 0x122, 0x123, 0x5, 0xc, 0x7, 0x2, 0x123, 0x124, 0x5, 
    0x2a, 0x16, 0x2, 0x124, 0x125, 0x7, 0x1f, 0x2, 0x2, 0x125, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x9, 0x2, 0x2, 0x127, 0x128, 0x5, 
    0xc, 0x7, 0x2, 0x128, 0x129, 0x5, 0x2a, 0x16, 0x2, 0x129, 0x12a, 0x7, 
    0x1f, 0x2, 0x2, 0x12a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x131, 0x7, 
    0x2b, 0x2, 0x2, 0x12c, 0x12d, 0x5, 0x2c, 0x17, 0x2, 0x12d, 0x12e, 0x7, 
    0x1f, 0x2, 0x2, 0x12e, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12c, 0x3, 
    0x2, 0x2, 0x2, 0x130, 0x133, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x134, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 
    0x2c, 0x2, 0x2, 0x135, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x5, 
    0x30, 0x19, 0x2, 0x137, 0x138, 0x5, 0xc, 0x7, 0x2, 0x138, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x1c, 0x2, 0x2, 0x13a, 0x13b, 0x5, 
    0x32, 0x1a, 0x2, 0x13b, 0x13c, 0x7, 0x45, 0x2, 0x2, 0x13c, 0x13d, 0x7, 
    0x1f, 0x2, 0x2, 0x13d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x5, 
    0x32, 0x1a, 0x2, 0x13f, 0x31, 0x3, 0x2, 0x2, 0x2, 0x140, 0x144, 0x5, 
    0x34, 0x1b, 0x2, 0x141, 0x143, 0x5, 0x36, 0x1c, 0x2, 0x142, 0x141, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x146, 0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 
    0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 0x154, 0x7, 0x3, 
    0x2, 0x2, 0x148, 0x154, 0x7, 0x4, 0x2, 0x2, 0x149, 0x154, 0x7, 0x5, 
    0x2, 0x2, 0x14a, 0x154, 0x7, 0x6, 0x2, 0x2, 0x14b, 0x154, 0x7, 0x7, 
    0x2, 0x2, 0x14c, 0x14d, 0x7, 0xf, 0x2, 0x2, 0x14d, 0x154, 0x9, 0x2, 
    0x2, 0x2, 0x14e, 0x14f, 0x7, 0x8, 0x2, 0x2, 0x14f, 0x154, 0x7, 0x45, 
    0x2, 0x2, 0x150, 0x151, 0x7, 0x9, 0x2, 0x2, 0x151, 0x154, 0x7, 0x45, 
    0x2, 0x2, 0x152, 0x154, 0x7, 0x45, 0x2, 0x2, 0x153, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x148, 0x3, 0x2, 0x2, 0x2, 0x153, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x153, 0x14b, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x153, 0x14e, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x150, 0x3, 0x2, 0x2, 0x2, 0x153, 0x152, 0x3, 0x2, 
    0x2, 0x2, 0x154, 0x35, 0x3, 0x2, 0x2, 0x2, 0x155, 0x157, 0x7, 0x2d, 
    0x2, 0x2, 0x156, 0x158, 0x7, 0x46, 0x2, 0x2, 0x157, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x158, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x160, 0x7, 0x2e, 0x2, 0x2, 0x15a, 0x160, 0x7, 0x23, 
    0x2, 0x2, 0x15b, 0x15c, 0x7, 0x27, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0x38, 
    0x1d, 0x2, 0x15d, 0x15e, 0x7, 0x28, 0x2, 0x2, 0x15e, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x155, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x160, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x168, 0x7, 0x3, 0x2, 0x2, 0x162, 0x165, 0x5, 0x3a, 0x1e, 
    0x2, 0x163, 0x164, 0x7, 0x29, 0x2, 0x2, 0x164, 0x166, 0x7, 0x3a, 0x2, 
    0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 
    0x2, 0x166, 0x168, 0x3, 0x2, 0x2, 0x2, 0x167, 0x161, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x162, 0x3, 0x2, 0x2, 0x2, 0x168, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x169, 0x16e, 0x5, 0x32, 0x1a, 0x2, 0x16a, 0x16b, 0x7, 0x29, 0x2, 0x2, 
    0x16b, 0x16d, 0x5, 0x32, 0x1a, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 0x2, 
    0x16d, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 0x2, 
    0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x170, 
    0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x173, 0x5, 0x3e, 0x20, 0x2, 0x172, 
    0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x176, 0x3, 0x2, 0x2, 0x2, 0x174, 
    0x172, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 0x185, 
    0x7, 0x1f, 0x2, 0x2, 0x178, 0x185, 0x5, 0x40, 0x21, 0x2, 0x179, 0x185, 
    0x5, 0x42, 0x22, 0x2, 0x17a, 0x185, 0x5, 0x44, 0x23, 0x2, 0x17b, 0x185, 
    0x5, 0x46, 0x24, 0x2, 0x17c, 0x185, 0x5, 0x48, 0x25, 0x2, 0x17d, 0x185, 
    0x5, 0x4a, 0x26, 0x2, 0x17e, 0x185, 0x5, 0x4c, 0x27, 0x2, 0x17f, 0x185, 
    0x5, 0x4e, 0x28, 0x2, 0x180, 0x185, 0x5, 0x5a, 0x2e, 0x2, 0x181, 0x185, 
    0x5, 0x5c, 0x2f, 0x2, 0x182, 0x185, 0x5, 0x5e, 0x30, 0x2, 0x183, 0x185, 
    0x5, 0x60, 0x31, 0x2, 0x184, 0x177, 0x3, 0x2, 0x2, 0x2, 0x184, 0x178, 
    0x3, 0x2, 0x2, 0x2, 0x184, 0x179, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17a, 
    0x3, 0x2, 0x2, 0x2, 0x184, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17c, 
    0x3, 0x2, 0x2, 0x2, 0x184, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17e, 
    0x3, 0x2, 0x2, 0x2, 0x184, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x184, 0x180, 
    0x3, 0x2, 0x2, 0x2, 0x184, 0x181, 0x3, 0x2, 0x2, 0x2, 0x184, 0x182, 
    0x3, 0x2, 0x2, 0x2, 0x184, 0x183, 0x3, 0x2, 0x2, 0x2, 0x185, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x186, 0x187, 0x7, 0x45, 0x2, 0x2, 0x187, 0x188, 0x7, 
    0x20, 0x2, 0x2, 0x188, 0x189, 0x5, 0x3e, 0x20, 0x2, 0x189, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x18a, 0x18b, 0x5, 0x62, 0x32, 0x2, 0x18b, 0x18c, 0x7, 
    0x1f, 0x2, 0x2, 0x18c, 0x43, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x5, 
    0x1e, 0x10, 0x2, 0x18e, 0x45, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 
    0x10, 0x2, 0x2, 0x190, 0x191, 0x7, 0x27, 0x2, 0x2, 0x191, 0x192, 0x5, 
    0x62, 0x32, 0x2, 0x192, 0x193, 0x7, 0x28, 0x2, 0x2, 0x193, 0x196, 0x5, 
    0x3e, 0x20, 0x2, 0x194, 0x195, 0x7, 0x11, 0x2, 0x2, 0x195, 0x197, 0x5, 
    0x3e, 0x20, 0x2, 0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 
    0x2, 0x2, 0x2, 0x197, 0x47, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x7, 0x15, 
    0x2, 0x2, 0x199, 0x19a, 0x7, 0x27, 0x2, 0x2, 0x19a, 0x19b, 0x5, 0x62, 
    0x32, 0x2, 0x19b, 0x19c, 0x7, 0x28, 0x2, 0x2, 0x19c, 0x19d, 0x5, 0x3e, 
    0x20, 0x2, 0x19d, 0x49, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0x16, 
    0x2, 0x2, 0x19f, 0x1a0, 0x5, 0x3e, 0x20, 0x2, 0x1a0, 0x1a1, 0x7, 0x15, 
    0x2, 0x2, 0x1a1, 0x1a2, 0x7, 0x27, 0x2, 0x2, 0x1a2, 0x1a3, 0x5, 0x62, 
    0x32, 0x2, 0x1a3, 0x1a4, 0x7, 0x28, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x1f, 
    0x2, 0x2, 0x1a5, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0x17, 
    0x2, 0x2, 0x1a7, 0x1a9, 0x7, 0x27, 0x2, 0x2, 0x1a8, 0x1aa, 0x5, 0x62, 
    0x32, 0x2, 0x1a9, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x3, 0x2, 
    0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ad, 0x7, 0x1f, 
    0x2, 0x2, 0x1ac, 0x1ae, 0x5, 0x62, 0x32, 0x2, 0x1ad, 0x1ac, 0x3, 0x2, 
    0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 0x2, 
    0x2, 0x2, 0x1af, 0x1b0, 0x7, 0x1f, 0x2, 0x2, 0x1b0, 0x1b1, 0x5, 0x62, 
    0x32, 0x2, 0x1b1, 0x1b2, 0x7, 0x28, 0x2, 0x2, 0x1b2, 0x1b3, 0x5, 0x3e, 
    0x20, 0x2, 0x1b3, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x7, 0x12, 
    0x2, 0x2, 0x1b5, 0x1b6, 0x7, 0x27, 0x2, 0x2, 0x1b6, 0x1b7, 0x5, 0x62, 
    0x32, 0x2, 0x1b7, 0x1b8, 0x7, 0x28, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x2b, 
    0x2, 0x2, 0x1b9, 0x1ba, 0x5, 0x50, 0x29, 0x2, 0x1ba, 0x1bb, 0x7, 0x2c, 
    0x2, 0x2, 0x1bb, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1be, 0x5, 0x52, 
    0x2a, 0x2, 0x1bd, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1c1, 0x3, 0x2, 
    0x2, 0x2, 0x1bf, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x3, 0x2, 
    0x2, 0x2, 0x1c0, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 
    0x2, 0x2, 0x1c2, 0x1c4, 0x5, 0x56, 0x2c, 0x2, 0x1c3, 0x1c2, 0x3, 0x2, 
    0x2, 0x2, 0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x1c5, 0x1c6, 0x5, 0x54, 0x2b, 0x2, 0x1c6, 0x1c7, 0x5, 0x58, 0x2d, 
    0x2, 0x1c7, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x7, 0x13, 0x2, 
    0x2, 0x1c9, 0x1ca, 0x5, 0x98, 0x4d, 0x2, 0x1ca, 0x1cb, 0x7, 0x20, 0x2, 
    0x2, 0x1cb, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1c8, 0x3, 0x2, 0x2, 
    0x2, 0x1cd, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cc, 0x3, 0x2, 0x2, 
    0x2, 0x1ce, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x1d0, 0x1d1, 0x7, 0x14, 0x2, 0x2, 0x1d1, 0x1d2, 0x7, 0x20, 0x2, 0x2, 
    0x1d2, 0x1d3, 0x5, 0x58, 0x2d, 0x2, 0x1d3, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x1d4, 0x1d6, 0x5, 0x3e, 0x20, 0x2, 0x1d5, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
    0x1d6, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 
    0x1d7, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
    0x1da, 0x7, 0x19, 0x2, 0x2, 0x1da, 0x1db, 0x7, 0x1f, 0x2, 0x2, 0x1db, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x7, 0x1a, 0x2, 0x2, 0x1dd, 
    0x1de, 0x7, 0x1f, 0x2, 0x2, 0x1de, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1df, 
    0x1e0, 0x7, 0x1b, 0x2, 0x2, 0x1e0, 0x1e1, 0x7, 0x45, 0x2, 0x2, 0x1e1, 
    0x1e2, 0x7, 0x1f, 0x2, 0x2, 0x1e2, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1e3, 
    0x1e5, 0x7, 0x18, 0x2, 0x2, 0x1e4, 0x1e6, 0x5, 0x62, 0x32, 0x2, 0x1e5, 
    0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
    0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x7, 0x1f, 0x2, 0x2, 0x1e8, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ea, 0x5, 0x8e, 0x48, 0x2, 0x1ea, 
    0x1eb, 0x7, 0x2a, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x62, 0x32, 0x2, 0x1ec, 
    0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x5, 0x8e, 0x48, 0x2, 0x1ee, 
    0x1ef, 0x5, 0x64, 0x33, 0x2, 0x1ef, 0x1f0, 0x5, 0x62, 0x32, 0x2, 0x1f0, 
    0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f3, 0x5, 0x66, 0x34, 0x2, 0x1f2, 
    0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
    0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 
    0x7, 0x21, 0x2, 0x2, 0x1f5, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x1f6, 0x1f7, 
    0x7, 0x22, 0x2, 0x2, 0x1f7, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x1f8, 0x1f9, 
    0x7, 0x23, 0x2, 0x2, 0x1f9, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x1fa, 0x1fb, 
    0x7, 0x24, 0x2, 0x2, 0x1fb, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x1fc, 0x1fd, 
    0x7, 0x25, 0x2, 0x2, 0x1fd, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x1fe, 0x1ff, 
    0x7, 0x26, 0x2, 0x2, 0x1ff, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x200, 0x201, 
    0x7, 0x3b, 0x2, 0x2, 0x201, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x202, 0x203, 
    0x7, 0x3e, 0x2, 0x2, 0x203, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x204, 0x205, 
    0x7, 0x37, 0x2, 0x2, 0x205, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x206, 0x207, 
    0x7, 0x38, 0x2, 0x2, 0x207, 0x209, 0x7, 0x2a, 0x2, 0x2, 0x208, 0x1f4, 
    0x3, 0x2, 0x2, 0x2, 0x208, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1f8, 
    0x3, 0x2, 0x2, 0x2, 0x208, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1fc, 
    0x3, 0x2, 0x2, 0x2, 0x208, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x208, 0x200, 
    0x3, 0x2, 0x2, 0x2, 0x208, 0x202, 0x3, 0x2, 0x2, 0x2, 0x208, 0x204, 
    0x3, 0x2, 0x2, 0x2, 0x208, 0x206, 0x3, 0x2, 0x2, 0x2, 0x209, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x20a, 0x210, 0x5, 0x68, 0x35, 0x2, 0x20b, 0x20c, 0x7, 
    0x3c, 0x2, 0x2, 0x20c, 0x20d, 0x5, 0x62, 0x32, 0x2, 0x20d, 0x20e, 0x7, 
    0x20, 0x2, 0x2, 0x20e, 0x20f, 0x5, 0x66, 0x34, 0x2, 0x20f, 0x211, 0x3, 
    0x2, 0x2, 0x2, 0x210, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x3, 
    0x2, 0x2, 0x2, 0x211, 0x67, 0x3, 0x2, 0x2, 0x2, 0x212, 0x217, 0x5, 0x6c, 
    0x37, 0x2, 0x213, 0x214, 0x7, 0x36, 0x2, 0x2, 0x214, 0x216, 0x5, 0x6a, 
    0x36, 0x2, 0x215, 0x213, 0x3, 0x2, 0x2, 0x2, 0x216, 0x219, 0x3, 0x2, 
    0x2, 0x2, 0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 
    0x2, 0x2, 0x218, 0x69, 0x3, 0x2, 0x2, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 
    0x2, 0x21a, 0x21b, 0x5, 0x6c, 0x37, 0x2, 0x21b, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x21c, 0x221, 0x5, 0x70, 0x39, 0x2, 0x21d, 0x21e, 0x7, 0x35, 0x2, 
    0x2, 0x21e, 0x220, 0x5, 0x6e, 0x38, 0x2, 0x21f, 0x21d, 0x3, 0x2, 0x2, 
    0x2, 0x220, 0x223, 0x3, 0x2, 0x2, 0x2, 0x221, 0x21f, 0x3, 0x2, 0x2, 
    0x2, 0x221, 0x222, 0x3, 0x2, 0x2, 0x2, 0x222, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x221, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x5, 0x70, 0x39, 0x2, 
    0x225, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x226, 0x22a, 0x5, 0x76, 0x3c, 0x2, 
    0x227, 0x229, 0x5, 0x72, 0x3a, 0x2, 0x228, 0x227, 0x3, 0x2, 0x2, 0x2, 
    0x229, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x228, 0x3, 0x2, 0x2, 0x2, 
    0x22a, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x71, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0x22a, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x5, 0x74, 0x3b, 0x2, 0x22e, 
    0x22f, 0x5, 0x76, 0x3c, 0x2, 0x22f, 0x73, 0x3, 0x2, 0x2, 0x2, 0x230, 
    0x231, 0x9, 0x3, 0x2, 0x2, 0x231, 0x75, 0x3, 0x2, 0x2, 0x2, 0x232, 0x237, 
    0x5, 0x7a, 0x3e, 0x2, 0x233, 0x234, 0x7, 0x3b, 0x2, 0x2, 0x234, 0x236, 
    0x5, 0x78, 0x3d, 0x2, 0x235, 0x233, 0x3, 0x2, 0x2, 0x2, 0x236, 0x239, 
    0x3, 0x2, 0x2, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 
    0x3, 0x2, 0x2, 0x2, 0x238, 0x77, 0x3, 0x2, 0x2, 0x2, 0x239, 0x237, 0x3, 
    0x2, 0x2, 0x2, 0x23a, 0x23b, 0x5, 0x7a, 0x3e, 0x2, 0x23b, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x23c, 0x241, 0x5, 0x7e, 0x40, 0x2, 0x23d, 0x23e, 0x7, 
    0x3e, 0x2, 0x2, 0x23e, 0x240, 0x5, 0x7c, 0x3f, 0x2, 0x23f, 0x23d, 0x3, 
    0x2, 0x2, 0x2, 0x240, 0x243, 0x3, 0x2, 0x2, 0x2, 0x241, 0x23f, 0x3, 
    0x2, 0x2, 0x2, 0x241, 0x242, 0x3, 0x2, 0x2, 0x2, 0x242, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x243, 0x241, 0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x5, 0x7e, 
    0x40, 0x2, 0x245, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x246, 0x24b, 0x5, 0x82, 
    0x42, 0x2, 0x247, 0x248, 0x7, 0x26, 0x2, 0x2, 0x248, 0x24a, 0x5, 0x80, 
    0x41, 0x2, 0x249, 0x247, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24d, 0x3, 0x2, 
    0x2, 0x2, 0x24b, 0x249, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x3, 0x2, 
    0x2, 0x2, 0x24c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24b, 0x3, 0x2, 0x2, 
    0x2, 0x24e, 0x24f, 0x5, 0x82, 0x42, 0x2, 0x24f, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x250, 0x254, 0x5, 0x86, 0x44, 0x2, 0x251, 0x253, 0x5, 0x84, 0x43, 
    0x2, 0x252, 0x251, 0x3, 0x2, 0x2, 0x2, 0x253, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x254, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x83, 0x3, 0x2, 0x2, 0x2, 0x256, 0x254, 0x3, 0x2, 0x2, 0x2, 
    0x257, 0x258, 0x9, 0x4, 0x2, 0x2, 0x258, 0x259, 0x5, 0x86, 0x44, 0x2, 
    0x259, 0x85, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25e, 0x5, 0x8a, 0x46, 0x2, 
    0x25b, 0x25d, 0x5, 0x88, 0x45, 0x2, 0x25c, 0x25b, 0x3, 0x2, 0x2, 0x2, 
    0x25d, 0x260, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25c, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x87, 0x3, 0x2, 0x2, 0x2, 0x260, 
    0x25e, 0x3, 0x2, 0x2, 0x2, 0x261, 0x262, 0x9, 0x5, 0x2, 0x2, 0x262, 
    0x263, 0x5, 0x8a, 0x46, 0x2, 0x263, 0x89, 0x3, 0x2, 0x2, 0x2, 0x264, 
    0x268, 0x5, 0x8e, 0x48, 0x2, 0x265, 0x267, 0x5, 0x8c, 0x47, 0x2, 0x266, 
    0x265, 0x3, 0x2, 0x2, 0x2, 0x267, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x268, 
    0x266, 0x3, 0x2, 0x2, 0x2, 0x268, 0x269, 0x3, 0x2, 0x2, 0x2, 0x269, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x268, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 
    0x9, 0x6, 0x2, 0x2, 0x26c, 0x26d, 0x5, 0x8e, 0x48, 0x2, 0x26d, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x26e, 0x26f, 0x7, 0x27, 0x2, 0x2, 0x26f, 0x270, 
    0x5, 0x30, 0x19, 0x2, 0x270, 0x271, 0x7, 0x28, 0x2, 0x2, 0x271, 0x272, 
    0x5, 0x8e, 0x48, 0x2, 0x272, 0x275, 0x3, 0x2, 0x2, 0x2, 0x273, 0x275, 
    0x5, 0x90, 0x49, 0x2, 0x274, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x274, 0x273, 
    0x3, 0x2, 0x2, 0x2, 0x275, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x7, 
    0x21, 0x2, 0x2, 0x277, 0x278, 0x7, 0x21, 0x2, 0x2, 0x278, 0x291, 0x5, 
    0x90, 0x49, 0x2, 0x279, 0x27a, 0x7, 0x22, 0x2, 0x2, 0x27a, 0x27b, 0x7, 
    0x22, 0x2, 0x2, 0x27b, 0x291, 0x5, 0x90, 0x49, 0x2, 0x27c, 0x27d, 0x7, 
    0x21, 0x2, 0x2, 0x27d, 0x291, 0x5, 0x8e, 0x48, 0x2, 0x27e, 0x27f, 0x7, 
    0x22, 0x2, 0x2, 0x27f, 0x291, 0x5, 0x8e, 0x48, 0x2, 0x280, 0x281, 0x7, 
    0x3d, 0x2, 0x2, 0x281, 0x291, 0x5, 0x8e, 0x48, 0x2, 0x282, 0x283, 0x7, 
    0x3f, 0x2, 0x2, 0x283, 0x291, 0x5, 0x8e, 0x48, 0x2, 0x284, 0x285, 0x7, 
    0x23, 0x2, 0x2, 0x285, 0x291, 0x5, 0x8e, 0x48, 0x2, 0x286, 0x287, 0x7, 
    0x26, 0x2, 0x2, 0x287, 0x291, 0x5, 0x8e, 0x48, 0x2, 0x288, 0x289, 0x7, 
    0x1e, 0x2, 0x2, 0x289, 0x28a, 0x7, 0x27, 0x2, 0x2, 0x28a, 0x28b, 0x5, 
    0x30, 0x19, 0x2, 0x28b, 0x28c, 0x7, 0x28, 0x2, 0x2, 0x28c, 0x291, 0x3, 
    0x2, 0x2, 0x2, 0x28d, 0x28e, 0x7, 0x1e, 0x2, 0x2, 0x28e, 0x291, 0x5, 
    0x90, 0x49, 0x2, 0x28f, 0x291, 0x5, 0x92, 0x4a, 0x2, 0x290, 0x276, 0x3, 
    0x2, 0x2, 0x2, 0x290, 0x279, 0x3, 0x2, 0x2, 0x2, 0x290, 0x27c, 0x3, 
    0x2, 0x2, 0x2, 0x290, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x290, 0x280, 0x3, 
    0x2, 0x2, 0x2, 0x290, 0x282, 0x3, 0x2, 0x2, 0x2, 0x290, 0x284, 0x3, 
    0x2, 0x2, 0x2, 0x290, 0x286, 0x3, 0x2, 0x2, 0x2, 0x290, 0x288, 0x3, 
    0x2, 0x2, 0x2, 0x290, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x290, 0x28f, 0x3, 
    0x2, 0x2, 0x2, 0x291, 0x91, 0x3, 0x2, 0x2, 0x2, 0x292, 0x296, 0x5, 0x98, 
    0x4d, 0x2, 0x293, 0x295, 0x5, 0x94, 0x4b, 0x2, 0x294, 0x293, 0x3, 0x2, 
    0x2, 0x2, 0x295, 0x298, 0x3, 0x2, 0x2, 0x2, 0x296, 0x294, 0x3, 0x2, 
    0x2, 0x2, 0x296, 0x297, 0x3, 0x2, 0x2, 0x2, 0x297, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x298, 0x296, 0x3, 0x2, 0x2, 0x2, 0x299, 0x29a, 0x7, 0x21, 0x2, 
    0x2, 0x29a, 0x2ab, 0x7, 0x21, 0x2, 0x2, 0x29b, 0x29c, 0x7, 0x22, 0x2, 
    0x2, 0x29c, 0x2ab, 0x7, 0x22, 0x2, 0x2, 0x29d, 0x29e, 0x7, 0x2d, 0x2, 
    0x2, 0x29e, 0x29f, 0x5, 0x62, 0x32, 0x2, 0x29f, 0x2a0, 0x7, 0x2e, 0x2, 
    0x2, 0x2a0, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x7, 0x39, 0x2, 
    0x2, 0x2a2, 0x2ab, 0x5, 0xc, 0x7, 0x2, 0x2a3, 0x2a4, 0x7, 0x40, 0x2, 
    0x2, 0x2a4, 0x2ab, 0x5, 0xc, 0x7, 0x2, 0x2a5, 0x2a7, 0x7, 0x27, 0x2, 
    0x2, 0x2a6, 0x2a8, 0x5, 0x96, 0x4c, 0x2, 0x2a7, 0x2a6, 0x3, 0x2, 0x2, 
    0x2, 0x2a7, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a9, 0x3, 0x2, 0x2, 
    0x2, 0x2a9, 0x2ab, 0x7, 0x28, 0x2, 0x2, 0x2aa, 0x299, 0x3, 0x2, 0x2, 
    0x2, 0x2aa, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x29d, 0x3, 0x2, 0x2, 
    0x2, 0x2aa, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a3, 0x3, 0x2, 0x2, 
    0x2, 0x2aa, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x2ac, 0x2b1, 0x5, 0x62, 0x32, 0x2, 0x2ad, 0x2ae, 0x7, 0x29, 0x2, 0x2, 
    0x2ae, 0x2b0, 0x5, 0x62, 0x32, 0x2, 0x2af, 0x2ad, 0x3, 0x2, 0x2, 0x2, 
    0x2b0, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 
    0x2b1, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x97, 0x3, 0x2, 0x2, 0x2, 0x2b3, 
    0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2bf, 0x7, 0x46, 0x2, 0x2, 0x2b5, 
    0x2bf, 0x7, 0x47, 0x2, 0x2, 0x2b6, 0x2bf, 0x7, 0x48, 0x2, 0x2, 0x2b7, 
    0x2bf, 0x7, 0x43, 0x2, 0x2, 0x2b8, 0x2bf, 0x7, 0x44, 0x2, 0x2, 0x2b9, 
    0x2bf, 0x7, 0x45, 0x2, 0x2, 0x2ba, 0x2bb, 0x7, 0x27, 0x2, 0x2, 0x2bb, 
    0x2bc, 0x5, 0x62, 0x32, 0x2, 0x2bc, 0x2bd, 0x7, 0x28, 0x2, 0x2, 0x2bd, 
    0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2be, 
    0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2be, 
    0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2be, 
    0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2bf, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x37, 0x9d, 0xa5, 0xab, 0xb4, 0xbf, 0xd7, 
    0xd9, 0xdd, 0xe3, 0xee, 0xf0, 0xf7, 0x101, 0x108, 0x110, 0x118, 0x131, 
    0x144, 0x153, 0x157, 0x15f, 0x165, 0x167, 0x16e, 0x174, 0x184, 0x196, 
    0x1a9, 0x1ad, 0x1bf, 0x1c3, 0x1ce, 0x1d7, 0x1e5, 0x1f2, 0x208, 0x210, 
    0x217, 0x221, 0x22a, 0x237, 0x241, 0x24b, 0x254, 0x25e, 0x268, 0x274, 
    0x290, 0x296, 0x2a7, 0x2aa, 0x2b1, 0x2be, 
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


// Generated from SesameLexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace parser {


class  SesameLexer : public antlr4::Lexer {
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

  SesameLexer(antlr4::CharStream *input);
  ~SesameLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace parser

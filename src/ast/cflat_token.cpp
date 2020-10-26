#include "cflat_token.hpp"

namespace ast {
CflatToken::CflatToken() : index_(0), line_no_(0), start_(0), end_(0) {}
CflatToken::CflatToken(std::string str, std::size_t i, std::size_t l, std::size_t s, std::size_t e)
  : text_(str), index_(i), line_no_(l), start_(s), end_(e) {}

CflatToken::~CflatToken() {}

// antlr4::Token::getText()
std::string CflatToken::text() {
  return text_;
}

void CflatToken::SetText(std::string str) {
  text_ = str;
}

// antlr4::Token::getTokenIndex()
std::size_t CflatToken::index() {
  return index_;
}

void CflatToken::SetIndex(std::size_t i) {
  index_ = i;
}

// antlr4::Token::getLine()
std::size_t CflatToken::line_no() {
  return line_no_;
}

void CflatToken::SetLineNo(std::size_t l) {
  line_no_ = l;
}

// antlr4::Token::getStartIndex()
std::size_t CflatToken::start() {
  return start_;
}

void CflatToken::SetStart(std::size_t s) {
  start_ = s;
}

// antlr4::Token::getStopIndex()
std::size_t CflatToken::end() {
  return end_;
}

void CflatToken::SetEnd(std::size_t e) {
  end_ = e;
}

std::string CflatToken::ToString() {
  // [@103,325:325=' ',<71>,channel=1,23:10]
  return "[@" + std::to_string(index_) + "," + std::to_string(start_) + ":" + 
    std::to_string(end_) + "='" + text_ + "'" + "," + std::to_string(line_no_) + "]";
}
} /* end ast */

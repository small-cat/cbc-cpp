#include "location.hpp"

namespace ast {
Location::Location(std::string name, CflatToken* t) : source_name_(name),
                                                      token_(t) {}

Location::Location(std::string name, std::string text, std::size_t i, std::size_t l, std::size_t s, std::size_t e) 
  : source_name_(name) {
    token_ = new CflatToken(text, i, l, s, e);
  }

Location::~Location() {
  if (token_ != nullptr) {
    delete token_;
  }

  token_ = nullptr;
}

std::string Location::source_name() {
  return source_name_;
}

CflatToken* Location::token() {
  return token_;
}

int Location::LineNo() {
  return token_->line_no();
}

int Location::Column() {
  return token_->start();
}

std::string Location::Line() {
  return std::to_string(LineNo());
}

std::string Location::ToString() {
  return source_name_ + ":" + Line();
}

} /* end ast */

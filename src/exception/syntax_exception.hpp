#ifndef __SYNTAX_EXCEPTION_H__
#define __SYNTAX_EXCEPTION_H__

#include "compile_exception.hpp"

class SyntaxException : public CompileException {
public:
  SyntaxException(const std::string& msg) : CompileException(msg) {}
  virtual ~SyntaxException() {}

  const std::string what() {
    return "SyntaxException:" + message();
  }
};

#endif /* __SYNTAX_EXCEPTION_H__ */

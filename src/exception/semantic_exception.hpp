#ifndef __SEMANTICEXCEPTION_H__
#define __SEMANTICEXCEPTION_H__

#include "compile_exception.hpp"

class SemanticException : public CompileException {
public:
  SemanticException(const std::string& msg) : CompileException(msg) {}
  virtual ~SemanticException() {}

  const std::string what() {
    return "SemanticException:" + message();
  }
};

#endif /* __SEMANTICEXCEPTION_H__ */

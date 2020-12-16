#ifndef __COMPILEEXCEPTION_H__
#define __COMPILEEXCEPTION_H__

#include <exception>
#include <iostream>

class CompileException : public std::exception {
public:
  CompileException(const std::string& msg) : message_(msg) {}
  virtual ~CompileException() {}

  std::string message() {
    return message_;
  }

  virtual const std::string what() {
    return message_;
  }
private:
  std::string message_;
};

#endif /* __COMPILEEXCEPTION_H__ */

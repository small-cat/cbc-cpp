#ifndef __FILE_EXCEPTION_H__
#define __FILE_EXCEPTION_H__

#include "compile_exception.hpp"

class FileException : public CompileException {
public:
  FileException(const std::string& msg) : CompileException(msg) {}
  virtual ~FileException() {}

  const std::string what() {
    return "FileException:" + message();
  }
};

#endif /* __FILE_EXCEPTION_H__ */

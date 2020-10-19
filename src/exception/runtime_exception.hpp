/**
 * @copyright (c) Copyright 2020 Secsmart. All Rights Reserved.
 * @license
 * @file  : parser_exceptions.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-08-04
 * @brief : parser exceptions definitions
*/
#ifndef __PARSER_EXCEPTIONS_H__
#define __PARSER_EXCEPTIONS_H__

#include <exception>

class RuntimeException : public std::exception {
public:
  RuntimeException(const std::string msg) : message_(msg) {}
  virtual ~RuntimeException() {}

  virtual const std::string what() {
    return message_;
  };
private:
  std::string message_;
};

// definitions for other exceptions

#endif /* __PARSER_EXCEPTIONS_H__ */

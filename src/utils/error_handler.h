/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : error_handler.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-20
 * @brief : error handler definitions
*/
#ifndef __ERROR_HANDLER_H__
#define __ERROR_HANDLER_H__

#include <string>
#include <iostream>

#include "../ast/location.hpp"

namespace utils {
class ErrorHandler  {
public:
  ErrorHandler(std::string prog_id);
  ErrorHandler(std::string prog_id, std::ostream* out);
  virtual ~ErrorHandler();

  void Error(const std::string& msg);
  void Warn(const std::string& msg);

  // with locations
  void Error(ast::Location* loc, const std::string& msg);
  void Warn(ast::Location* loc, const std::string& msg);
  bool ErrorOccured();
private:
  std::string program_id_;
  std::ostream* out_;
  long error_;
  long warning_;
};
} /* end utils */

#endif /* __ERROR_HANDLER_H__ */

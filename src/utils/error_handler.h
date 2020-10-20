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

namespace utils {
class ErrorHandler  {
public:
  ErrorHandler(std::string prog_id);
  virtual ~ErrorHandler();

  void error(const std::string& msg);
  void warn(const std::string& msg);

  // with locations
  // void error(Location* loc, const std::string& msg);
  // void warn(Location* loc, const std::string& msg);
private:
  std::string program_id_;
  long error_;
  long warning_;
};
} /* end utils */

#endif /* __ERROR_HANDLER_H__ */

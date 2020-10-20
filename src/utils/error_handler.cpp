#include "error_handler.h"

#include <iostream>

namespace utils {
ErrorHandler::ErrorHandler(std::string prog_id) : program_id_(prog_id) {}
ErrorHandler::~ErrorHandler() {}

void ErrorHandler::error(const std::string& msg) {
  std::cout << program_id_ << ": error: " << msg << std::endl;
  error_ ++;
}

void ErrorHandler::warn(const std::string& msg) {
  std::cout << program_id_ << ": warn: " << msg << std::endl;
  warning_ ++;
}

} /* end utils */

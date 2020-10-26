#include "error_handler.h"

namespace utils {
ErrorHandler::ErrorHandler(std::string prog_id) : program_id_(prog_id) {}
ErrorHandler::ErrorHandler(std::string prog_id, std::ostream* out) 
  : program_id_(prog_id), out_(out) {}

ErrorHandler::~ErrorHandler() {}

void ErrorHandler::Error(const std::string& msg) {
  *out_ << program_id_ << ": error: " << msg << std::endl;
  error_ ++;
}

void ErrorHandler::Warn(const std::string& msg) {
  *out_ << program_id_ << ": warn: " << msg << std::endl;
  warning_ ++;
}

void ErrorHandler::Error(ast::Location* loc, const std::string& msg) {
  Error(loc->ToString() + ": " + msg);
}

void ErrorHandler::Warn(ast::Location* loc, const std::string& msg) {
  Warn(loc->ToString() + ": " + msg);
}

bool ErrorHandler::ErrorOccured() {
  return error_ > 0;
}

} /* end utils */

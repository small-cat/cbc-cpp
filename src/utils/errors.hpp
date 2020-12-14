/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : errors.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-12-14
 * @brief : errors definitions
*/

#ifndef __ERRORS_H__
#define __ERRORS_H__

#include <system_error>

namespace utils {
enum class CompileError {
  SUCCESS = 0,

  SYNTAX_ERROR,
};

class CompileErrorCategory : public std::error_category {
  public:
    virtual const char* name() const noexcept override {
      return "compile error";
    }

    virtual std::string message(int err) const override {
      auto err_val = static_cast<CompileError>(err);
      switch (err_val) {
        CompileError::SYNTAX_ERROR:
          return "Syntax Error";
        default:
          return "Unknown Error";
      }
    }
};

static const std::error_category& CompileCategory() {
  static const CompileErrorCategory compile_err_cg;
  return compile_err_cg;
}

inline std::error_code make_error_code(CompileError err) noexcept {
  return std::error_code(static_cast<int>(err), CompileCategory());
}

} /* end utils */

namespace std {
template <> 
  struct is_error_code_enum<utils::CompileError> : true_type {};
}

#endif /* __ERRORS_H__ */
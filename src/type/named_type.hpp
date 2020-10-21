#ifndef __NAMED_TYPE_H__
#define __NAMED_TYPE_H__

#include "type.hpp"
#include "../ast/location.hpp"

namespace type {
class NamedType : public Type {
public:
  NamedType(std::string n, ast::Location* l) : name_(n), location_(l) {}
  virtual ~NamedType() {}

  std::string name() {
    return name_;
  }

  ast::Location* location() {
    return location_;
  }

  std::string ToString() {
    return name_;
  }
private:
  std::string name_;
  ast::Location* location_;
};
} /* end type */

#endif /* __NAMED_TYPE_H__ */

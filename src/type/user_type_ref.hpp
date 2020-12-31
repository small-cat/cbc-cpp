#ifndef __USER_TYPE_REF_H__
#define __USER_TYPE_REF_H__

#include "../ast/location.hpp"
#include "type_ref.hpp"

namespace type {
class UserTypeRef : public TypeRef {
public:
  UserTypeRef(std::string n);
  UserTypeRef(ast::Location* l, std::string n);
  virtual ~UserTypeRef();

  bool IsUserType();
  std::string name() const;
  std::string ToString();
private:
  std::string name_;
};
} /* end type */

#endif /* __USER_TYPE_REF_H__ */

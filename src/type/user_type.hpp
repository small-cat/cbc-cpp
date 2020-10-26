#ifndef __USER_TYPE_H__
#define __USER_TYPE_H__

#include "named_type.hpp"
#include "../ast/type/type_node.hpp"
#include "../ast/location.hpp"

namespace type {
class UserType : public NamedType {
public:
  UserType(std::string n, ast::TypeNode* r, ast::Location* l) : NamedType(n, l), real_(r) {}
  virtual ~UserType() {}

  ast::TypeNode* real() { return real_; }
  Type* RealType() { return real_->type(); }
  std::string ToString() { return name(); }

  // methods for real type 
  long Size() { return RealType()->Size(); }
  long AllocSize() { return RealType()->AllocSize(); }
  long Alignment() { return RealType()->Alignment(); }

  bool IsSameType(Type* other) { return RealType()->IsSameType(other); }
  bool IsCompatible(Type* other) { return RealType()->IsCompatible(other); }
  bool IsCastableTo(Type* target) { return RealType()->IsCastableTo(target); }

  Type* base_type() { return RealType()->base_type(); }
private:
  ast::TypeNode* real_;
};
} /* end type */

#endif /* __USER_TYPE_H__ */

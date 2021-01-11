#ifndef __USER_TYPE_H__
#define __USER_TYPE_H__

#include "named_type.hpp"
#include "../ast/type/type_node.hpp"
#include "../ast/location.hpp"
#include "../utils/string_utils.hpp"
#include "../utils/cpp_utils.hpp"

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

  // typedef realtype aliastype; 比较是不是同一个类型，比较 realtype 即可
  bool IsSameRealType(Type* other) { return RealType()->IsSameType(other); }

  // 这个方法比较的是 UserType 别名类型是否相同
  bool IsSameType(Type* other) {
    if (utils::is<UserType *>(other)) {
      return utils::StringUtils::StrCmp(name(), ((UserType *)other)->name());
    } else {
      return false;
    }
  }

  bool IsCompatible(Type* other) { return RealType()->IsCompatible(other); }
  bool IsCastableTo(Type* target) { return RealType()->IsCastableTo(target); }

  Type* base_type() { return RealType()->base_type(); }
private:
  ast::TypeNode* real_;
};
} /* end type */

#endif /* __USER_TYPE_H__ */

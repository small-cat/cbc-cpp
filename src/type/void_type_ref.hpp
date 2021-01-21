#ifndef VOID_TYPE_REF_H
#define VOID_TYPE_REF_H

#include "type_ref.hpp"

namespace type {
class VoidTypeRef : public TypeRef {
public:
  VoidTypeRef() : TypeRef(nullptr) {}
  VoidTypeRef(ast::Location* l) : TypeRef(l) {}
  virtual ~VoidTypeRef() {}

  bool IsVoid() { return true; }
  std::string ToString() { return "void"; }
  std::string name() const { return ""; }
  virtual bool IsSameTypeRef(TypeRef *other) {
    return utils::is<VoidTypeRef *>(other);
  }
};
} /* type */

#endif
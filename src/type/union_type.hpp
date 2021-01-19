#ifndef __UNION_TYPE_H__
#define __UNION_TYPE_H__

#include "composite_type.hpp"

namespace type {
class UnionType : public CompositeType {
public:
  UnionType(std::string n, std::vector<ast::SlotNode*> membs, ast::Location* l);
  virtual ~UnionType(); 

  bool IsUnion();
  bool IsSameType(Type *other);
  bool EqualType(Type *other);
  void ComputeOffsets();
  std::string ToString();
};
} /* end type */

#endif /* __UNION_TYPE_H__ */

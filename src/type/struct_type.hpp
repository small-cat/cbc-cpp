#ifndef __STRUCT_TYPE_H__
#define __STRUCT_TYPE_H__

#include "type.hpp"
#include "composite_type.hpp"
#include "../ast/slot.hpp"

#include <vector>

namespace type {
class StructType : public CompositeType {
public:
  StructType(std::string n, std::vector<ast::SlotNode*> membs, ast::Location* l);
  virtual ~StructType();

  bool IsStruct();
  bool IsSameType(Type* other);
  void ComputeOffsets();
  std::string ToString();
private:
};
} /* end type */

#endif /* __STRUCT_TYPE_H__ */

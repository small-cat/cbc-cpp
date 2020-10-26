#ifndef __COMPOSITE_TYPE_H__
#define __COMPOSITE_TYPE_H__

#include <vector>
#include "named_type.hpp"
#include "../ast/slot.hpp"
#include "type.hpp"

namespace type {
class CompositeType : public NamedType {
public:
  CompositeType(std::string n, std::vector<ast::SlotNode*> membs, ast::Location* l) : NamedType(n, l) {
    members_.swap(membs);
    cached_size_ = Type::SizeUnknown;
    cached_align_ = Type::SizeUnknown;
    is_recursive_checked_ = false;
  }
  virtual ~CompositeType() {}

  bool IsCompositeType() { return true; }
  bool IsSameType(Type* other);
  bool IsCompatible(Type* target);
  bool IsCastableTo(Type* target);

  bool CompareMemberTypes(Type* other);
  long Size();
  long Alignment();
  std::vector<ast::SlotNode*> members();
  std::vector<Type*> MemberTypes();
  bool HasMember(std::string mem_name);
  Type* MemberType(std::string mem_name);
  long MemberOffset(std::string mem_name);
  
  virtual void ComputeOffsets() = 0;
  std::string ToString() {
    return "";
  }

  ast::SlotNode* Fetch(std::string mem_name);
  ast::SlotNode* Get(std::string mem_name);

  long cached_size();
  void SetCachedSize(long size);
  long cached_align();
  void SetCachedAlign(long size);
private:
  std::vector<ast::SlotNode*> members_;
  long cached_size_;
  long cached_align_;
  bool is_recursive_checked_;
};
} /* end type */

#endif /* __COMPOSITE_TYPE_H__ */

#ifndef __COMPOSITE_TYPE_H__
#define __COMPOSITE_TYPE_H__

#include <vector>
#include "named_type.hpp"
#include "../ast/slot.hpp"

namespace type {
class CompositeType : public NamedType {
public:
  CompositeType(std::string n, std::vector<ast::SlotNode> membs, ast::Location* l) : NamedType(n, l) {
    members_.swap(membs);
    cached_size_ = Type::SizeUnknown;
    cached_align_ = Type::SizeUnknown;
    is_recursive_checked_ = false;
  }
  virtual ~CompositeType() {}

  bool IsCompositeType() { return true; }
  // @todo { other member function definition }
private:
  std::vector<ast::SlotNode> members_;
  long cached_size_;
  long cached_align_;
  bool is_recursive_checked_;
};
} /* end type */

#endif /* __COMPOSITE_TYPE_H__ */

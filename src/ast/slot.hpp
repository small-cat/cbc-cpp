#ifndef __SLOT_H__
#define __SLOT_H__

#include "node.hpp"
#include "type/type_node.hpp"

namespace ast {
class SlotNode : public Node {
public:
  SlotNode(TypeNode* t, std::string n);
  virtual ~SlotNode();

  TypeNode* type_node();
  TypeRef GetTypeRef();
  type::Type* type();
  std::string name();
  long Size();
  long AllocSize();
  long Alignment();
  long offset();
  void SetOffset(long off);
  Location* location();
  void _dump(Dumper* d);
private:
  TypeNode* type_node_;
  std::string name_;
  long offset_;
};
} /* end ast */

#endif /* __SLOT_H__ */

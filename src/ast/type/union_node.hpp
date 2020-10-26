#ifndef __UNION_NODE_H__
#define __UNION_NODE_H__

#include "composite_type_definition_node.hpp"
#include "../slot.hpp"
#include "../location.hpp"
#include "../../type/type_ref.hpp"

#include <vector>

namespace ast {
class UnionTypeNode : public CompositeTypeDefinitionNode {
public:
  UnionTypeNode(Location* l, type::TypeRef* tr, std::string n, std::vector<SlotNode*> m);
  virtual ~UnionTypeNode();

  std::string Kind();
  bool IsUnion();
  
  // defining type
  type::Type* DefiningType();
  // void accept();
};
} /* end ast */

#endif /* __UNION_NODE_H__ */

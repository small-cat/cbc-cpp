#ifndef __UNION_NODE_H__
#define __UNION_NODE_H__

#include "composite_type_definition_node.hpp"

namespace ast {
class UnionTypeNode : public CompositeTypeDefinitionNode {
public:
  UnionTypeNode();
  virtual ~UnionTypeNode();

private:
  /* data */
};
} /* end ast */

#endif /* __UNION_NODE_H__ */

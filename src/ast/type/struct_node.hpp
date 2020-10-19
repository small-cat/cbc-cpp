#ifndef __STRUCT_NODE_H__
#define __STRUCT_NODE_H__

#include "composite_type_definition_node.hpp"

namespace ast {
class StructTypeNode : public CompositeTypeDefinitionNode {
public:
  StructTypeNode();
  virtual ~StructTypeNode();

private:
  /* data */
};
} /* end ast */

#endif /* __STRUCT_NODE_H__ */

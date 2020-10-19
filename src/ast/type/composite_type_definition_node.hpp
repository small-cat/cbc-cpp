#ifndef __COMPOSITE_TYPE_DEFINITION_NODE_H__
#define __COMPOSITE_TYPE_DEFINITION_NODE_H__

#include "type_definition_node.hpp"

namespace ast {
class CompositeTypeDefinitionNode : public TypeDefinitionNode {
public:
  CompositeTypeDefinitionNode();
  virtual ~CompositeTypeDefinitionNode();

private:
  /* data */
};
} /* end ast */

#endif /* __COMPOSITE_TYPE_DEFINITION_NODE_H__ */

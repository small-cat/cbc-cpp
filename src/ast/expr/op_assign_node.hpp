#ifndef __OP_ASSIGN_NODE_H__
#define __OP_ASSIGN_NODE_H__

#include "abstract_assign_node.hpp"

namespace ast {
class OpAssignNode : public AbstractAssignNode {
public:
  OpAssignNode();
  virtual ~OpAssignNode();

private:
  /* data */
};
} /* end ast */

#endif /* __OP_ASSIGN_NODE_H__ */

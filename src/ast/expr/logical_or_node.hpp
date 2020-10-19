#ifndef __LOGICAL_OR_NODE_H__
#define __LOGICAL_OR_NODE_H__

#include "binary_op_node.hpp"

namespace ast {
class LogicalOrNode : public BinaryOpNode {
public:
  LogicalOrNode();
  virtual ~LogicalOrNode();

private:
  /* data */
};
} /* end ast */

#endif /* __LOGICAL_OR_NODE_H__ */

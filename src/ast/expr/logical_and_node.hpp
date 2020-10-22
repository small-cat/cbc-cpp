#ifndef __LOGICAL_AND_NODE_H__
#define __LOGICAL_AND_NODE_H__

#include "binary_op_node.hpp"

namespace ast {
class LogicalAndNode : public BinaryOpNode {
public:
  LogicalAndNode(ExprNode* l, ExprNode* r) : BinaryOpNode(l, "&&", r) {}
  virtual ~LogicalAndNode() {}
};
} /* end ast */

#endif /* __LOGICAL_AND_NODE_H__ */

#ifndef __LOGICAL_OR_NODE_H__
#define __LOGICAL_OR_NODE_H__

#include "binary_op_node.hpp"

namespace ast {
class LogicalOrNode : public BinaryOpNode {
public:
  LogicalOrNode(ExprNode* l, ExprNode* r) : BinaryOpNode(l, "||", r) {}
  virtual ~LogicalOrNode() {}

  // void accept();
};
} /* end ast */

#endif /* __LOGICAL_OR_NODE_H__ */

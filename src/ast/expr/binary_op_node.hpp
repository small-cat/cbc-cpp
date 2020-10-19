#ifndef __BINARY_OP_NODE_H__
#define __BINARY_OP_NODE_H__

#include "expr_node.hpp"

namespace ast {
class BinaryOpNode : public ExprNode {
public:
  BinaryOpNode();
  virtual ~BinaryOpNode();

private:
  /* data */
};
} /* end ast */

#endif /* __BINARY_OP_NODE_H__ */

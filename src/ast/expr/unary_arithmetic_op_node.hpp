#ifndef __UNARY_ARITHMETIC_OP_NODE_H__
#define __UNARY_ARITHMETIC_OP_NODE_H__

#include "unary_op_node.hpp"

namespace ast {
class UnaryArithmeticOpNode : public UnaryOpNode {
public:
  UnaryArithmeticOpNode(arguments);
  virtual ~UnaryArithmeticOpNode();

private:
  /* data */
};
} /* end ast */

#endif /* __UNARY_ARITHMETIC_OP_NODE_H__ */

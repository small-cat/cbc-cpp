#ifndef __PREFIX_OP_NODE_H__
#define __PREFIX_OP_NODE_H__

#include "unary_arithmetic_op_node.hpp"

namespace ast {
class PrefixOpNode : public UnaryArithmeticOpNode {
public:
  PrefixOpNode(std::string op, ExprNode* e) : UnaryArithmeticOpNode(op, e) {}
  virtual ~PrefixOpNode() {}

  // void accept();
};
} /* end ast */

#endif /* __PREFIX_OP_NODE_H__ */

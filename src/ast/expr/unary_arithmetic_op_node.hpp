#ifndef __UNARY_ARITHMETIC_OP_NODE_H__
#define __UNARY_ARITHMETIC_OP_NODE_H__

#include "unary_op_node.hpp"

namespace ast {
class UnaryArithmeticOpNode : public UnaryOpNode {
public:
  UnaryArithmeticOpNode(std::string op, ExprNode* e) : UnaryOpNode(op, e), amount_(1) {}
  virtual ~UnaryArithmeticOpNode() {}

  long amount() {
    return amount_;
  }

  void SetAmount(long a) {
    amount_ = a;
  }
private:
  long amount_;
};
} /* end ast */

#endif /* __UNARY_ARITHMETIC_OP_NODE_H__ */

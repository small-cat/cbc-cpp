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

  /// 自增或者自减，指针的步长为所指类型的大小，整数为1
  void SetAmount(long a) {
    amount_ = a;
  }

  virtual std::string GetClass() { return "UnaryArithmeticOpNode"; }
private:
  /// 单目操作符，如果是整，自增或者自减，amount 设置为1即可，如是指针，amount 设置为指针所指向类型的大小
  long amount_;
};
} /* end ast */

#endif /* __UNARY_ARITHMETIC_OP_NODE_H__ */

#ifndef __PREFIX_OP_NODE_H__
#define __PREFIX_OP_NODE_H__

#include "unary_arithmetic_op_node.hpp"

namespace ast {
class PrefixOpNode : public UnaryArithmeticOpNode {
public:
  PrefixOpNode(std::string op, ExprNode* e) : UnaryArithmeticOpNode(op, e) {}
  virtual ~PrefixOpNode() {}
  virtual std::string GetClass() { return "PrefixOpNode"; }

  void Accept(ASTVisitor * visitor) { visitor->Visit(this); }
};
} /* end ast */

#endif /* __PREFIX_OP_NODE_H__ */

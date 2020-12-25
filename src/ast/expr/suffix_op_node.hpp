#ifndef __SUFFIX_OP_NODE_H__
#define __SUFFIX_OP_NODE_H__

#include "unary_arithmetic_op_node.hpp"

namespace ast {
class SuffixOpNode : public UnaryArithmeticOpNode {
public:
  SuffixOpNode(std::string op, ExprNode* e) : UnaryArithmeticOpNode(op, e) {}
  virtual ~SuffixOpNode() {}

  virtual std::string GetClass() { return "SuffixOpNode"; }
  void Accept(ASTVisitor * visitor) { visitor->Visit(this); }
};
} /* end ast */

#endif /* __SUFFIX_OP_NODE_H__ */

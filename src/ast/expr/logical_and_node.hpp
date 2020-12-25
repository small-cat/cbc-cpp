#ifndef __LOGICAL_AND_NODE_H__
#define __LOGICAL_AND_NODE_H__

#include "binary_op_node.hpp"

namespace ast {
class LogicalAndNode : public BinaryOpNode {
public:
  LogicalAndNode(ExprNode* l, ExprNode* r) : BinaryOpNode(l, "&&", r) {}
  virtual ~LogicalAndNode() {}

  std::string GetClass() { return "LogicalAndNode"; }

  void Accept(ASTVisitor * visitor) { visitor->Visit(this); }
};
} /* end ast */

#endif /* __LOGICAL_AND_NODE_H__ */

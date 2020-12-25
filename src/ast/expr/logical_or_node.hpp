#ifndef __LOGICAL_OR_NODE_H__
#define __LOGICAL_OR_NODE_H__

#include "binary_op_node.hpp"

namespace ast {
class LogicalOrNode : public BinaryOpNode {
public:
  LogicalOrNode(ExprNode* l, ExprNode* r) : BinaryOpNode(l, "||", r) {}
  virtual ~LogicalOrNode() {}

  virtual std::string GetClass() { return "LogicalOrNode"; }

  void Accept(ASTVisitor * visitor) { visitor->Visit(this); }
};
} /* end ast */

#endif /* __LOGICAL_OR_NODE_H__ */

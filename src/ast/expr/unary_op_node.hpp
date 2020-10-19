#ifndef __UNARY_OP_NODE_H__
#define __UNARY_OP_NODE_H__

#include "expr_node.hpp"

namespace ast {
class UnaryOpNode : public ExprNode {
public:
  UnaryOpNode();
  virtual ~UnaryOpNode();

private:
  /* data */
};
} /* end ast */

#endif /* __UNARY_OP_NODE_H__ */

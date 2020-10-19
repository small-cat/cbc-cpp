#ifndef __COND_EXPR_NODE_H__
#define __COND_EXPR_NODE_H__

#include "expr_node.hpp"

namespace ast {
class CondExprNode : public ExprNode {
public:
  CondExprNode();
  virtual ~CondExprNode();

private:
  /* data */
};
} /* end ast */

#endif /* __COND_EXPR_NODE_H__ */

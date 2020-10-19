#ifndef __SIZEOF_EXPR_NODE_H__
#define __SIZEOF_EXPR_NODE_H__

#include "expr_node.hpp"

namespace ast {
class SizeofExprNode : public ExprNode {
public:
  SizeofExprNode();
  virtual ~SizeofExprNode();

private:
  /* data */
};
} /* end ast */

#endif /* __SIZEOF_EXPR_NODE_H__ */

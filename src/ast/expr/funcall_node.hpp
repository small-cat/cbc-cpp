#ifndef __FUNCALL_NODE_H__
#define __FUNCALL_NODE_H__

#include "expr_node.hpp"

namespace ast {
class FuncallNode : public ExprNode {
public:
  FuncallNode();
  virtual ~FuncallNode();

private:
  /* data */
};
} /* end ast */

#endif /* __FUNCALL_NODE_H__ */

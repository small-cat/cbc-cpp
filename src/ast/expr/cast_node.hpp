#ifndef __CAST_NODE_H__
#define __CAST_NODE_H__

#include "expr_node.hpp"

namespace ast {
class CastNode : public ExprNode {
public:
  CastNode();
  virtual ~CastNode();

private:
  /* data */
};
} /* end ast */

#endif /* __CAST_NODE_H__ */

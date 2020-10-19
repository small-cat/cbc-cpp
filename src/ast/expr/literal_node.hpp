#ifndef __LITERAL_NODE_H__
#define __LITERAL_NODE_H__

#include "expr_node.hpp"

namespace ast {
class LiteralNode : public ExprNode {
public:
  LiteralNode();
  virtual ~LiteralNode();

private:
  /* data */
};
} /* end ast */

#endif /* __LITERAL_NODE_H__ */

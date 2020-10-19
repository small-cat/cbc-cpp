#ifndef __SIZEOF_TYPE_NODE_H__
#define __SIZEOF_TYPE_NODE_H__

#include "expr_node.hpp"

namespace ast {
class SizeofTypeNode : public ExprNode {
public:
  SizeofTypeNode();
  virtual ~SizeofTypeNode();

private:
  /* data */
};
} /* end ast */

#endif /* __SIZEOF_TYPE_NODE_H__ */

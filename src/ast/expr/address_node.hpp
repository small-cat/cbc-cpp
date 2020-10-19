#ifndef __ADDRESS_NODE_H__
#define __ADDRESS_NODE_H__

#include "expr_node.hpp"

namespace ast {
class AddressNode : public ExprNode {
public:
  AddressNode();
  virtual ~AddressNode();

private:
  /* data */
};
} /* end ast */

#endif /* __ADDRESS_NODE_H__ */

#ifndef __DEREFERENCE_NODE_H__
#define __DEREFERENCE_NODE_H__

#include "lhs_node.hpp"

namespace ast {
class DereferenceNode : public LHSNode {
public:
  DereferenceNode();
  virtual ~DereferenceNode();

private:
  /* data */
};
} /* end ast */

#endif /* __DEREFERENCE_NODE_H__ */

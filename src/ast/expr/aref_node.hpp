#ifndef __AREF_NODE_H__
#define __AREF_NODE_H__

#include "lhs_node.hpp"

namespace ast {
class ARefNode : public LHSNode {
public:
  ARefNode();
  virtual ~ARefNode();

private:
  /* data */
};
} /* end ast */

#endif /* __AREF_NODE_H__ */

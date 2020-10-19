#ifndef __IF_NODE_H__
#define __IF_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class IfNode : public StmtNode {
public:
  IfNode();
  virtual ~IfNode();

private:
  /* data */
};
} /* end ast */

#endif /* __IF_NODE_H__ */

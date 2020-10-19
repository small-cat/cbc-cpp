#ifndef __DO_WHILE_NODE_H__
#define __DO_WHILE_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class DoWhileNode : public StmtNode {
public:
  DoWhileNode();
  virtual ~DoWhileNode();

private:
  /* data */
};
} /* end ast */

#endif /* __DO_WHILE_NODE_H__ */

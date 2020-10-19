#ifndef __GOTO_NODE_H__
#define __GOTO_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class GotoNode : public StmtNode {
public:
  GotoNode();
  virtual ~GotoNode();

private:
  /* data */
};
} /* end ast */

#endif /* __GOTO_NODE_H__ */

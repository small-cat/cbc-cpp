#ifndef __BREAK_NODE_H__
#define __BREAK_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class BreakNode : public StmtNode {
public:
  BreakNode();
  virtual ~BreakNode();

private:
  /* data */
};
} /* end ast */

#endif /* __BREAK_NODE_H__ */

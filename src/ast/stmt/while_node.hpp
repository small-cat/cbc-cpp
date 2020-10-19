#ifndef __WHILE_NODE_H__
#define __WHILE_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class WhileNode : public StmtNode {
public:
  WhileNode();
  virtual ~WhileNode();

private:
  /* data */
};
} /* end ast */

#endif /* __WHILE_NODE_H__ */

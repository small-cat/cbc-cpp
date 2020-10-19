#ifndef __BLOCK_NODE_H__
#define __BLOCK_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class BlockNode : public StmtNode {
public:
  BlockNode();
  virtual ~BlockNode();

private:
  /* data */
};
} /* end ast */

#endif /* __BLOCK_NODE_H__ */

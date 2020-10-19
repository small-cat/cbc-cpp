#ifndef __CONTINUE_NODE_H__
#define __CONTINUE_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class ContinueNode : public StmtNode {
public:
  ContinueNode();
  virtual ~ContinueNode();

private:
  /* data */
};
} /* end ast */

#endif /* __CONTINUE_NODE_H__ */

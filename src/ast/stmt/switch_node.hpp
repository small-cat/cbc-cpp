#ifndef __SWITCH_NODE_H__
#define __SWITCH_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class SwitchNode : public StmtNode {
public:
  SwitchNode();
  virtual ~SwitchNode();

private:
  /* data */
};
} /* end ast */

#endif /* __SWITCH_NODE_H__ */

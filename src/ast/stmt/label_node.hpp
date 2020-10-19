#ifndef __LABEL_NODE_H__
#define __LABEL_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class LabelNode : public StmtNode {
public:
  LabelNode();
  virtual ~LabelNode();

private:
  /* data */
};
} /* end ast */

#endif /* __LABEL_NODE_H__ */

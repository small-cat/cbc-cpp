#ifndef __RETURN_NODE_H__
#define __RETURN_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class ReturnNode : public StmtNode {
public:
  ReturnNode();
  virtual ~ReturnNode();

private:
  /* data */
};
} /* end ast */

#endif /* __RETURN_NODE_H__ */

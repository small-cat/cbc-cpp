#ifndef __EXPR_STMT_NODE_H__
#define __EXPR_STMT_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class ExprStmtNode : public StmtNode {
public:
  ExprStmtNode();
  virtual ~ExprStmtNode();

private:
  /* data */
};
} /* end ast */

#endif /* __EXPR_STMT_NODE_H__ */

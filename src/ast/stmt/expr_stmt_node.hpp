#ifndef __EXPR_STMT_NODE_H__
#define __EXPR_STMT_NODE_H__

#include "stmt_node.hpp"
#include "../expr/expr_node.hpp"

namespace ast {
class ExprStmtNode : public StmtNode {
public:
  ExprStmtNode(Location* l, ExprNode* e);
  virtual ~ExprStmtNode();

  ExprNode* expr();
  void SetExpr(ExprNode* e);
  void _dump(Dumper* d);

  // void accept();
private:
  ExprNode* expr_;
};
} /* end ast */

#endif /* __EXPR_STMT_NODE_H__ */

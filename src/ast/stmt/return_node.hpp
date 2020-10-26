#ifndef __RETURN_NODE_H__
#define __RETURN_NODE_H__

#include "stmt_node.hpp"
#include "../expr/expr_node.hpp"

namespace ast {
class ReturnNode : public StmtNode {
public:
  ReturnNode(Location* l, ExprNode* e) : StmtNode(l), expr_(e) {}
  virtual ~ReturnNode() {}

  ExprNode* expr() { return expr_; }
  void SetExpr(ExprNode* e) { expr_ = e; }
  void _dump(Dumper* d) { /* @todo { not implement _dump }*/ }
private:
  ExprNode* expr_;
};
} /* end ast */

#endif /* __RETURN_NODE_H__ */

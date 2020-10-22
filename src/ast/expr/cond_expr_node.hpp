#ifndef __COND_EXPR_NODE_H__
#define __COND_EXPR_NODE_H__

#include "expr_node.hpp"

namespace ast {
class CondExprNode : public ExprNode {
public:
  CondExprNode(ExprNode* c, ExprNode* t, ExprNode* e) : cond_(c), then_expr_(t), else_expr_(e) {}
  virtual ~CondExprNode() {}

  type::Type* Type() {
    return then_expr_->type();
  }

  ExprNode* cond() { return cond_; }
  ExprNode* then_expr() { return then_expr_; }
  ExprNode* else_expr() { return else_expr_; }
  void SetThen(ExprNode* t) { then_expr_ = t; }
  void SetElse(ExprNode* e) { else_expr_ = e; }
  Location* location() { return cond->location(); }

  void _dump(Dumper* d) {
    d->PrintMember("Cond", cond_);
    d->PrintMember("ThenExpr", then_expr_);
    d->PrintMember("ElseExpr", else_expr_);
  }

  // void accept(ASTVisitor* visitor);
private:
  ExprNode* cond_;
  ExprNode* then_expr_;
  ExprNode* else_expr_;
};
} /* end ast */

#endif /* __COND_EXPR_NODE_H__ */

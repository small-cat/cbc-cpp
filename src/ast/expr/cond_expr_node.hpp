#ifndef __COND_EXPR_NODE_H__
#define __COND_EXPR_NODE_H__

#include "expr_node.hpp"

namespace ast {
class CondExprNode : public ExprNode {
public:
  CondExprNode(ExprNode* c, ExprNode* t, ExprNode* e) : cond_(c), then_expr_(t), else_expr_(e) {}
  virtual ~CondExprNode() {
    if (nullptr != cond_)
    {
      delete cond_;
      cond_ = nullptr;
    }

    if (nullptr != then_expr_)
    {
      delete then_expr_;
      then_expr_ = nullptr;
    }

    if (nullptr != else_expr_)
    {
      delete else_expr_;
      else_expr_ = nullptr;
    }
  }

  type::Type* type() {
    return then_expr_->type();
  }

  ExprNode* cond() { return cond_; }
  ExprNode* then_expr() { return then_expr_; }
  ExprNode* else_expr() { return else_expr_; }
  void SetThen(ExprNode* t) { then_expr_ = t; }
  void SetElse(ExprNode* e) { else_expr_ = e; }
  Location* location() { return cond_->location(); }

  std::string GetClass() { return "condition expression"; }

  void _dump(Dumper* d) {
    d->PrintMember("CondExpr", cond_);
    d->PrintMember("ThenExpr", then_expr_);
    d->PrintMember("ElseExpr", else_expr_);
  }

  void Accept(ASTVisitor * visitor) { visitor->Visit(this); }
private:
  ExprNode* cond_;
  ExprNode* then_expr_;
  ExprNode* else_expr_;
};
} /* end ast */

#endif /* __COND_EXPR_NODE_H__ */

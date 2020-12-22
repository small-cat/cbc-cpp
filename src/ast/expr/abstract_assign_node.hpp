/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : abstract_assign_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-24
 * @brief : assign expression
*/

#ifndef __ABSTRACT_ASSIGN_NODE_H__
#define __ABSTRACT_ASSIGN_NODE_H__

#include "expr_node.hpp"

namespace ast {
class AbstractAssignNode : public ExprNode {
public:
  AbstractAssignNode(ExprNode* l, ExprNode* r) : lhs_(l), rhs_(r) {}
  virtual ~AbstractAssignNode() {
    if (nullptr != lhs_) {
      delete lhs_;
      lhs_ = nullptr;
    }

    if (nullptr != rhs_) {
      delete rhs_;
      rhs_ = nullptr;
    }
  }

  type::Type* type() { return lhs_->type(); }
  ExprNode* lhs() { return lhs_; }
  ExprNode* rhs() { return rhs_; }
  void SetRHS(ExprNode* r) { rhs_ = r; }
  Location* location() { return lhs_->location(); }
  void _dump(Dumper* d) {
    d->PrintMember("Left", lhs_);
    d->PrintMember("Right", rhs_);
  }
private:
  ExprNode* lhs_;
  ExprNode* rhs_;
};
} /* end ast */

#endif /* __ABSTRACT_ASSIGN_NODE_H__ */

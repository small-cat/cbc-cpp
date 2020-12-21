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
  virtual ~AbstractAssignNode() {}

  type::Type* type() { return lhs_->type(); }
  ExprNode* lhs() { return lhs_; }
  ExprNode* rhs() { return rhs_; }
  void SetRHS(ExprNode* r) { rhs_ = r; }
  Location* location() { return lhs_->location(); }
  void _dump(Dumper* d) {
    d->PrintMember("lhs", lhs_);
    d->PrintMember("rhs", rhs_);
  }
private:
  ExprNode* lhs_;
  ExprNode* rhs_;
};
} /* end ast */

#endif /* __ABSTRACT_ASSIGN_NODE_H__ */

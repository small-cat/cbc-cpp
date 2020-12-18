/**
 * @copyright (c) Copyright 2020 Secsmart. All Rights Reserved.
 * @license
 * @file  : lhs_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-23
 * @brief : left hand side node 
*/
#ifndef __LHS_NODE_H__
#define __LHS_NODE_H__

#include "expr_node.hpp"
#include "../../type/type.hpp"

namespace ast {
class LHSNode : public ExprNode {
public:
  LHSNode() : type_(nullptr), original_type_(nullptr) {}
  virtual ~LHSNode() {}

  void SetType(type::Type* type) {
    type_ = type;
  }

  type::Type* type() {
    return type_ == nullptr ? original_type_ : type_;
  }

  virtual type::Type* original_type() = 0;

  long AllocSize() { return original_type_->AllocSize(); }
  bool IsLValue() { return true; }
  bool IsAssignable() { return IsLoadable(); }
  bool IsLoadable() {
    return !original_type_->IsArray() && !original_type_->IsFunction();
  }

private:
  type::Type* type_;
  type::Type* original_type_;
};
} /* end ast */

#endif /* __LHS_NODE_H__ */

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
  LHSNode() : type_(nullptr) {}
  virtual ~LHSNode() {}

  void SetType(type::Type* type) {
    type_ = type;
  }

  type::Type* GetLhsNodeType() {
    return type_;
  }

  type::Type* type() {
    return type_ == nullptr ? original_type() : type_;
  }

  virtual type::Type* original_type() = 0;

  long AllocSize() { return original_type()->AllocSize(); }
  bool IsLValue() { return true; }

  /************************************************************************************
  * @fn IsAssignable
  * @brief 数组或者函数是不能被赋值的， 如果是数组或者函数, IsLoadable 返回的是false
  * @param
  * @author Jona
  * @date 2021/01/08
  ************************************************************************************/
  bool IsAssignable() { return IsLoadable(); }
  bool IsLoadable() {
    return !original_type()->IsArray() && !original_type()->IsFunction();
  }

  std::string GetClass() { return ""; }

private:
  type::Type* type_;
};
} /* end ast */

#endif /* __LHS_NODE_H__ */

/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : op_assign_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-22
 * @brief : 符合赋值操作，比如 +=, -= /= *= ...
*/

#ifndef __OP_ASSIGN_NODE_H__
#define __OP_ASSIGN_NODE_H__

#include "abstract_assign_node.hpp"

namespace ast {
class OpAssignNode : public AbstractAssignNode {
public:
  OpAssignNode(ExprNode* l, std::string op, ExprNode* r) : AbstractAssignNode(l, r), operator_(op) {}
  virtual ~OpAssignNode() {}

  std::string OpAssignOperator() { return operator_; }
  virtual std::string GetClass() { return "OpAssignNode"; }

  // void accept();
private:
  std::string operator_;
};
} /* end ast */

#endif /* __OP_ASSIGN_NODE_H__ */

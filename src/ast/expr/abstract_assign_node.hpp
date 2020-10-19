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
  AbstractAssignNode();
  virtual ~AbstractAssignNode();

private:
  /* data */
};
} /* end ast */

#endif /* __ABSTRACT_ASSIGN_NODE_H__ */

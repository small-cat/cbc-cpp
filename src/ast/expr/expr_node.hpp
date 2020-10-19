/**
 * @copyright (c) Copyright 2020 Secsmart. All Rights Reserved.
 * @license
 * @file  : expr_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-23
 * @brief : expression node definitions
*/
#ifndef __EXPR_NODE_H__
#define __EXPR_NODE_H__

#include "node.hpp"

namespace ast {
class ExprNode : public Node {
public:
  ExprNode();
  virtual ~ExprNode();

  virtual std::string GetClass() { return ""; }
  virtual Type* type() = 0;
  Type* OriginalType() { return type(); }

  long AllocSize() { return type()->AllocSize(); }

  bool IsConstant() { return false; }
  bool IsParameter() { return false; }
  bool IsLValue() { return false; }
  bool IsAssignalble() { return false; }
  bool IsLoadable() { return false; }
  bool IsCallable() { return type()->IsCallable(); }
  bool IsPointer() { return type()->IsPointer(); }

  virtual void Accept(ASTVisitor* visitor) = 0;
};
} /* end ast */

#endif /* __EXPR_NODE_H__ */

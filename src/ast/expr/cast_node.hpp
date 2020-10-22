/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : cast_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-22
 * @brief : type cast, convert expr to type_node_
*/

#ifndef __CAST_NODE_H__
#define __CAST_NODE_H__

#include "expr_node.hpp"
#include "../type/type_node.hpp"
#include "../../type/type.hpp"

namespace ast {
class CastNode : public ExprNode {
public:
  // CastNode(type::Type* t, ExprNode* expr);
  CastNode(TypeNode* t, ExprNode* expr);
  virtual ~CastNode();

  type::Type* type();
  TypeNode* type_node();
  ExprNode* expr();

  bool IsLValue();
  bool IsAssignable();
  bool IsEffectiveCast();

  Location* location();
  void _dump(Dumper* d);

  // void accept(ASTVisitor* visitor);
private:
  TypeNode type_node_;
  ExprNode* expr_;
};
} /* end ast */

#endif /* __CAST_NODE_H__ */

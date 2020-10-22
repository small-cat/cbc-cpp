/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : literal_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-22
 * @brief : 常量节点
*/

#ifndef __LITERAL_NODE_H__
#define __LITERAL_NODE_H__

#include "expr_node.hpp"
#include "../type/type_node.hpp"

namespace ast {
class LiteralNode : public ExprNode {
public:
  LiteralNode(Location* l, type::TypeRef* tr);
  virtual ~LiteralNode();

  Location* location();
  type::Type* type();
  TypeNode* type_node();
  bool IsConstant();
private:
  Location* location_;
  TypeNode* type_node_;
};
} /* end ast */

#endif /* __LITERAL_NODE_H__ */

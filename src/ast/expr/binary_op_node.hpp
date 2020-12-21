/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : binary_op_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-22
 * @brief : 二元表达式, 至少有两个操作数，比如 a + b, a - b ...
*/

#ifndef __BINARY_OP_NODE_H__
#define __BINARY_OP_NODE_H__

#include "expr_node.hpp"

namespace ast {
class BinaryOpNode : public ExprNode {
public:
  BinaryOpNode(ExprNode* l, std::string op, ExprNode* r);
  BinaryOpNode(type::Type* t, ExprNode* l, std::string op, ExprNode* r);
  virtual ~BinaryOpNode();

  std::string BinaryOpOperator();
  type::Type* type();
  void SetType(type::Type* t);

  ExprNode* left();
  void SetLeft(ExprNode* l);
  ExprNode* right();
  void SetRight(ExprNode* r);

  Location* location();
  virtual std::string GetClass();
  void _dump(Dumper* d);
  // void accept();
private:
  std::string operator_;
  ExprNode* left_;
  ExprNode* right_;
  type::Type* type_;       // type of returned value
};
} /* end ast */

#endif /* __BINARY_OP_NODE_H__ */

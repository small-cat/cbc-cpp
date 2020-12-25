/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : aref_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-22
 * @brief : array node definitions
*/

#ifndef __AREF_NODE_H__
#define __AREF_NODE_H__

#include "lhs_node.hpp"

namespace ast {
class ARefNode : public LHSNode {
public:
  ARefNode(ExprNode* e, ExprNode* i);
  virtual ~ARefNode();

  ExprNode* expr();
  ExprNode* index();

  bool IsMultiDimension();
  ExprNode* base_expr();
  long ElementSize();
  long Length();
  type::Type* original_type();
  Location* location();
  std::string GetClass();
  void _dump(Dumper* d);
  void Accept(ASTVisitor * visitor);
private:
  ExprNode* expr_;
  ExprNode* index_;     // like expr_[index_]
};
} /* end ast */

#endif /* __AREF_NODE_H__ */

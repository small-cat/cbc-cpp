/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : if_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : if stmt_node
 *          if (cond) {
 *            then body
 *          } else {
 *            elsebody
 *          }
 *          NOTE: not support "else if"
*/

#ifndef __IF_NODE_H__
#define __IF_NODE_H__

#include "stmt_node.hpp"
#include "../expr/expr_node.hpp"

namespace ast {
class IfNode : public StmtNode {
public:
  IfNode(Location* l, ExprNode* c, StmtNode* t, StmtNode* e);
  virtual ~IfNode();

  ExprNode* cond();
  StmtNode* then_body();
  StmtNode* else_body();
  void _dump(Dumper* d);

  // void accept();
private:
  ExprNode* cond_;
  StmtNode* then_body_;
  StmtNode* else_body_;
};
} /* end ast */

#endif /* __IF_NODE_H__ */

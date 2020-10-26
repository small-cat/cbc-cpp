/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : for_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : for statements, like 
 *          for (init_; cond_; incr_) { body_; }
*/

#ifndef __FOR_NODE_H__
#define __FOR_NODE_H__

#include "stmt_node.hpp"
#include "expr_stmt_node.hpp"
#include "../expr/expr_node.hpp"

namespace ast {
class ForNode : public StmtNode {
public:
  ForNode(Location* l, ExprNode* init, ExprNode* c, ExprNode* incr, StmtNode* body);
  virtual ~ForNode();

  StmtNode* init();
  ExprNode* cond();
  StmtNode* incr();
  StmtNode* body();

  void _dump(Dumper* d);
  // void accept();
private:
  StmtNode* init_;
  ExprNode* cond_;
  StmtNode* incr_;
  StmtNode* body_;
};
} /* end ast */

#endif /* __FOR_NODE_H__ */

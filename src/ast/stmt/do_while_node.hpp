/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : do_while_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : do while stmt :
 *          do { body_ } while(cond_);
*/

#ifndef __DO_WHILE_NODE_H__
#define __DO_WHILE_NODE_H__

#include "stmt_node.hpp"
#include "../expr/expr_node.hpp"

namespace ast {
class DoWhileNode : public StmtNode {
public:
  DoWhileNode(Location* l, StmtNode* b, ExprNode* c);
  virtual ~DoWhileNode();

  StmtNode* body();
  ExprNode* cond();
  void _dump(Dumper* d);
  virtual std::string GetClass();

  // void accept();
private:
  StmtNode* body_;
  ExprNode* cond_;
};
} /* end ast */

#endif /* __DO_WHILE_NODE_H__ */

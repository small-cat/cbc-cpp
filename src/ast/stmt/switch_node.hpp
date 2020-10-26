/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : switch_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : switch stmt node description
 *          switch (cond_) {
 *            CaseNode;
 *            CaseNode;
 *            ...
 *          }
*/

#ifndef __SWITCH_NODE_H__
#define __SWITCH_NODE_H__

#include "stmt_node.hpp"
#include "case_node.hpp"
#include "../expr/expr_node.hpp"

#include <vector>

namespace ast {
class SwitchNode : public StmtNode {
public:
  SwitchNode(Location* l, ExprNode* c, std::vector<CaseNode*> cases);
  virtual ~SwitchNode();

  ExprNode* cond();
  std::vector<CaseNode*> cases();
  void _dump(Dumper* d);
private:
  ExprNode* cond_;
  std::vector<CaseNode*> cases_;
};
} /* end ast */

#endif /* __SWITCH_NODE_H__ */

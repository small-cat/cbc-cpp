/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : case_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : case node stmt:
 *          case value1:
 *          case value2:
 *          ...
 *            body_;
 *            break;
*/

#ifndef __CASE_NODE_H__
#define __CASE_NODE_H__

#include "stmt_node.hpp"
#include "../expr/expr_node.hpp"
#include "block_node.hpp"

#include <vector>

namespace ast {
class CaseNode : public StmtNode {
public:
  CaseNode(Location* l, std::vector<ExprNode*> vs, BlockNode* b);
  virtual ~CaseNode();

  std::vector<ExprNode*> values();
  bool IsDefault();
  BlockNode* body();
  // Label* label();
  void _dump(Dumper* d);
  // void accept();
private:
  // Label label_;    // used in assembly code
  std::vector<ExprNode*> values_;
  BlockNode* body_;
};
} /* end ast */

#endif /* __CASE_NODE_H__ */

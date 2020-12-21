/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : label_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : label stmt_node
 *          ERROR:
 *            StmtNode;
 *
 *          goto ERROR;
*/

#ifndef __LABEL_NODE_H__
#define __LABEL_NODE_H__

#include "stmt_node.hpp"
#include "../expr/expr_node.hpp"

namespace ast {
class LabelNode : public StmtNode {
public:
  LabelNode(Location* l, std::string n, StmtNode* s);
  virtual ~LabelNode();

  std::string name();
  StmtNode* stmt();
  void _dump(Dumper* d);
  virtual std::string GetClass();

  // void accept();
private:
  std::string name_;
  StmtNode* stmt_;
};
} /* end ast */

#endif /* __LABEL_NODE_H__ */

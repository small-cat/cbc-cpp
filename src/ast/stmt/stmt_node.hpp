/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : stmt_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-24
 * @brief : abstract statement node 
*/

#ifndef __STMT_NODE_H__
#define __STMT_NODE_H__

#include "../node.hpp"

namespace ast {
class StmtNode : public Node {
public:
  StmtNode();
  virtual ~StmtNode();

private:
  /* data */
};
} /* end ast */

#endif /* __STMT_NODE_H__ */

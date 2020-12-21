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
#include "../location.hpp"

namespace ast {
class StmtNode : public Node {
public:
  StmtNode(Location* l) : location_(l) {}
  virtual ~StmtNode() {}

  Location* location() { return location_; }
  virtual std::string GetClass() { return ""; }
private:
  Location* location_;
};
} /* end ast */

#endif /* __STMT_NODE_H__ */

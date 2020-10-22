/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : dereference_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-22
 * @brief : dereference pointers, like *ptr to get its value 
*/

#ifndef __DEREFERENCE_NODE_H__
#define __DEREFERENCE_NODE_H__

#include "lhs_node.hpp"
#include "../../type/type.hpp"

namespace ast {
class DereferenceNode : public LHSNode {
public:
  DereferenceNode(ExprNode* e);
  virtual ~DereferenceNode();

  type::Type* OriginalType();
  ExprNode* expr();
  void SetExpr(ExprNode* e);
  Location* location();
  void _dump(Dumper* d);
  // void accept();
private:
  ExprNode* expr_;
};
} /* end ast */

#endif /* __DEREFERENCE_NODE_H__ */

/**
 * @copyright (c) Copyright 2020 Secsmart. All Rights Reserved.
 * @license
 * @file  : ptr_member_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-24
 * @brief : pointer member
*/
#ifndef __PTR_MEMBER_NODE_H__
#define __PTR_MEMBER_NODE_H__

#include "lhs_node.hpp"

namespace ast {
class ExprNode;
class PtrMemberNode : public LHSNode {
public:
  PtrMemberNode(ExprNode* e, std::string m);
  virtual ~PtrMemberNode();

  CompositeType DereferedCompositeType();
  Type DereferedType();
  ExprNode* expr();
  std::string member();

  long Offset();
  Type* original_type();
  Location* location();

  void Dump(Dumper* d);

private:
  ExprNode* expr_;
  std::string member_;
};
} /* end ast */

#endif /* __PTR_MEMBER_NODE_H__ */

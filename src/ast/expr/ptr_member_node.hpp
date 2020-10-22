/**
 * @copyright (c) Copyright 2020 Secsmart. All Rights Reserved.
 * @license
 * @file  : ptr_member_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-24
 * @brief : pointer member : expr_->member_
*/
#ifndef __PTR_MEMBER_NODE_H__
#define __PTR_MEMBER_NODE_H__

#include "lhs_node.hpp"
#include "../../type/type.hpp"
#include "../../type/composite_type.hpp"

namespace ast {
class ExprNode;
class PtrMemberNode : public LHSNode {
public:
  PtrMemberNode(ExprNode* e, std::string m);
  virtual ~PtrMemberNode();

  type::CompositeType* DereferedCompositeType();
  type::Type* DereferedType();
  ExprNode* expr();
  std::string member();

  long Offset();
  type::Type* OriginalType();

  Location* location();
  void _dump(Dumper* d);

private:
  ExprNode* expr_;
  std::string member_;
};
} /* end ast */

#endif /* __PTR_MEMBER_NODE_H__ */

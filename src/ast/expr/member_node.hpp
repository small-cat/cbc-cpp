/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: member_node.hpp
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/18
* @brief: member of class, struct or union..., like node.member
*/
#ifndef __MEMBER_NODE_H__
#define __MEMBER_NODE_H__

#include "lhs_node.hpp"
#include "../../type/type.hpp"
#include "../../type/composite_type.hpp"

namespace ast {
class ExprNode;
class MemberNode : public LHSNode {
public:
  MemberNode(ExprNode* e, std::string m);
  virtual ~MemberNode();

  type::CompositeType* BaseType();
  ExprNode* expr();
  std::string member();
  long Offset();
  type::Type* original_type();
  Location* location();
  virtual std::string GetClass();
  void _dump(Dumper* d);
  // void accept(ASTVisitor visitor);

private:
  ExprNode* expr_;
  std::string member_;    // expr_.member_
};
} /* end ast */

#endif /* __MEMBER_NODE_H__ */

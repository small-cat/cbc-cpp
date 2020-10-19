#ifndef __MEMBER_NODE_H__
#define __MEMBER_NODE_H__

#include "lhs_node.hpp"

namespace ast {
class ExprNode;
class MemberNode : public LHSNode {
public:
  MemberNode(arguments);
  virtual ~MemberNode();

  MemberNode(ExprNode expr, String member);
  CompositeType* BaseType();
  ExprNode* expr();
  std::string member();
  long Offset();
  Type* original_type();
  Location* location();
  void Dump(Dumper* d);
  void accept(ASTVisitor visitor);
};
} /* end ast */

#endif /* __MEMBER_NODE_H__ */

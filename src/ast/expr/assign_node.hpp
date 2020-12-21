#ifndef __ASSIGN_NODE_H__
#define __ASSIGN_NODE_H__

#include "abstract_assign_node.hpp"

namespace ast {
class AssignNode : public AbstractAssignNode {
public:
  AssignNode(ExprNode* l, ExprNode* r) : AbstractAssignNode(l, r) {}
  virtual ~AssignNode() {}

  std::string GetClass() { return "AssignNode"; }

  // void accept();
};
} /* end ast */

#endif /* __ASSIGN_NODE_H__ */

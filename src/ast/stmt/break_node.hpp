#ifndef __BREAK_NODE_H__
#define __BREAK_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class BreakNode : public StmtNode {
public:
  BreakNode(Location* l) : StmtNode(l) {}
  virtual ~BreakNode() {}

  void _dump(Dumper* d) {}
  void Accept(ASTVisitor * visitor) { visitor->Visit(this); }
  virtual std::string GetClass() { return "BreakStmtNode"; }
};
} /* end ast */

#endif /* __BREAK_NODE_H__ */

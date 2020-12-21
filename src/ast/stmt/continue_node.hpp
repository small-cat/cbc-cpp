#ifndef __CONTINUE_NODE_H__
#define __CONTINUE_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class ContinueNode : public StmtNode {
public:
  ContinueNode(Location* l) : StmtNode(l) {}
  virtual ~ContinueNode() {}

  void _dump(Dumper* d) { /* @todo { not implement _dump } */ }
  virtual std::string GetClass() { return "ContinueStmtNode"; }

  // void accept();
};
} /* end ast */

#endif /* __CONTINUE_NODE_H__ */

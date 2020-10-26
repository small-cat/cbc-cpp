#ifndef __BREAK_NODE_H__
#define __BREAK_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class BreakNode : public StmtNode {
public:
  BreakNode(Location* l) : StmtNode(l) {}
  virtual ~BreakNode() {}

  void _dump(Dumper* d) { /* @todo { not implement _dump } */ }
  // void accept();
};
} /* end ast */

#endif /* __BREAK_NODE_H__ */

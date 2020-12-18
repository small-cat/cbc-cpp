#ifndef __GOTO_NODE_H__
#define __GOTO_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class GotoNode : public StmtNode {
public:
  GotoNode(Location* l, std::string n) : StmtNode(l), label_name_(n) {}
  virtual ~GotoNode() {}

  std::string label_name() { return label_name_; }
  void _dump(Dumper* d) { /* @todo { not implement _dump }*/ }
  // void accept();
private:
  std::string label_name_;
};
} /* end ast */

#endif /* __GOTO_NODE_H__ */

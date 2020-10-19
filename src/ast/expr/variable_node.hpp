#ifndef __VARIABLE_NODE_H__
#define __VARIABLE_NODE_H__

#include "lhs_node.hpp"

namespace ast {
class VariableNode : public LHSNode {
public:
  VariableNode();
  virtual ~VariableNode();

private:
  Location* location_;
  std::string name_;
  Entity* entity_;
};
} /* end ast */

#endif /* __VARIABLE_NODE_H__ */

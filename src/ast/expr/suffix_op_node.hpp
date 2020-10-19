#ifndef __SUFFIX_OP_NODE_H__
#define __SUFFIX_OP_NODE_H__

#include "unary_arithmetic_op_node.hpp"

namespace ast {
class SuffixOpNode : public UnaryArithmeticOpNode {
public:
  SuffixOpNode();
  virtual ~SuffixOpNode();

private:
  /* data */
};
} /* end ast */

#endif /* __SUFFIX_OP_NODE_H__ */

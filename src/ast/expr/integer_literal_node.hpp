#ifndef __INTEGER_LITERAL_NODE_H__
#define __INTEGER_LITERAL_NODE_H__

#include "literal_node.hpp"

namespace ast {
class IntegerLiteralNode : public LiteralNode {
public:
  IntegerLiteralNode();
  virtual ~IntegerLiteralNode();

private:
  /* data */
};
} /* end ast */

#endif /* __INTEGER_LITERAL_NODE_H__ */

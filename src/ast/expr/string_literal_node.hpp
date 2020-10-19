#ifndef __STRING_LITERAL_NODE_H__
#define __STRING_LITERAL_NODE_H__

#include "literal_node.hpp"

namespace ast {
class StringLiteralNode : public LiteralNode {
public:
  StringLiteralNode();
  virtual ~StringLiteralNode();

private:
  /* data */
};
} /* end ast */

#endif /* __STRING_LITERAL_NODE_H__ */

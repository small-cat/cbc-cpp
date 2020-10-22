#ifndef __INTEGER_LITERAL_NODE_H__
#define __INTEGER_LITERAL_NODE_H__

#include "literal_node.hpp"

namespace ast {
class IntegerLiteralNode : public LiteralNode {
public:
  IntegerLiteralNode(Location* l, type::TypeRef* tr, long val);
  virtual ~IntegerLiteralNode();

  long value();
  void _dump(Dumper* d);
  // void accept();
private:
  long value_;
};
} /* end ast */

#endif /* __INTEGER_LITERAL_NODE_H__ */

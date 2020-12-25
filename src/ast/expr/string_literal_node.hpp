#ifndef __STRING_LITERAL_NODE_H__
#define __STRING_LITERAL_NODE_H__

#include "literal_node.hpp"

namespace ast {
class StringLiteralNode : public LiteralNode {
public:
  StringLiteralNode(Location* l, type::TypeRef* tr, std::string val);
  virtual ~StringLiteralNode();

  std::string value();
  void _dump(Dumper* d);
  void Accept(ASTVisitor * visitor);

  virtual std::string GetClass();
private:
  std::string value_;
  // entity::ConstantEntry* entry_;
};
} /* end ast */

#endif /* __STRING_LITERAL_NODE_H__ */

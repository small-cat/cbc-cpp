#ifndef __SIZEOF_TYPE_NODE_H__
#define __SIZEOF_TYPE_NODE_H__

#include "expr_node.hpp"
#include "../type/type_node.hpp"

namespace ast {
class SizeofTypeNode : public ExprNode {
public:
  SizeofTypeNode(TypeNode* op, type::TypeRef* tr);
  virtual ~SizeofTypeNode();

  type::Type* OperandType();
  TypeNode* OperandTypeNode();
  type::Type* type();
  TypeNode* type_node();
  Location* location();
  void _dump(Dumper* d);

  virtual std::string GetClass();

  void Accept(ASTVisitor * visitor);
private:
  TypeNode* operand_;     // type of operand
  TypeNode* type_node_;   // return type
};
} /* end ast */

#endif /* __SIZEOF_TYPE_NODE_H__ */

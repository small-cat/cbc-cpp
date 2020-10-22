#ifndef __SIZEOF_EXPR_NODE_H__
#define __SIZEOF_EXPR_NODE_H__

#include "expr_node.hpp"
#include "../type/type_node.hpp"

namespace ast {
class SizeofExprNode : public ExprNode {
public:
  SizeofExprNode(ExprNode* e, TypeRef* tr);
  virtual ~SizeofExprNode();

  ExprNode* expr();
  void SetExpr(ExprNode* e);
  type::Type* type();
  TypeNode* type_node();
  Location* location();
  void _dump(Dumper* d);
private:
  ExprNode* expr_;
  TypeNode* type_node_;
};
} /* end ast */

#endif /* __SIZEOF_EXPR_NODE_H__ */

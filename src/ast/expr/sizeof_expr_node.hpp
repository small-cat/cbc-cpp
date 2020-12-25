#ifndef __SIZEOF_EXPR_NODE_H__
#define __SIZEOF_EXPR_NODE_H__

#include "expr_node.hpp"
#include "../type/type_node.hpp"
#include "../../type/type_ref.hpp"

namespace ast {
class SizeofExprNode : public ExprNode {
public:
  SizeofExprNode(ExprNode* e, type::TypeRef* tr);
  virtual ~SizeofExprNode();

  ExprNode* expr();
  void SetExpr(ExprNode* e);
  type::Type* type();
  TypeNode* type_node();
  Location* location();
  std::string GetClass();
  void _dump(Dumper* d);

  void Accept(ASTVisitor * visitor);
private:
  ExprNode* expr_;
  TypeNode* type_node_;
};
} /* end ast */

#endif /* __SIZEOF_EXPR_NODE_H__ */

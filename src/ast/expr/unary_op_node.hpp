#ifndef __UNARY_OP_NODE_H__
#define __UNARY_OP_NODE_H__

#include "expr_node.hpp"
#include "../../type/type.hpp"

namespace ast {

/// 单目操作符表达式，比如 +， -， ！， ~
class UnaryOpNode : public ExprNode {
public:
  UnaryOpNode(std::string op, ExprNode* e);
  virtual ~UnaryOpNode();

  std::string UnaryOpNodeOperator();
  type::Type* type();
  void SetOpType(type::Type* t);
  type::Type* op_type();
  ExprNode* expr();
  void SetExpr(ExprNode* e);
  Location* location();
  void _dump(Dumper* d);

  virtual std::string GetClass();
  void Accept(ASTVisitor * visitor);
private:
  std::string operator_;
  ExprNode* expr_;
  type::Type* op_type_;
};
} /* end ast */

#endif /* __UNARY_OP_NODE_H__ */

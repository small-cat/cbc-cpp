#ifndef __WHILE_NODE_H__
#define __WHILE_NODE_H__

#include "stmt_node.hpp"
#include "../expr/expr_node.hpp"

namespace ast {
class WhileNode : public StmtNode {
public:
  WhileNode(Location* l, ExprNode* c, StmtNode* b);
  virtual ~WhileNode();

  ExprNode* cond();
  StmtNode* body();
  void _dump(Dumper* d);
  virtual std::string GetClass();
  void Accept(ASTVisitor * visitor);
private:
  ExprNode* cond_;
  StmtNode* body_;
};
} /* end ast */

#endif /* __WHILE_NODE_H__ */

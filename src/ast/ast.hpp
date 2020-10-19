#ifndef __AST_H__
#define __AST_H__

#include "node.hpp"

namespace ast {
class ASTNode : public Node {
public:
  ASTNode(Location* l, Declarations* d);
  ASTNode(Declarations* d);
  virtual ~ASTNode();

  void AddDeclarations(Declarations* decl);
private:
  Location* location_;
  Declarations* declarations_;
  ToplLevelScope* scope_;
  ConstantTable* constant_table_;
};
} /* end ast */

#endif /* __AST_H__ */

#ifndef __DEFINED_VARIABLE_H__
#define __DEFINED_VARIABLE_H__

#include "variable.h"
#include "../ast/expr/expr_node.hpp"
#include "../ast/dumper.h"

namespace entity {
class DefinedVariable : public Variable {
public:
  DefinedVariable(bool priv, ast::TypeNode* tn, std::string n, ast::ExprNode* init);
  virtual ~DefinedVariable();

  static long TmpSeq;
  static DefinedVariable* Tmp(type::Type* t);

  bool IsDefined();
  void SetSequence(long seq);
  long sequence();
  std::string SymbolString();
  bool HasInitializer();
  bool IsInitialized();
  ast::ExprNode* initializer();
  void SetInitializer(ast::ExprNode* init);

  // void SetIR(ir::Expr* ir);
  // ir::Expr* ir();
  
  void _dump(ast::Dumper* d);
  // void accept();
private:
  ast::ExprNode* initializer_;
  // ir::Expr* ir_;     // @todo { do not implement ir so far }
  long sequence_;
  // Symbol symbol_;
};
} /* end entity */

#endif /* __DEFINED_VARIABLE_H__ */

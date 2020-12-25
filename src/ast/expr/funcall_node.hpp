#ifndef __FUNCALL_NODE_H__
#define __FUNCALL_NODE_H__

#include "expr_node.hpp"
#include "../../type/function_type.hpp"

#include <vector>

namespace ast {
class FuncallNode : public ExprNode {
public:
  FuncallNode(ExprNode *expr, std::vector<ExprNode *> args);
  virtual ~FuncallNode();

  ExprNode* expr();
  type::Type* type();
  type::FunctionType* GetFunctionType();
  long NumOfArgs();
  std::vector<ExprNode *> args();

  // void ReplaceArgs(std::vector<ExprNode*> args);  // called by TypeChecker

  Location* location();
  std::string GetClass();
  void _dump(Dumper* d);

  void Accept(ASTVisitor * visitor);
private:
  ExprNode* expr_;              // function name expression
  std::vector<ExprNode*> args_; // arguments
};
} /* end ast */

#endif /* __FUNCALL_NODE_H__ */

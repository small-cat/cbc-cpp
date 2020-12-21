#ifndef __DEFINED_FUNCTION_H__
#define __DEFINED_FUNCTION_H__

#include <vector>
#include "../ast/type/type_node.hpp"
#include "../ast/stmt/block_node.hpp"
#include "../ast/dumper.h"
#include "local_scope.h"

#include "params.h"
#include "function.h"

namespace entity {
class DefinedFunction : public Function {
public:
  DefinedFunction(bool priv, ast::TypeNode* tn, std::string n, Params* params, ast::BlockNode* body);
  virtual ~DefinedFunction();

  bool IsDefined();
  std::vector<Parameter*> GetParameters();
  ast::BlockNode* body();

  // std::vector<ir:Stmt*> ir();
  // void SetIR(std::vector<ir::Stmt*> ir);

  LocalScope* scope();
  void SetScope(LocalScope* sp);

  std::vector<DefinedVariable*> GetLocalVariables();
  void _dump(ast::Dumper* d);
  std::string GetClass();
  // void accept();
private:
  Params* params_;
  ast::BlockNode* body_;
  LocalScope* scope_;
  // std::vector<ir::Stmt*> ir_;   // todo ir
};
} /* end entity */

#endif /* __DEFINED_FUNCTION_H__ */

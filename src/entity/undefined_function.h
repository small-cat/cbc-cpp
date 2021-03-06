#ifndef __UNDEFINED_FUNCTION_H__
#define __UNDEFINED_FUNCTION_H__

#include "function.h"

namespace entity {
class UndefinedFunction : public Function {
public:
  UndefinedFunction(ast::TypeNode* t, std::string n, Params* params) : Function(false, t, n), params_(params) {}
  virtual ~UndefinedFunction() {}

  std::vector<Parameter*> GetParameters() { return params_->GetParameters(); }

  bool HasParameters() { 
    return !params_->IsParamsEmpty();
  }

  bool IsDefined() { return false; }

  void _dump(ast::Dumper* d) {
    d->PrintMember("Name", name());
    d->PrintMember("IsPrivate", is_private());
    d->PrintMember("TypeNode", type_node());
    d->PrintMember("Parameters", params_);
  }
  std::string GetClass() { return "UndefinedFunction"; }
  virtual void Accept(ast::ASTVisitor *visitor) { visitor->Visit(this); }
private:
  Params* params_;
};
} /* end entity */

#endif /* __UNDEFINED_FUNCTION_H__ */

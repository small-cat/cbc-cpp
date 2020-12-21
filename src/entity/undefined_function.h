#ifndef __UNDEFINED_FUNCTION_H__
#define __UNDEFINED_FUNCTION_H__

#include "function.h"

namespace entity {
class UndefinedFunction : public Function {
public:
  UndefinedFunction(ast::TypeNode* t, std::string n, Params* params) : Function(false, t, n), params_(params) {}
  virtual ~UndefinedFunction() {}

  std::vector<Parameter*> GetParameters() { return params_->GetParameters(); }
  bool IsDefined() { return false; }

  // @todo { not implement _dump accept }
  void _dump(ast::Dumper* d) {
    d->PrintMember("Name", name());
    d->PrintMember("IsPrivate", is_private());
    d->PrintMember("TypeNode", type_node());
    d->PrintMember("Parameters", params_);
  }
  std::string GetClass() { return "UndefinedFunction"; }
  // void accept();
private:
  Params* params_;
};
} /* end entity */

#endif /* __UNDEFINED_FUNCTION_H__ */

#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#include "defined_variable.h"

namespace entity {
class Parameter : public DefinedVariable {
public:
  Parameter(ast::TypeNode* tn, std::string n) : DefinedVariable(false, tn, n, nullptr) {}
  virtual ~Parameter() {}

  bool IsParameter() { return true; }
  void _dump(ast::Dumper* d) {
    d->PrintMember("Name", name());
    d->PrintMember("TypeNode", type_node());
  }

  std::string GetClass() { return "Parameter"; }
};
} /* end entity */

#endif /* __PARAMETER_H__ */

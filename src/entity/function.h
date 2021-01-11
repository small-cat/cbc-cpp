#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <vector>

#include "entity.h"
#include "../type/type.hpp"
#include "parameter.h"

namespace entity {
class Function : public Entity {
public:
  Function(bool priv, ast::TypeNode* tn, std::string n);
  virtual ~Function();

  bool IsInitialized();
  virtual bool IsDefined();
  virtual std::vector<Parameter*> GetParameters() = 0;
  virtual bool HasParameters() { return false; }

  type::Type* ReturnType();
  bool IsVoid();
  std::string GetClass();

  virtual void _dump(ast::Dumper* d);

  // @todo { not implement calling symbol and label in Function }
  // void SetCallingSymbol(Symbol* s);
  // Symbol calling_symbol();
  // Label label();
//private:
  // Symbol* calling_symbol_;
  // Label* label_;
};
} /* end entity */

#endif /* __FUNCTION_H__ */

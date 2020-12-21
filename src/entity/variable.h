#ifndef __VARIABLE_H__
#define __VARIABLE_H__

#include "entity.h"

namespace entity {
class Variable : public Entity {
public:
  Variable(bool priv, ast::TypeNode* tn, std::string n) : Entity(priv, tn, n) {}
  virtual ~Variable() {}
  
  std::string GetClass() { return "Variable"; }
};
} /* end entity */

#endif /* __VARIABLE_H__ */

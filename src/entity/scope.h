#ifndef __SCOPE_H__
#define __SCOPE_H__

#include <vector>
#include <string>

#include "entity.h"

namespace entity {

class LocalScope;
class TopLevelScope;

class Scope {
public:
  Scope() {}
  virtual ~Scope() {}

  virtual bool IsTopLevel() = 0;
  virtual TopLevelScope* GetTopLevelScope() = 0;
  virtual Scope* GetParent() = 0;
  virtual Entity* Get(std::string n) = 0;

  void AddChildren(LocalScope* s) { children_.push_back(s); }
  std::vector<LocalScope*> children() { return children_; }
private:
  std::vector<LocalScope*> children_;
};
} /* end entity */

#endif /* __SCOPE_H__ */

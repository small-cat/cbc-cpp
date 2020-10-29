#ifndef __TOP_LEVEL_SCOPE_H__
#define __TOP_LEVEL_SCOPE_H__

#include <string>
#include <vector>
#include <map>

#include "defined_variable.h"
#include "scope.h"
#include "../utils/error_handler.h"

namespace entity {
class TopLevelScope : public Scope {
public:
  TopLevelScope();
  virtual ~TopLevelScope();

  bool IsTopLevel();
  TopLevelScope* GetTopLevelScope();
  Scope* GetParent();

  // declare or define variable and function globally
  void DeclareOrDefineEntity(Entity* e);

  Entity* Get(std::string n);

  // returns a list of all global vars
  // in TopLevelScope, vars regardes as global 
  std::vector<Variable*> AllGlobalVariables();
  std::vector<DefinedVariable*> DefinedGlobalScopeVariables();
  std::vector<DefinedVariable*> StaticLocalVariables();

  void CheckReferences(utils::ErrorHandler* h);
private:
  std::map<std::string, Entity*> entities_;
  std::vector<DefinedVariable*> static_local_variables_;
};
} /* end entity */

#endif /* __TOP_LEVEL_SCOPE_H__ */

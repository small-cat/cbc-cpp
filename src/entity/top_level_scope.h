#ifndef __TOP_LEVEL_SCOPE_H__
#define __TOP_LEVEL_SCOPE_H__

#include <string>
#include <vector>
#include <map>

#include "entity.h"
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
  void DeclareEntity(Entity* e);
  void DefineEntity(Entity* e);

  Entity* Get(std::string n);

  std::vector<Variable*> AllGlobalVariables();
  std::vector<DefinedVariable*> DefinedGlobalScopeVariables();
  std::vector<DefinedVariable*> StaticLocalVariables();

  void CheckReferences(utils::ErrorHandler* h);
private:
  std::map<std::string, Entity*> entities_;   // 全局变量符号表(变量和函数)，全局变量名称及其定义的映射关系
  std::vector<DefinedVariable*> static_local_variables_;
};
} /* end entity */

#endif /* __TOP_LEVEL_SCOPE_H__ */

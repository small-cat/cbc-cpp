#ifndef __LOCAL_SCOPE_H__
#define __LOCAL_SCOPE_H__

#include <map>

#include "scope.h"
#include "defined_variable.h"
#include "../utils/error_handler.h"
#include "../type/type.hpp"

namespace entity {
class LocalScope : public Scope {
public:
  LocalScope(Scope* s);
  virtual ~LocalScope();

  bool IsTopLevel();
  TopLevelScope* GetTopLevelScope();
  Scope* GetParent();
  std::vector<LocalScope*> GetChildren();
  bool IsDefinedLocally(std::string n);
  void DefineVariable(DefinedVariable* var);

  DefinedVariable* AllocateTmp(type::Type* t);
  Entity* Get(std::string n);

  // return all local vars without static local vars
  std::vector<DefinedVariable*> AllLocalVariables();

  // return all local vars without children's local vars and static local vars
  std::vector<DefinedVariable*> LocalVariables();

  // return all static local vars
  std::vector<DefinedVariable*> StaticLocalVariables();

  // return all children's scopes
  std::vector<LocalScope*> AllLocalScopes();
  void CollectScope(std::vector<LocalScope*>& buf);

  void CheckReferences(utils::ErrorHandler* h);
  std::map<std::string, DefinedVariable*> variables();
private:
  Scope* parent_;
  std::map<std::string, DefinedVariable*> variables_;
};
} /* end entity */

#endif /* __LOCAL_SCOPE_H__ */

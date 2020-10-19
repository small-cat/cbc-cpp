/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : declarations.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-24
 * @brief : declarations def
*/
#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__

#include <string>
#include <vector>

namespace ast {
class Declarations {
public:
  Declarations();
  virtual ~Declarations();

  std::vector<TypedefNode*> typedefs();
  void AddDefvar(DefinedVariable* var);
  void AddDefvars(std::vector<DefinedVariable*> vars);
  std::vector<DefinedVariable*> defvars();

  void AddDefun(DefinedFunction* fun);
  void AddConstant(Constant* cons);
  void AddStruct(StructTypeNode* s);
  void AddUnion(UnionTypeNode* u);
  void AddTypedef(TypedefNode* t);

private:
  std::vector<DefinedVariable*> defvars_;
  std::vector<UndefinedVariable*> vardecls_;
  std::vector<DefinedFunction*> defuns_;
  std::vector<UndefinedFunction*> funcdecls_;
  std::vector<Constant*> constants_;
  std::vector<StructTypeNode*> def_structs_;
  std::vector<UnionTypeNode*> def_unions_;
  std::vector<TypedefNode*> typedefs_;
};
} /* end ast */

#endif /* __DECLARATIONS_H__ */

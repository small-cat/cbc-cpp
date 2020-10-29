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

#include "type/type_node.hpp"
#include "type/typedef_node.hpp"
#include "type/struct_node.hpp"
#include "type/union_node.hpp"

#include "../entity/defined_variable.h"
#include "../entity/defined_function.h"
#include "../entity/constant.hpp"
#include "../entity/undefined_function.h"
#include "../entity/undefined_variable.h"

namespace ast {
class Declarations {
public:
  Declarations();
  virtual ~Declarations();

  std::vector<TypeDefNode*> typedefs();
  void AddDefvar(entity::DefinedVariable* var);
  void AddDefvars(std::vector<entity::DefinedVariable*> vars);
  std::vector<entity::DefinedVariable*> defvars();

  void AddDefun(entity::DefinedFunction* fun);
  void AddConstant(entity::Constant* cons);
  void AddStruct(ast::StructTypeNode* s);
  void AddUnion(ast::UnionTypeNode* u);
  void AddTypedef(TypeDefNode* t);

private:
  std::vector<entity::DefinedVariable*> defvars_;
  std::vector<entity::UndefinedVariable*> vardecls_;
  std::vector<entity::DefinedFunction*> defuns_;
  std::vector<entity::UndefinedFunction*> funcdecls_;
  std::vector<entity::Constant*> constants_;
  std::vector<StructTypeNode*> def_structs_;
  std::vector<UnionTypeNode*> def_unions_;
  std::vector<TypeDefNode*> typedefs_;
};
} /* end ast */

#endif /* __DECLARATIONS_H__ */

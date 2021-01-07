/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: local_resolver.h
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/24
* @brief: variable resolver. bind referenced ast::VariableNode with its definition entity::Variable.
*         将在表达式或者赋值语句中引用的变量与其定义绑定起来，确定其作用域
*/
#ifndef __LOCAL_RESOLVER_H__
#define __LOCAL_RESOLVER_H__

#include <vector>

#include "visitor.h"
#include "entity/scope.h"
#include "entity/local_scope.h"
#include "entity/top_level_scope.h"
#include "entity/constant_table.hpp"
#include "entity/parameter.h"
#include "utils/error_handler.h"

#include "ast/ast.hpp"
#include "type/param_slots.hpp"

namespace compiler {
class LocalResolver : public Visitor {
public:
  LocalResolver(utils::ErrorHandler * err);
  virtual ~LocalResolver();

  void Resolve(ast::StmtNode * node);
  void Resolve(ast::ExprNode * expr);
  void Resolve(ast::ASTNode * ast);
  void ResolveGlobalVarInitializers(std::vector<entity::DefinedVariable *> gvars);
  void ResolveConstantValues(std::vector<entity::Constant *> constants);
  void ResolveFunctions(std::vector<entity::DefinedFunction *> funcs);

  void Visit(ast::BlockNode * node);
  void Visit(ast::StringLiteralNode * node);
  void Visit(ast::VariableNode * node);
  void PushScope(std::vector<entity::DefinedVariable *> vars);
  void PushScope(std::vector<entity::Parameter *> params);
  void PushScope(entity::DefinedVariable * var, entity::LocalScope* ls);
  entity::LocalScope* PopScope();
  entity::Scope* GetCurrentScope();
private:
  std::vector<entity::Scope *> scope_stack_;    // 保存作用于的变量，也称为符号表 symbol table
  entity::ConstantTable * constant_table_;
  utils::ErrorHandler * err_handler_;

  type::ParamSlotsTracker<entity::Scope> scope_tracker_;
};
} /* compiler */

#endif
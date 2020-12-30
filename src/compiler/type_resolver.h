/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: type_resolver.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/30
 * @brief: 类型的消解，将 ast 中所有的 TypeRef 全部转换成 Type
*/
#ifndef __TYPE_RESOLVER_H__
#define __TYPE_RESOLVER_H__

#include "visitor.h"
#include "../utils/error_handler.h"

#include "../type/type_table.h"
#include "../ast/ast.hpp"
#include "../ast/type/type_definition_node.hpp"

namespace compiler {
class TypeResolver : public Visitor {
public:
  TypeResolver(type::TypeTable *tb, utils::ErrorHandler *err);
  virtual ~TypeResolver();

  void Resolve(ast::ASTNode *ast);
  void AddDefineTypes(std::vector<ast::TypeDefinitionNode *> deftypes);
  void BindType(ast::TypeNode *node);

  // ast
  void Visit(ast::StructTypeNode *node);
  void Visit(ast::UnionTypeNode *node);
  void Visit(ast::TypeDefNode *node);
  void ResolveCompositeType(ast::CompositeTypeDefinitionNode *def);

  // expression
  void Visit(ast::BlockNode *node);
  void Visit(ast::CastNode *node);
  void Visit(ast::SizeofExprNode *node);
  void Visit(ast::SizeofTypeNode *node);
  void Visit(ast::StringLiteralNode *node);
  void Visit(ast::IntegerLiteralNode *node);

  // entities
  void Visit(entity::DefinedVariable *var);
  void Visit(entity::UndefinedVariable *var);
  void Visit(entity::DefinedFunction *func);
  void Visit(entity::UndefinedFunction *func);
  void Visit(entity::Constant *c);
  void ResolveFunctionHeader(entity::Function *func);
private:
  type::TypeTable *type_table_;
  utils::ErrorHandler *err_handler_;
};
} /* compiler */

#endif
/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: type_resolver.cpp
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/30
 * @brief: AddDefineTypes 和 BindType 都会添加新的 Type 到 TypeTable 中
*/
#include "type_resolver.h"

namespace compiler {
TypeResolver::TypeResolver(type::TypeTable *tb, utils::ErrorHandler *err) : type_table_(tb), err_handler_(err) {}
TypeResolver::~TypeResolver() {}

void TypeResolver::Resolve(ast::ASTNode *ast) {
  auto all_types = ast->GetAllTypes();
  AddDefineTypes(all_types);

  for (auto t : all_types) {
    t->Accept(this);
  }

  for (auto ent : ast->GetAllEntities()) {
    ent->Accept(this);
  }
}

/************************************************************************************
* @fn AddDefineTypes
* @brief 添加聚合类型到 TypeTable 中
* @param
* @author Jona
* @date 2020/12/30
************************************************************************************/
void TypeResolver::AddDefineTypes(std::vector<ast::TypeDefinitionNode *> deftypes) {
  for (auto def_t : deftypes) {

    // deftypes 包含 struct，union 和 typedef 的用户类型， struct 和 union 按照 TypeRef 在
    // table 中可作为key直接识别，但是 typedef 的用户类型，首先需要检测 realtype 是否存在，然后
    // 再检测用户自定义的类型名称是否存在，因为同一个类型可以有多个 typedef 的类型申明
    if(type_table_->IsDefined(def_t->TypeRef())) {
      // 目前 type table 记录的是类型名称与类型定义的映射，暂时无法知道第一次定义的位置
      // 作为改进的目标，后续可以加上 TODO
      auto first_def_tr = type_table_->GetTypeRef(def_t->TypeRef());
      err_handler_->Error(def_t->location(), 
                          "duplicated type definition: " + def_t->name() + ", first defined at " 
                          + first_def_tr->location()->ToString());
    } else {
      type_table_->AddType(def_t->TypeRef(), def_t->DefiningType());
    }
  }
}

void TypeResolver::BindType(ast::TypeNode *node) {
  if (node->IsResolved()) {
    return;
  }

  node->SetType(type_table_->GetType(node->type_ref()));
}

void TypeResolver::Visit(ast::StructTypeNode *node) {
  ResolveCompositeType(node);
}

void TypeResolver::Visit(ast::UnionTypeNode *node) {
  ResolveCompositeType(node);
}

void TypeResolver::Visit(ast::TypeDefNode *node) {
  BindType(node->type_node());
  BindType(node->RealTypeNode());
}

void TypeResolver::ResolveCompositeType(ast::CompositeTypeDefinitionNode *node) {
  type::CompositeType* ct = (type::CompositeType *)type_table_->GetType(node->type_node()->type_ref());
  if (nullptr == ct) {
    err_handler_->Error(node->location(), "can not intern composite type: " + node->name());
  }

  for (auto m : ct->members()) {
    BindType(m->type_node());
  }
}

// expression
/************************************************************************************
* @fn Visit
* @brief 遍历 ast，对所有含有 TypeRef 的节点进行处理，也就是说，在遍历过程中，对包含有 TypeRef
         的节点的访问，都会在当前 TypeResolver 这个 visitor 中进行重写，然后处理
         这样的节点有 DefinedFunction, UndefinedFunction, DefinedVariable, UndefinedVariable,
         Constant, StructTypeNode, UnionTypeNode, TypeDefNode, expression
* @param
* @author Jona
* @date 2020/12/30
************************************************************************************/
void TypeResolver::Visit(ast::BlockNode *node) {
  for (auto v : node->variables()) {
    v->Accept(this);
  }

  VisitStmts(node->stmts());
}

void TypeResolver::Visit(ast::CastNode *node) {
  BindType(node->type_node());
  VisitExpr(node->expr());
}

void TypeResolver::Visit(ast::SizeofExprNode *node) {
  BindType(node->type_node());
  VisitExpr(node->expr());
}

void TypeResolver::Visit(ast::SizeofTypeNode *node) {
  BindType(node->type_node());
  BindType(node->OperandTypeNode());
}

void TypeResolver::Visit(ast::StringLiteralNode *node) {
  BindType(node->type_node());
}

void TypeResolver::Visit(ast::IntegerLiteralNode *node) {
  BindType(node->type_node());
}

void TypeResolver::Visit(entity::DefinedVariable *var) {
  BindType(var->type_node());
  if (var->HasInitializer()) {
    VisitExpr(var->initializer());
  }
}

void TypeResolver::Visit(entity::UndefinedVariable *var) {
  BindType(var->type_node());
}

void TypeResolver::Visit(entity::DefinedFunction *func) {
  ResolveFunctionHeader(func);
  VisitStmt(func->body());
}

void TypeResolver::Visit(entity::UndefinedFunction *func) {
  ResolveFunctionHeader(func);
}

void TypeResolver::Visit(entity::Constant *c) {
  BindType(c->type_node());
  VisitExpr(c->value());
}

void TypeResolver::ResolveFunctionHeader(entity::Function *func) {
  BindType(func->type_node());
  if (func->HasParameters()) {
    for (auto &param : func->GetParameters()) {
      // arrays must be converted to pointers in function parameters
      type::Type *t = type_table_->GetParamType(param->type_node()->type_ref());
      param->type_node()->SetType(t);   // 在函数的时候，函数名作为 VariableNode 的时候，SetType 出了问题
    }
  }
}

} /* compiler */
#include "local_resolver.h"

namespace compiler {
LocalResolver::LocalResolver(utils::ErrorHandler * err) : err_handler_(err) {
  scope_stack_.clear();
  constant_table_ = new entity::ConstantTable();
}

LocalResolver::~LocalResolver() {
  if (constant_table_ != nullptr) {
    delete constant_table_;
    constant_table_ = nullptr;
  }

  scope_tracker_.Reset();
}

void LocalResolver::Resolve(ast::StmtNode * node) {
  node->Accept(this);
}

void LocalResolver::Resolve(ast::ExprNode * expr) {
  expr->Accept(this);
}

void LocalResolver::Resolve(ast::ASTNode * ast) {
  entity::TopLevelScope* top_scope = scope_tracker_.CreateInstance<entity::TopLevelScope>();
  scope_stack_.push_back(top_scope);

  // 将顶层作用域中的所有申明的变量或者函数加入到符号表中，TopLevelScope 就是符号表
  for (auto& e : ast->DeclarationEntities()) {
    top_scope->DeclareEntity(e);
  }

  // 检查所有的定义
  for (auto& e : ast->DefinitionEntities()) {
    top_scope->DefineEntity(e);
  }

  // variable, function and constant resolving
  // 将全局变量的引用与定义进行绑定，将常量引用与其定义进行绑定，将函数与其定义进行绑定
  ResolveGlobalVarInitializers(ast->DefinedVariables());
  ResolveConstantValues(ast->GetConstants());
  ResolveFunctions(ast->DefinedFunctions());

  // 检查变量是否有未使用的变量
  top_scope->CheckReferences(err_handler_);
  if (err_handler_->ErrorOccured()) {
    err_handler_->Error("Compiler Failed");
    exit(EXIT_FAILURE);
  }

  ast->SetScope(top_scope);
  ast->SetConstantTable(constant_table_);
}

/************************************************************************************
* @fn ResolveGlobalVarInitializers
* @brief resolve global variables, bind its reference with definitions
* @param
* @author Jona
* @date 2020/12/25
************************************************************************************/
void LocalResolver::ResolveGlobalVarInitializers(std::vector<entity::DefinedVariable *> gvars) {
  for (auto& gv : gvars) {
    if (gv->HasInitializer()) {
      Resolve(gv->initializer());
    }
  }
}

void LocalResolver::ResolveConstantValues(std::vector<entity::Constant *> constants) {
  for (auto& c : constants) {
    Resolve(c->value());
  }
}

/************************************************************************************
* @fn ResolveFunctions
* @brief 
* @param
* @author Jona
* @date 2020/12/25
************************************************************************************/
void LocalResolver::ResolveFunctions(std::vector<entity::DefinedFunction *> funcs) {
  for (auto& f : funcs) {
    if (f->HasParameters()) {
      PushScope(f->GetParameters());
    }
    Resolve(f->body());
    f->SetScope(PopScope());
  }
}

void LocalResolver::Visit(ast::BlockNode* node) {
  PushScope(node->variables());

  for (auto def_var : node->variables()) {
    if (def_var->HasInitializer()) {
      VisitExpr(def_var->initializer());
    }
  }

  VisitStmts(node->stmts());

  node->SetScope(PopScope());
}

/************************************************************************************
* @fn Visit
* @brief 字符串常量的处理，在字符串常量符号表中进行查找和插入
* @param
* @author Jona
* @date 2020/12/25
************************************************************************************/
void LocalResolver::Visit(ast::StringLiteralNode *node) {
  node->SetEntry(constant_table_->Intern(node->value()));
}

void LocalResolver::Visit(ast::VariableNode* node) {
  // 从当前作用域（符号表）开始查找变量定义，如果当前没有，就通过当前作用域的父节点往上查找，直到找到为止
  // 否则，该变量就是未定义的变量。
  entity::Entity* ent = GetCurrentScope()->Get(node->name());
  if (nullptr == ent) {
    err_handler_->Error(node->location(), "unresolved reference: " + node->name());
    exit(EXIT_FAILURE);
  }

  ent->refered(); // inc reference count
  node->SetEntity(ent);
}

void LocalResolver::PushScope(std::vector<entity::DefinedVariable *> vars) {
  entity::LocalScope* ls = scope_tracker_.CreateInstance<entity::LocalScope>(GetCurrentScope());
  for (auto& v : vars) {
    PushScope(v, ls);
  }

  scope_stack_.push_back(ls);
}

void LocalResolver::PushScope(std::vector<entity::Parameter *> params) {
  entity::LocalScope* ls = scope_tracker_.CreateInstance<entity::LocalScope>(GetCurrentScope());
  for (auto& p : params) {
    PushScope(p, ls);
  }

  scope_stack_.push_back(ls);
}

void LocalResolver::PushScope(entity::DefinedVariable* var, entity::LocalScope* ls) {
  ls->DefineVariable(var);
}

entity::Scope* LocalResolver::GetCurrentScope() {
  return scope_stack_.back();
}

entity::LocalScope* LocalResolver::PopScope() {
  entity::LocalScope* ls = (entity::LocalScope *)(scope_stack_.back());
  scope_stack_.pop_back();
  return ls;
}

} /* compiler */
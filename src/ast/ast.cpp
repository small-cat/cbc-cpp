#include "ast.hpp"

namespace ast {

ASTNode::ASTNode(Location* l, Declarations* d) : location_(l), declarations_(d) {
}

ASTNode::ASTNode(Declarations* d) : declarations_(d) {}

ASTNode::~ASTNode() {
  if(nullptr != declarations_) {
    delete declarations_;
    declarations_ = nullptr;
  }

  if (nullptr != scope_) {
    delete scope_;
    scope_ = nullptr;
  }

  if (nullptr != constant_table_) {
    delete constant_table_;
    constant_table_ = nullptr;
  }
}

Location* ASTNode::location() {
  return location_;
}

void ASTNode::AddDeclarations(Declarations* decl) {
  // @todo {  things to be done }
  // add defvars defuncs, constants, structs unions typedefs
}

void ASTNode::SetTokenStrings(std::vector<std::string> sv) {
  token_strings_.swap(sv);
}

void ASTNode::DumpTokens() {
  for (auto& t : token_strings_) {
    std::cout << t << std::endl;
  }
}

void ASTNode::DumpAst(Dumper* d) {
  d->PrintNodeList("variables", declarations_->defvars());
  d->PrintNodeList("functions", declarations_->defuns());
}

std::string ASTNode::GetClass() { return ""; }

std::vector<entity::Entity *> ASTNode::DeclarationEntities() {
  std::vector<entity::Entity *> entities;
  for (auto& v : declarations_->funcdecls()) {
    entities.push_back(v);
  }

  for (auto& f : declarations_->vardecls()) {
    entities.push_back(f);
  }

  return entities;
}

/************************************************************************************
* @fn DefinitionEntities
* @brief 返回所有的定义，变量，函数，常量
* @param
* @author Jona
* @date 2020/12/25
************************************************************************************/
std::vector<entity::Entity *> ASTNode::DefinitionEntities() {
  std::vector<entity::Entity *> entities;
  for (auto& v : declarations_->defvars()) {
    entities.push_back(v);
  }

  for (auto& f : declarations_->defuns()) {
    entities.push_back(f);
  }

  for (auto& c : declarations_->constants()) {
    entities.push_back(c);
  }

  return entities;
}

std::vector<entity::DefinedVariable *> ASTNode::DefinedVariables() {
  return declarations_->defvars();
}

std::vector<entity::DefinedFunction *> ASTNode::DefinedFunctions() {
  return declarations_->defuns();
}

std::vector<entity::Constant *> ASTNode::GetConstants() {
  return declarations_->constants();
}

void ASTNode::SetScope(entity::TopLevelScope* top_scope) {
  scope_ = top_scope;
}

void ASTNode::SetConstantTable(entity::ConstantTable* tb) {
  // 拷贝构造函数，这样 ast 与 local_resolver 之间的 constant table 就不会相互影响了
  // local_resolver 即使释放了也不会影响
  constant_table_ = new entity::ConstantTable(*tb);
}

} /* end as */

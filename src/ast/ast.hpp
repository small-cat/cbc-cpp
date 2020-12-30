#ifndef __AST_H__
#define __AST_H__

#include <iostream>
#include <vector>

#include "node.hpp"
#include "declarations.hpp"
#include "location.hpp"

#include "../entity/top_level_scope.h"
#include "../entity/constant.hpp"
#include "../entity/constant_table.hpp"
#include "dumper.h"

namespace ast {
class ASTNode : public Node {
public:
  ASTNode(Location* l, Declarations* d);
  ASTNode(Declarations* d);
  virtual ~ASTNode();

  Location* location();
  void AddDeclarations(Declarations* decl);
  std::vector<entity::Entity *> DeclarationEntities();
  std::vector<entity::Entity *> DefinitionEntities();
  std::vector<entity::DefinedVariable *> DefinedVariables();
  std::vector<entity::DefinedFunction *> DefinedFunctions();
  std::vector<entity::Constant *> GetConstants();

  void SetTokenStrings(std::vector<std::string> sv);
  void DumpTokens();
  void DumpAst(Dumper* d);
  virtual std::string GetClass();

  void SetScope(entity::TopLevelScope* top_scope);
  void SetConstantTable(entity::ConstantTable* tb);

  std::vector<TypeDefinitionNode *> GetAllTypes();
  std::vector<entity::Entity *> GetAllEntities();
private:
  Location* location_;
  Declarations* declarations_;
  entity::TopLevelScope* scope_;
  entity::ConstantTable* constant_table_;
  std::vector<std::string> token_strings_;
};
} /* end ast */

#endif /* __AST_H__ */

#include "top_level_scope.h"
#include "../utils/cpp_utils.hpp"
#include "local_scope.h"

#include <stdlib.h>
#include <iostream>

namespace entity {
TopLevelScope::TopLevelScope() {}
TopLevelScope::~TopLevelScope() {}

bool TopLevelScope::IsTopLevel() {
  return true;
}

TopLevelScope* TopLevelScope::GetTopLevelScope() {
  return this;
}

Scope* TopLevelScope::GetParent() {
  return nullptr;
}

/************************************************************************************
* @fn DeclareOrDefineEntity
* @brief 在符号表中查找，该符号表保存的是所有的全局变量定义或者申明。
* @param
* @author Jona
* @date 2020/12/25
************************************************************************************/
void TopLevelScope::DeclareEntity(Entity* e) {
  auto search = entities_.find(e->name());
  if (search != entities_.end()) {
    std::cout << "duplicated declaration: " << e->name() << ": " <<
      search->second->GetLocation()->ToString() << " and " << e->GetLocation()->ToString() << std::endl;
    exit(EXIT_FAILURE);
  }

  entities_.emplace(std::make_pair(e->name(), e));
}

void TopLevelScope::DefineEntity(Entity* e) {
  auto search = entities_.find(e->name());
  if (search != entities_.end() && search->second->IsDefined()) {
    std::cout << "duplicated declaration: " << e->name() << ": " <<
      search->second->GetLocation()->ToString() << " and " << e->GetLocation()->ToString() << std::endl;
    exit(EXIT_FAILURE);
  }

  entities_.emplace(std::make_pair(e->name(), e));
}

Entity* TopLevelScope::Get(std::string n) {
  auto search = entities_.find(n);
  if (search == entities_.end()) {
    return nullptr;
  }

  return search->second;
}

/************************************************************************************
* @fn AllGlobalVariables
* @brief 返回所有的全局变量定义，在顶层作用域 TopLevelScope 中
* @param
* @author Jona
* @date 2020/12/24
************************************************************************************/
std::vector<Variable*> TopLevelScope::AllGlobalVariables() {
  std::vector<Variable*> result;
  for (auto iter = entities_.begin(); iter != entities_.end(); iter++) {
    if (utils::is<Variable*>(iter->second)) {
      result.push_back((Variable*)(iter->second));
    }
  }

  return result;
}

/************************************************************************************
* @fn DefinedGlobalScopeVariables
* @brief 返回所有的全局变量，在顶层作用域中的全局变量
* @param
* @author Jona
* @date 2020/12/25
************************************************************************************/
std::vector<DefinedVariable*> TopLevelScope::DefinedGlobalScopeVariables() {
  std::vector<DefinedVariable*> result;
  for (auto iter = entities_.begin(); iter != entities_.end(); iter++) {
    if (utils::is<DefinedVariable*>(iter->second)) {
      result.push_back((DefinedVariable*)(iter->second));
    }
  }

  for (auto& dv : StaticLocalVariables()) {
    result.push_back(dv);
  }

  return result;
}

// get all children's static local vars
std::vector<DefinedVariable*> TopLevelScope::StaticLocalVariables() {
  if (static_local_variables_.empty()) {
    for (auto& ls : children()) {
      for (auto& dv : ls->StaticLocalVariables()) {
        static_local_variables_.push_back(dv);
      }
    }

    std::map<std::string, long> seqTable;
    for (auto& dv : static_local_variables_) {
      auto search = seqTable.find(dv->name());
      if (search == seqTable.end()) {
        dv->SetSequence(0);
        seqTable.emplace(std::make_pair(dv->name(), 1));
      } else {
        long seq = search->second;
        dv->SetSequence(seq);
        seqTable[dv->name()] = seq + 1; 
      }
    }
  }

  return static_local_variables_;
}

void TopLevelScope::CheckReferences(utils::ErrorHandler* h) {
  for (auto iter = entities_.begin(); iter != entities_.end(); iter++) {
    auto ent = iter->second;
    if (ent->IsDefined() &&
        ent->is_private() &&
        !ent->IsConstant() &&
        !ent->IsRefered()) {
      h->Warn(ent->GetLocation(), "unused variable: " + ent->name());
    }
  }

  // don't check parameters
  for (auto ls : children()) {
    ls->CheckReferences(h);
  }
}

} /* end entity */

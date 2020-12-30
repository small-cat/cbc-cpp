#include "local_scope.h"
#include <iostream>

namespace entity {
LocalScope::LocalScope(Scope* s) : parent_(s) {
  parent_->AddChildren(this);
}

LocalScope::~LocalScope() {
  parent_ = nullptr;
  variables_.clear();

  for (auto& child : children()) {
    if (child != nullptr) {
      delete child;
      child = nullptr;
    }
  }
}

bool LocalScope::IsTopLevel() {
  return false;
}

TopLevelScope* LocalScope::GetTopLevelScope() {
  return parent_->GetTopLevelScope();
}

Scope* LocalScope::GetParent() {
  return parent_;
}

std::vector<LocalScope*> LocalScope::GetChildren() {
  return children();
}

entity::DefinedVariable* LocalScope::IsDefinedLocally(std::string n) {
  auto search = variables_.find(n);
  if (search == variables_.end()) {
    return nullptr;
  } else {
    return search->second;
  }
}

void LocalScope::DefineVariable(DefinedVariable* var) {
  auto ent = IsDefinedLocally(var->name());
  if (nullptr != ent) {
    std::cout << var->name() << "defined duplicated, first defined at " << ent->GetLocation()->ToString() << std::endl;
    exit(EXIT_FAILURE);
  }

  variables_.emplace(std::make_pair(var->name(), var));
}

DefinedVariable* LocalScope::AllocateTmp(type::Type* t) {
  // @todo { AllocateTmp }
  return nullptr;
}

/************************************************************************************
* @fn Get
* @brief 从作用域中查找变量定义，该作用域也就是符号表.此处符号表作用域的处理方法，每一次均保留了之前
         的完整作用域范围，且没有破坏，属于数式子风格的符号表,见 《现代编译原理c语言描述 5.1.5》
* @param
* @author Jona
* @date 2020/12/25
************************************************************************************/
Entity* LocalScope::Get(std::string n) {
  auto search = variables_.find(n);
  if (search == variables_.end()) {
    return parent_->Get(n);
  } else {
    return search->second;
  }
}

/**
 * @fn AllLocalVariables
 * @brief return all local vars in this scope 
 * @param 
 * @author Jona
 * @date 27/10/2020 20:13:13 
*/ 
std::vector<DefinedVariable*> LocalScope::AllLocalVariables() {
  std::vector<DefinedVariable*> result;
  for (auto& s : AllLocalScopes()) {
    auto vars = s->variables();
    for (auto iter = vars.begin(); iter != vars.end(); iter++) {
      result.push_back(iter->second);
    }
  }

  return result;
}

/**
 * @fn LocalVariables
 * @brief return all local vars in this scope without static local vars
 * @param 
 * @author Jona
 * @date 27/10/2020 20:23:10 
*/ 
std::vector<DefinedVariable*> LocalScope::LocalVariables() {
  std::vector<DefinedVariable*> result;
  for (auto& s : AllLocalScopes()) {
    auto vars = s->variables();
    for (auto iter = vars.begin(); iter != vars.end(); iter++) {
      if (!iter->second->is_private()) {
        result.push_back(iter->second);
      }
    }
  } // end for

  return result;
}

// return all static local variables
// if DefinedVariable is_private_ is true, it is static local var
std::vector<DefinedVariable*> LocalScope::StaticLocalVariables() {
  std::vector<DefinedVariable*> result;
  for (auto& s : AllLocalScopes()) {
    for (auto iter = s->variables().begin(); iter != s->variables().end(); iter++) {
      if (iter->second->is_private()) {
        result.push_back(iter->second);
      }
    }
  }

  return result;
}

/**
 * @fn AllLocalScopes
 * @brief return all children's scopes including this scope
 * @param 
 * @author Jona
 * @date 27/10/2020 20:24:47 
*/ 
std::vector<LocalScope*> LocalScope::AllLocalScopes() {
  std::vector<LocalScope*> result;
  CollectScope(result);
  return result;
}

/**
 * @fn CollectScope
 * @brief collect current scope and its all children scope into buf
 * @param 
 * @author Jona
 * @date 27/10/2020 20:26:13 
*/ 
void LocalScope::CollectScope(std::vector<LocalScope*>& buf) {
  buf.push_back(this);
  for (auto& s : children()) {
    s->CollectScope(buf);
  }
}

std::map<std::string, DefinedVariable*> LocalScope::variables() {
  return variables_;
}

void LocalScope::CheckReferences(utils::ErrorHandler* h) {
  for (auto iter = variables_.begin(); iter != variables_.end(); iter++) {
    if (!iter->second->IsRefered()) {
      h->Warn(iter->second->GetLocation(), "unused variable: " + iter->second->name());
    }
  }

  for (auto lc : children()) {
    lc->CheckReferences(h);
  }
}

} /* end entity */

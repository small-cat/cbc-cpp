#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>
#include "../ast/location.hpp"
#include "../ast/type/type_node.hpp"
#include "../type/type.hpp"
#include "../ast/dumper.h"

namespace entity {
class Entity  {
public:
  Entity(bool priv, ast::TypeNode* tn, std::string n);
  virtual ~Entity();

  std::string name();
  std::string SymbolString();

  virtual bool IsDefined() { return false; }
  virtual bool IsInitialized() { return false; }

  bool IsConstant();
  bool IsParameter();
  bool is_private();
  ast::TypeNode* type_node();
  type::Type* GetType();
  long AllocSize();
  long Alignment();
  void refered();
  bool IsRefered();
  // void SetMemref(MemoryReference* m);
  // MemoryReference* memref();
  // void SetAddress();
  // Operand* address();
  // void CheckAddress();

  ast::Location* GetLocation();
  virtual std::string GetClass();

  // void accept();
  void Dump(ast::Dumper* d);
  virtual void _dump(ast::Dumper* d);
private:
  bool is_private_;               // attribute
  ast::TypeNode* type_node_;      // type: typename and type definition
  std::string name_;              // symbol name
  long refered_;
  // MemoryReference* memref_;    // defined in asm
  // Operand* address_;
};
} /* end entity */

#endif /* __ENTITY_H__ */

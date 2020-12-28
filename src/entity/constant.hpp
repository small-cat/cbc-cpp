#ifndef __CONSTANT_H__
#define __CONSTANT_H__

#include "entity.h"
#include "../ast/type/type_node.hpp"
#include "../ast/expr/expr_node.hpp"

namespace entity {
class Constant : public Entity {
public:
  Constant(ast::TypeNode* tn, std::string n, ast::ExprNode* e) : Entity(true, tn, n), value_(e) {}
  virtual ~Constant() {}

  bool IsAssignable() { return false; }
  bool IsDefined() { return true; }
  bool IsInitialized() { return true; }
  bool IsConstant() { return true; }

  ast::ExprNode* value() { return value_; }

  virtual std::string GetClass() { return "Constant"; }

  void _dump(ast::Dumper* d) {
    d->PrintMember("Name", name());
    d->PrintMember("TypeNode", type_node());
    d->PrintMember("Value", value_);
  }

  // @todo { not implement accept }
  // void accept();
private:
  // ast::TypeNode* type_node_;    // 常量类型, inherited from Entity
  // std::string name_;            // 常量名称
  ast::ExprNode* value_;        // 常量赋值的值
};
} /* end entity */

#endif /* __CONSTANT_H__ */

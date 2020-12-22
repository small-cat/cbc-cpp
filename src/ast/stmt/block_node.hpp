#ifndef __BLOCK_NODE_H__
#define __BLOCK_NODE_H__

#include "stmt_node.hpp"
#include <vector>

#include "../../entity/defined_variable.h"
#include "../../entity/local_scope.h"

namespace ast {
class BlockNode : public StmtNode {
public:
  BlockNode(Location* l, std::vector<entity::DefinedVariable*> vars, std::vector<StmtNode*> stmts)
    : StmtNode(l) {
      variables_.swap(vars);
      stmts_.swap(stmts);
    }
  virtual ~BlockNode() {}

  std::vector<entity::DefinedVariable*> variables() { return variables_; }
  std::vector<StmtNode*> stmts() { return stmts_; }

  entity::LocalScope* scope() { return scope_; }
  void SetScope(entity::LocalScope* s) { scope_ = s; }

  virtual std::string GetClass() { return "BlockNode"; }
  void _dump(ast::Dumper* d) {
    d->PrintNodeList("variables", variables_);
    d->PrintNodeList("statements", stmts_);
  }
  // @todo { not implement and accept }
  // void accept();
private:
  std::vector<StmtNode*> stmts_;
  std::vector<entity::DefinedVariable*> variables_;   // 申明的变量定义
  entity::LocalScope* scope_;            // 当前作用域，保存有指向父作用域的指针和当前作用域的变量信息
};
} /* end ast */

#endif /* __BLOCK_NODE_H__ */

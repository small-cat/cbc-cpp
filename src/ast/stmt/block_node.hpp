#ifndef __BLOCK_NODE_H__
#define __BLOCK_NODE_H__

#include "stmt_node.hpp"
#include <vector>

// @todo { not implement BlockNode }
namespace ast {
class BlockNode : public StmtNode {
public:
  BlockNode() {}
  virtual ~BlockNode() {}

private:
  std::vector<StmtNode*> stmt_;
  // std::vector<entity::DefinedVariable*> variables_;   // 申明的变量定义
  // std::vector<entity::LocalScope*> scope_;            // 当前作用域，保存有指向父作用域的指针和当前作用域的变量信息
};
} /* end ast */

#endif /* __BLOCK_NODE_H__ */

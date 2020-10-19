#ifndef __CASE_NODE_H__
#define __CASE_NODE_H__

#include "stmt_node.hpp"

namespace ast {
class CaseNode : public StmtNode {
public:
  CaseNode();
  virtual ~CaseNode();

private:
  /* data */
};
} /* end ast */

#endif /* __CASE_NODE_H__ */

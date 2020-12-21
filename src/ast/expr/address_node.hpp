#ifndef __ADDRESS_NODE_H__
#define __ADDRESS_NODE_H__

#include "expr_node.hpp"
#include "../../type/type.hpp"

// AddressNode like &a, expr_ is a
namespace ast {
class AddressNode : public ExprNode {
public:
  AddressNode(ExprNode* e);
  virtual ~AddressNode();

  ExprNode* expr();
  type::Type* type();
  void SetType(type::Type* t);
  Location* location();

  std::string GetClass();
  void _dump(Dumper* d);
  //void accept();
private:
  ExprNode* expr_;
  type::Type* type_;
};
} /* end ast */

#endif /* __ADDRESS_NODE_H__ */

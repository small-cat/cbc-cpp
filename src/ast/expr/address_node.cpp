#include "address_node.hpp"
#include <iostream>

namespace ast {
AddressNode::AddressNode(ExprNode* e) : expr_(e), type_(nullptr) {}
AddressNode::~AddressNode() {}

ExprNode* AddressNode::expr() {
  return expr_;
}

type::Type* AddressNode::type() {
  if (type_ == nullptr) {
    std::cout << "Error: type is null" << std::endl;
  }

  return type_;
}

void AddressNode::SetType(type::Type* t) {
  if (type_ != nullptr) {
    std::cout << "Error: type set twice" << std::endl;
  }

  type_ = t;
}

Location* AddressNode::location() {
  return expr_->location();
}

void AddressNode::_dump(Dumper* d) {
  if (type_ != nullptr) {
    // d->PrintMember("Type", type_);
  }

  // d->PrintMember("Expr", expr_);
}

} /* end ast */

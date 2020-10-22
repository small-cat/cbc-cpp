#include "binary_op_node.hpp"

#include <iostream>

namespace ast {
BinaryOpNode::BinaryOpNode(ExprNode* l, std::string op, ExprNode* r) 
  : operator_(op), left_(l), right_(r), type_(nullptr) {}

BinaryOpNode::BinaryOpNode(type::Type* t, ExprNode* l, std::string op, ExprNode* r) 
  : operator_(op), left_(l), right_(r), type_(t) {}

BinaryOpNode::~BinaryOpNode() {}

std::string BinaryOpNode::BinaryOpOperator() {
  return operator_;
}

type::Type* BinaryOpNode::type() {
  return (type_ != nullptr)? type_ : left_->type();
}

void BinaryOpNode::SetType(type::Type* t) {
  if (type_ != nullptr) {
    std::cout << "Error: BinaryOpNode#SetType called twice" << std::endl;
  }

  type_ = t;
}

ExprNode* BinaryOpNode::left() { return left_; }
void BinaryOpNode::SetLeft(ExprNode* l) {
  left_ = l;
}

ExprNode* BinaryOpNode::right() { return right_; }
void BinaryOpNode::SetRight(ExprNode* r) {
  right_ = r;
}

Location* BinaryOpNode::location() {
  return left_->location();
}

void BinaryOpNode::_dump(Dumper* d) {
  // @todo {  things to be done }
}
} /* end ast */

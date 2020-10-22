#include "unary_op_node.hpp"

namespace ast {

UnaryOpNode::UnaryOpNode(std::string op, ExprNode* e) : operator_(op), expr_(e), op_type_(nullptr) {}
UnaryOpNode::~UnaryOpNode() {}

std::string UnaryOpNode::UnaryOpNodeOperator() {
  return operator_;
}

type::Type* UnaryOpNode::type() {
  return expr_->type();
}

void UnaryOpNode::SetOpType(type::Type* t) {
  op_type_ = t;
}

type::Type* UnaryOpNode::op_type() {
  return op_type_;
}

ExprNode* UnaryOpNode::expr() {
  return expr_;
}

void UnaryOpNode::SetExpr(ExprNode* e) {
  expr_ = e;
}

Location* UnaryOpNode::location() {
  return expr_->location();
}

void UnaryOpNode::_dump(Dumper* d) {
  // @todo {  things to be done }
}
  
} /* end as */

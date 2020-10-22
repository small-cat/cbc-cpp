#include "cast_node.hpp"

namespace ast {
CastNode::CastNode(TypeNode* t, ExprNode* expr) : type_node_(t), expr_(expr) {
}

CastNode::~CastNode() {}

type::Type* CastNode::type() {
  return type_node_->type();
}

TypeNode* CastNode::type_node() {
  return type_node_;
}

ExprNode* CastNode::expr() {
  return expr_;
}

bool CastNode::IsLValue() {
  return expr_->IsLValue();
}

bool CastNode::IsAssignable() {
  return expr_->IsAssignable();
}

bool CastNode::IsEffectiveCast() {
  return type()->size() > expr_->type()->size();
}

} /* end ast */

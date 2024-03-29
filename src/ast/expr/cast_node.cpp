/** 
* @copyright (c) Copyright, All Rights Reserved.
* @license
* @file: cast_node.cpp
* @author: Jona
* @email: mblrwuzy@gmail.com
* @date: 2020/12/18
* @brief: type convert
*/
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
  return type()->Size() > expr_->type()->Size();
}

Location* CastNode::location() {
  return type_node_->location();
}

std::string CastNode::GetClass() {
  return "CastNode";
}

void CastNode::_dump(Dumper *d) {
  d->PrintMember("TypeNode", type_node_);
  d->PrintMember("Expr", expr_);
}

void CastNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}

} /* end ast */

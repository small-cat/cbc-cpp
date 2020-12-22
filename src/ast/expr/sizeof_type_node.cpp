#include "sizeof_type_node.hpp"

namespace ast {
SizeofTypeNode::SizeofTypeNode(TypeNode* op, type::TypeRef* tr) : operand_(op) {
  type_node_ = new TypeNode(tr);
} 

SizeofTypeNode::~SizeofTypeNode() {
  if (type_node_ != nullptr) {
    delete type_node_;
    type_node_ = nullptr;
  }

  if (nullptr != operand_) {
    delete operand_;
    operand_ = nullptr;
  }
}

type::Type* SizeofTypeNode::OperandType() {
  return operand_->type();
}

TypeNode* SizeofTypeNode::OperandTypeNode() {
  return operand_;
}

type::Type* SizeofTypeNode::type() {
  return type_node_->type();
}

TypeNode* SizeofTypeNode::type_node() {
  return type_node_;
}

Location* SizeofTypeNode::location() {
  return operand_->location();
}

std::string SizeofTypeNode::GetClass() {
  return "SizeofTypeNode";
}

void SizeofTypeNode::_dump(Dumper* d) {
  d->PrintMember("Operand", type_node_);
}
} /* end ty */

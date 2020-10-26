#include "slot.hpp"

namespace ast {
SlotNode::SlotNode(TypeNode* t, std::string n) : type_node_(t), name_(n), offset_(0) {}
SlotNode::~SlotNode() {}

TypeNode* SlotNode::type_node() {
  return type_node_;
}

type::TypeRef* SlotNode::GetTypeRef() {
  return type_node_->type_ref();
}

type::Type* SlotNode::type() {
  return type_node_->type();
}

std::string SlotNode::name() {
  return name_;
}

long SlotNode::Size() {
  return type()->Size();
}

long SlotNode::AllocSize() {
  return type()->AllocSize();
}

long SlotNode::offset() {
  return offset_;
}

long SlotNode::Alignment() {
  return type()->Alignment();
}

void SlotNode::SetOffset(long off) {
  offset_ = off;
}

Location* SlotNode::location() {
  return type_node_->location();
}

void SlotNode::_dump(Dumper* d) {
  // @todo {  things to be done }
}
} /* end ast */

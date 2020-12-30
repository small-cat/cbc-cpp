#include "import_file_node.h"

namespace ast {
ImportFileNode::ImportFileNode(std::string name, Location* loc) : filename_(name), location_(loc) {}
ImportFileNode::~ImportFileNode() {}

std::string ImportFileNode::GetClass() {
  return "ImportFileNode";
}

Location* ImportFileNode::location() {
  return location_;
}

std::string ImportFileNode::filename() {
  return filename_;
}

} /* ast */
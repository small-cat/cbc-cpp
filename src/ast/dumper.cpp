#include "dumper.h"

namespace ast {

const std::string Dumper::INDENT_STRING = "  ";

Dumper::Dumper(std::fstream* fs) : indent_(0), stream_(fs) {}
Dumper::~Dumper() {}

/**
 * @fn PrintClass
 * @brief dumper class info for node
 * @param loc contains location for current node
 * @author Jona
 * @date 23/09/2020 16:14:37 
*/ 
void Dumper::PrintClass(Node* node, Location* loc) {
  // @todo { not implelemented }
  PrintIndent();
  *stream_ << ("<<" + node->GetClass() + ">>" + "(" + loc->ToString() + ")");
}

void Dumper::PrintNodeList(const std::string& name, std::vector<Node*> nodes) {
  // @todo {  things to be done }
}

void Dumper::PrintMember(const std::string& name, Node* node) {
  // @todo {  things to be done }
}

void Dumper::Indent() {
  indent_++;
}

void Dumper::UnIndent() {
  indent_--;
}

void Dumper::PrintIndent() {
  int n = indent_;
  while (n > 0) {
    *stream_ << INDENT_STRING;
    n--;
  }
}

} /* end ast */

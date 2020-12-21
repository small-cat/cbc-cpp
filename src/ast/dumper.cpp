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
  PrintIndent();
  *stream_ << "<<" << node->GetClass() << ">> (" << loc->ToString() << ")\n";
}

void Dumper::PrintClass(entity::Entity *node, Location *loc) {
  PrintIndent();
  *stream_ << "<<" << node->GetClass() << ">> (" << loc->ToString() << ")\n";
}

void Dumper::PrintNodeList(const std::string& name, std::vector<Node*> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumper::PrintNodeList(const std::string &name, std::vector<ExprNode *> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->Dump(this);
  }
  UnIndent();
}

void Dumper::PrintNodeList(const std::string& name, std::vector<entity::DefinedVariable*> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumper::PrintNodeList(const std::string& name, std::vector<entity::DefinedFunction*> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumper::PrintNodeList(const std::string& name, std::vector<entity::Parameter*> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumper::PrintMember(const std::string& name, std::string value) {
  PrintPair(name, value);
}

void Dumper::PrintMember(const std::string &name, int n) {
  PrintPair(name, std::to_string(n));
}

void Dumper::PrintMember(const std::string &name, long l) {
  PrintPair(name, std::to_string(l));
}

void Dumper::PrintMember(const std::string &name, bool b) {
  PrintPair(name, b?"true":"false");
}

void Dumper::PrintMember(const std::string &name, type::TypeRef *ref) {
  PrintPair(name, ref->ToString());
}

void Dumper::PrintMember(const std::string &name, type::Type *t) {
  PrintPair(name, t->ToString());
}

void Dumper::PrintMember(const std::string &name, std::string str, bool is_resolved) {
  PrintPair(name, str + (is_resolved?":(resolved)":""));
}

void Dumper::PrintMember(const std::string &name, ast::TypeNode *tn) {
  PrintMember(name, tn->type_ref()->ToString(), tn->IsResolved());
}

void Dumper::PrintMember(const std::string &name, entity::Params* pams) {
  PrintIndent();
  if (pams == nullptr) {
    *stream_ << name << ": null\n"; 
  } else {
    *stream_ << name << ": \n";
    Indent();
    pams->_dump(this);
    UnIndent();
  }
}

void Dumper::PrintMember(const std::string &name, ast::StmtNode *stmt) {
  PrintIndent();
  if (stmt == nullptr) {
    *stream_ << name << ": null\n";
  } else {
    *stream_ << name << ": \n";
    Indent();
    stmt->_dump(this);
    UnIndent();
  }
}

void Dumper::PrintMember(const std::string &name, ast::ExprNode *expr) {
  PrintIndent();
  if (expr == nullptr) {
    *stream_ << name << ": null\n";
  } else {
    *stream_ << name << ": \n";
    Indent();
    expr->Dump(this);
    UnIndent();
  }
}

void Dumper::PrintPair(const std::string& name, std::string val) {
  PrintIndent();
  *stream_ << name << ": " << val << "\n";
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

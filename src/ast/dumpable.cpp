#include "dumpable.h"

namespace ast {

const std::string Dumpable::INDENT_STRING = "  ";

Dumpable::Dumpable(std::ostream* fs) : Dumper(), stream_(fs), indent_(0) {}
Dumpable::~Dumpable() {}

/**
 * @fn PrintClass
 * @brief dumper class info for node
 * @param loc contains location for current node
 * @author Jona
 * @date 23/09/2020 16:14:37 
*/ 
void Dumpable::PrintClass(Node* node, Location* loc) {
  PrintIndent();
  *stream_ << "<<" << node->GetClass() << ">> (" << loc->ToString() << ")\n";
}

void Dumpable::PrintClass(entity::Entity *node, Location *loc) {
  PrintIndent();
  *stream_ << "<<" << node->GetClass() << ">> (" << loc->ToString() << ")\n";
}

void Dumpable::PrintNodeList(const std::string& name, std::vector<Node*> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumpable::PrintNodeList(const std::string &name, std::vector<ExprNode *> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->Dump(this);
  }
  UnIndent();
}

void Dumpable::PrintNodeList(const std::string& name, std::vector<entity::DefinedVariable*> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumpable::PrintNodeList(const std::string& name, std::vector<entity::DefinedFunction*> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumpable::PrintNodeList(const std::string& name, std::vector<entity::Parameter*> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumpable::PrintNodeList(const std::string &name, std::vector<StmtNode *> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->Dump(this);
  }
  UnIndent();
}

void Dumpable::PrintNodeList(const std::string &name, std::vector<CaseNode *> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumpable::PrintNodeList(const std::string &name, std::vector<SlotNode *> nodes) {
  PrintIndent();
  *stream_ << name << ":\n";
  Indent();
  for (auto& n : nodes) {
    n->_dump(this);
  }
  UnIndent();
}

void Dumpable::PrintMember(const std::string& name, std::string value) {
  PrintPair(name, value);
}

void Dumpable::PrintMember(const std::string &name, int n) {
  PrintPair(name, std::to_string(n));
}

void Dumpable::PrintMember(const std::string &name, long l) {
  PrintPair(name, std::to_string(l));
}

void Dumpable::PrintMember(const std::string &name, bool b) {
  PrintPair(name, b?"true":"false");
}

void Dumpable::PrintMember(const std::string &name, type::TypeRef *ref) {
  PrintPair(name, ref->ToString());
}

void Dumpable::PrintMember(const std::string &name, type::Type *t) {
  PrintPair(name, t->ToString());
}

void Dumpable::PrintMember(const std::string &name, std::string str, bool is_resolved) {
  PrintPair(name, str + (is_resolved?":(resolved)":""));
}

void Dumpable::PrintMember(const std::string &name, ast::TypeNode *tn) {
  PrintMember(name, tn->type_ref()->ToString(), tn->IsResolved());
}

void Dumpable::PrintMember(const std::string &name, entity::Params* pams) {
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

void Dumpable::PrintMember(const std::string &name, ast::StmtNode *stmt) {
  PrintIndent();
  if (stmt == nullptr) {
    *stream_ << name << ": null\n";
  } else {
    *stream_ << name << ": \n";
    Indent();
    stmt->Dump(this);
    UnIndent();
  }
}

void Dumpable::PrintMember(const std::string &name, ast::ExprNode *expr) {
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

void Dumpable::PrintPair(const std::string& name, std::string val) {
  PrintIndent();
  *stream_ << name << ": " << val << "\n";
}

void Dumpable::Indent() {
  indent_++;
}

void Dumpable::UnIndent() {
  indent_--;
}

void Dumpable::PrintIndent() {
  int n = indent_;
  while (n > 0) {
    *stream_ << INDENT_STRING;
    n--;
  }
}

} /* end ast */

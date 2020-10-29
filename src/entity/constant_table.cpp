#include "constant_table.hpp"

namespace entity {
ConstantTable::ConstantTable() {}
ConstantTable::~ConstantTable() {}

bool ConstantTable::IsEmpty() {
  return table_.empty();
}

ConstantEntry* ConstantTable::Intern(std::string n) {
  auto search = table_.find(n);
  if (search == table_.end()) {
    ConstantEntry* ent = new ConstantEntry(n);
    table_.emplace(std::make_pair(n, ent));
    return ent;
  }

  return search->second;
}
} /* end entity */

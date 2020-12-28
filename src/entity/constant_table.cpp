#include "constant_table.hpp"

namespace entity {
ConstantTable::ConstantTable() {}

ConstantTable::ConstantTable(ConstantTable& tb) {
  if (tb.IsEmpty()) {
    return;
  }

  auto map_table = tb.table();
  for (auto& it : map_table) {
    auto tb_ent = it.second;
    ConstantEntry* ent = new ConstantEntry(tb_ent->value());
    table_[it.first] = ent;
  }
}

ConstantTable::~ConstantTable() {
  for (auto& cons : table_) {
    auto ent = cons.second;
    if (nullptr != ent) {
      delete ent;
      ent = nullptr;
    }
  }
}

bool ConstantTable::IsEmpty() {
  return table_.empty();
}

std::map<std::string, ConstantEntry *> ConstantTable::table() {
  return table_;
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

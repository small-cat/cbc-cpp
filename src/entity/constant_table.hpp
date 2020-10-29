#ifndef __CONSTANT_TABLE_H__
#define __CONSTANT_TABLE_H__

#include <map>
#include <string>

#include "constant_entry.h"

namespace entity {
class ConstantTable  {
public:
  ConstantTable();
  virtual ~ConstantTable();

  bool IsEmpty();
  ConstantEntry* Intern(std::string n);
private:
  std::map<std::string, ConstantEntry*> table_;
};
} /* end entity */

#endif /* __CONSTANT_TABLE_H__ */

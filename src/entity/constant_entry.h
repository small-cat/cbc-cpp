#ifndef __CONSTANT_ENTRY_H__
#define __CONSTANT_ENTRY_H__

#include <string>

namespace entity {
class ConstantEntry  {
public:
  ConstantEntry(std::string val) : value_(val) {}
  virtual ~ConstantEntry() {}

  std::string value() { return value_; }
  // void SetSymbol(Symbol sym);
  // Symbol symbol();
  // void SetMemory(MemoryReference* m);
  // MemoryReference* memref();
  // void SetAddress(ImmediateValue* iv);
  // ImmediateValue* address();
private:
  std::string value_;
  // Symbol* symbol_;
  // MemoryReference* memref_;
  // ImmediateValue* address_;
};
} /* end entity */

#endif /* __CONSTANT_ENTRY_H__ */

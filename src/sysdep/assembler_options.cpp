#include "assembler_options.h"

namespace sysdep {
AssemblerOptions::AssemblerOptions() : verbose_(false) {}

AssemblerOptions::~AssemblerOptions() {}

std::vector<std::string> AssemblerOptions::args() {
  return args_;
}

void AssemblerOptions::AddArg(const std::string& arg) {
  args_.push_back(arg);
}

void AssemblerOptions::SetVerbose(bool v) {
  verbose_ = v;
}

bool AssemblerOptions::verbose() {
  return verbose_;
}

} /* end sysdep */

#include "compiler_mode.h"

#include <string.h>

namespace compiler {

CompilerMode::CompilerMode(Mode m) : mode_(m){
}

CompilerMode::~CompilerMode() {}

std::map<std::string, CompilerMode::Mode> CompilerMode::modes_map_ = {
  {"check-syntax", CompilerMode::Mode::CheckSyntax},
  {"dump-tokens", CompilerMode::DumpTokens},
  {"dump-ast", CompilerMode::Mode::DumpAST},
  {"dump-stmt", CompilerMode::Mode::DumpStmt},
  {"dump-expr", CompilerMode::Mode::DumpExpr},
  {"dump-semantic", CompilerMode::Mode::DumpSemantic},
  {"dump-reference", CompilerMode::Mode::DumpReference},
  {"dump-ir", CompilerMode::Mode::DumpIR},
  {"dump-asm", CompilerMode::Mode::DumpAsm},
  {"print-asm", CompilerMode::Mode::PrintAsm},
  {"S", CompilerMode::Mode::Compile},
  {"c", CompilerMode::Mode::Assemble},
};

bool CompilerMode::IsModeOption(const std::string& opt) {
  for (auto iter = CompilerMode::modes_map_.begin(); iter != CompilerMode::modes_map_.end(); iter++) {
    if (strcmp(iter->first.c_str(), opt.c_str())) {
      return true;
    }
  }

  return false;
}

CompilerMode::Mode CompilerMode::FromOption(const std::string& opt) {
  auto search = CompilerMode::modes_map_.find(opt);
  if (search != CompilerMode::modes_map_.end()) {
    return search->second;
  } else {
    return CompilerMode::Mode::UNKNOWN;
  }
}

CompilerMode::Mode CompilerMode::mode() {
  return mode_;
}

void CompilerMode::SetMode(CompilerMode::Mode m) {
  mode_ = m;
}

bool CompilerMode::Requires(CompilerMode::Mode m) {
  return mode_ > m;
}

std::string CompilerMode::ToOption() {
  for (auto iter = CompilerMode::modes_map_.begin(); iter != CompilerMode::modes_map_.end(); iter++) {
    if (iter->second == mode_) {
      return iter->first;
    }
  }

  return "UNKNOWN";
}

} /* end compiler */

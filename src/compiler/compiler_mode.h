#ifndef __COMPILER_MODE_H__
#define __COMPILER_MODE_H__

#include <string>
#include <map>

namespace compiler {
class CompilerMode  {
public:
  enum Mode {
    UNKNOWN = 0,
    CheckSyntax = 1,
    DumpTokens,
    DumpAST,
    DumpStmt,
    DumpExpr,
    DumpSemantic,
    DumpReference,
    DumpIR,
    DumpAsm,
    PrintAsm,
    Compile,
    Assemble,
    Link
  };

  CompilerMode(Mode m);
  virtual ~CompilerMode();

  static std::map<std::string, Mode> modes_map_;

  static bool IsModeOption(const std::string& opt);
  static Mode FromOption(const std::string& opt);
  Mode mode();
  void SetMode(Mode m);
  bool Requires(Mode m);
  std::string ToOption();
private:
  Mode mode_;
};
}

#endif /* __COMPILER_MODE_H__ */

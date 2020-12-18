#include "../compiler/compiler.h"

int main(int argc, char *argv[]) {
  compiler::Compiler* compiler = new compiler::Compiler(compiler::Compiler::kProgramName);
  compiler->CommandMain(argc, argv);

  delete compiler;
  return 0;
}

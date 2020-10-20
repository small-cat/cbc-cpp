#include "../compiler/compiler.h"

void HelloSesame() {
  printf("   .--,       .--,\n");
  printf("  ( (  \\.---./  ) )\n");
  printf("   '.__/o   o\\__.'\n");
  printf("      {=  ^  =}\n");
  printf("       >  -  <\n");
  printf(" __.\"\"`-------`\"\".__\n");
  printf("/         #         \\\n");
  printf("\\    hello sesame   /\n");
  printf("/    hello sesame   \\\n");
  printf("\\___________________/\n");
  printf("     ___)( )(___\n");
  printf("    (((__) (__)))\n");
  printf("\n");
}

int main(int argc, char *argv[]) {
  HelloSesame();

  compiler::Compiler* compiler = new compiler::Compiler(compiler::Compiler::kProgramName);
  compiler->CommandMain(argc, argv);

  delete compiler;
  return 0;
}

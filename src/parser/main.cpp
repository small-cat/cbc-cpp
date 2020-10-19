/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "SesameLexer.h"
#include "SesameParser.h"
#include "error_verbose_listener.hpp"

using namespace antlr4;
using namespace parser;

void HelloSesame();
void ParseFile(const std::string& filename);
void ParseString(std::string &sql);
static void _ParseString(ANTLRInputStream* input);

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
}

void ParseFile(const std::string& filename) {
  ANTLRFileStream input(filename);
  _ParseString(&input);
}

void ParseString(std::string &sql) {
  ANTLRInputStream input(sql);
  _ParseString(&input);
}

static void _ParseString(ANTLRInputStream* input) {
  SesameLexer lexer(input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << std::endl;
  }

  SesameParser parser(&tokens);

  ErrorVerboseListener err_listener;
  parser.removeErrorListeners();
  parser.addErrorListener(&err_listener);

  auto compile_ctx = parser.compilation_unit();
  std::cout << ((tree::ParseTree*)(compile_ctx))->toStringTree(&parser) << std::endl;

  if (err_listener.has_error()) {
    std::cout << "Parse failed: " << err_listener.err_message() << std::endl;
  }
}

int main(int argc, char *argv[]) {
  HelloSesame();
  int ret;
  extern char *optarg;
  if (1 == argc) {
    std::cout << "Usage: " << argv[0] << " [-f filename] [-e sqlstatement]" << std::endl;
    return 0;
  }

  while ((ret = getopt(argc, argv, "f:e:")) != -1) {
    switch (ret) {
      case 'f':
        ParseFile(std::string(optarg));
        break;
      case 'e':
        {
          std::string sqlstmt(optarg);
          ParseString(sqlstmt);
        }
        break;
      case '?':
      default:
        std::cout << "Usage: " << argv[0] << " [-f filename] [-e sqlstatement]" << std::endl;
        break;
    }
  }

  return 0;
}

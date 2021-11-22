/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : options.h
 * @author: Jona
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-16
 * @brief : parse options commands
 */
#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include <iostream>
#include <list>
#include <vector>

#include "compiler_mode.h"
#include "source_file.h"
#include "sysdep/assembler_options.h"
#include "sysdep/code_generator_options.h"
#include "sysdep/linker_options.h"
#include "sysdep/platform.h"

#define PROGNAME "sesame"

#define AX(X) AX_(X)
#define AX_(X) #X

#ifdef SVERSION
#define PROG_VERSION AX(SVERSION)
#else
#define PROG_VERSION "0.0.1"
#endif

#ifndef COMMIT_ID
#define COMMIT_ID ""
#endif

#ifndef BUILD_DATE
#define BUILD_DATE ""
#endif

#ifndef COMPILE_TOOL_VERSION
#define COMPILE_TOOL_VERSION ""
#endif

#ifndef COMPILE_OS
#define COMPILE_OS ""
#endif

namespace compiler {

class Options {
 public:
  Options();
  virtual ~Options();

  CompilerMode mode();
  bool IsAssembleRequired();
  bool IsLinkRequired();
  std::vector<SourceFile> source_file();

  std::string AsmFileNameOf(SourceFile* src);
  std::string ObjFileNameOf(SourceFile* src);
  std::string ExeFileName();
  std::string SoFileName();

  const static std::string DEFAULT_LINKER_OUTPUT;

  std::string LinkedFileName(std::string new_ext);
  std::string output_filename();
  bool IsVerboseMode();
  bool DoesDebugParser();

  // @todo { not implement }
  type::TypeTable::TypeTableClass GetTypeTableClass();
  // CodeGenerator* GetCodeGenerator();
  sysdep::CodeGeneratorOptions gen_options();
  // Assembler* GetAssembler();
  sysdep::AssemblerOptions asm_options();
  // Linker* GetLinker();
  sysdep::LinkerOptions ld_options();
  std::list<std::string> ld_args();
  void AddLdArg(const std::string& arg);
  void ParseArgs(int argc, char* argv[]);
  void PrintUsage();
  void HelloSesame();
  void ShowVersion();
  std::vector<std::string> include_path();

  void ParseError(const std::string& msg);

 private:
  void Split(const std::string& s, std::vector<std::string>& sv,
             const char delim = ' ');
  std::string Trim(std::string str);

 private:
  CompilerMode mode_;
  sysdep::Platform* platform_;
  std::string output_filename_;
  bool verbose_;
  bool debug_parser_;
  // LibraryLoader* loader_;
  sysdep::CodeGeneratorOptions gen_options_;
  sysdep::AssemblerOptions asm_options_;
  sysdep::LinkerOptions ld_options_;
  std::list<std::string> ld_args_;
  std::vector<SourceFile> src_files_;
  std::vector<std::string> include_path_;  // -I includepath
};
}  // namespace compiler

#endif /* __OPTIONS_H__ */

#include "options.h"

#include <regex>
#include <sstream>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#include "sysdep/X86Linux.h"

extern char* optarg;
namespace compiler {

const std::string Options::DEFAULT_LINKER_OUTPUT = "a.out";

Options::Options() : mode_(CompilerMode::Mode::UNKNOWN),
                     output_filename_(""),
                     verbose_(false),
                     debug_parser_(false) {
  platform_ = new sysdep::X86Linux();
}

Options::~Options() {
  if (nullptr != platform_) {
    delete platform_;
    platform_ = nullptr;
  }
}

CompilerMode Options::mode() {
  return mode_;
}

bool Options::IsAssembleRequired() {
  return mode_.Requires(CompilerMode::Mode::Assemble);
}

bool Options::IsLinkRequired() {
  return mode_.Requires(CompilerMode::Mode::Link);
}

std::vector<SourceFile> Options::source_file() {
  return src_files_;
}

/**
 * @fn AsmFileNameOf
 * @brief return file name with assembly extensions
 *  test.cbc -> test.s
 * @param 
 * @author Jona
 * @date 16/10/2020 17:17:35 
*/ 
std::string Options::AsmFileNameOf(SourceFile* src) {
  if (!output_filename_.empty() && mode_.mode() == CompilerMode::Mode::Compile) {
    return output_filename_;
  }

  return src->AsmFileName();
}

std::string Options::ObjFileNameOf(SourceFile* src) {
  if (!output_filename_.empty() && mode_.mode() == CompilerMode::Mode::Assemble) {
    return output_filename_;
  }

  return src->ObjFileName();
}

std::string Options::ExeFileName() {
  return LinkedFileName("");
}

std::string Options::SoFileName() {
  return LinkedFileName(".so");
}

/**
 * @fn LinkedFileName
 * @brief file name with new extension named new_ext 
 * @param 
 * @author Jona
 * @date 16/10/2020 17:25:47 
*/ 
std::string Options::LinkedFileName(std::string new_ext) {
  if (!output_filename_.empty()) {
    return output_filename_;
  }

  if (src_files_.size() == 1) {
    return src_files_.at(0).LinkedFileName(new_ext);
  } else {
    return DEFAULT_LINKER_OUTPUT;
  }
}

std::string Options::output_filename() {
  return output_filename_;
}

bool Options::IsVerboseMode() {
  return verbose_;
}

bool Options::DoesDebugParser() {
  return debug_parser_;
}

sysdep::CodeGeneratorOptions Options::gen_options() {
  return gen_options_;
}

sysdep::AssemblerOptions Options::asm_options() {
  return asm_options_;
}

sysdep::LinkerOptions Options::ld_options() {
  return ld_options_;
}

void Options::ParseArgs(int argc, char* argv[]) {
  int ret = 0;
  std::string optstring = ":Sco:O::vI:l:L:";
  static struct option long_options[] = {
    {"check-syntax",  no_argument,       0, 300},
    {"dump-tokens",   no_argument,       0, 301},
    {"dump-ast",      no_argument,       0, 302},
    {"dump-semantic", no_argument,       0, 303},
    {"dump-ir",       no_argument,       0, 304},
    {"dump-asm",      no_argument,       0, 305},
    {"print-asm",     no_argument,       0, 306},
    {"version",       no_argument,       0, 307},
    {"help",          no_argument,       0, 308},
    {"debug-parser",  no_argument,       0, 309},
    {"readonly-got",  no_argument,       0, 310},
    {"Wa,",           required_argument, 0, 311},
    {"Wl,",           required_argument, 0, 312},
    {"Xassembler",    required_argument, 0, 313},
    {"shared",        no_argument,       0, 314},
    {"static",        no_argument,       0, 315},
    {"pie",           no_argument,       0, 316},
    {"nostartfiles",  no_argument,       0, 317},
    {"nodefaultlibs", no_argument,       0, 318},
    {"nostdlib",      no_argument,       0, 319},
    {"Xlinker",       required_argument, 0, 320},
    {"fpie",          no_argument,       0, 321},
    {"fPIE",          no_argument,       0, 322},
    {"fpic",          no_argument,       0, 323},
    {"fPIC",          no_argument,       0, 324},
    {"fverbose-asm",  no_argument,       0, 325},
    {"verbose-asm",   no_argument,       0, 326},
    {0,               0,                 0, 0}
  };

  while (1) {
    int opt_index = 0;
    ret = getopt_long_only(argc, argv, optstring.c_str(), long_options, &opt_index);
    if (ret == -1) {
      break;
    }

    switch (ret) {
      case 'o':
        output_filename_ = std::string(optarg);
        break;
      case 'O': 
        {
          const std::regex regO("[0123s]");
          if (std::regex_search(optarg, regO)) {
            if (strcmp(optarg, "0") == 0) {
              gen_options_.SetOptimizeLevel(0);
            } else {
              gen_options_.SetOptimizeLevel(1);
            }
          } else {
            ParseError("unknown optimization arg: " + std::string(optarg));
            exit(EXIT_FAILURE);
          }

          break;
        }
      case 'v':
        verbose_ = true;
        asm_options_.SetVerbose(true);
        ld_options_.SetVerbose(true);
        break;
      case 'I':
        include_path_.push_back(std::string(optarg));
        break;
      case 'l':
        AddLdArg("-l" + std::string(optarg));
        break;
      case 'L':
        AddLdArg("-L" + std::string(optarg));
        break;

      case 'S': 
        // compile
      case 'c':
        // generate assembly code
        // long options 
      case 300:
      case 301:
      case 302:
      case 303:
      case 304:
      case 305:
      case 306:
        if (CompilerMode::IsModeOption(std::string(long_options[opt_index].name))) {
          if (mode_.mode() != CompilerMode::Mode::UNKNOWN) {
            std::cout << mode_.ToOption() << " option and " << std::string(long_options[opt_index].name)
              << " option is exclusive" << std::endl;
          }

          mode_ = CompilerMode::FromOption(std::string(long_options[opt_index].name));
        }
        break;
      case 307:
        printf("%s VERSION %s\n", AX(PROGNAME), AX(PROG_VERSION));
        exit(EXIT_SUCCESS);
        break;
      case 308:
        PrintUsage();
        exit(EXIT_SUCCESS);
        break;
      case 309:
        debug_parser_ = true;
        break;
      case 310:
        {
          // readonly
          AddLdArg("-z");
          AddLdArg("combreloc");
          AddLdArg("-z");
          AddLdArg("now");
          AddLdArg("-z");
          AddLdArg("relro");
          break;
        }
      case 311:
        {
          // -Wa, OPT
          // there must be at least one blank before OPT
          std::vector<std::string> sv;
          Split(std::string(optarg), sv, ',');
          for (auto& opt : sv) {
            asm_options_.AddArg(opt);
          }
          break;
        }
      case 312:
        {
          std::vector<std::string> sv;
          Split(std::string(optarg), sv, ',');
          for (auto& opt : sv) {
            ld_args_.push_back(opt);
          }
          break;
        }
      case 313:
        {
          // -Xassembler OPT
          asm_options_.AddArg(std::string(optarg));
          break;
        }
      case 314:
        ld_options_.SetGenerateSharedLib(true);
        break;
      case 315:
        AddLdArg("-" + std::string(long_options[opt_index].name));
        break;
      case 316:
        ld_options_.SetGeneratePie(true);
        break;
      case 317:
        ld_options_.SetNoStartFiles(true);
        break;
      case 318:
        ld_options_.SetNoDefaultLibs(true);
        break;
      case 319:
        ld_options_.SetNoStartFiles(true);
        ld_options_.SetNoDefaultLibs(true);
        break;
      case 320:
        AddLdArg(std::string(optarg));
        break;
      case 321:
      case 322:
        gen_options_.GeneratePie();
        break;
      case 323:
      case 324:
        gen_options_.GeneratePic();
        break;
      case 325:
      case 326:
        gen_options_.GenerateVerboseAsm();
        break;

      case '?':
        printf("extraneous argument\n");
        PrintUsage();
        exit(EXIT_SUCCESS);
      default:
        printf("?? getopt_long_only returned character code 0%o ??\n", ret);
        exit(EXIT_FAILURE);
        break;
    }
  } // end while
  while (optind < argc) {
    src_files_.push_back(SourceFile(std::string(argv[optind++])));
  }

  if (mode_.mode() == CompilerMode::Mode::UNKNOWN) {
    mode_.SetMode(CompilerMode::Mode::Link);
  }

  if (src_files_.empty()) {
    ParseError("no input file");
  }

  for (auto& f : src_files_) {
    if (!f.IsKnownFileType()) {
      ParseError("unknown file type for " + f.Path() + ", request for .cb");
    }
  }

  if (!output_filename_.empty() && src_files_.size() > 1 && !IsLinkRequired()) {
    ParseError("-o option requires only one input (except linking)");
  }
}

std::list<std::string> Options::ld_args() {
  return ld_args_;
}

void Options::AddLdArg(const std::string& arg) {
  ld_args_.push_back(arg);
}

void Options::HelloSesame() {
  printf("   .--,       .--,\n");
  printf("  ( (  \\.---./  ) )\n");
  printf("   '.__/o   o\\__.'\n");
  printf("      {=  ^  =}\n");
  printf("       >  -  <\n");
  printf(" __.\"\"`-------`\"\".__\n");
  printf("/         #         \\\n");
  printf("\\       HELLO       /\n");
  printf("/      SESAME!      \\\n");
  printf("\\___________________/\n");
  printf("     ___)( )(___\n");
  printf("    (((__) (__)))\n");
  printf("\n");
}

void Options::PrintUsage() {
  HelloSesame();
  printf("\n");
  printf("Global Options:\n");
  printf("  --check-syntax   Checks syntax and quit.\n");
  printf("  --dump-tokens    Dumps tokens and quit.\n");
  // --dump-stmt is a hidden option.
  // --dump-expr is a hidden option.
  printf("  --dump-ast       Dumps AST and quit.\n");
  printf("  --dump-semantic  Dumps AST after semantic checks and quit.\n");
  // --dump-reference is a hidden option.
  printf("  --dump-ir        Dumps IR and quit.\n");
  printf("  --dump-asm       Dumps AssemblyCode and quit.\n");
  printf("  --print-asm      Prints assembly code and quit.\n");
  printf("  -S               Generates an assembly file and quit.\n");
  printf("  -c               Generates an object file and quit.\n");
  printf("  -o PATH          Places output in file PATH.\n");
  printf("  -v               Turn on verbose mode.\n");
  printf("  --version        Shows compiler version and quit.\n");
  printf("  --help           Prints this message and quit.\n");
  printf("\n");
  printf("Optimization Options:\n");
  printf("  -O               Enables optimization.\n");
  printf("  -O1, -O2, -O3    Equivalent to -O.\n");
  printf("  -Os              Equivalent to -O.\n");
  printf("  -O0              Disables optimization (default).\n");
  printf("\n");
  printf("Parser Options:\n");
  printf("  -I PATH          Adds PATH as import file directory.\n");
  printf("  --debug-parser   Dumps parsing process.\n");
  printf("\n");
  printf("Code Generator Options:\n");
  printf("  -O               Enables optimization.\n");
  printf("  -O1, -O2, -O3    Equivalent to -O.\n");
  printf("  -Os              Equivalent to -O.\n");
  printf("  -O0              Disables optimization (default).\n");
  printf("  -fPIC            Generates PIC assembly.\n");
  printf("  -fpic            Equivalent to -fPIC.\n");
  printf("  -fPIE            Generates PIE assembly.\n");
  printf("  -fpie            Equivalent to -fPIE.\n");
  printf("  -fverbose-asm    Generate assembly with verbose comments.\n");
  printf("\n");
  printf("Assembler Options:\n");
  printf("  -Wa, OPT         Passes OPT to the assembler (as).\n");
  printf("  -Xassembler OPT  Passes OPT to the assembler (as).\n");
  printf("\n");
  printf("Linker Options:\n");
  printf("  -l LIB           Links the library LIB.\n");
  printf("  -L PATH          Adds PATH as library directory.\n");
  printf("  -shared          Generates shared library rather than executable.\n");
  printf("  -static          Linkes only with static libraries.\n");
  printf("  -pie             Generates PIE.\n");
  printf("  --readonly-got   Generates read-only GOT (ld -z combreloc -z now -z relro).\n");
  printf("  -nostartfiles    Do not link startup files.\n");
  printf("  -nodefaultlibs   Do not link default libraries.\n");
  printf("  -nostdlib        Enables -nostartfiles and -nodefaultlibs.\n");
  printf("  -Wl, OPT         Passes OPT to the linker (ld).\n");
  printf("  -Xlinker OPT     Passes OPT to the linker (ld).\n");
}

void Options::ParseError(const std::string& msg) {
  // throw parse error
  std::cout << "Parse Error: " << msg << std::endl;
  exit(EXIT_FAILURE);
}

void Options::Split(const std::string& s, std::vector<std::string>& sv, const char delim) {
  sv.clear();
  std::istringstream iss(s);
  std::string temp;
  while (std::getline(iss, temp, delim)) {
    sv.push_back(Trim(temp));
  }
}

std::string Options::Trim(std::string str) {
  if (str.size() == 0) {
    return str;
  }

  std::string blanks {"\t "};
  std::size_t pos = 0;
  if ((pos = str.find_first_not_of(blanks)) != std::string::npos) {
    str.erase(0, pos);
  }

  if ((pos = str.find_last_not_of(blanks)) != std::string::npos) {
    str.erase(pos + 1);
  }

  return str;
}

std::vector<std::string> Options::include_path() {
  return include_path_;
}

type::TypeTable::TypeTableClass Options::GetTypeTableClass() {
  return platform_->GetTypeTableClass();
}

} /* end compiler */

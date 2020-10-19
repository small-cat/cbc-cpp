#ifndef __SOURCE_FILE_H__
#define __SOURCE_FILE_H__

#include <string>

namespace compiler {

const static std::string EXT_CFLAT_SOURCE = ".cb";
const static std::string EXT_ASSEMBLY_SOURCE = ".s";
const static std::string EXT_OBJECT_FILE = ".o";
const static std::string EXT_STATIC_LIBRARY = ".a";
const static std::string EXT_SHARED_LIBRARY = ".so";
const static std::string EXT_EXECUTABLE_FILE = "";

static std::string KNOWN_EXTENSIONS[] = {
  EXT_CFLAT_SOURCE,
  EXT_ASSEMBLY_SOURCE,
  EXT_OBJECT_FILE,
  EXT_STATIC_LIBRARY,
  EXT_SHARED_LIBRARY,
  EXT_EXECUTABLE_FILE
};

class SourceFile  {
public:
  SourceFile(std::string filename);
  virtual ~SourceFile();

  bool IsSourceFile();
  std::string ToString();
  std::string Path();
  std::string current_name();
  void SetCurrentName(const std::string& cur);
  bool IsKnownFileType(); // check file extension 
  bool IsCFlatSource();
  bool IsAssemblySource();
  bool IsObjectFile();
  bool IsSharedLibrary();
  bool IsStaticLibrary();
  bool IsExecutable();
  std::string AsmFileName();
  std::string ObjFileName();
  std::string LinkedFileName(const std::string& new_ext);

private:
  std::string ReplaceExt(const std::string& ext);
  std::string BaseName(const std::string& path);
  std::string ExtName(const std::string& path);

private:
  std::string original_name_;
  std::string current_name_;
};
} /* end compiler */

#endif /* __SOURCE_FILE_H__ */

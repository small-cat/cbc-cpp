#ifndef __LINKER_OPTIONS_H__
#define __LINKER_OPTIONS_H__

namespace sysdep {
class LinkerOptions {
public:
  LinkerOptions();
  virtual ~LinkerOptions();

  void SetGenerateSharedLib(bool b);
  bool generate_shared_lib();
  void SetGeneratePie(bool);
  bool generate_pie();
  void SetNoStartFiles(bool b);
  bool no_start_files();
  void SetNoDefaultLibs(bool b);
  bool no_default_libs();
  void SetVerbose(bool b);
  bool verbose();
private:
  bool generate_shared_lib_;
  bool generate_pie_;
  bool no_start_files_;
  bool no_default_libs_;
  bool verbose_;
};
} /* end sysdep */

#endif /* __LINKER_OPTIONS_H__ */

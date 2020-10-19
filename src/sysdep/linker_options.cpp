#include "linker_options.h"

namespace sysdep {
LinkerOptions::LinkerOptions() : generate_shared_lib_(false),
                                 generate_pie_(false),
                                 no_start_files_(false),
                                 no_default_libs_(false),
                                 verbose_(false) {}
LinkerOptions::~LinkerOptions() {}

void LinkerOptions::SetGenerateSharedLib(bool b) {
  generate_shared_lib_ = b;
}

bool LinkerOptions::generate_shared_lib() {
  return generate_shared_lib_;
}

void LinkerOptions::SetGeneratePie(bool b) {
  generate_pie_ = b;
}

bool LinkerOptions::generate_pie() {
  return generate_pie_;
}

void LinkerOptions::SetNoStartFiles(bool b) {
  no_start_files_ = b;
}

bool LinkerOptions::no_start_files() {
  return no_start_files_;
}

void LinkerOptions::SetNoDefaultLibs(bool b) {
  no_default_libs_ = b;
}

bool LinkerOptions::no_default_libs() {
  return no_default_libs_;
}

void LinkerOptions::SetVerbose(bool b) {
  verbose_ = b;
}

bool LinkerOptions::verbose() {
  return verbose_;
}

} /* end sysdep */

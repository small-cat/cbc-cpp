#include "code_generator_options.h"

namespace sysdep {
CodeGeneratorOptions::CodeGeneratorOptions() : optimize_level_(0),
                                               generate_pic_(false),
                                               generate_pie_(false),
                                               verbose_asm_(false) {}

CodeGeneratorOptions::~CodeGeneratorOptions() {}

void CodeGeneratorOptions::SetOptimizeLevel(int l) {
  optimize_level_ = l;
}

int CodeGeneratorOptions::optimize_level() {
  return optimize_level_;
}

void CodeGeneratorOptions::GenerateVerboseAsm() {
  verbose_asm_ = true;
}

bool CodeGeneratorOptions::verbose_asm() {
  return verbose_asm_;
}

bool CodeGeneratorOptions::IsPositionIndependent() {
  return generate_pic_ || generate_pie_;
}

void CodeGeneratorOptions::GeneratePic() {
  generate_pic_ = true;
}

void CodeGeneratorOptions::GeneratePie() {
  generate_pie_ = true;
}

bool CodeGeneratorOptions::IsPicRequired() {
  return generate_pic_;
}

bool CodeGeneratorOptions::IsPieRequired() {
  return generate_pie_;
}

} /* end sysdep */

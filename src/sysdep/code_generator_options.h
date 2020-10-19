/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : code_generator_options.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-19
 * @brief : code generator options definitions
*/
#ifndef __CODEGENERATOROPTIONS_H__
#define __CODEGENERATOROPTIONS_H__

#include <stdio.h>

namespace sysdep {
class CodeGeneratorOptions {
public:
  CodeGeneratorOptions();
  virtual ~CodeGeneratorOptions();

  void SetOptimizeLevel(int l);
  int optimize_level();
  void GenerateVerboseAsm();
  bool verbose_asm();
  bool IsPositionIndependent();
  void GeneratePic();
  bool IsPicRequired();
  void GeneratePie();
  bool IsPieRequired();

private:
  int optimize_level_;
  bool generate_pic_;
  bool generate_pie_;
  bool verbose_asm_;
};
} /* end sysdep */

#endif /* __CODEGENERATOROPTIONS_H__ */

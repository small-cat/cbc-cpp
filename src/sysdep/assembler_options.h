/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : assembler_options.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-19
 * @brief : assembler options definitions
*/
#ifndef __ASSEMBLER_OPTIONS_H__
#define __ASSEMBLER_OPTIONS_H__

#include <stdio.h>
#include <string>
#include <vector>

namespace sysdep {
class AssemblerOptions  {
public:
  AssemblerOptions();
  virtual ~AssemblerOptions();

  std::vector<std::string> args();
  void AddArg(const std::string& arg);
  void SetVerbose(bool v);
  bool verbose();
private:
  bool verbose_;
  std::vector<std::string> args_;
};
} /* end sysdep */

#endif /* __ASSEMBLER_OPTIONS_H__ */

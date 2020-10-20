/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : parser.h
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-20
 * @brief : This is ...
*/
#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <vector>

namespace parser {
class FileParser {
public:
  FileParser(const std::string& filename);
  virtual ~FileParser();

  bool ParseFile();
  std::vector<std::string> GetTokenStrings();
private:
  std::string filename_;
  std::vector<std::string> token_strings_; // dump tokens
};
} /* end parser */

#endif /* __PARSER_H__ */

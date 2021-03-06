/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : source_file.cpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-16
 * @brief : source file definitions
*/
#include "source_file.h"
#include "../utils/string_utils.hpp"

namespace compiler {
SourceFile::SourceFile(std::string filename) : original_name_(filename), current_name_(filename) {}
SourceFile::~SourceFile() {}

bool SourceFile::IsSourceFile() {
  return true;
}

std::string SourceFile::ToString() {
  return current_name_;
}

std::string SourceFile::Path() {
  return current_name_;
}

std::string SourceFile::current_name() {
  return current_name_;
}

void SourceFile::SetCurrentName(const std::string& cur) {
  current_name_ = cur;
}

/**
 * @fn IsKnownFileType
 * @brief check extension of original_name_ is known or not
 * @param 
 * @author Jona
 * @date 16/10/2020 16:03:53 
*/ 
bool SourceFile::IsKnownFileType() {
  std::string ext = ExtName(original_name_);
  for (auto& e : KNOWN_EXTENSIONS) {
    if (utils::StringUtils::StrCmp(ext, e)) {
      return true;
    }
  }

  return false;
}

bool SourceFile::IsCFlatSource() {
  return utils::StringUtils::StrCmp(ExtName(current_name_), EXT_CFLAT_SOURCE);
}

bool SourceFile::IsAssemblySource() {
  return utils::StringUtils::StrCmp(ExtName(current_name_), EXT_ASSEMBLY_SOURCE);
}

bool SourceFile::IsObjectFile() {
  return utils::StringUtils::StrCmp(ExtName(current_name_), EXT_OBJECT_FILE);
}

bool SourceFile::IsSharedLibrary() {
  return utils::StringUtils::StrCmp(ExtName(current_name_), EXT_SHARED_LIBRARY);
}

bool SourceFile::IsStaticLibrary() {
  return utils::StringUtils::StrCmp(ExtName(current_name_), EXT_STATIC_LIBRARY);
}

bool SourceFile::IsExecutable() {
  return utils::StringUtils::StrCmp(ExtName(current_name_), EXT_EXECUTABLE_FILE);
}

std::string SourceFile::AsmFileName() {
  return ReplaceExt(EXT_ASSEMBLY_SOURCE);
}

std::string SourceFile::ObjFileName() {
  return ReplaceExt(EXT_OBJECT_FILE);
}

std::string SourceFile::LinkedFileName(const std::string& new_ext) {
  return ReplaceExt(new_ext);
}

// static function definitions
std::string SourceFile::ReplaceExt(const std::string& ext) {
  // replace suffix .cb with ext
  std::size_t pos = original_name_.find_last_of('.');
  if (pos == std::string::npos) {
    return original_name_;
  }

  return original_name_.substr(0, pos) + ext;
}

std::string SourceFile::BaseName(const std::string& path) {
  return utils::StringUtils::BaseName(path);
}

std::string SourceFile::ExtName(const std::string& path) {
  std::size_t pos = path.find_last_of('.');
  if (pos == std::string::npos) {
    return "";
  } else {
    return path.substr(pos);
  }
}

} /* end compiler */

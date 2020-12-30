#include <unistd.h>

#include "load_import_file.h"

namespace parser {
LoadImportFile::LoadImportFile(utils::ErrorHandler* handler) : err_handler_(handler) {
  load_path_.push_back(".");
}

LoadImportFile::~LoadImportFile() {}

void LoadImportFile::AddPath(const std::string& path) {
  load_path_.push_back(path);
}

void LoadImportFile::AddPath(std::vector<std::string> paths) {
  for (auto& p : paths) {
    load_path_.push_back(p);
  }
}

std::map<std::string, ast::Declarations *> LoadImportFile::GetAllDeclarations() {
  return decls_map_;
}

/************************************************************************************
* @fn GetImportFilePath
* @brief get file absolutely path by load_path_
* @param
* @author Jona
* @date 2020/12/29
************************************************************************************/
std::string LoadImportFile::GetImportFilePath(const std::string& filename) {
  for (auto& p : load_path_) {
    std::string filepath {""};
    if (p.back() == '/') {
      filepath = p + filename;
    } else {
      filepath = p + "/" + filename;
    }

    if (access(filepath.c_str(), F_OK) != 0) {
      continue;
    } else {
      return filepath;
    }
  }

  return "";
}

void LoadImportFile::LoadImportFile(ast::ImportFileNode* imp_file) {
  std::string fname = imp_file->filename();
  auto filepath = GetImportFilePath(fname);
  if (filepath.empty()) {
    err_handler_->Error(imp_file->location(), "can not find file " + fname);
    return;
  }

  auto search = loaded_file_map_.find(fname);
  if (search != loaded_file_map_.end()) {
    // file had been loaded, return 
    return;
  } else {
    loaded_file_map_.emplace(std::make_pair(fname, imp_file));
  }

  parser::FileParser fp(filepath);
  auto decls = fp.ParseImportFile();
  auto impfiles = fp.import_files();
}

} /* parser */
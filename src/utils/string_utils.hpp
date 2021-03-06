#ifndef __STRING_UTILS_H__
#define __STRING_UTILS_H__

#include <string>
#include <string.h>
#include <libgen.h>

namespace utils {
class StringUtils  {
public:
  StringUtils() {}
  virtual ~StringUtils() {}

  /**
   * @fn StrCmp
   * @brief string compare
   * @param 
   * @return true if lhs==rhs, otherwise false 
   * @author Jona
   * @date 16/10/2020 16:10:48 
  */ 
  static bool StrCmp(const std::string& lhs, const std::string rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }

    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
  }

  static bool StrCaseCmp(const std::string& lhs, const std::string& rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }

    return strcasecmp(lhs.c_str(), rhs.c_str()) == 0;
  }

  static std::string BaseName(const std::string& path) {
    char* base = basename((char*)(path.c_str()));
    return std::string(base);
  }

  static std::string DirName(const std::string& path) {
    char* dir = dirname((char*)(path.c_str()));
    return std::string(dir);
  }
};
} /* end utils */

#endif /* __STRING_UTILS_H__ */

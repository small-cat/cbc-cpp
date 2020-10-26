#ifndef __ASM_UTILS_H__
#define __ASM_UTILS_H__

namespace utils {
class AsmUtils {
public:
  AsmUtils() {}
  virtual ~AsmUtils() {}

  static long Align(long n, long alignment) {
    return (n + alignment - 1) & alignment;
  }
};
} /* end utils */

#endif /* __ASM_UTILS_H__ */

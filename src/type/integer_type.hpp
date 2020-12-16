#ifndef __INTEGER_TYPE_H__
#define __INTEGER_TYPE_H__

#include "type.hpp"

#include <math.h>

namespace type {
class IntegerType : public Type {
public:
  IntegerType(long size, bool is_signed, std::string name);
  virtual ~IntegerType();

  bool IsInteger();
  bool IsSigned();
  bool IsScalar();

  long MinValue();
  long MaxValue();

  bool IsInDomain(long i);
  long Size();
  bool is_signed();
  std::string name();
  friend bool operator==(const IntegerType&, const IntegerType&);
  bool IsSameType(Type* other);
  bool IsCompatible(Type* other);
  bool IsCastableTo(Type* target);
  std::string ToString();
private:
  long size_;
  bool is_signed_;
  std::string name_;
};
} /* end type */

#endif /* __INTEGER_TYPE_H__ */

#ifndef __STRUCT_TYPE_H__
#define __STRUCT_TYPE_H__

#include "type.hpp"
#include "composite_type.hpp"

// @todo { not implemented StructType }
namespace type {
class StructType : public CompositeType {
public:
  StructType() {}
  virtual ~StructType() {}

private:
};
} /* end type */

#endif /* __STRUCT_TYPE_H__ */

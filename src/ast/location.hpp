#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <vector>
#include "cflat_token.hpp"

namespace ast {
class Location {
public:
  Location(std::string name, CflatToken* t);
  Location(Location* l);
  Location(std::string name, std::string text, std::size_t i, std::size_t l, std::size_t s, std::size_t e, std::size_t pil);
  virtual ~Location();

  std::string source_name();
  CflatToken* token();

  int LineNo();
  int Column();
  std::string Line();
  std::string ToString();

private:
  std::string source_name_;
  CflatToken* token_;
};

} /* end ast */

#endif /* __LOCATION_H__ */

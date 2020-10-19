#ifndef __LOCATION_H__
#define __LOCATION_H__

namespace ast {
class Location {
public:
  Location(std::string name, antlr4::Token* t);
  Location(std::string name, CflatToken* t);
  virtual ~Location();

  std::string source_name();
  CflatToken* token();

  int LineNo();
  int Column();
  std::string Line();
  std::string NumberedLine();
  std::string ToString();

private:
  std::string source_name_;
  CflatToken* token_;
};
} /* end ast */

#endif /* __LOCATION_H__ */

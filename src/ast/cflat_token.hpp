#ifndef __CFLAT_TOKEN_H__
#define __CFLAT_TOKEN_H__

#include <string>

namespace ast {
class CflatToken {
public:
  CflatToken();
  CflatToken(std::string str, std::size_t i, std::size_t l, std::size_t s, std::size_t e, std::size_t pos_in_line);
  virtual ~CflatToken();

  std::string text();
  void SetText(std::string str);
  std::size_t index();
  void SetIndex(std::size_t i);
  std::size_t line_no();
  void SetLineNo(std::size_t ln);
  std::size_t start();
  void SetStart(std::size_t s);
  std::size_t end();
  void SetEnd(std::size_t e);
  std::string ToString(); 
  std::size_t position_in_line();
private:
  std::string text_;      // content of token
  std::size_t index_;     // index in all tokens
  std::size_t line_no_;   // line number of file which token exists
  std::size_t start_;     // start pos of token
  std::size_t end_;       // end pos of token
  std::size_t pos_in_line_; // position in current line, start from 0
};
} /* end ast */

#endif /* __CFLAT_TOKEN_H__ */

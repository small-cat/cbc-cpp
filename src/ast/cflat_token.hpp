#ifndef __CFLAT_TOKEN_H__
#define __CFLAT_TOKEN_H__

namespace ast {
class CflatToken {
public:
  CflatToken(arguments);
  virtual ~CflatToken();

private:
  antlr4::Token* token_;
};
} /* end ast */

#endif /* __CFLAT_TOKEN_H__ */

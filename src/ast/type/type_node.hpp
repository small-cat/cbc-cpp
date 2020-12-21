/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : type_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-09-24
 * @brief : type definitions, different from TypeRef, which only contain type name
*/

#ifndef __TYPE_NODE_H__
#define __TYPE_NODE_H__

#include "../node.hpp"
#include "../../type/type_ref.hpp"
#include "../../type/type.hpp"

namespace ast {
class TypeNode : public Node {
public:
  TypeNode(type::TypeRef* ref);
  TypeNode(type::Type* t);
  virtual ~TypeNode();

  type::TypeRef* type_ref();
  type::Type* type();
  bool IsResolved();
  void SetType(type::Type* t);
  Location* location();

  virtual std::string GetClass();
  void _dump(Dumper* d);

  // void Accept(ASTVisitor* visitor);
private:
  type::TypeRef* type_ref_;
  type::Type* type_;
};
} /* end ast */

#endif /* __TYPE_NODE_H__ */

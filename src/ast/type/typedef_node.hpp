/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : typedef_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : TypeDefNode
 *          typedef int newInt;
 *          int -> real, newInt->UserTypeRef, name of new type is "newInt"
*/

#ifndef __TYPEDEF_NODE_H__
#define __TYPEDEF_NODE_H__

#include "type_definition_node.hpp"
#include "../../type/type_ref.hpp"
#include "../../type/user_type.hpp"
#include "../../type/user_type_ref.hpp"

namespace ast {
class TypeDefNode : public TypeDefinitionNode {
public:
  TypeDefNode(Location* l, type::TypeRef* real, type::UserTypeRef* user_ref, std::string name);
  virtual ~TypeDefNode();

  bool IsUserType();
  TypeNode* RealTypeNode();
  type::Type* RealType();
  type::TypeRef* RealTypeRef();
  type::Type* DefiningType();

  void Dump(Dumper* d);
  // todo: Accept()

private:
  TypeNode* real_;
};
} /* end ast */

#endif /* __TYPEDEF_NODE_H__ */

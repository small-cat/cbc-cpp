/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : composite_type_definition_node.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-23
 * @brief : eg: struct _NODE_ { int a; int b; };
 *          _NODE_ -> TypeRef, name 
 *          a, b   -> members_
*/

#ifndef __COMPOSITE_TYPE_DEFINITION_NODE_H__
#define __COMPOSITE_TYPE_DEFINITION_NODE_H__

#include "type_definition_node.hpp"
#include "../location.hpp"
#include "../../type/type_ref.hpp"
#include "../slot.hpp"

#include <vector>

namespace ast {
class CompositeTypeDefinitionNode : public TypeDefinitionNode {
public:
  CompositeTypeDefinitionNode(Location* l, type::TypeRef* tr, std::string n, std::vector<SlotNode*> m);
  virtual ~CompositeTypeDefinitionNode();

  bool IsCompositeType();
  std::vector<SlotNode*> members();
  virtual std::string Kind() = 0;

  void _dump(Dumper* d);
private:
  std::vector<SlotNode*> members_;     // 聚合类型的成员
};
} /* end ast */

#endif /* __COMPOSITE_TYPE_DEFINITION_NODE_H__ */

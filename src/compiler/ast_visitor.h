/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: ast_Visitor.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2020/12/24
 * @brief: abstract interface for Visitor
*/

#ifndef __AST_VISITOR_H__
#define __AST_VISITOR_H__

namespace entity {
class DefinedFunction;
class UndefinedFunction;
class DefinedVariable;
class UndefinedVariable;
class Constant;
}

namespace ast {

class BlockNode;
class ExprStmtNode;
class IfNode;
class SwitchNode;
class CaseNode;
class WhileNode;
class DoWhileNode;
class ForNode;
class BreakNode;
class ContinueNode;
class GotoNode;
class LabelNode;
class ReturnNode;

class AssignNode;
class OpAssignNode;
class CondExprNode;
class LogicalOrNode;
class LogicalAndNode;
class BinaryOpNode;
class UnaryOpNode;
class PrefixOpNode;
class SuffixOpNode;
class ARefNode;
class MemberNode;
class PtrMemberNode;
class FuncallNode;
class DereferenceNode;
class AddressNode;
class CastNode;
class SizeofExprNode;
class SizeofTypeNode;
class VariableNode;
class IntegerLiteralNode;
class StringLiteralNode;

class StructTypeNode;
class UnionTypeNode;
class TypeDefNode;

class ASTVisitor {
public:
  ASTVisitor() {}
  virtual ~ASTVisitor() {}

  virtual void Visit(BlockNode * node) = 0;
  virtual void Visit(ExprStmtNode * node) = 0;
  virtual void Visit(IfNode * node) = 0;
  virtual void Visit(SwitchNode * node) = 0;
  virtual void Visit(CaseNode * node) = 0;
  virtual void Visit(WhileNode * node) = 0;
  virtual void Visit(DoWhileNode * node) = 0;
  virtual void Visit(ForNode * node) = 0;
  virtual void Visit(BreakNode * node) = 0;
  virtual void Visit(ContinueNode * node) = 0;
  virtual void Visit(GotoNode * node) = 0;
  virtual void Visit(LabelNode * node) = 0;
  virtual void Visit(ReturnNode * node) = 0;

  // Expressions
  virtual void Visit(AssignNode * node) = 0;
  virtual void Visit(OpAssignNode * node) = 0;
  virtual void Visit(CondExprNode * node) = 0;
  virtual void Visit(LogicalOrNode * node) = 0;
  virtual void Visit(LogicalAndNode * node) = 0;
  virtual void Visit(BinaryOpNode * node) = 0;
  virtual void Visit(UnaryOpNode * node) = 0;
  virtual void Visit(PrefixOpNode * node) = 0;
  virtual void Visit(SuffixOpNode * node) = 0;
  virtual void Visit(ARefNode * node) = 0;
  virtual void Visit(MemberNode * node) = 0;
  virtual void Visit(PtrMemberNode * node) = 0;
  virtual void Visit(FuncallNode * node) = 0;
  virtual void Visit(DereferenceNode * node) = 0;
  virtual void Visit(AddressNode * node) = 0;
  virtual void Visit(CastNode * node) = 0;
  virtual void Visit(SizeofExprNode * node) = 0;
  virtual void Visit(SizeofTypeNode * node) = 0;
  virtual void Visit(VariableNode * node) = 0;
  virtual void Visit(IntegerLiteralNode * node) = 0;
  virtual void Visit(StringLiteralNode * node) = 0;

  virtual void Visit(StructTypeNode * node) = 0;
  virtual void Visit(UnionTypeNode * node) = 0;
  virtual void Visit(TypeDefNode * node) = 0;

  virtual void Visit(entity::DefinedFunction * ent) = 0;
  virtual void Visit(entity::UndefinedFunction * ent) = 0;
  virtual void Visit(entity::DefinedVariable * ent) = 0;
  virtual void Visit(entity::UndefinedVariable * ent) = 0;
  virtual void Visit(entity::Constant * ent) = 0;
};
} /* ast */

#endif
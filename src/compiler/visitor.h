#ifndef __VISITOR_H__
#define __VISITOR_H__

#include "ast_visitor.h"
#include "ast/stmt/block_node.hpp"
#include "ast/stmt/expr_stmt_node.hpp"
#include "ast/stmt/if_node.hpp"
#include "ast/stmt/switch_node.hpp"
#include "ast/stmt/case_node.hpp"
#include "ast/stmt/while_node.hpp"
#include "ast/stmt/do_while_node.hpp"
#include "ast/stmt/for_node.hpp"
#include "ast/stmt/break_node.hpp"
#include "ast/stmt/label_node.hpp"
#include "ast/stmt/return_node.hpp"

// exprs
#include "ast/expr/assign_node.hpp"
#include "ast/expr/op_assign_node.hpp"
#include "ast/expr/cond_expr_node.hpp"
#include "ast/expr/logical_or_node.hpp"
#include "ast/expr/logical_and_node.hpp"
#include "ast/expr/binary_op_node.hpp"
#include "ast/expr/unary_op_node.hpp"
#include "ast/expr/prefix_op_node.hpp"
#include "ast/expr/suffix_op_node.hpp"
#include "ast/expr/aref_node.hpp"
#include "ast/expr/member_node.hpp"
#include "ast/expr/ptr_member_node.hpp"
#include "ast/expr/funcall_node.hpp"
#include "ast/expr/dereference_node.hpp"
#include "ast/expr/address_node.hpp"
#include "ast/expr/cast_node.hpp"
#include "ast/expr/sizeof_expr_node.hpp"
#include "ast/expr/sizeof_type_node.hpp"
#include "ast/expr/integer_literal_node.hpp"
#include "ast/expr/string_literal_node.hpp"
#include "ast/expr/variable_node.hpp"

// type
#include "ast/type/type_definition_node.hpp"
#include "ast/type/composite_type_definition_node.hpp"
#include "ast/type/struct_node.hpp"
#include "ast/type/union_node.hpp"
#include "ast/type/typedef_node.hpp"

// entity
#include "entity/defined_function.h"
#include "entity/undefined_function.h"
#include "entity/defined_variable.h"
#include "entity/undefined_variable.h"
#include "entity/constant.hpp"

namespace compiler {
class Visitor : public ast::ASTVisitor {
public:
  Visitor();
  virtual ~Visitor();

  virtual void VisitStmt(ast::StmtNode* stmt);
  virtual void VisitStmts(std::vector<ast::StmtNode *> stmts);
  virtual void VisitExpr(ast::ExprNode * expr);
  virtual void VisitExprs(std::vector<ast::ExprNode *> exprs);

  virtual void Visit(ast::BlockNode *node);
  virtual void Visit(ast::ExprStmtNode * node);
  virtual void Visit(ast::IfNode * node);
  virtual void Visit(ast::SwitchNode * node);
  virtual void Visit(ast::CaseNode * node);
  virtual void Visit(ast::WhileNode * node);
  virtual void Visit(ast::DoWhileNode * node);
  virtual void Visit(ast::ForNode * node);
  virtual void Visit(ast::BreakNode * node);
  virtual void Visit(ast::ContinueNode * node);
  virtual void Visit(ast::GotoNode * node);
  virtual void Visit(ast::LabelNode * node);
  virtual void Visit(ast::ReturnNode * node);

  // Expressions
  virtual void Visit(ast::AssignNode * node);
  virtual void Visit(ast::OpAssignNode * node);
  virtual void Visit(ast::CondExprNode * node);
  virtual void Visit(ast::LogicalOrNode * node);
  virtual void Visit(ast::LogicalAndNode * node);
  virtual void Visit(ast::BinaryOpNode * node);
  virtual void Visit(ast::UnaryOpNode * node);
  virtual void Visit(ast::PrefixOpNode * node);
  virtual void Visit(ast::SuffixOpNode * node);
  virtual void Visit(ast::ARefNode * node);
  virtual void Visit(ast::MemberNode * node);
  virtual void Visit(ast::PtrMemberNode * node);
  virtual void Visit(ast::FuncallNode * node);
  virtual void Visit(ast::DereferenceNode * node);
  virtual void Visit(ast::AddressNode * node);
  virtual void Visit(ast::CastNode * node);
  virtual void Visit(ast::SizeofExprNode * node);
  virtual void Visit(ast::SizeofTypeNode * node);
  virtual void Visit(ast::VariableNode * node);
  virtual void Visit(ast::IntegerLiteralNode * node);
  virtual void Visit(ast::StringLiteralNode * node);

  // type
  virtual void Visit(ast::StructTypeNode * node);
  virtual void Visit(ast::UnionTypeNode * node);
  virtual void Visit(ast::TypeDefNode * node);

  // entity
  virtual void Visit(entity::DefinedFunction * ent);
  virtual void Visit(entity::UndefinedFunction * ent);
  virtual void Visit(entity::DefinedVariable * ent);
  virtual void Visit(entity::UndefinedVariable * ent);
  virtual void Visit(entity::Constant * ent);
};
}

#endif
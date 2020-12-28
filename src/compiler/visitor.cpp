#include "visitor.h"

#include "entity/defined_variable.h"

namespace compiler {
Visitor::Visitor() {}
Visitor::~Visitor() {}

void Visitor::VisitStmt(ast::StmtNode * stmt) {
  stmt->Accept(this);
}

void Visitor::VisitStmts(std::vector<ast::StmtNode *> stmts) {
  for (auto& st : stmts) {
    VisitStmt(st);
  }
}

void Visitor::VisitExpr(ast::ExprNode * expr) {
  expr->Accept(this);
}

void Visitor::VisitExprs(std::vector<ast::ExprNode *> exprs) {
  for (auto& e : exprs) {
    VisitExpr(e);
  }
}

// stmt
void Visitor::Visit(ast::BlockNode *node) {
  for (auto def_var : node->variables()) {
    if (def_var->HasInitializer()) {
      VisitExpr(def_var->initializer());
    }
  }

  VisitStmts(node->stmts());
} 

void Visitor::Visit(ast::ExprStmtNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::IfNode * node) {
  VisitExpr(node->cond());
  VisitStmt(node->then_body());

  if (node->else_body() != nullptr) {
    VisitStmt(node->else_body());
  }
}

void Visitor::Visit(ast::SwitchNode * node) {
  VisitExpr(node->cond());
  for (auto& c : node->cases()) {
    Visit(c);
  }
}

void Visitor::Visit(ast::CaseNode * node) {
  VisitExprs(node->values());
  VisitStmt(node->body());
}

void Visitor::Visit(ast::WhileNode * node) {
  VisitExpr(node->cond());
  VisitStmt(node->body());
}

void Visitor::Visit(ast::DoWhileNode * node) {
  VisitExpr(node->cond());
  VisitStmt(node->body());
}

void Visitor::Visit(ast::ForNode * node) {
  VisitStmt(node->init());
  VisitExpr(node->cond());
  VisitStmt(node->incr());
  VisitStmt(node->body());
}

void Visitor::Visit(ast::BreakNode * node) {}
void Visitor::Visit(ast::ContinueNode * node) {}
void Visitor::Visit(ast::GotoNode * node) {}

void Visitor::Visit(ast::LabelNode * node) {
  VisitStmt(node->stmt());
}

void Visitor::Visit(ast::ReturnNode * node) {
  VisitExpr(node->expr());
}

// expr
void Visitor::Visit(ast::AssignNode * node) {
  VisitExpr(node->lhs());
  VisitExpr(node->rhs());
}

void Visitor::Visit(ast::OpAssignNode * node) {
  VisitExpr(node->lhs());
  VisitExpr(node->rhs());
}

void Visitor::Visit(ast::CondExprNode * node) {
  VisitExpr(node->cond());
  VisitExpr(node->then_expr());

  if (node->else_expr() != nullptr) {
    VisitExpr(node->else_expr());
  }
}

void Visitor::Visit(ast::LogicalOrNode * node) {
  VisitExpr(node->left());
  VisitExpr(node->right());
}
void Visitor::Visit(ast::LogicalAndNode * node) {
  VisitExpr(node->left());
  VisitExpr(node->right());
}

void Visitor::Visit(ast::BinaryOpNode * node) {
  VisitExpr(node->left());
  VisitExpr(node->right());
}

void Visitor::Visit(ast::UnaryOpNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::PrefixOpNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::SuffixOpNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::ARefNode * node) {
  VisitExpr(node->expr());
  VisitExpr(node->index());
}

void Visitor::Visit(ast::MemberNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::PtrMemberNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::FuncallNode * node) {
  VisitExpr(node->expr());
  VisitExprs(node->args());
}

void Visitor::Visit(ast::DereferenceNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::AddressNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::CastNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::SizeofExprNode * node) {
  VisitExpr(node->expr());
}

void Visitor::Visit(ast::SizeofTypeNode * node) {}
void Visitor::Visit(ast::VariableNode * node) {}
void Visitor::Visit(ast::IntegerLiteralNode * node) {}
void Visitor::Visit(ast::StringLiteralNode * node) {}
} /* compiler */
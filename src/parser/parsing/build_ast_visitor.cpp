#include "build_ast_visitor.h"
#include "ast/ast.hpp"

namespace parser {

BuildAstVistor::BuildAstVistor(SesameParser* parser, LibraryLoader* loader, 
                               const std::string& sname, ErrorHandler* handler) 
                              : parser_(parser), 
                                loader_(loader), 
                                source_name_(sname), 
                                err_handler_(handler) {
  tokens_ = parser_->getTokenStream();
}

BuildAstVistor::~BuildAstVistor() {}

void BuildAstVistor::AddKnownTypedefs(std::vector<TypedefNode*> typedefs) {
  for (auto t : typedefs) {
    known_typedefs_.push_back(t.name());
  }
}

antlrcpp::Any BuildAstVistor::visitCompilation_unit(SesameParser::Compilation_unitContext* ctx) {
  ast::ASTNode* ast = new ast::ASTNode();
  auto import_stmt_ctxs = ctx->import_stmt();

  for (auto import_stmt_ctx : import_stmt_ctxs) {
    std::string imp = tokens_->getText(import_stmt_ctx->import_name());
    ast::Declarations* import_decl = loader_->LoadLibrary(imp);
    ast->AddDeclarations(import_decl);
    AddKnownTypedefs(import_decl.typedefs());   // add all typedef definitions
  }

  auto top_def_ctxs = ctx->top_def();
  for (auto top_ctx : top_def_ctxs) {
    Declarations* decl = (Declarations*)visit(top_ctx);
    ast->AddDeclarations(decl);
  }

  return (antlrcpp::Any)ast;
}

antlrcpp::Any BuildAstVistor::visitTop_def(SesameParser::Top_defContext* ctx) {
  Declarations* decl = new Declarations();
  if (ctx->def_func()) {
    // define function
    DefinedFunction* defun = (DefinedFunction*)visit(ctx->def_func());
    decl->AddDefun(defun);
  } else if (ctx->def_vars()) {
    // define variable
    DefinedVariable* defvar = (DefinedVariable*)visit(ctx->def_vars());
    decl->AddDefvar(defvar);
  } else if (ctx->def_const()) {
    Constant* cons = (Constant*)visit(ctx->def_const());
    decl->AddConstant(cons);
  } else if (ctx->def_struct()) {
    StructTypeNode* s = (StructTypeNode*)visit(ctx->def_struct());
    decl->AddStruct(s);
  } else if (ctx->def_union()) {
    UnionTypeNode* u = (UnionTypeNode*)visit(ctx->def_union());
    decl->AddUnion(u);
  } else if (ctx->s_typedef()) {
    TypedefNode* t = (TypedefNode*)visit(ctx->s_typedef());
    decl->AddTypedef(t);
  }

  return (antlrcpp::Any)decl;
}

antlrcpp::Any BuildAstVistor::visitDef_func(SesameParser::Def_funcContext* ctx) {

}

} /* end parser */

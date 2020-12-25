#include "funcall_node.hpp"
#include "../../type/pointer_type.hpp"

namespace ast {
FuncallNode::FuncallNode(ExprNode* expr, std::vector<ExprNode*> args) : expr_(expr) {
  args_.swap(args);
}

FuncallNode::~FuncallNode() {
  if (nullptr != expr_) {
    delete expr_;
    expr_ = nullptr;
  }

  for (auto& arg : args_) {
    delete arg;
    arg = nullptr;
  }
}

ExprNode* FuncallNode::expr() {
  return expr_;
}

std::vector<ExprNode*> FuncallNode::args() {
  return args_;
}

/**
 * @fn type
 * @brief returns a type of return value of the function which is refered
 *        by expr. This method expects expr->type()->IsCallable() is true
 * @param 
 * @author Jona
 * @date 21/10/2020 15:40:25 
*/ 
type::Type* FuncallNode::type() {
  return GetFunctionType()->return_type();
}

/**
 * @fn GetFunctionType
 * @brief returns a type of function which is refered by expr. This method
 *        expects expr->type()->IsCallable() is true.
 * @param 
 * @author Jona
 * @date 21/10/2020 15:45:05 
*/ 
type::FunctionType* FuncallNode::GetFunctionType() {
  return expr_->type()->GetPointerType()->base_type()->GetFunctionType();
}

long FuncallNode::NumOfArgs() {
  return args_.size();
}

Location* FuncallNode::location() {
  return expr_->location();
}

std::string FuncallNode::GetClass() {
  return "FunctioncallNode";
}

void FuncallNode::_dump(Dumper* d) {
  d->PrintMember("Expr", expr_);
  d->PrintNodeList("Arguments", args_);
}

void FuncallNode::Accept(ASTVisitor * visitor) {
  visitor->Visit(this);
}

} /* end ast */

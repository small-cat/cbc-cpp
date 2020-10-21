#include "funcall_node.hpp"

namespace ast {
FuncallNode::FuncallNode(ExprNode* expr, std::vector<ExprNode*> args) : expr_(expr) {
  args_.swap(args);
}

FuncallNode::~FuncallNode() {}

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
  return GetFunctionType()->ReturnType();
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
  return expr->type()->GetPointerType()->BaseType()->GetFunctionType();
}

long FuncallNode::NumOfArgs() {
  return args_.size();
}

Location* FuncallNode::location() {
  return expr->location();
}

void FuncallNode::_dump(Dumper* d) {
  d->PrintMember("expr", expr_);
  d->PrintNodeList("args", args_);
}

} /* end ast */
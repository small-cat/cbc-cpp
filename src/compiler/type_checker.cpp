/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: type_checker.cpp
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/12
 * @brief: TypeChecker 中申请的 node 节点，也都由 tracker 统一管理
*/
#include "type_checker.h"
#include "utils/cpp_utils.hpp"
#include "type/integer_type.hpp"
#include "type/integer_type_ref.h"

namespace compiler {
TypeChecker::TypeChecker(type::TypeTable *tb, utils::ErrorHandler *err) : table_(tb), handler_(err) {}
TypeChecker::~TypeChecker() {
  ast_node_tracker_.Reset();
}

std::map<std::string, int> TypeChecker::BinaryOpMaps = {
  {"+", 0},
  {"-", 1},

  {"*", 2},
  {"/", 3},
  {"%", 4},
  {"&", 5},
  {"|", 6},
  {"^", 7},
  {"<<", 8},
  {">>", 9},

  {"==", 10},
  {"!=", 11},
  {"<",  12},
  {"<=", 13},
  {">",  14},
  {">=", 15},
};

void TypeChecker::Check(ast::StmtNode *node) {
  VisitStmt(node);
}

void TypeChecker::Check(ast::ExprNode *node) {
  VisitExpr(node);
}

void TypeChecker::Check(ast::ASTNode *ast) {
  for (auto defvar : ast->DefinedVariables()) {
    CheckVariable(defvar);
  }

  for (auto defun : ast->DefinedFunctions()) {
    cur_function_ = defun;
    CheckReturnType(defun);
    CheckParamTypes(defun);
    Check(defun->body());
  }

  if (handler_->ErrorOccured()) {
    handler_->Error("Compile failed in TypeCheck");
    exit(EXIT_FAILURE);
  }
}

void TypeChecker::CheckReturnType(entity::DefinedFunction *defun) {
  if (IsInvalidReturnType(defun->ReturnType())) {
    handler_->Error(defun->GetLocation(), "returns invalid type: " + defun->ReturnType()->ToString());
  }
}

void TypeChecker::CheckParamTypes(entity::DefinedFunction *defun) {
  for (auto param : defun->GetParameters()) {
    if (IsInvalidParameterType(param->GetType())) {
      handler_->Error(param->GetLocation(), "invalid parameter type: " + param->GetType()->ToString());
    }
  }
}

// statements
void TypeChecker::Visit(ast::BlockNode *node) {
  for (auto var : node->variables()) {
    CheckVariable(var);
  }

  for (auto stmt : node->stmts()) {
    Check(stmt);
  }
}

void TypeChecker::CheckVariable(entity::DefinedVariable *defvar) {
  if (IsInvalidVariableType(defvar->GetType())) {
    handler_->Error(defvar->GetLocation(), "invalid variable type: " + defvar->GetType()->ToString());
    return;
  }

  if (defvar->HasInitializer()) {
    if (IsInvalidLHSType(defvar->GetType())) {
      handler_->Error(defvar->GetLocation(), "invalid LHS type: " + defvar->GetType()->ToString());
      return;
    }

    Check(defvar->initializer());

    // 如果左值的类型与初始化的值类型不同，需要进行一次隐式类型转换
    defvar->SetInitializer(ImplicitCast(defvar->GetType(), defvar->initializer()));
  }
}

void TypeChecker::Visit(ast::ExprStmtNode *node) {
  Check(node->expr());
  if (IsInvalidStatementType(node->expr()->type())) {
    handler_->Error(node->location(), "invalid statement type: " + node->expr()->type()->ToString());
  }
}

void TypeChecker::Visit(ast::IfNode *node) {
  Visitor::Visit(node);
  CheckCond(node->cond());
}

void TypeChecker::Visit(ast::WhileNode *node) {
  Visitor::Visit(node);
  CheckCond(node->cond());
}

void TypeChecker::Visit(ast::ForNode *node) {
  Visitor::Visit(node);
  CheckCond(node->cond());
}

void TypeChecker::CheckCond(ast::ExprNode *cond) {
  MustBeScalar(cond, "condition expression");
}

void TypeChecker::Visit(ast::SwitchNode *node) {
  Visitor::Visit(node);
  MustBeInteger(node->cond(), "switch condition expression");
}

void TypeChecker::Visit(ast::ReturnNode *node) {
  Visitor::Visit(node);

  if (cur_function_->IsVoid()) {
    if (node->expr() != nullptr) {
      handler_->Error(node->location(), "returning value from void function");
    }
  } else {
    // non void function
    if (node->expr() == nullptr) {
      handler_->Error(node->location(), "missing return value");
      return;
    }

    if (node->expr()->type()->IsVoid()) {
      handler_->Error(node->location(), "returning void");
      return;
    }

    node->SetExpr(ImplicitCast(cur_function_->ReturnType(), node->expr()));
  }
}

// assignment expressions
void TypeChecker::Visit(ast::AssignNode *node) {
  Visitor::Visit(node);
  if (!CheckLHS(node->lhs())) {
    return;
  }

  if (!CheckRHS(node->rhs())) {
    return;
  }

  node->SetRHS(ImplicitCast(node->lhs()->type(), node->rhs()));
}

/************************************************************************************
* @fn Visit(ast::OpAssignNode *node)
* @brief 复合操作符，比如 += -= *= /= %= |= ^= <<= >>=
*        左值和右值是指针，整数或者类型相同的整数其中，只有 +=， -= 左值可以是指针
* @param
* @author Jona
* @date 2021/01/12
************************************************************************************/
void TypeChecker::Visit(ast::OpAssignNode *node) {
  Visitor::Visit(node);
  if (!CheckLHS(node->lhs())) { return; }
  if (!CheckRHS(node->rhs())) { return; }

  std::string op = node->OpAssignOperator();
  if (utils::StringUtils::StrCmp(op, "+=") || utils::StringUtils::StrCmp(op, "-=")) {
    // 如果左值是指针，那么右值必须是integer
    if (node->lhs()->type()->IsPointer()) {
      MustBeInteger(node->rhs(), op);
      node->SetRHS(IntegerPromotedExpr(node->rhs()));
      return;
    }
  }

  if (!MustBeInteger(node->lhs(), op)) { return; }
  if (!MustBeInteger(node->rhs(), op)) { return; }

  type::Type *left = IntegerPromotion(node->lhs()->type());
  type::Type *right = IntegerPromotion(node->rhs()->type());

  // 根据左右类型，计算返回值类型 - 根据integer类型优先级计算
  type::Type *optype = UsualArithmeticConversion(left, right);
  if (!optype->IsCompatible(left) && !IsSafeIntegerCast(node->rhs(), optype)) {
    handler_->Warn(node->location(), 
      "imcompatible implicit cast from " + optype->ToString() + " to " + left->ToString());
  }

  // 如果返回值类型与右值不同，将右值转换成optype在进行赋值
  if (!right->IsSameType(optype)) {
    auto castnode = GetCastNode(optype, node->rhs());
    node->SetRHS(castnode);
  }
}

/************************************************************************************
* @fn Visit(ast::CondExprNode *node)
* @brief 三目操作符
* @param
* @author Jona
* @date 2021/01/12
************************************************************************************/
void TypeChecker::Visit(ast::CondExprNode *node) {
  Visitor::Visit(node);
  CheckCond(node->cond());

  type::Type *then_t = node->then_expr()->type();
  type::Type *else_t = node->else_expr()->type();
  if (then_t->IsSameType(else_t)) {
    // no error
    return;
  }

  if (then_t->IsCompatible(else_t)) {
    auto castnode = GetCastNode(else_t, node->then_expr());
    node->SetThen(castnode);
  } else if (else_t->IsCompatible(then_t)) {
    auto castnode = GetCastNode(then_t, node->else_expr());
    node->SetElse(castnode);
  } else {
    handler_->Error(node->then_expr()->location(), 
      "invalid cast from " + then_t->ToString() + " to " + else_t->ToString());
  }
}

void TypeChecker::Visit(ast::BinaryOpNode *node) {
  Visitor::Visit(node);
  std::string op = node->BinaryOpOperator();
  int idx = FindBinaryOp(op, BinaryOpMaps);
  if (utils::StringUtils::StrCmp(op, "+") || utils::StringUtils::StrCmp(op, "-")) {
    ExpectsSameIntegerOrPointerDiff(node);
  } else if (idx >= 2 && idx <= 9) {
    ExpectsSameInteger(node);
  } else if (idx >= 10 && idx <= 15) {
    ExpectsComparableScalars(node);
  } else {
    handler_->Error(node->location(), "unknown binary operator: " + op);
    return;
  }
}

void TypeChecker::Visit(ast::LogicalAndNode *node) {
  Visitor::Visit(node);
  ExpectsComparableScalars(node);
}

void TypeChecker::Visit(ast::LogicalOrNode *node) {
  Visitor::Visit(node);
  ExpectsComparableScalars(node);
}

void TypeChecker::Visit(ast::UnaryOpNode *node) {
  Visitor::Visit(node);
  if (utils::StringUtils::StrCmp(node->UnaryOpNodeOperator(), "!")) {
    MustBeScalar(node->expr(), node->UnaryOpNodeOperator());
    return;
  }

  MustBeInteger(node->expr(), node->UnaryOpNodeOperator());
}

void TypeChecker::Visit(ast::PrefixOpNode *node) {
  Visitor::Visit(node);
  ExpectsScalarLHS(node);
}

void TypeChecker::Visit(ast::SuffixOpNode *node) {
  Visitor::Visit(node);
  ExpectsScalarLHS(node);
}

/************************************************************************************
* @fn Visit(ast::FuncallNode *node)
* @brief 函数原型检查
* 1. 检查函数参数个数是否与函数原型匹配
* 2. 检查参数类型是否与函数原型匹配
* 3. 检查参数是否是 struct 或者 union，参数不支持 struct 或者 union
* @param
* @author Jona
* @date 2021/01/13
************************************************************************************/
void TypeChecker::Visit(ast::FuncallNode *node) {
  Visitor::Visit(node);
  type::FunctionType *ftype = node->GetFunctionType();
  if (!ftype->AcceptsArgc(node->NumOfArgs())) {
    handler_->Error(node->location(), "wrong number of arguments: " + std::to_string(node->NumOfArgs()));
    return;
  }

  std::vector<ast::ExprNode *> new_args;

  auto args = node->args();
  auto pam_types = ftype->GetParamTypes();
  std::vector<ast::ExprNode *>::size_type pos = 0;

  // 检查实参类型和行参类型，不一致就做隐式类型转换
  // 对于可变参数函数，先检查固定参数，然后检查可变参数部分
  for (; pos < args.size(); pos ++) {
    auto tmp = args.at(pos);
    new_args.push_back(CheckRHS(tmp) ? ImplicitCast(pam_types.at(pos), tmp) : tmp);
  }
  
  for (; pos < args.size(); pos++) {
    // 可变参数部分
    auto tmp = args.at(pos);
    new_args.push_back(CheckRHS(tmp) ? CastOptionalArg(tmp) : tmp);
  }

  node->SetArgs(new_args);
}

void TypeChecker::Visit(ast::ARefNode *node) {
  Visitor::Visit(node);
  MustBeInteger(node->index(), "[]");
}

void TypeChecker::Visit(ast::CastNode *node) {
  Visitor::Visit(node);
  if (!node->expr()->type()->IsCastableTo(node->type())) {
    handler_->Error(node->location(), "invalid cast from " + node->expr()->type()->ToString() + " to " + node->type()->ToString());
    return;
  }
}

/************************************************************************************
* @fn ImplicitCast
* @brief 隐式类型转换, 用于函数返回值，赋值计算，或者函数参数传递时使用
* @param target 转换成的目标类型
* @param expr 待转换的表达式
* @author Jona
* @date 2021/01/12
************************************************************************************/
ast::ExprNode* TypeChecker::ImplicitCast(type::Type *target, ast::ExprNode *expr) {
  auto t = expr->type();
  if (t->IsSameType(target)) {
    return expr;
  } else if (t->IsCastableTo(target)) {
    if (!t->IsCompatible(target) && !IsSafeIntegerCast(expr, target)) {
      handler_->Warn(expr->location(), 
        "incompatible implicit cast from " + t->ToString() + " to " + target->ToString());
    }

    auto new_expr = GetCastNode(target, expr);
    return new_expr;
  } else {
    handler_->Error(expr->location(), "invalid cast from " + t->ToString() + " to " + target->ToString());
    return expr;
  }
}

bool TypeChecker::CheckLHS(ast::ExprNode *lhs) {
  if (lhs->IsParameter()) {
    // parameter is always assignable
    return true;
  } else if (IsInvalidLHSType(lhs->type())) {
    handler_->Error(lhs->location(), "invalid lhs expression type: " + lhs->type()->ToString());
    return false;
  }

  return true;
}

bool TypeChecker::CheckRHS(ast::ExprNode *rhs) {
  if (IsInvalidLHSType(rhs->type())) {
    handler_->Error(rhs->location(), "invalid rhs expression type: " + rhs->type()->ToString());
    return false;
  }

  return true;
}

/************************************************************************************
* @fn IsInvalidStatementType
* @brief 表达式语句的返回类型，因为 struct 和 union 的表达式不能进行赋值和其他运，表达式语句也不可能返回这些类型
* @param
* @author Jona
* @date 2021/01/12
************************************************************************************/
bool TypeChecker::IsInvalidStatementType(type::Type *t) {
  return t->IsStruct() || t->IsUnion();
}

/************************************************************************************
* @fn IsInvalidReturnType
* @brief 函数不支持返回 struct，union 和 array 类型
* @param
* @author Jona
* @date 2021/01/12
************************************************************************************/
bool TypeChecker::IsInvalidReturnType(type::Type *t) {
  return t->IsStruct() || t->IsUnion() || t->IsArray();
}

bool TypeChecker::IsInvalidParameterType(type::Type *t) {
  // 数组是可以作为函数参数进行传递的
  return t->IsStruct() || t->IsUnion() || t->IsVoid() || t->IsIncompleteArray();
}

bool TypeChecker::IsInvalidVariableType(type::Type *t) {
  return t->IsVoid() || (t->IsArray() && !t->IsAllocatedArray());
}

/************************************************************************************
* @fn IsInvalidLHSType
* @brief 检查左值类型，左值是可以被赋值的，但是不支持对 struct，union，array 和 void 类型进行赋值.
*        但是，数组类型如果作为函数行参，是可以被赋值的
* @param
* @author Jona
* @date 2021/01/12
************************************************************************************/
bool TypeChecker::IsInvalidLHSType(type::Type *t) {
  return t->IsStruct() || t->IsUnion() || t->IsArray() || t->IsVoid();
}

bool TypeChecker::IsInvalidRHSType(type::Type *t) {
  return t->IsStruct() || t->IsUnion() || t->IsVoid();
}

/************************************************************************************
* @fn IsSafeIntegerCast
* @brief 安全的整型隐式类型转换，比如 char c = 0; 0 就是整型，将 0 转换成 (char)0 就是安全的。
*        在cbc中，char，short，int，long，unsigned……都是 IntegerType。IntegerType 转换
*        成 IntegerType 才是安全的，否则就是不安全的
* @param node 待转换的表达式
* @param t 将整型转换成的目标类型
* @author Jona
* @date 2021/01/12
************************************************************************************/
bool TypeChecker::IsSafeIntegerCast(ast::Node *node, type::Type *t) {
  if (!t->IsInteger()) {
    return false;
  }

  auto int_type = t->GetIntegerType();
  if (!utils::is<ast::IntegerLiteralNode *>(int_type)) {
    return false;
  }

  // 判断整型数值是否是有效值
  ast::IntegerLiteralNode *n = (ast::IntegerLiteralNode *)node;
  return int_type->IsInDomain(n->value());
}

// expr 的类型必须是整型
bool TypeChecker::MustBeInteger(ast::ExprNode *expr, std::string op) {
  if (!expr->type()->IsInteger()) {
    handler_->Error(expr->location(), "wrong operand type for " + op + ": " + expr->type()->ToString());
    return false;
  }

  return true;
}

bool TypeChecker::MustBeScalar(ast::ExprNode *expr, std::string op) {
  if (!expr->type()->IsScalar()) {
    handler_->Error(expr->location(), "wrong operand type for " + op + ": " + expr->type()->ToString());
    return false;
  }
  return true;
}

int TypeChecker::FindBinaryOp(const std::string &op, std::map<std::string, int> op_map) {
  auto search = op_map.find(op);
  if (search == op_map.end()) {
    return -1;
  } 

  return search->second;
}

/************************************************************************************
* @fn ExpectsSameIntegerOrPointerDiff
* @brief 对于 + 和 - 表达式，左右表达式的类型如下
*        case 1: integer + integer
*        case 2: pointer + integer
*        case 3: integer + pointer
*        case 4: integer - integer
*        case 5: pointer - integer
*        case 6: pointer - pointer
* @param
* @author Jona
* @date 2021/01/12
************************************************************************************/
void TypeChecker::ExpectsSameIntegerOrPointerDiff(ast::BinaryOpNode *node) {
  auto left = node->left();
  auto right = node->right();
  std::string op = node->BinaryOpOperator();
  
  if (left->type()->IsPointer() && right->type()->IsPointer()) {
    // case 6
    if (utils::StringUtils::StrCmp(op, "+")) {
      handler_->Error(node->location(), "invalid binary operation for pointer + pointer");
      return;
    }

    node->SetType(table_->PtrDiffType());
  } else if (left->type()->IsPointer()) {
    // case 2 and case 5
    MustBeInteger(right, op);

    // promote integer for pointer calculation
    // 指针增长按照指针所指向的类型作为步长
    node->SetRight(IntegerPromotedExpr(right));
    node->SetType(left->type());
  } else if (right->type()->IsPointer()) {
    // case 3
    if (utils::StringUtils::StrCmp(op, "-")) {
      handler_->Error(node->location(), "invalid operation: integer - pointer");
      return;
    }

    MustBeInteger(left, op);
    node->SetLeft(IntegerPromotedExpr(left));
    node->SetType(right->type());
  } else {
    // case 1 and case 4
    ExpectsSameInteger(node);
  }
}

/************************************************************************************
* @fn ExpectsSameInteger
* @brief +， -， *， /， %， &， |， ^， <<, >>
* @param
* @author Jona
* @date 2021/01/12
************************************************************************************/
void TypeChecker::ExpectsSameInteger(ast::BinaryOpNode *node) {
  if (!MustBeInteger(node->left(), node->BinaryOpOperator())) { return; }
  if (!MustBeInteger(node->right(), node->BinaryOpOperator())) { return; }

  ArithmeticImplicitCast(node);
}

/************************************************************************************
* @fn IntegerPromotedExpr
* @brief 隐式类型转换，提升表达式的类型，向更高兼容的整型类型转换
* @param
* @author Jona
* @date 2021/01/12
************************************************************************************/
ast::ExprNode* TypeChecker::IntegerPromotedExpr(ast::ExprNode *node) {
  type::Type *t = IntegerPromotion(node->type());
  if (t->IsSameType(node->type())) {
    // 不需要隐式类型转换
    return node;
  } else {
    return GetCastNode(t, node);
  }
}

// 仅对整型做类型转换，转换成 int
// 将 signed char、unsigned char、signed short、unsigned short 转换为 signed int
type::Type* TypeChecker::IntegerPromotion(type::Type *t) {
  if (!t->IsInteger()) {
    handler_->Error("IntegerPromotion for " + t->ToString());
    exit(EXIT_FAILURE);
  }

  type::Type *int_type = table_->GetIntegerType(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT);
  if (t->Size() < int_type->Size()) {
    return int_type;
  } else {
    return t;
  }
}

/************************************************************************************
* @fn UsualArithmeticConversion
* @brief usual arithmetic conversion for ILP32 platform (integers only) 
* 1. 首先将 signed char、unsigned char、signed short、unsigned short 转换为 signed int,
     再按照下述步骤比较两者的类型
* 2. 按照 unsigned long、signed long、unsigned int、signed int 的优先顺序选用类型,使两者的类型相一致
* 3. 只有当一方为 unsigned int,另一方为 signed long 时 , 要例外地统一成 unsigned long
* @param
* @author Jona
* @date 2021/01/13
************************************************************************************/
type::Type* TypeChecker::UsualArithmeticConversion(type::Type *l, type::Type *r) {
  type::Type *s_int  = table_->GetIntegerType(type::IntegerTypeRef::IntegerTypeClass::SESAME_INT);
  type::Type *u_int  = table_->GetIntegerType(type::IntegerTypeRef::IntegerTypeClass::SESAME_UINT); 
  type::Type *s_long = table_->GetIntegerType(type::IntegerTypeRef::IntegerTypeClass::SESAME_LONG);
  type::Type *u_long = table_->GetIntegerType(type::IntegerTypeRef::IntegerTypeClass::SESAME_ULONG);

  // case 3
  if ((l->IsSameType(u_int) && r->IsSameType(s_long))
     || (l->IsSameType(s_long) && r->IsSameType(u_int))) {
       return u_long;
  }

  if (l->IsSameType(u_long) || r->IsSameType(u_long)) {
    return u_long;
  }

  if (l->IsSameType(s_long) || r->IsSameType(s_long)) {
    return s_long;
  }

  if (l->IsSameType(u_int) || r->IsSameType(u_int)) {
    return u_int;
  }

  return s_int;
}

/************************************************************************************
* @fn ExpectsComparableScalars
* @brief 用于比较操作，检查左右两边表达式的类型。如 ==, !=, >, >=, <, <=, &&, ||, 返回结果为 bool。
*        左右两边可以是类型相同的整数，指针
* @param
* @author Jona
* @date 2021/01/13
************************************************************************************/
void TypeChecker::ExpectsComparableScalars(ast::BinaryOpNode *node) {
  auto l = node->left();
  auto r = node->right();
  std::string op = node->BinaryOpOperator();
  if (!MustBeScalar(l, op)) { return; }
  if (!MustBeScalar(r, op)) { return; }

  if (l->type()->IsPointer()) {
    auto right = ForcePointerType(l, r);
    node->SetRight(right);
    node->SetType(l->type());
    return;
  }

  if (r->type()->IsPointer()) {
    auto left = ForcePointerType(r, l);
    node->SetLeft(left);
    node->SetType(r->type());
    return;
  }
  ArithmeticImplicitCast(node);
}

/************************************************************************************
* @fn ForcePointerType
* @brief cast slave node type to master node type
* @param
* @author Jona
* @date 2021/01/13
************************************************************************************/
ast::ExprNode* TypeChecker::ForcePointerType(ast::ExprNode *master, ast::ExprNode *slave) {
  if (master->type()->IsCompatible(slave->type())) {
    return slave;
  }

  handler_->Warn(slave->location(), 
    "incompatible implicit cast from " + slave->type()->ToString() + " to " + master->type()->ToString());

  return GetCastNode(master->type(), slave);
}

void TypeChecker::ArithmeticImplicitCast(ast::BinaryOpNode *node) {
  auto l = IntegerPromotion(node->left()->type());
  auto r = IntegerPromotion(node->right()->type());
  auto target = UsualArithmeticConversion(l, r);

  if (!l->IsSameType(target)) {
    node->SetLeft(GetCastNode(target, node->left()));
  }

  if (!r->IsSameType(target)) {
    node->SetRight(GetCastNode(target, node->right()));
  }

  node->SetType(target);
}

/************************************************************************************
* @fn GetCastNode
* @brief return cast node, cast expr to type t
* @param expr the target expression to cast
* @param t the target type
* @author Jona
* @date 2021/01/13
************************************************************************************/
ast::CastNode* TypeChecker::GetCastNode(type::Type *t, ast::ExprNode *expr) {
  ast::TypeNode *tn = ast_node_tracker_.CreateInstance<ast::TypeNode>(t);
  ast::CastNode *cn = ast_node_tracker_.CreateInstance<ast::CastNode>(tn, expr);

  return cn;
}

void TypeChecker::ExpectsScalarLHS(ast::UnaryArithmeticOpNode *node) {
  if (node->expr()->IsParameter()) {
    /// parameter is always a scalar
    return;
  }

  auto t = node->expr()->type();
  if (node->expr()->type()->IsArray()) {
    handler_->Error(node->location(), "wrong operand type for " + node->UnaryOpNodeOperator() + ": " + t->ToString());
    return;
  }

  MustBeScalar(node->expr(), node->UnaryOpNodeOperator());

  if (t->IsInteger()) {
    type::Type *optype = IntegerPromotion(t);
    if (!t->IsSameType(optype)) {
      node->SetOpType(optype);
    }
    node->SetAmount(1);
  } else if (t->IsPointer()) {
    if (t->base_type()->IsVoid()) {
      // can not increment/decrement void*
      handler_->Error(node->location(), "wrong operand type for " + node->UnaryOpNodeOperator() + ": " + t->ToString());
      return;
    }
    node->SetAmount(t->base_type()->Size());
  } else {
    handler_->Error(node->location(), "ExpectsScalarLHS wrong");
  }
}

/************************************************************************************
* @fn CastOptionalArg
* @brief 对函数可变参数部分进行的类型转换
* @param
* @author Jona
* @date 2021/01/13
************************************************************************************/
ast::ExprNode* TypeChecker::CastOptionalArg(ast::ExprNode *arg) {
  if (!arg->type()->IsInteger()) {
    return arg;
  }

  // arg is integer, 隐式转换成 long 或者 unsigned long
  auto t = arg->type()->IsSigned() ? table_->SignedStackType() : table_->UnsignedStackType();
  return arg->type()->Size() < t->Size() ? ImplicitCast(t, arg) : arg;
}

} /* compiler */
parser grammar SesameParser;

options {
    tokenVocab = SesameLexer;
}

@parser::postinclude {
#include <string.h>
}

compilation_unit
    : import_stmt* top_defs
    ;

declaration_file
    : import_stmt* declaration_stmt* 
    ;

declaration_stmt
    : func_decl | var_decl | def_const | def_struct | def_union | s_typedef
    ;

// import stdio -> #include <stdio.h>
// import sys.types -> #include <sys/types.h>
import_stmt
    : S_IMPORT import_name SEMI
    ;

import_name
    : name (PERIOD name)*
    ;

name 
    : IDENTIFIER
    ;

func_decl
    : S_EXTERN typeref name LPAREN params RPAREN SEMI
    ;

var_decl
    : S_EXTERN type name SEMI
    ;

top_defs
    : (def_func
    | def_vars
    | def_const
    | def_struct
    | def_union
    | s_typedef)*
    ;

def_func
    : storage? typeref name LPAREN params? RPAREN block
    ;

storage
    : S_STATIC
    ;

// 1. params is empty or void
// 2. fixed params. (int a, double b)
// 3. varadic params, (char* fmt, ...)
params
    : /*{strcasecmp(_input->LA(1), "void")==0}?*/ S_VOID
    | fixed_params (COMMA CDOTS)?
    ;

fixed_params
    : param (COMMA param)*
    ;

param
    : type name
    ;

block
    : LBRACE def_vars* stmts RBRACE
    ;

def_vars
    : storage? type assign_expr (COMMA assign_expr)* SEMI
    ;

assign_expr
    : name (EQUAL expr)?
    ;

def_const
    : S_CONST type name EQUAL expr SEMI
    ;

def_struct
    : S_STRUCT name member_list SEMI
    ;

def_union
    : S_UNION name member_list SEMI
    ;

member_list
    : LBRACE (slot SEMI)* RBRACE
    ;

slot
    : type name
    ;

s_typedef
    : S_TYPEDEF typeref IDENTIFIER SEMI 
    ;

type
    : typeref
    ;

typeref
    : typeref_base typeref_precise*
    ;

typeref_base
    : S_VOID                # typeref_void
    | S_CHAR                # typeref_char
    | S_SHORT               # typeref_short
    | S_INT                 # typeref_int
    | S_LONG                # typeref_long
    | S_UNSIGNED (S_CHAR | S_SHORT | S_INT | S_LONG)     # typeref_unsigned
    | S_STRUCT IDENTIFIER   # typeref_struct
    | S_UNION IDENTIFIER    # typeref_union
    | IDENTIFIER            # typeref_usertype // here, the type named identifier must be typedef
    ;

typeref_precise
    : LBRACKET INTEGER? RBRACKET      // [2]
    | ASTERISK                       // pointer  
    | LPAREN param_typerefs RPAREN   // function pointer
    ;

param_typerefs
    : S_VOID
    | fixed_param_typerefs (COMMA CDOTS)?
    ;

fixed_param_typerefs
    : typeref (COMMA typeref)*
    ;

stmts
    : stmt*
    ;

stmt
    : SEMI
    | labeled_stmt      // the label for goto
    | expr_stmt
    | block
    | if_stmt
    | while_stmt
    | do_while_stmt
    | for_stmt
    | switch_stmt
    | break_stmt
    | continue_stmt
    | goto_stmt
    | return_stmt
    ;

labeled_stmt
    : label_name=IDENTIFIER COLON stmt
    ;

expr_stmt
    : expr SEMI
    ;

// if (cond) ... else ... 
if_stmt
    : S_IF LPAREN expr RPAREN then_stmt=stmt (S_ELSE else_stmt=stmt)?
    ;

while_stmt
    : S_WHILE LPAREN expr RPAREN stmt
    ;

do_while_stmt
    : S_DO body=stmt S_WHILE LPAREN cond=expr RPAREN SEMI
    ;

for_stmt
    : S_FOR LPAREN init=expr? SEMI cond=expr? SEMI incr=expr RPAREN body=stmt
    ;

switch_stmt
    : S_SWITCH LPAREN cond=expr RPAREN LBRACE body=case_clauses RBRACE
    ;

case_clauses
    : case_clause* default_clause?
    ;

case_clause
    : values=cases body=case_body
    ;

cases
    : (S_CASE primary COLON)+
    ;

default_clause
    : S_DEFAULT COLON body=case_body
    ;

case_body
    : stmt+
    ;

break_stmt
    : S_BREAK SEMI
    ;

continue_stmt
    : S_CONTINUE SEMI
    ;

goto_stmt
    : S_GOTO label_name=IDENTIFIER SEMI
    ;

return_stmt
    : S_RETURN expr? SEMI
    ;

// expression definitions
expr
    : term EQUAL expr        # assignment_expr
    | term opassign_op expr  # op_assign_expr
    | expr10                 # expression_10
    ;

// += -= *= /= %= |= ^= <<= >>=
opassign_op
    : PLUS EQUAL
    | MINUS EQUAL
    | ASTERISK EQUAL
    | SOLIDUS EQUAL
    | PERCENT EQUAL
    | AMPERSAND EQUAL
    | BAR EQUAL
    | CARRET_OPERATOR_PART EQUAL
    | LSHIFT EQUAL
    | RSHIFT EQUAL
    ;

// the number means the privileges of expression
// the lower the number is, the higher the privilege is
expr10
    : expr9 (QUESTION expr COLON expr10)?   // 三目操作符, cond ? a : b
    ;

// 二元运算符的优先级
// | level | operator        |
// | 9     | ||              |
// | 8     | &&              |
// | 7     | > < >= <= == != |
// | 6     | |               |
// | 5     | ^               |
// | 4     | &               |
// | 3     | >> <<           |
// | 2     | + -             |
// | 1     | * / %           |

// expr9

expr9
    : lhs=expr8 (LOGIC_OR logic_or_rhs)*
    ;

logic_or_rhs
    : expr8
    ;

expr8
    : lhs=expr7 (LOGIC_AND logic_and_rhs)*
    ;

logic_and_rhs
    : expr7
    ;

expr7
    : lhs=expr6 binary_op_rhs*
    ;

binary_op_rhs
    : logical_op expr6
    ;

logical_op
    : LESS
    | LESS_EQ
    | GREATER
    | GREATER_EQ
    | NOT_EQ
    | EQ_SIGN
    ;

expr6
    : lhs=expr5 (BAR bit_or_rhs)*
    ;

bit_or_rhs
    : expr5
    ;

expr5
    : lhs=expr4 (CARRET_OPERATOR_PART xor_rhs)*
    ;

xor_rhs
    : expr4
    ;

expr4
    : lhs=expr3 (AMPERSAND bit_and_rhs)*
    ;

bit_and_rhs
    : expr3
    ;

expr3
    : lhs=expr2 shift_op_rhs*
    ;

shift_op_rhs
    : (LSHIFT | RSHIFT) expr2
    ;

expr2
    : lhs=expr1 add_sub_rhs*
    ;

add_sub_rhs
    : tk=(PLUS | MINUS) expr1
    ;

expr1
    : lhs=term multi_div_mod_rhs*
    ;

multi_div_mod_rhs
    : tk=(ASTERISK | SOLIDUS | PERCENT) term
    ;

term
    : LPAREN type RPAREN term
    | unary
    ;

unary
    : PLUS PLUS unary               # inc_expr          // ++a
    | MINUS MINUS unary             # dec_expr          // --a
    | PLUS term                     # positive_expr     // +a
    | MINUS term                    # negative_expr     // -a
    | EXCLAMATION_OPERATOR term     # logic_not_expr    // ! not
    | TILDE_OPERATOR term           # bit_not_expr      // ~
    | ASTERISK term                 # dereference_expr  // dereference pointer
    | AMPERSAND term                # addr_expr         // & get addr
    | S_SIZEOF LPAREN type RPAREN   # sizeof_type_expr // sizeof(a)
    | S_SIZEOF unary                # sizeof_expr       // sizeof a
    | postfix                       # unary_postfix_expr
    ;

postfix
    : primary postfix_option*
    ;

postfix_option
    : PLUS PLUS               // a++
    | MINUS MINUS             // a--
    | LBRACKET expr RBRACKET  // [a]
    | PERIOD memb1=name             // .a
    | POINTER_REF memb2=name        // ->a
    | LPAREN args? RPAREN      // (a, b, c)
    ;

args
    : expr (COMMA expr)*
    ;

primary
    : INTEGER
    | HEX
    | OCT
    | S_CHARACTER
    | S_STRING
    | IDENTIFIER
    | LPAREN expr RPAREN
    ;

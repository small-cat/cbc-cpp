lexer grammar SesameLexer;

S_VOID    : V O I D ;
S_CHAR    : C H A R ;
S_SHORT   : S H O R T;
S_INT     : I N T ;
S_LONG    : L O N G ;
S_STRUCT  : S T R U C T ;
S_UNION   : U N I O N ;
S_ENUM    : E N U M ;
S_STATIC  : S T A T I C ;
S_EXTERN  : E X T E R N ;
S_CONST   : C O N S T ;
S_SIGNED  : S I G N E D;
S_UNSIGNED: U N S I G N E D;
S_IF      : I F;
S_ELSE    : E L S E;
S_SWITCH  : S W I T C H;
S_CASE    : C A S E;
S_DEFAULT : D E F A U L T;
S_WHILE   : W H I L E;
S_DO      : D O;
S_FOR     : F O R;
S_RETURN  : R E T U R N;
S_BREAK   : B R E A K;
S_CONTINUE: C O N T I N U E;
S_GOTO    : G O T O;
S_TYPEDEF : T Y P E D E F;
S_IMPORT  : I M P O R T;
S_SIZEOF  : S I Z E O F;

// punctuations
SEMI    : ';';
COLON   : ':';
PLUS    : '+';
MINUS   : '-';
ASTERISK: '*';
SOLIDUS : '/';
PERCENT : '%';
AMPERSAND:'&';
LPAREN  : '(';
RPAREN  : ')';
COMMA   : ',';
EQUAL   : '=';

LBRACE  : '{';
RBRACE  : '}';
LBRACKET: '[';
RBRACKET: ']';
LESS    : '<';
LESS_EQ : '<=';
GREATER : '>';
GREATER_EQ: '>=';
NOT_EQ  : '!=';
EQ_SIGN : '==';

// logical op
LOGIC_AND : '&&';
LOGIC_OR  : '||';

LSHIFT  : '<<';
RSHIFT  : '>>';

PERIOD  : '.';
CDOTS   : '...';
BAR     : '|';
QUESTION: '?';
EXCLAMATION_OPERATOR: '!';
CARRET_OPERATOR_PART: '^';
TILDE_OPERATOR: '~';
POINTER_REF: '->';

SINGLE_LINE_COMM : '//' ~('\r' | '\n')* '\r'? '\n' -> channel(HIDDEN);
MULTI_LINE_COMM  : '/*' .*? '*/' -> channel(HIDDEN);

S_CHARACTER : '\'' . '\'';    // single char
S_STRING    : '"' ('\\"' | ~('\r' | '\n' | '"'))* '"';

IDENTIFIER : [a-zA-Z_]([a-zA-Z_0-9])*;
INTEGER : [0-9]([0-9])* U? L?;
HEX : '0' X ([0-9a-fA-F])+ U? L?;
OCT : '0' ([0-7])* U? L? ;
SPACES: [ \t\r\n]+ -> channel(HIDDEN);

fragment A : 'A' | 'a' ;
fragment B : 'B' | 'b' ;
fragment C : 'C' | 'c' ;
fragment D : 'D' | 'd' ;
fragment E : 'E' | 'e' ;
fragment F : 'F' | 'f' ;
fragment G : 'G' | 'g' ;
fragment H : 'H' | 'h' ;
fragment I : 'I' | 'i' ;
fragment J : 'J' | 'j' ;
fragment K : 'K' | 'k' ;
fragment L : 'L' | 'l' ;
fragment M : 'M' | 'm' ;
fragment N : 'N' | 'n' ;
fragment O : 'O' | 'o' ;
fragment P : 'P' | 'p' ;
fragment Q : 'Q' | 'q' ;
fragment R : 'R' | 'r' ;
fragment S : 'S' | 's' ;
fragment T : 'T' | 't' ;
fragment U : 'U' | 'u' ;
fragment V : 'V' | 'v' ;
fragment W : 'W' | 'w' ;
fragment X : 'X' | 'x' ;
fragment Y : 'Y' | 'y' ;
fragment Z : 'Z' | 'z' ;
fragment UNI_CHAR : '\u2E80-\u2FD5' | '\u3190-\u319F' | '\u3400-\u4DBF' | '\u4E00'..'\u9FEF' | '\uF900'..'\uFAAD';
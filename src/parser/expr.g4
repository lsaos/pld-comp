grammar expr;

prog: preproc SPACE* main;


preproc: (SPACE* include)*;
include: '#include' SPACE* '<' LIB '>';

main: funcType SPACE+ 'main' SPACE* '(' SPACE* ')' SPACE* '{' SPACE* (declaration SPACE*)* (instruction SPACE*)* ret? SPACE* '}' SPACE*;
ret: 'return' SPACE+ expression SPACE* ';' #retExpr
	| 'return' SPACE* ';' #retNoExpr
	;
block: (instruction SPACE*)+;
instruction: assignment;
declaration: varType SPACE* newVar SPACE* (',' SPACE* newVar SPACE*)* ';';
newVar: VAR #plainNewVariable
	| VAR SPACE* '=' SPACE* expression #valuedNewVariable
	;
assignment: VAR SPACE* '=' SPACE* expression ';';
expression: VAR #variable
		  | INT #int
		  | CHAR #char
		  | '('SPACE* expression SPACE* ')' #parenthesis
		  | expression SPACE* OPMUL SPACE* expression #mult
		  | expression SPACE* '+' SPACE* expression #add
		  | expression SPACE* '-' SPACE* expression #sub
		  | expression SPACE* OPBIN SPACE* expression #bin
		  | '-' SPACE* expression #negativeUnary
		  | UNARYOP SPACE* expression #unary
		  ;

funcType: 'int'|'void';
varType: 'int'|'char';
SPACE: [ \t\r\n];
OPMUL: ('*'|'/'); 
UNARYOP: ('!'|'~');
OPBIN: ('&'|'^'|'|');
INT: [0-9]+;
LIB: [a-zA-Z]+ '.h';
CHAR: '\'' [a-zA-Z0-9] '\'';
VAR: [a-zA-Z_] [a-zA-Z_0-9]*;

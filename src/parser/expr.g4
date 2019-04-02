grammar expr;

prog: preproc SPACE* main;


preproc: (SPACE* include)*;
include: '#include' SPACE* '<' VAR '>';

main: funcType SPACE+ 'main' SPACE* '(' SPACE* ')' SPACE* '{' SPACE* (declaration SPACE*)* (instruction SPACE*)* ret? SPACE* '}' SPACE*;
declaration: varType SPACE* newVar SPACE* (',' SPACE* newVar SPACE*)* ';';
newVar: VAR #plainNewVariable
	| VAR SPACE* '=' SPACE* expression #valuedNewVariable
	;
ret: 'return' SPACE+ expression SPACE* ';' #retExpr
	| 'return' SPACE* ';' #retNoExpr
	;
block: '{' SPACE* (declaration SPACE*)* (instruction SPACE*)* '}';
instruction: assignment
			| optional
			| loop
			;
assignment: VAR SPACE* '=' SPACE* expression ';';
optional: 'if' condition controlBody (SPACE* 'else' SPACE* controlBody)?;
loop: 'while' condition controlBody;
condition: SPACE* '(' SPACE* expression SPACE* ')' SPACE*;
controlBody: block
			| instruction;
expression: VAR #variable
		  | INT #int
		  | CHAR #char
		  | '('SPACE* expression SPACE* ')' #parenthesis
		  | UNARYOP SPACE* expression #unary		  
		  | '-' SPACE* expression #negativeUnary
		  | expression SPACE* OPMUL SPACE* expression #mult
		  | expression SPACE* '+' SPACE* expression #add
		  | expression SPACE* '-' SPACE* expression #sub
		  | expression SPACE* OPCOMP SPACE* expression #comparison
		  | expression SPACE* OPBIN SPACE* expression #bin
		  | expression SPACE* LOGICOP SPACE* expression #logical
		  ;

funcType: 'int'|'void';
varType: 'int'|'char';
SPACE: [ \t\r\n];
OPMUL: ('*'|'/'); 
UNARYOP: ('!'|'~');
OPCOMP: ('=='|'<='|'<'|'>'|'>='|'!=');
OPBIN: ('&'|'^'|'|');
LOGICOP: ('&&'|'||');
INT: [0-9]+;
CHAR: '\'' [a-zA-Z0-9] '\'';
VAR: [a-zA-Z_] [a-zA-Z_0-9]*;
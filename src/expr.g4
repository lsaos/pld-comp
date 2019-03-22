grammar expr;

prog: preproc SPACE* main;


preproc: (SPACE* include)*;
include: '#include' SPACE* '<' LIB '>';

main: 'int' SPACE+ 'main' SPACE* '(' SPACE* ')' SPACE* '{' SPACE* (instruction SPACE*)* ret SPACE* '}' SPACE*;
ret: 'return' SPACE+ expression SPACE* ';';
block: (instruction SPACE*)+;
instruction: declaration SPACE* ';'
		   | definition SPACE* ';'
		   | assignment SPACE* ';'
		   ;
declaration: type SPACE* VAR;
definition: type SPACE* VAR SPACE* '=' SPACE* expression;
assignment: VAR SPACE* '=' SPACE* expression;
expression: VAR #variable
		  | INT #int
		  | CHAR #char
		  | '('SPACE* expression SPACE* ')' #parenthesis
		  | UNARYOP expression #unary
		  | expression SPACE* OPMUL SPACE* expression #mult
		  | expression SPACE* OPADD SPACE* expression #add
		  | expression SPACE* OPBIN SPACE* expression #bin
		  ;

type: 'int'|'char';
SPACE: [ \t\r\n];
UNARYOP: ('-'|'!');
OPMUL: ('*'|'/');
OPADD: ('+'|'-');
OPBIN: ('&'|'^'|'|'); 
INT: [0-9]+;
LIB: [a-zA-Z]+ '.h';
CHAR: '\'' [a-zA-Z0-9] '\'';
VAR: [a-zA-Z_] [a-zA-Z_0-9]*;

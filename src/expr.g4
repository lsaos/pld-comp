grammar expr;

prog: main;

main: preproc SPACE* 'int' SPACE+ 'main' SPACE* '(' SPACE* ')'
    SPACE* '{' SPACE* (instruction SPACE*)* 'return' SPACE+ expression SPACE* ';'
    SPACE* '}' SPACE*;
preproc: (SPACE* include)*;
include: '#include' SPACE* '<' LIB '>';
block: (instruction SPACE*)+;
instruction: declaration SPACE* ';'
		   | definition SPACE* ';'
		   ;
declaration: type SPACE* VAR;
definition: type SPACE* VAR SPACE* '=' SPACE* expression;
expression: VAR #variable
		  | INT #int
		  | CHAR #char
		  | '('SPACE* expression SPACE* ')' #parenthesis
		  | expression SPACE* OPMUL SPACE* expression #mult
		  | expression SPACE* OPADD SPACE* expression #add
		  ;

type: 'int'|'char';
SPACE: [ \t\r\n];
OPMUL: ('*'|'/');
OPADD: ('+'|'-');
INT: [0-9]+;
LIB: [a-zA-Z]+ '.h';
CHAR: '\'' [a-zA-Z0-9] '\'';
VAR: [a-zA-Z_] [a-zA-Z_0-9]*;

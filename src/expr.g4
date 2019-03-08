grammar expr;

prog: main;

main: SPACE* 'int' SPACE+ 'main' SPACE* '(' SPACE* ')'
    SPACE* '{' SPACE* 'return' SPACE+ INT SPACE* ';'
    SPACE* '}' SPACE*;

TYPE: 'int' | 'char';
INT: [0-9]+;
CHAR: '\'' [a-zA-Z0-9] '\'';
VAR: [a-zA-Z_] [a-zA-Z_0-9]*;
SPACE: [ \t\r\n];

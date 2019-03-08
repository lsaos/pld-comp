grammar expr;

prog: main;

main: TYPE SPACE+ 'main' SPACE* '(' SPACE* ')'
    SPACE* '{' SPACE* 'return' SPACE+ INT SPACE* ';'
    SPACE* '}';

TYPE: 'int' | 'void';

INT: [0-9]+;

SPACE: ' ' | '\r' | '\n' | '\t';

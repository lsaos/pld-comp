grammar expr;

prog:  main;

main: funcType  'main'  '('  ')'  '{'  (declaration )* (instruction )* ret?  '}' ;
declaration: varType  newVar  (','  newVar )* ';';
newVar: VAR #plainNewVariable
	| VAR  '='  expression #valuedNewVariable
	;
ret: 'return'  expression  ';' #retExpr
	| 'return'  ';' #retNoExpr
	;
block: '{'  (declaration )* (instruction )* '}';
instruction: assignment ';'
			| optional
			| loop
			;
assignment: VAR  '='  expression;
optional: 'if' condition controlBody ( 'else'  controlBody)?;
loop: 'while' condition controlBody #whileLoop
	| 'for' '(' declaration expression ';' assignment ')' controlBody #forLoop
	;
condition:  '('  expression  ')' ;
controlBody: block
			| instruction;
expression: VAR #variable
		  | INT #int
		  | CHAR #char
		  | '(' expression  ')' #parenthesis
		  | '-'  expression #minus
		  | '!'  expression #logicalNot
		  | '~'  expression #bitwiseNot
		  |	expression  '*'  expression #multiply
		  |	expression  '+'  expression #add
		  |	expression  '-'  expression #substract
		  |	expression  '<<'  expression #leftShift
		  |	expression  '>>'  expression #rightShift
		  |	expression  '<'  expression #LowerThan
		  |	expression  '>'  expression #GreaterThan
		  |	expression  '>='  expression #GreaterThanEquals
		  |	expression  '<='  expression #lowerThanEquals
		  |	expression  '=='  expression #equals
		  |	expression  '!='  expression #Different
		  |	expression  '&'  expression #bitwiseAnd
		  |	expression  '^'  expression #bitwiseXor
		  |	expression  '|'  expression #bitwiseOr
		  |	expression  '&&'  expression #LogicalAnd
		  |	expression  '||'  expression #LogicalOr
		  ;

funcType: 'int'|'void';
varType: 'int'|'char';
WS: [ \t\r\n] -> skip;
Comment: '//' ~[\r\n]* -> skip;
BlockComment: '/*' .*? '*/' -> skip;
Preproc: '#' ~[\r\n]* -> skip;
INT: [0-9]+;
CHAR: '\'' [a-zA-Z0-9] '\'';
VAR: [a-zA-Z_] [a-zA-Z_0-9]*;
grammar expr;

prog:  function+;

function: funcType  VAR  '(' parameters? ')'  block ;
parameters: varType VAR (',' varType VAR)*;
declaration: varType  newVar  (','  newVar )* ';';
newVar: newVarName #plainNewVariable
	| VAR  '='  expression #valuedNewVariable
	;
newVarName: VAR #declareVariable
			| VAR '[' expression ']' #declareArray
			;
ret: 'return'  expression  ';' #retExpr
	| 'return'  ';' #retNoExpr
	;
block: '{'  (declaration )* (instruction )* '}';
instruction: assignment ';'
			| optional
			| loop
			| ret
			| funcCall ';'
			;
assignment: varExpr  '='  expression;
varExpr: VAR #variableExpression
	| VAR '[' expression ']' #arrayExpression
	;
optional: 'if' condition controlBody ( 'else'  controlBody)?;
loop: 'while' condition controlBody #whileLoop
	| 'for' '(' forInit expression ';' assignment ')' controlBody #forLoop
	;
forInit: declaration #forDeclaration
		| assignment ';' #forAssignment
		;
condition:  '('  expression  ')' ;
controlBody: block
			| instruction;
expression: funcCall #exprFunc
		  | varExpr #variable
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
funcCall: VAR '(' funcCallArguments? ')';
funcCallArguments: expression (',' expression)*;

funcType: 'int'|'void';
varType: 'int'|'char';
WS: [ \t\r\n] -> skip;
Comment: '//' ~[\r\n]* -> skip;
BlockComment: '/*' .*? '*/' -> skip;
Preproc: '#' ~[\r\n]* -> skip;
INT: [0-9]+;
CHAR: '\'' [a-zA-Z0-9] '\'';
VAR: [a-zA-Z_] [a-zA-Z_0-9]*;

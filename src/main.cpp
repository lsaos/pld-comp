#include <antlr4-runtime.h>
#include <iostream>
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseVisitor.h"

using namespace antlr4;
using namespace std;

int main()
{
	ANTLRInputStream input("int main() { return 42; }");
	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.prog();

	cout << tree->toStringTree() << endl;

	return 0;
}

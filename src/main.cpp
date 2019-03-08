#include <antlr4-runtime.h>
#include <iostream>
#include "exprLexer.h"
#include "exprParser.h"
#include "exprBaseVisitor.h"
#include "assembl.h"

using namespace antlr4;
using namespace std;

int main()
{
	ANTLRInputStream input("int main() { return 10; }");
	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.prog();

	//cout << tree->toStringTree() << endl;
	cout<<endl<<endl;
	Assembl visitor;
	int resultat = (int)visitor.visit(tree);
	
	cout << "Le programme a retourné : "<< resultat << endl;

	return 0;
}

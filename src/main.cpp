#include <antlr4-runtime.h>
#include <iostream>
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseVisitor.h"

using namespace antlr4;
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Usage: comp source_file [-a] [-o] [-c]" << endl;
		return -1;
	}

	ifstream file;
	file.open(argv[1], ios::in);

	if (!file)
	{
		cout << "Failed to open file '" << argv[1] << '\'' << endl;
		return -1;
	}

	ANTLRInputStream input(file);
	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	file.close();

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.prog();

	cout << tree->toStringTree() << endl;

	return 0;
}

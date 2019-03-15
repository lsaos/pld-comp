#include <antlr4-runtime.h>
#include <string>
#include <iostream>
#include "unistd.h"
#include "exprLexer.h"
#include "exprParser.h"
#include "exprBaseVisitor.h"
#include "visiteur.hpp"

using namespace antlr4;
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Usage: comp source_file [-a] [-o] [-c]" << endl;
		system("pause");
		return -1;
	}

	ifstream file;
	file.open(argv[1], ios::in);

	if (!file)
	{
		cout << "Failed to open file '" << argv[1] << '\'' << endl;
		system("pause");
		return -1;
	}

	int opt;
	bool optionA = false, optionC = false, optionO = false;
	while ((opt = getopt(argc, argv, "oca")) != -1) {
		switch (opt) {
		case 'o':
			cout << "Il y aura optimisation" << endl;
			optionO = true;
			break;
		case 'c':
			cout << "Il y aura génération de code assembleur" << endl;
			optionC = true;
			break;
		case 'a':
			cout << "Il y aura analyse statique" << endl;
			optionA = true;
			break;
		}
	}

	ANTLRInputStream input(file);
	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	file.close();

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.prog();

	//cout << tree->toStringTree() << endl;
	cout << endl << endl;
	string name = string(argv[1]);
	Visiteur visitor(name);
	int resultat = (int)visitor.visit(tree);

	cout << "Le programme a retourné : "<< resultat << endl;
	system("pause");
	return 0;
}

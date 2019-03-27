#include <antlr4-runtime.h>
#include <string>
#include <iostream>
#include "../lib/unistd.h"
#include "../parser/exprLexer.h"
#include "../parser/exprParser.h"
#include "../parser/exprBaseVisitor.h"
#include "../parser/visiteur.hpp"

#include "../ast/program.hpp"
#include "../ast/assignment.hpp"
#include "../ast/binaryExpression.hpp"
#include "../ast/block.hpp"
#include "../ast/constant.hpp"
#include "../ast/controlStructure.hpp"
#include "../ast/expression.hpp"
#include "../ast/functionCall.hpp"
#include "../ast/function.hpp"
#include "../ast/instruction.hpp"
#include "../ast/operator.hpp"
#include "../ast/program.hpp"
#include "../ast/type.hpp"
#include "../ast/unaryExpression.hpp"
#include "../ast/variable.hpp"
#include "../ast/error.hpp"
#include "../ast/return.hpp"

#include "../assembly/assembly.hpp"

using namespace antlr4;
using namespace std;
using namespace ast;
using namespace assembly;

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

	cout << "options : " << getopt(argc, argv, "o:c:a");
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
		if (!strcmp(argv[i], "-c")) {
			cout << "Il y aura génération de code assembleur" << endl;
			optionC = true;
			break;
		}
	}

	while ((opt = getopt(argc, argv, "o:c:a:")) != -1) {
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
	size_t nbErrors = parser.getNumberOfSyntaxErrors();

	//Pour tester l'assemblage
	optionC = true;

	if (nbErrors == 0)
	{

		Visiteur visitor;
		Program* prog = (Program*)visitor.visit(tree);

		try
		{
			prog->checkSemantic(optionA);
			prog->toTextualRepresentation(cout);

			if (optionO) {
				cout << "-------------------------------" << endl
					<< " After optimization"
					<< "-------------------------------" << endl;

				prog->optimize();
				prog->toTextualRepresentation(cout);
			}

			cout << "Le programme s'est fini correctement" << endl;

			if (optionC) {
				AssemblyGenerator ag(argv[1]);
				ag.generateAssembly(prog);
			}
		}
		catch (...)
		{
		}

		system("pause");
	}
	else
	{
		cout << "Erreur de compilation" << endl;
	}

	return 0;
}
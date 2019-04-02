#include <antlr4-runtime.h>
#include <string>
#include <cstring>
#include <iostream>

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

	bool optionA = false, optionC = false, optionO = false;

	for (int i = 2; i < argc; i++) {
		if (strcmp(argv[i], "-c") == 0) {
			optionC = true;
		}
		else if (strcmp(argv[i], "-a") == 0) {
			optionA = true;
		}
		else if (strcmp(argv[i], "-o") == 0) {
			optionO = true;
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

	if (nbErrors != 0) {
		cout << "Erreur de compilation" << endl;
		return -1;
	}

	Visiteur visitor;
	Program* prog = (Program*)visitor.visit(tree);
	prog->prepare();

	try
	{
		prog->checkSemantic(optionA);
		prog->toTextualRepresentation(cout);
	}
	catch (...)
	{
	}

	if (optionO) {
		cout << "-------------------------------" << endl
			<< " After optimization" << endl
			<< "-------------------------------" << endl;

		prog->optimize();
		prog->toTextualRepresentation(cout);
	}

	if (optionC) {
		AssemblyGenerator ag(argv[1]);
		ag.generateAssembly(prog);
	}

	system("pause");

	return 0;
}

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

#include "../ir/ir.hpp"

using namespace antlr4;
using namespace std;
using namespace ast;
using namespace assembly;
using namespace ir;

// Register external functions which can be called by
// the specified program without being part of it
void registerExternalFunctions(Program* prog)
{
	Variable* funcPutCharArg = new Variable(ItemPosition());
	funcPutCharArg->setName("character");
	funcPutCharArg->setType(Type::Integer);

	Function* funcPutChar = new Function(ItemPosition());
	funcPutChar->setName("putchar");
	funcPutChar->setType(Type::Integer);
	funcPutChar->addParameter(funcPutCharArg);
	prog->addExternalFunction(funcPutChar);

	Function* funcGetChar = new Function(ItemPosition());
	funcGetChar->setName("getchar");
	funcGetChar->setType(Type::Integer);
	prog->addExternalFunction(funcGetChar);
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Usage: comp source_file [-a] [-o] [-c]" << endl;
		system("pause");
		return -1;
	}

	bool optionA = false;
	bool optionC = false;
	bool optionO = false;

	for (int i = 2; i < argc; i++) {
		const string arg(argv[i]);

		if (arg == "-c") {
			optionC = true;
		}
		else if (arg == "-a") {
			optionA = true;
		}
		else if (arg == "-o") {
			optionO = true;
		}
		else {
			cout << "Warning: unknown option " << arg << endl;
		}
	}

	ifstream file;
	file.open(argv[1], ios::in);

	if (!file)
	{
		cout << "Failed to open file '" << argv[1] << '\'' << endl;
		system("pause");
		return -1;
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

	if (nbErrors != 0)
	{
		cout << "Compilation failed with synthax errors" << endl;
		return -1;
	}

	Visiteur visitor;
	Program* prog = (Program*)visitor.visit(tree);
	registerExternalFunctions(prog);
	prog->prepare();

	try
	{
		prog->checkSemantic(optionA);
		prog->toTextualRepresentation(cout);
	}
	catch (...)
	{
		cout << "Compilation failed with semantic errors" << endl;
		return -1;
	}

	if (optionO) {
		cout << "-------------------------------" << endl
			<< " After optimization" << endl
			<< "-------------------------------" << endl;

		prog->optimize();
		prog->toTextualRepresentation(cout);
	}

	if (optionC) {
		/*AssemblyGenerator ag(argv[1]);
		ag.generateAssembly(prog);*/
		IR ir(prog);
		ir.generateIR();
		ir.generateAssembly(argv[1]);
	}

	system("pause");

	return 0;
}

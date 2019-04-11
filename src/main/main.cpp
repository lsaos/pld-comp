//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

// Standard library
#include <string>
#include <cstring>
#include <iostream>
#include <chrono>

using namespace std;

// ANTLR
#include <antlr4-runtime.h>

using namespace antlr4;

// Syntaxic parser
#include "../parser/exprLexer.h"
#include "../parser/exprParser.h"
#include "../parser/exprBaseVisitor.h"
#include "../parser/visiteur.hpp"

// Abstract syntax tree
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

using namespace ast;

// Assembly generation
#include "../ir/ir.hpp"

using namespace ir;

// Values returned by the program.
enum RETURN_CODE
{
	RETURN_CODE_OK = 0,
	RETURN_CODE_INVALID_ARGS = -1,
	RETURN_CODE_OPEN_FILE_FAILED = -2,
	RETURN_CODE_SYNTAX_ERROR = -3,
	RETURN_CODE_SEMANTIC_ERROR = -4
};

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
	cout << "-------------------------------" << endl
		<< " The Super 4404 C Compiler" << endl
		<< " Copyright 2019 (c) A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri" << endl
		<< " INSA Lyon" << endl
		<< "-------------------------------" << endl;

	// Start the timer
	const chrono::high_resolution_clock::time_point startTime(chrono::high_resolution_clock::now());

	// Check we have the filename
	if (argc < 2)
	{
		cout << "Usage: comp source_file [-a] [-o] [-c] [-t]" << endl;
		system("pause"); // TODO: remove it
		return RETURN_CODE_INVALID_ARGS;
	}

	// Parse compiler options
	bool staticAnalysis = false;
	bool genAsm = false;
	bool optimize = false;
	bool textualRepresentation = false;

	for (int i = 2; i < argc; i++) {
		const string arg(argv[i]);

		if (arg == "-c") {
			genAsm = true;
		}
		else if (arg == "-a") {
			staticAnalysis = true;
		}
		else if (arg == "-o") {
			optimize = true;
		}
		else if (arg == "-t") {
			textualRepresentation = true;
		}
		else {
			cout << "Warning: unknown option " << arg << endl;
		}
	}

	// Open the file and parse it with ANTLR
	ifstream file;
	file.open(argv[1], ios::in);

	if (!file)
	{
		cout << "Failed to open file '" << argv[1] << '\'' << endl;
		system("pause"); // TODO: remove it
		return RETURN_CODE_OPEN_FILE_FAILED;
	}

	ANTLRInputStream input(file);
	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	file.close();

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.prog();
	const size_t syntaxErrorCount = parser.getNumberOfSyntaxErrors();

	if (syntaxErrorCount != 0)
	{
		cout << "Compilation failed with syntax errors" << endl;
		system("pause"); // TODO: remove it
		return RETURN_CODE_SYNTAX_ERROR;
	}

	// Create the abstract syntax tree
	Visiteur visitor;
	Program* prog = nullptr;

	try
	{
		prog = (Program*)visitor.visit(tree);
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
		cout << "Compilation failed with syntax errors" << endl;
		system("pause"); // TODO: remove it
		return RETURN_CODE_SYNTAX_ERROR;
	}

	registerExternalFunctions(prog);
	prog->prepare();

	// Check the program's semantic validity
	// Errors throw exceptions
	try
	{
		prog->checkSemantic(staticAnalysis);
	}
	catch (...)
	{
		cout << "Compilation failed with semantic errors" << endl;
		system("pause"); // TODO: remove it
		return RETURN_CODE_SEMANTIC_ERROR;
	}

	if (textualRepresentation) {
		prog->toTextualRepresentation(cout);
	}

	// Optimize the program at the AST level
	if (optimize) {
		prog->optimize();

		if (textualRepresentation) {
			cout << "-------------------------------" << endl
				<< " After optimization" << endl
				<< "-------------------------------" << endl;

			prog->toTextualRepresentation(cout);
		}
	}

	// Generate the assembly
	if (genAsm) {
		/*AssemblyGenerator ag(argv[1]);
		ag.generateAssembly(prog);*/
		IR ir(prog);
		ir.generateIR(optimize);
		cout << endl << endl;
		ir.printIR();
		cout << endl;
		ir.generateAssembly(argv[1]);
	}

	// Show the measured time
	cout << "Job done in " <<
		chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
		<< "ms" << endl;

	system("pause"); // TODO: remove it

	return RETURN_CODE_OK;
}
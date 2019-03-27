//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "block.hpp"

namespace ast
{
	class Function;

	// The program is the root of the AST.
	// It contains global variables and functions.
	class Program : public Block
	{
	public:
		// Create a program.
		Program();

	public:
		// Get the function with the specified name.
		// Returns null if the function doesn't exist.
		Function* getFunction(const string& name) const;

		// Get the list of functions contained in the program.
		vector<Function*> getFunctions() const;

		// Get the number of function the program contains.
		size_t getFunctionsCount() const;

		// Get the main function of the program.
		Function* getMain() const {
			return getFunction("main");
		}

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i = 0) const;

	public:
		virtual bool isProgram() const { return true; }
	};
}

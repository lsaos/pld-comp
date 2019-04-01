//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "function.hpp"

namespace ast
{
	// The program is the root of the AST.
	// It contains global variables and functions.
	class Program : public Block
	{
	public:
		// Create a program.
		Program();

	public:
		// Add an external function to the program.
		void addExternalFunction(Function* func);

	public:
		// Get the function with the specified name.
		// Returns null if the function doesn't exist.
		Function* getFunction(const string& name, bool withExternals = true) const;

		// Get the list of functions contained in the program.
		vector<Function*> getFunctions(bool withExternals = false) const;

		// Get the number of function the program contains.
		size_t getFunctionsCount(bool withExternals = false) const;

		// Get the main function of the program.
		Function* getMain() const {
			return getFunction("main");
		}

		// Get all external functions.
		vector<Function*> getExternalFunctions() const;

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i = 0) const;

	public:
		virtual bool isProgram() const { return true; }

	private:
		vector<unique_ptr<Function>> externalFunctions; // List of external functions.
	};
}

//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "block.hpp"
#include "identifiable.hpp"

namespace ast
{
	class Block;

	// Represents a C function.
	// It has a block of code and is an identifiable.
	class Function : public Block, public Identifiable
	{
	public:
		// Create a function.
		Function(const ItemPosition& position);

	public:
		// Add the specified variable as a parameter of the function.
		void addParameter(Variable* var);

		// Mark the function as extern.
		void setIsExtern();

	public:
		// Get the list of parameters.
		vector<Variable*> getParameters() const;

		// Get the number of parameters.
		size_t getParametersCount() const;

		// Return true if the variable is extern.
		bool isExtern() const {
			return isExternal;
		}

	public:
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual string getStringRepresentation() const;

	public:
		virtual bool isFunction() const { return true; }

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg = "%eax");

	private:
		bool isExternal; // True if the variable if extern.
	};
}

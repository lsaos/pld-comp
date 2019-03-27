//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "instruction.hpp"
#include "identifiable.hpp"

namespace ast
{
	// Variable scope.
	enum class Scope
	{
		Global, // Global variable in the program.
		Parameter, // Parameter variable in a function.
		Block // Standard variable in a block.
	};

	// Represents a memory allocation with a name and a type.
	class Variable : public Instruction, public Identifiable
	{
	public:
		// Create a variable.
		Variable(const ItemPosition& position);

	public:
		// Set the variable scope.
		void setScope(Scope s);

	public:
		// Get the variable scope.
		Scope getScope() const {
			return scope;
		}

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual string getStringRepresentation() const;

	public:
		virtual bool isVariable() const { return true; }

	private:
		Scope scope; // Scope of the variable.

	public:
		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}
	};
}


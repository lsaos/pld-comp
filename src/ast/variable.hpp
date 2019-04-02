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
#include "expression.hpp"

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

		// Mark the variable as used.
		void markUsed();

		// Set the variable is an array.
		void setIsArray();

		// Set the expression for the size of the array.
		void setArraySize(Expression* expr);

	public:
		// Get the variable scope.
		Scope getScope() const {
			return scope;
		}

		// Return true if the variable is an array.
		// It can be a real array or a pointer to another array.
		// Use isArraySizeKnown to know it.
		bool isArray() const {
			return isTypeArray;
		}

		// Return true if the size of the array is known.
		// If not, the variable is a pointer to an other array.
		bool isArraySizeKnown() const {
			return arraySize != nullptr;
		}

		// Get the size of the array.
		// Return -1 of the size is not known
		// or if the variable is not an array.
		int getArraySize() const;

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual string getStringRepresentation() const;
		virtual void prepare();
		virtual Instruction* optimize();

	public:
		virtual bool isVariable() const { return true; }

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg = "%eax") {}

	private:
		Scope scope; // Scope of the variable.
		bool used; // True if the variable is used.
		bool isTypeArray; // True if the variable is an array.
		unique_ptr<Expression> arraySize; // Expression for the size of the array.

	public:
		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}
		virtual string buildIR(ir::CFG*) {}
	};
}

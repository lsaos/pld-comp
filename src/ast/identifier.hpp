//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "expression.hpp"
#include "identifiable.hpp"

namespace ast
{
	class Variable;

	// Represents a link to an identifiable as an expression.
	class Identifier : public Expression
	{
	public:
		// Create an identifier.
		Identifier(const ItemPosition& position);

	public:
		// Set the identifier string.
		void setIdent(const string& str);

		// Set array indexing expression.
		void setArrayIndex(Expression* expr);

	public:
		// Get the referenced variable.
		// Return null if it doesn't reference a variable.
		Variable* getReferencedVariable() const;

		// Get the referenced function.
		// Return null if it doesn't reference a function.
		Function* getReferencedFunction() const;

		// Get the the identifier string.
		const string& getIdent() {
			return ident;
		}

		// Return true if the identifier is referencing a variable.
		bool isReferencingVariable() const {
			return getReferencedVariable() != nullptr;
		}

		// Return true if the identifier is referencing a function.
		bool isReferencingFunction() const {
			return getReferencedFunction() != nullptr;
		}

		// Return true if the identifier is an array variable.
		bool isReferencingArray() const;

		// Get array indexing expression.
		Expression* getArrayIndex() const {
			return arrayIndex.get();
		}

		// Return true if the identifier is used as a left value in an assignment.
		bool isLeftValue() const;

		// Return true if the identifier is used as a right value.
		bool isRightValue() const {
			return !isLeftValue();
		}

	public:
		virtual Type getType() const;
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual string getStringRepresentation() const { return ident; }

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg = "%eax");

		virtual void prepare();
		virtual Instruction* optimize();

		virtual bool isIdentifier() const { return true; }

	private:
		string ident; // Identifier string.
		unique_ptr<Expression> arrayIndex; // Array indexing expression.
	};
}

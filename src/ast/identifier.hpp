#pragma once

#include "expression.hpp"
#include "identifiable.hpp"
#include "variable.hpp"

namespace ast
{
	class Identifier : public Expression
	{
	public:
		Identifier(const ItemPosition& position)
			: Expression(position)
		{
		}

	public:
		void setIdent(const string& str)
		{
			assert(!str.empty());
			ident = str;
		}

		const string& getIdent()
		{
			return ident;
		}

		bool isReferencingVariable() const
		{
			return getReferencedVariable() != nullptr;
		}

		bool isReferencingFunction() const
		{
			return getReferencedFunction() != nullptr;
		}

		Variable* getReferencedVariable() const
		{
			return getParentBlock()->getVariable(ident, true);
		}

		Function* getReferencedFunction() const
		{
			return getProgram()->getFunction(ident);
		}

	public:
		virtual Type getType() const
		{
			// If referencing a variable
			Variable* var = getReferencedVariable();
			if (var) {
				return var->getType();
			}

			// If referencing a function
			Function* func = getReferencedFunction();
			if (func) {
				return func->getType();
			}

			return Type::Void;
		}

		virtual bool checkSemantic()
		{
			// Check the ident is valid
			if (ident.empty()) {
				error(Error::InvalidInstruction, this);
				return false;
			}

			const bool refFunction = isReferencingFunction();

			// Check if the identifier is referencing something
			if (!isReferencingVariable() && !refFunction) {
				error(Error::UnknownIdentifier, this);
				return false;
			}

			// A function identifier can only be in a function call
			if (refFunction && !getParent()->isFunctionCall()) {
				error(Error::InvalidInstruction, this);
				return false;
			}

			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << "Ident(" << ident << ')' << endl;
		}

		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}

	private:
		string ident;
	};
}

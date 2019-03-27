//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "identifier.hpp"
#include "variable.hpp"
#include "function.hpp"
#include "program.hpp"

namespace ast
{
	//
	// Identifier
	//

	Identifier::Identifier(const ItemPosition& position)
		: Expression(position)
	{
	}

	void Identifier::setIdent(const string& str)
	{
		assert(!str.empty());
		ident = str;

		// Mark the variable used if it exists
		if (getParentBlock()) {
			Variable* var = getParentBlock()->getVariable(str, true);
			if (var) {
				var->markUsed();
			}
		}
	}

	Variable* Identifier::getReferencedVariable() const
	{
		return getParentBlock()->getVariable(ident, true);
	}

	Function* Identifier::getReferencedFunction() const
	{
		return getProgram()->getFunction(ident);
	}

	Type Identifier::getType() const
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

	void Identifier::checkSemantic(bool advanced) const
	{
		// Check the ident is valid
		if (ident.empty()) {
			error(Error::InvalidInstruction, this);
		}

		const bool refFunction = isReferencingFunction();

		// Check if the identifier is referencing something
		if (!isReferencingVariable() && !refFunction) {
			error(Error::UnknownIdentifier, this);
		}

		// A function identifier can only be in a function call
		if (refFunction && !getParent()->isFunctionCall()) {
			error(Error::InvalidInstruction, this);
		}
	}

	void Identifier::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "Ident(" << ident << ')' << endl;
	}
}

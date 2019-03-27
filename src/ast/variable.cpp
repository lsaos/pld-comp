//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "variable.hpp"

namespace ast
{
	//
	// Variable
	//

	Variable::Variable(const ItemPosition& position)
		: Instruction(position),
		scope(Scope::Block)
	{
	}

	void Variable::setScope(Scope s)
	{
		scope = s;
	}

	void Variable::checkSemantic(bool advanced) const
	{
		if (getName().empty() || getType() == Type::Void) {
			error(Error::InvalidStatement, this);
		}
	}

	void Variable::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "Var {" << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << getTypeName() << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Ident(" << getName() << ')' << endl;

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	string Variable::getStringRepresentation() const
	{
		return getTypeName() + ' ' + getName();
	}
}

//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "constant.hpp"

namespace ast
{
	//
	// Constant
	//

	Constant::Constant(const ItemPosition& position)
		: Expression(position),
		type(Type::Void),
		value(0)
	{
	}

	void Constant::setValue(int val)
	{
		value = val;
	}

	void Constant::setType(Type t)
	{
		type = t;
	}

	void Constant::checkSemantic(bool advanced) const
	{
		if (type == Type::Void) {
			error(Error::InvalidStatement, this);
		}
	}

	string Constant::getStringRepresentation() const
	{
		switch (type)
		{
		case Type::Character:
			switch (value)
			{
			case '\0': return "'\0'";
			case '\n': return "'\n'";
			case '\r': return "'\r'";
			case '\t': return "'\t'";
			case '\b': return "'\b'";
			default: return string("'") + (char)value + '\'';
			}
		case Type::Integer: return to_string(value);
		default: return "error";
		}
	}

	void Constant::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "Const(" << getStringRepresentation() << ')' << endl;
	}
}

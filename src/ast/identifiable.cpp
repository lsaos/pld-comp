//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "identifiable.hpp"

namespace ast
{
	//
	// Identifiable
	//

	Identifiable::Identifiable()
		: type(Type::Void)
	{
	}

	void Identifiable::setName(const string& n)
	{
		assert(!n.empty());
		name = n;
	}

	void Identifiable::setType(Type t)
	{
		type = t;
	}

	string Identifiable::getTypeName() const
	{
		switch (type)
		{
		case Type::Integer: return "int";
		case Type::Character: return "char";
		case Type::Void: return "void";
		default: return "error";
		}
	}
}

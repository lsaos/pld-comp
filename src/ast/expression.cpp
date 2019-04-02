//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "expression.hpp"

namespace ast
{
	//
	// Expression
	//

	Expression::Expression(const ItemPosition& position)
		: Instruction(position)
	{
	}

	int Expression::getValue() const
	{
		error(Error::NotConstant, this);
		return 0;
	}

	bool Expression::isCastSafe(Type newType) const
	{
		switch (getType())
		{
		case Type::Integer:
			switch (newType)
			{
			case Type::Character:
				return false;
			default:
				return true;
			}
		case Type::Character:
			return true;
		default:
			return false;
		}
	}
}

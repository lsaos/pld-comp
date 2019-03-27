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
}

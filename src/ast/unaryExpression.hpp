#pragma once

#include "expression.hpp"
#include "operator.hpp"

namespace ast
{
	class UnaryExpression : public Expression
	{
	private:
		UnaryOperator op;
		Expression* expr;
	};
}

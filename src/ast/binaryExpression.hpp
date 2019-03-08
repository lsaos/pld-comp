#pragma once

#include "expression.hpp"
#include "operator.hpp"

namespace ast
{
	class BinaryExpression : public Expression
	{
	private:
		BinaryOperator op;
		Expression* left;
		Expression* right;
	};
}

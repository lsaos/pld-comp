#pragma once

namespace ast
{
	enum class BinaryOperator
	{
		Add,
		Substract,
		Multiply,
		Divide,

		LogicalAnd,
		LogicalOr,
		LogicalXor,

		Equals,
		DifferentThan,
		GreaterThan,
		LowerThan,
		GreaterThanOrEquals,
		LowerThanOrEquals
	};

	enum class UnaryOperator
	{
		Not,
		Minus
	};
}

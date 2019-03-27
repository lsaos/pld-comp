//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

namespace ast
{
	// Supported binary operators between values.
	enum class BinaryOperator
	{
		Add, // Addition (+).
		Substract, // Substraction (-).
		Multiply, // Multiplication (*).
		Divide, // Division (/).
		Modulo, // Modulo (%).

		LogicalAnd, // Logical and (&&).
		LogicalOr, // Logical or (||).

		BitwiseAnd, // Bitwise and (&).
		BitwiseOr, // Bitwise or (|).
		BitwiseXor, // Bitwise xor (^).
		BitwiseLeftShift, // Bitwise left shift (<<).
		BitwiseRightShift, // Bitwise right shift (>>).

		Equals, // Equals (==).
		DifferentThan, // Different than (!=).
		GreaterThan, // Greater than (>).
		LowerThan, // Lower than (<).
		GreaterThanOrEquals, // Greater than or equals (>=).
		LowerThanOrEquals // Lower than or equals (<=).
	};

	// Supported unary operators.
	enum class UnaryOperator
	{
		Minus, // Unary minus (-).

		LogicalNot, // Logical not (!)

		BitwiseNot // Bitwise not (~).
	};
}

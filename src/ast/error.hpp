#pragma once

namespace ast
{
	enum class Error
	{
		None,
		InvalidInstruction,
		DivisionByZero,
		NotConstant
	};
}

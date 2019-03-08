#pragma once

#include "expression.hpp"

namespace ast
{
	class Constant : public Expression
	{
	private:
		int value;
	};
}

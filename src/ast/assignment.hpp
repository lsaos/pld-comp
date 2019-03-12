#pragma once

#include "expression.hpp"

namespace ast
{
	class Variable;

	class Assignment : public Expression
	{
	private:
		Variable* variable;
		Expression* value;
	};
}

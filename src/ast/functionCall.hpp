#pragma once

#include "identifier.hpp"

namespace ast
{
	class FunctionCall : public Expression
	{
	public:
		FunctionCall(const ItemPosition& position)
			: Expression(position),
			identifier(nullptr)
		{
		}

	private:
		Identifier* identifier;
	};
}

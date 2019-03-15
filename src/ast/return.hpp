#pragma once

#include "instruction.hpp"

namespace ast
{
	class Expression;

	class Return : public Instruction
	{
	public:
		Return(const ItemPosition& position, Block* parent)
			: Instruction(position, parent)
		{
		}

	public:
		void setExpression(Expression* expression)
		{
			assert(expression);
			expr = expression;
		}

		Expression* getExpression()
		{
			return expr;
		}

	private:
		Expression* expr;
	};
}

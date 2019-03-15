#pragma once

#include "instruction.hpp"

namespace ast
{
	class Expression;

	class Return : public Instruction
	{
	public:
		Return(const ItemPosition& position)
			: Instruction(position)
		{
		}

	public:
		void setExpression(Expression* expression)
		{
			assert(expression);
			expr = expression;
		}

		const Expression* getExpression() const
		{
			return expr;
		}

	private:
		Expression* expr;
	};
}

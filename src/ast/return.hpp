#pragma once

#include "expression.hpp"

namespace ast
{
	class Return : public Instruction
	{
	public:
		Return(const ItemPosition& position)
			: Instruction(position),
			expr(nullptr)
		{
		}

	public:
		void setExpression(Expression* expression)
		{
			assert(expression);
			expression->setParent(this);
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

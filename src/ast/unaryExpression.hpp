#pragma once

#include "expression.hpp"
#include "operator.hpp"

namespace ast
{
	class UnaryExpression : public Expression
	{
	public:
		UnaryExpression(const ItemPosition& position)
			: Expression(position),
			op(UnaryOperator::Minus),
			expr(nullptr)
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

		void setOperator(UnaryOperator ope)
		{
			op = ope;
		}

		UnaryOperator getOperator() const
		{
			return op;
		}

	public:
		virtual Type getType() const
		{
			assert(expr);
			return expr->getType();
		}

		virtual int getValue() const
		{
			assert(expr);

			switch (op)
			{
			case UnaryOperator::Minus:
				return -expr->getValue();
			case UnaryOperator::Not:
				return expr->getValue() ? 0 : 1;
			default:
				assert(false);
				return 0;
			}
		}

		virtual bool isConstant() const
		{
			assert(expr);
			return expr->isConstant();
		}

	private:
		UnaryOperator op;
		Expression* expr;
	};
}

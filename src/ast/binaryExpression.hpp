#pragma once

#include "expression.hpp"
#include "operator.hpp"

namespace ast
{
	class BinaryExpression : public Expression
	{
	public:
		BinaryExpression(const ItemPosition& position)
			: Expression(position),
			op(BinaryOperator::Add),
			left(nullptr),
			right(nullptr)
		{
		}

	public:
		void setLeftExpression(Expression* expression)
		{
			assert(expression);
			left = expression;
		}

		void setRightExpression(Expression* expression)
		{
			assert(expression);
			right = expression;
		}

		void setOperator(BinaryOperator ope)
		{
			op = ope;
		}

		const Expression* getLeftExpression() const
		{
			return left;
		}

		const Expression* getRightExpression() const
		{
			return right;
		}

		BinaryOperator getOperator() const
		{
			return op;
		}

	public:
		virtual Type getType() const
		{
			assert(left);
			// TODO
			return left->getType();
		}

		virtual int getValue() const
		{
			assert(false);
			// TODO
			return 0;
		}

		virtual bool isConstant() const
		{
			assert(left && right);
			return left->isConstant() && right->isConstant();
		}

	private:
		BinaryOperator op;
		Expression* left;
		Expression* right;
	};
}

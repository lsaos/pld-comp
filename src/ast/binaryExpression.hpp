#pragma once

#include "expression.hpp"
#include "operator.hpp"

namespace ast
{
	class BinaryExpression : public Expression
	{
	public:
		BinaryExpression(const ItemPosition& position, Block* parent)
			: Expression(position, parent),
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

		Expression* getLeftExpression()
		{
			return left;
		}

		Expression* getRightExpression()
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
			return Type::Integer;
		}

		virtual int getValue() const
		{
			assert(left && right);

			const int l = left->getValue();
			const int r = right->getValue();

			switch (op)
			{
			case BinaryOperator::Add:
				return l + r;
			case BinaryOperator::Substract:
				return l - r;
			case BinaryOperator::Multiply:
				return l * r;
			case BinaryOperator::Divide:
				if (r == 0) {
					error(Error::DivisionByZero, right);
				}
				return l / r;

			case BinaryOperator::LogicialAnd:
				return l & r;
			case BinaryOperator::LogicalOr:
				return l | r;
			case BinaryOperator::LogicalXor:
				return l ^ r;

			case BinaryOperator::Equals:
				return l == r;
			case BinaryOperator::DifferentThan:
				return l != r;
			case BinaryOperator::GreaterThan:
				return l > r;
			case BinaryOperator::LowerThan:
				return l < r;
			case BinaryOperator::GreaterThanOrEquals:
				return l >= r;
			case BinaryOperator::LowerThanOrEquals:
				return l <= r;

			default:
				assert(false);
				return 0;
			}
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

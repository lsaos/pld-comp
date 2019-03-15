#pragma once

#include "expression.hpp"

namespace ast
{
	class Variable;

	class Assignment : public Expression
	{
	public:
		Assignment(const ItemPosition& position)
			: Expression(position),
			variable(nullptr),
			expr(nullptr)
		{
		}

	public:
		void setVariable(Variable* var)
		{
			assert(var);
			variable = var;
		}

		void setValue(Expression* expression)
		{
			assert(expression);
			expr = expression;
		}

		const Variable* getVariable() const
		{
			return variable;
		}

		const Expression* getExpression() const
		{
			return expr;
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
			return expr->getValue();
		}

		virtual bool isConstant() const
		{
			return false;
		}

	private:
		Variable* variable;
		Expression* expr;
	};
}

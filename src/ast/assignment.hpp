#pragma once

#include "expression.hpp"

namespace ast
{
	class Identifier;

	class Assignment : public Expression
	{
	public:
		Assignment(const ItemPosition& position, Block* parent)
			: Expression(position, parent),
			identifier(nullptr),
			expr(nullptr)
		{
		}

	public:
		void setIdentifier(Identifier* ident)
		{
			assert(ident);
			identifier = ident;
		}

		void setValue(Expression* expression)
		{
			assert(expression);
			expr = expression;
		}

		Identifier* getIdentifier()
		{
			return identifier;
		}

		Expression* getExpression()
		{
			return expr;
		}

	public:
		virtual Type getType() const
		{
			assert(expr);
			return expr->getType();
		}

	private:
		Identifier* identifier;
		Expression* expr;
	};
}

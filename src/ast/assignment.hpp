#pragma once

#include "expression.hpp"
#include "identifier.hpp"

namespace ast
{
	class Assignment : public Expression
	{
	public:
		Assignment(const ItemPosition& position)
			: Expression(position),
			identifier(nullptr),
			expr(nullptr)
		{
		}

	public:
		void setIdentifier(Identifier* ident)
		{
			assert(ident);
			ident->setParent(this);
			identifier = ident;
		}

		void setValue(Expression* expression)
		{
			assert(expression);
			expression->setParent(this);
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

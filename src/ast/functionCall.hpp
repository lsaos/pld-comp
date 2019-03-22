#pragma once

#include <vector>

using namespace std;

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

	public:
		void setIdentifier(Identifier* ident)
		{
			assert(ident);
			ident->setParent(this);
			identifier = unique_ptr<Identifier>(ident);
		}

		void addArgument(Expression* arg)
		{
			assert(arg);
			arg->setParent(this);
			args.push_back(arg);
		}

	public:
		virtual Type getType() const
		{
			assert(identifier);
			return identifier->getType();
		}

	private:
		vector<Expression*> args;
		unique_ptr<Identifier> identifier;
	};
}

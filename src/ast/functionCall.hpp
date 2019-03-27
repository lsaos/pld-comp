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
		virtual bool checkSemantic()
		{
			if (!identifier) {
				error(Error::InvalidStatement, this);
				return false;
			}

			if (!identifier->checkSemantic()) {
				return false;
			}

			// The identifier must reference an existing function
			if (!identifier->isReferencingFunction()) {
				error(Error::InvalidStatement, identifier.get());
				return false;
			}

			return true;
		}

		virtual Type getType() const
		{
			assert(identifier);
			return identifier->getType();
		}

		virtual bool isFunctionCall() const { return true; }

		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}

	private:
		vector<Expression*> args;
		unique_ptr<Identifier> identifier;
	};
}

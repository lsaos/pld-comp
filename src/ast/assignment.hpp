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
			identifier = unique_ptr<Identifier>(ident);
		}

		void setValue(Expression* expression)
		{
			assert(expression);
			expression->setParent(this);
			expr = unique_ptr<Expression>(expression);
		}

		Identifier* getIdentifier()
		{
			return identifier.get();
		}

		Expression* getExpression()
		{
			return expr.get();
		}

	public:
		virtual Type getType() const
		{
			assert(expr);
			return expr->getType();
		}

		virtual bool checkSemantic()
		{
			if (!identifier || !expr) {
				error(Error::InvalidStatement, this);
				return false;
			}

			if (!identifier->checkSemantic() || !expr->checkSemantic()) {
				return false;
			}

			// We can't assign a value to a function
			if (!identifier->isReferencingVariable()) {
				error(Error::InvalidStatement, identifier.get());
				return false;
			}

			// We can't assign a value to something void
			if (identifier->getType() == Type::Void) {
				error(Error::InvalidStatement, identifier.get());
				return false;
			}

			// Something void can't be assigned
			if (expr->getType() == Type::Void) {
				error(Error::InvalidStatement, expr.get());
				return false;
			}

			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << "Assignment {" << endl;

			identifier->toTextualRepresentation(out, i + 1);
			expr->toTextualRepresentation(out, i + 1);

			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << '}' << endl;
		}

		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}

	private:
		unique_ptr<Identifier> identifier;
		unique_ptr<Expression> expr;
	};
}

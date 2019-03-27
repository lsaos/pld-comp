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
			expression->setParent(this);
			expr = unique_ptr<Expression>(expression);
		}

		Expression* getExpression()
		{
			return expr.get();
		}

		void setOperator(UnaryOperator ope)
		{
			op = ope;
		}

		UnaryOperator getOperator() const
		{
			return op;
		}

		string getOperatorName() const
		{
			switch (op)
			{
			case UnaryOperator::Minus: return "-";
			case UnaryOperator::Not: return "!";
			default: return "error";
			}
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

	public:
		virtual bool checkSemantic()
		{
			if (!expr) {
				error(Error::InvalidStatement, this);
				return false;
			}

			if (!expr->checkSemantic()) {
				return false;
			}

			if (expr->getType() == Type::Void) {
				error(Error::InvalidStatement, expr.get());
				return false;
			}

			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << getOperatorName() << " {" << endl;

			expr->toTextualRepresentation(out, i + 1);

			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << '}' << endl;
		}

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*,int>& addressTable) {}

	private:
		UnaryOperator op;
		unique_ptr<Expression> expr;
	};
}

#pragma once

#include "expression.hpp"

namespace ast
{
	class Return : public Instruction
	{
	public:
		Return(const ItemPosition& position)
			: Instruction(position),
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

	public:
		virtual bool checkSemantic()
		{
			Function* parentFunc = getParentFunction();

			if (parentFunc->getType() == Type::Void) {
				if (expr) {
					error(Error::InvalidStatement, expr.get());
					return false;
				}
			}
			else {
				if (!expr) {
					error(Error::ExpectingExpression, this);
					return false;
				}

				if (!expr->checkSemantic()) {
					return false;
				}

				if (expr->getType() == Type::Void) {
					error(Error::InvalidStatement, expr.get());
					return false;
				}
			}

			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << "Ret {" << endl;

			if (expr) {
				expr->toTextualRepresentation(out, i + 1);
			}
			else {
				for (size_t j = 0; j < i + 1; j++) { out << ' '; }
				out << "void" << endl;
			}

			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << '}' << endl;
		}

		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}

	private:
		unique_ptr<Expression> expr;
	};
}

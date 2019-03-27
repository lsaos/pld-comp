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
			expression->setParent(this);
			left = unique_ptr<Expression>(expression);
		}

		void setRightExpression(Expression* expression)
		{
			assert(expression);
			expression->setParent(this);
			right = unique_ptr<Expression>(expression);
		}

		void setOperator(BinaryOperator ope)
		{
			op = ope;
		}

		Expression* getLeftExpression()
		{
			return left.get();
		}

		Expression* getRightExpression()
		{
			return right.get();
		}

		BinaryOperator getOperator() const
		{
			return op;
		}

		string getOperatorName() const
		{
			switch (op)
			{
			case BinaryOperator::Add: return "+";
			case BinaryOperator::Substract: return "-";
			case BinaryOperator::Multiply: return "*";
			case BinaryOperator::Divide: return "/";
			case BinaryOperator::LogicalAnd: return "&";
			case BinaryOperator::LogicalOr: return "|";
			case BinaryOperator::LogicalXor: return "^";
			case BinaryOperator::Equals: return "==";
			case BinaryOperator::DifferentThan: return "!=";
			case BinaryOperator::GreaterThan: return ">";
			case BinaryOperator::LowerThan: return "<";
			case BinaryOperator::GreaterThanOrEquals: return ">=";
			case BinaryOperator::LowerThanOrEquals: return "<=";
			default: return "error";
			}
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
					error(Error::DivisionByZero, right.get());
				}
				return l / r;

			case BinaryOperator::LogicalAnd:
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

	public:
		virtual bool checkSemantic()
		{
			if (!left || !right) {
				error(Error::InvalidStatement, this);
				return false;
			}

			if (!left->checkSemantic() || !right->checkSemantic()) {
				return false;
			}

			if (left->getType() == Type::Void) {
				error(Error::InvalidStatement, left.get());
				return false;
			}

			if (right->getType() == Type::Void) {
				error(Error::InvalidStatement, right.get());
				return false;
			}

			// Special case: division by zero
			if (op == BinaryOperator::Divide && right->isConstant() && right->getValue() == 0) {
				error(Error::DivisionByZero, right.get());
				return false;
			}

			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << getOperatorName() << " {" << endl;

			left->toTextualRepresentation(out, i + 1);
			right->toTextualRepresentation(out, i + 1);

			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << '}' << endl;
		}

		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}

	private:
		BinaryOperator op;
		unique_ptr<Expression> left;
		unique_ptr<Expression> right;
	};
}

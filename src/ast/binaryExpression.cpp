//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "binaryExpression.hpp"
#include "constant.hpp"

namespace ast
{
	//
	// BinaryExpression
	//

	BinaryExpression::BinaryExpression(const ItemPosition& position)
		: Expression(position),
		op(BinaryOperator::Add)
	{
	}

	void BinaryExpression::setLeftExpression(Expression* expression)
	{
		assert(expression);
		expression->setParent(this);
		left = unique_ptr<Expression>(expression);
	}

	void BinaryExpression::setRightExpression(Expression* expression)
	{
		assert(expression);
		expression->setParent(this);
		right = unique_ptr<Expression>(expression);
	}

	void BinaryExpression::setOperator(BinaryOperator ope)
	{
		op = ope;
	}

	string BinaryExpression::getOperatorName() const
	{
		switch (op)
		{
		case BinaryOperator::Add: return "+";
		case BinaryOperator::Substract: return "-";
		case BinaryOperator::Multiply: return "*";
		case BinaryOperator::Divide: return "/";
		case BinaryOperator::Modulo: return "%";
		case BinaryOperator::BitwiseAnd: return "&";
		case BinaryOperator::BitwiseOr: return "|";
		case BinaryOperator::BitwiseXor: return "^";
		case BinaryOperator::BitwiseLeftShift: return "<<";
		case BinaryOperator::BitwiseRightShift: return ">>";
		case BinaryOperator::LogicalAnd: return "&&";
		case BinaryOperator::LogicalOr: return "||";
		case BinaryOperator::Equals: return "==";
		case BinaryOperator::DifferentThan: return "!=";
		case BinaryOperator::GreaterThan: return ">";
		case BinaryOperator::LowerThan: return "<";
		case BinaryOperator::GreaterThanOrEquals: return ">=";
		case BinaryOperator::LowerThanOrEquals: return "<=";
		default: return "error";
		}
	}

	int BinaryExpression::getValue() const
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
		case BinaryOperator::Modulo:
			if (r == 0) {
				error(Error::DivisionByZero, right.get());
			}
			return l % r;

		case BinaryOperator::LogicalAnd:
			return l && r;
		case BinaryOperator::LogicalOr:
			return l || r;


		case BinaryOperator::BitwiseAnd:
			return l & r;
		case BinaryOperator::BitwiseOr:
			return l | r;
		case BinaryOperator::BitwiseXor:
			return l ^ r;
		case BinaryOperator::BitwiseLeftShift:
			return l << r;
		case BinaryOperator::BitwiseRightShift:
			return l >> r;

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

	Type BinaryExpression::getType() const
	{
		return Type::Integer;
	}

	bool BinaryExpression::isConstant() const
	{
		assert(left && right);

		// This exception is not constant
		if ((op == BinaryOperator::Divide || op == BinaryOperator::Modulo) && right->isConstant() && right->getValue() == 0) {
			return false;
		}

		return left->isConstant() && right->isConstant();
	}

	void BinaryExpression::checkSemantic(bool advanced) const
	{
		if (!left || !right) {
			error(Error::InvalidStatement, this);
		}

		left->checkSemantic(advanced);
		right->checkSemantic(advanced);

		if (left->getType() == Type::Void) {
			error(Error::InvalidStatement, left.get());
		}

		if (right->getType() == Type::Void) {
			error(Error::InvalidStatement, right.get());
		}

		// Special case: division by zero
		if (advanced) {
			if ((op == BinaryOperator::Divide || op == BinaryOperator::Modulo) && right->isConstant() && right->getValue() == 0) {
				error(Error::DivisionByZero, right.get());
			}
		}
	}

	void BinaryExpression::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << getOperatorName() << " {" << endl;

		left->toTextualRepresentation(out, i + 1);
		right->toTextualRepresentation(out, i + 1);

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	Instruction* BinaryExpression::optimize()
	{
		// Try to optimize the left operand
		if (left) {
			Instruction* optimized = left->optimize();
			if (optimized) {
				assert(optimized != left.get() && optimized->isExpression());
				left = unique_ptr<Expression>((Expression*)optimized);
			}
		}

		// Try to optimize the right operand
		if (right) {
			Instruction* optimized = right->optimize();
			if (optimized) {
				assert(optimized != right.get() && optimized->isExpression());
				right = unique_ptr<Expression>((Expression*)optimized);
			}
		}

		// If the expression is constant, replace by the precomputed constant
		if (isConstant()) {
			Constant* constant = new Constant(getPosition());
			constant->setType(getType());
			constant->setValue(getValue());
			return constant;
		}
		else {
			return nullptr;
		}
	}

	void BinaryExpression::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable) 
	{
		switch (op)
		{
			case BinaryOperator::Add :
				/*if (left->isConstant() && right->isConstant()) {
					int a = left->getValue() + right->getValue();
					cout << a << endl;
					f << "\tmovl $" << a << ", %eax" << endl;
				}*/
				left->generateAssembly(f, addressTable);
				f << "\tmovl %eax, %edx" << endl;
				right->generateAssembly(f, addressTable);
				f << "\taddl %edx, %eax" << endl;
				break;
			case BinaryOperator::Substract :
				left->generateAssembly(f, addressTable);
				f << "\tmovl %eax, %edx" << endl;
				right->generateAssembly(f, addressTable);
				f << "\tsubl %edx, %eax" << endl;
				break;
			case BinaryOperator::Multiply :
				left->generateAssembly(f, addressTable);
				f << "\tmovl %eax, %edx" << endl;
				right->generateAssembly(f, addressTable);
				f << "\timul %edx, %eax" << endl;
				break;
			case BinaryOperator::BitwiseAnd:
				left->generateAssembly(f, addressTable);
				f << "\tmovl %eax, %edx" << endl;
				right->generateAssembly(f, addressTable);
				f << "\tandl %edx, %eax" << endl;
				break;
			case BinaryOperator::BitwiseOr:
				left->generateAssembly(f, addressTable);
				f << "\tmovl %eax, %edx" << endl;
				right->generateAssembly(f, addressTable);
				f << "\torl %edx, %eax" << endl;
				break;
			case BinaryOperator::BitwiseXor:
				left->generateAssembly(f, addressTable);
				f << "\tmovl %eax, %edx" << endl;
				right->generateAssembly(f, addressTable);
				f << "\txorl %edx, %eax" << endl;
				break;
		}
	}
}
//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "unaryExpression.hpp"
#include "constant.hpp"

namespace ast
{
	//
	// UnaryExpression
	//

	UnaryExpression::UnaryExpression(const ItemPosition& position)
		: Expression(position),
		op(UnaryOperator::Minus),
		expr(nullptr)
	{
	}

	void UnaryExpression::setExpression(Expression* expression)
	{
		assert(expression);
		expression->setParent(this);
		expr = unique_ptr<Expression>(expression);
	}

	void UnaryExpression::setOperator(UnaryOperator ope)
	{
		op = ope;
	}

	string UnaryExpression::getOperatorName() const
	{
		switch (op)
		{
		case UnaryOperator::Minus: return "-";
		case UnaryOperator::LogicalNot: return "!";
		case UnaryOperator::BitwiseNot: return "~";
		default: return "error";
		}
	}

	Type UnaryExpression::getType() const
	{
		assert(expr);
		return expr->getType();
	}

	int UnaryExpression::getValue() const
	{
		assert(expr);

		switch (op)
		{
		case UnaryOperator::Minus:
			return -expr->getValue();
		case UnaryOperator::LogicalNot:
			return expr->getValue() ? 0 : 1;
		case UnaryOperator::BitwiseNot:
			return ~expr->getValue();
		default:
			assert(false);
			return 0;
		}
	}

	bool UnaryExpression::isConstant() const
	{
		assert(expr);
		return expr->isConstant();
	}

	void UnaryExpression::checkSemantic(bool advanced) const
	{
		if (!expr) {
			error(Error::InvalidStatement, this);
		}

		expr->checkSemantic(advanced);

		if (expr->getType() == Type::Void) {
			error(Error::InvalidStatement, expr.get());
		}
	}

	void UnaryExpression::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << getOperatorName() << " {" << endl;

		expr->toTextualRepresentation(out, i + 1);

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	Instruction* UnaryExpression::optimize()
	{
		// Try to optimize the operand
		if (expr) {
			Instruction* optimized = expr->optimize();
			if (optimized) {
				assert(optimized != expr.get() && optimized->isExpression());
				expr = unique_ptr<Expression>((Expression*)optimized);
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

	void UnaryExpression::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg)
	{
		switch (op)
		{
		case UnaryOperator::Minus:
			expr->generateAssembly(f, addressTable, curReg);
			f << "\tnegl ";
			break;

		case UnaryOperator::LogicalNot:
			//Quel op�rateur : ! ou ~ ?
			break;
}
    
void UnaryExpression::prepare()
{
	  if (expr) {
			expr->prepare();
		}
}

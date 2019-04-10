//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once
#include "binaryExpression.hpp"
#include "constant.hpp"
#include "identifier.hpp"
#include "../ir/cfg.hpp"
#include "../ir/irInstrBinaryOperation.hpp"
#include "../ir/irInstrComparison.hpp"

using namespace ir;

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
				optimized->setParent(this);
				left = unique_ptr<Expression>((Expression*)optimized);
			}
		}

		// Try to optimize the right operand
		if (right) {
			Instruction* optimized = right->optimize();
			if (optimized) {
				assert(optimized != right.get() && optimized->isExpression());
				optimized->setParent(this);
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

		if (left->isConstant() && isLeftNeutralElement(left->getValue())) {
			return right.release();
		}

		if (right->isConstant() && isRightNeutralElement(right->getValue())) {
			return left.release();
		}

		return nullptr;
	}

	bool BinaryExpression::isLeftNeutralElement(int value) const
	{
		switch (op)
		{
		case BinaryOperator::Add: return value == 0;
		case BinaryOperator::Multiply: return value == 1;
		default: return false;
		}
	}

	bool BinaryExpression::isRightNeutralElement(int value) const
	{
		switch (op)
		{
		case BinaryOperator::Add: return value == 0;
		case BinaryOperator::Multiply: return value == 1;
		case BinaryOperator::Substract: return value == 0;
		case BinaryOperator::Divide: return value == 1;
		default: return false;
		}
	}

	void BinaryExpression::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg)
	{
		string assemblyOp;
		switch (op)
		{
		case BinaryOperator::Add:
			/* A revoir pour une certaine optimisation
			if (left->isConstant() && right->isConstant()) {
				int a = left->getValue() + right->getValue();
				cout << a << endl;
				f << "\tmovl $" << a << ", %eax" << endl;
			}*/
			assemblyOp = "addl";
			break;

		case BinaryOperator::Substract:
			assemblyOp = "subl";
			break;
		case BinaryOperator::Multiply:
			assemblyOp = "imull";
			break;
		case BinaryOperator::Divide:
			assemblyOp = "idivl";
			break;
		case BinaryOperator::BitwiseAnd:
			assemblyOp = "andl";
			break;
		case BinaryOperator::BitwiseOr:
			assemblyOp = "orl";
			break;
		case BinaryOperator::BitwiseXor:
			assemblyOp = "xorl";
			break;
		}

		if (!right->isFinal() && !right->isIdentifier())
		{
			if (!left->isFinal() && !left->isIdentifier())
			{
				right->generateAssembly(f, addressTable, "%edx");
				f << "%edx" << endl;
				left->generateAssembly(f, addressTable); //%eax
				f << "%eax" << endl;
				f << "\t" << assemblyOp << " %edx, "; //%eax
			}
			else
			{
				right->generateAssembly(f, addressTable, "%eax");
				f << "%eax" << endl;
				f << "\t" << assemblyOp << " ";
				if (left->isFinal())
					f << '$' << left->getValue();
				else
					f << addressTable[((Identifier*)(left.get()))->getReferencedVariable()] << "(%rbp)";
				f << ", ";
			}
		}
		else
		{
			left->generateAssembly(f, addressTable, curReg);
			f << curReg << endl;
			f << "\t" << assemblyOp << " ";
			if (right->isFinal())
				f << '$' << right->getValue();
			else
				f << addressTable[((Identifier*)(right.get()))->getReferencedVariable()] << "(%rbp)";
			f << ", ";
		}
	}

	void BinaryExpression::prepare()
	{
		if (left) {
			left->prepare();
		}

		if (right) {
			right->prepare();
		}
	}

	string BinaryExpression::buildIR(CFG* cfg)
	{
		IRInstrBinaryOperation::Operation operation;
		IRInstrComparison::Operation operationComp;
		bool comparison = false;
		unique_ptr<Expression> temp;
		switch (op)
		{
		case BinaryOperator::Add:
			operation = IRInstrBinaryOperation::Operation::add;
			break;
		case BinaryOperator::Substract:
			operation = IRInstrBinaryOperation::Operation::sub;
			break;
		case BinaryOperator::Multiply:
			operation = IRInstrBinaryOperation::Operation::mul;
			break;
		case BinaryOperator::BitwiseAnd:
			operation = IRInstrBinaryOperation::Operation::bitwiseAnd;
			break;
		case BinaryOperator::BitwiseOr:
			operation = IRInstrBinaryOperation::Operation::bitwiseOr;
			break;
		case BinaryOperator::BitwiseXor:
			operation = IRInstrBinaryOperation::Operation::bitwiseXor;
			break;
		case BinaryOperator::Equals:
			comparison = true;
			operationComp = IRInstrComparison::Operation::cmp_eq;
			break;
		case BinaryOperator::LowerThan:
			comparison = true;
			operationComp = IRInstrComparison::Operation::cmp_lt;
			break;
		case BinaryOperator::LowerThanOrEquals:
			comparison = true;
			operationComp = IRInstrComparison::Operation::cmp_le;
			break;
		case BinaryOperator::DifferentThan:
			comparison = true;
			operationComp = IRInstrComparison::Operation::cmp_neq;
			break;
		case BinaryOperator::GreaterThan:
			comparison = true;
			operationComp = IRInstrComparison::Operation::cmp_gt;
			break;
		case BinaryOperator::GreaterThanOrEquals:
			comparison = true;
			operationComp = IRInstrComparison::Operation::cmp_ge;
			break;
		}

		string var_1 = (left.get())->buildIR(cfg);
		string var_2 = (right.get())->buildIR(cfg);
		//string var_3 = cfg->create_new_tempvar(getType()); //A FAIRE DANS LE FUTUR POUR PLUS DE COHERENCE !!
		string var_3 = cfg->create_new_tempvar(getLeftExpression()->getType());

		if (!comparison)
			cfg->current_bb->add_IRInstr(new IRInstrBinaryOperation(cfg->current_bb, operation, var_3, var_1, var_2), getLeftExpression()->getType()); //getType de l'expression à la place de getLeftExpression()->getType() !!
		else
			cfg->current_bb->add_IRInstr(new IRInstrComparison(cfg->current_bb, operationComp, var_3, var_1, var_2), getLeftExpression()->getType());
		return var_3;
	}
}

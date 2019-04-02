//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <string>

using namespace std;

#include "expression.hpp"
#include "operator.hpp"

namespace ast
{
	// Represents an operation with 2 operands.
	class BinaryExpression : public Expression
	{
	public:
		// Create a binary expression.
		BinaryExpression(const ItemPosition& position);

	public:
		// Set the left operand.
		void setLeftExpression(Expression* expression);

		// Set the right operand.
		void setRightExpression(Expression* expression);

		// Set the operator.
		void setOperator(BinaryOperator ope);

	public:
		// Get the operator as a string.
		string getOperatorName() const;

		// Get the left operand.
		Expression* getLeftExpression() const {
			return left.get();
		}

		// Get the right operand.
		Expression* getRightExpression() const {
			return right.get();
		}

		// Get the operator.
		BinaryOperator getOperator() const {
			return op;
		}

	public:
		virtual Type getType() const;
		virtual int getValue() const;
		virtual bool isConstant() const;

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual string getStringRepresentation() const { return getOperatorName(); }
		virtual Instruction* optimize();
		virtual void prepare();

	private:
		BinaryOperator op; // Binary operator.
		unique_ptr<Expression> left; // Left operand.
		unique_ptr<Expression> right; // Right operand.

	public:
		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg = "%eax");
		virtual string buildIR(ir::CFG*);
	};
}

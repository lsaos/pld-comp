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
	// Represents an operation with only one operand.
	class UnaryExpression : public Expression
	{
	public:
		// Create an unary expression.
		UnaryExpression(const ItemPosition& position);

	public:
		// Set the operand.
		void setExpression(Expression* expression);

		// Set the operator.
		void setOperator(UnaryOperator ope);

	public:
		// Get the operand.
		Expression* getExpression() const {
			return expr.get();
		}

		// Get the operator.
		UnaryOperator getOperator() const {
			return op;
		}

		// Get the operator as a string.
		string getOperatorName() const;

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
		UnaryOperator op; // Unary operator.
		unique_ptr<Expression> expr; // Unary operand.

	public:
		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg = "%eax");
		virtual string buildIR(ir::CFG*) { return string(); }
	};
}

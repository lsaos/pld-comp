//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "expression.hpp"
#include "identifier.hpp"

namespace ast
{
	// Represents an assignment (operator =).
	// It returns the value of the assigned variable.
	class Assignment : public Expression
	{
	public:
		// Create an assignment.
		Assignment(const ItemPosition& position);

	public:
		// Set the left value.
		void setIdentifier(Identifier* ident);

		// Set the right value.
		void setValue(Expression* expression);

	public:
		// Get the left-value.
		Identifier* getIdentifier() const {
			return identifier.get();
		}

		// Get the right value.
		Expression* getExpression() const {
			return expr.get();
		}

	public:
		virtual Type getType() const;
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual string getStringRepresentation() const { return "="; }
		virtual Instruction* optimize();
		virtual void prepare();

		virtual bool isAssignment() const { return true; }

	private:
		unique_ptr<Identifier> identifier; // Identifier of the assigned variable.
		unique_ptr<Expression> expr; // Expression of the value to assign.

	public:
		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg = "%eax");
		virtual string buildIR(ir::CFG*);
	};
}

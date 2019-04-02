//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "expression.hpp"

namespace ast
{
	// Return instruction in a function.
	// A return has an expression if it returns a value.
	class Return : public Instruction
	{
	public:
		// Create a return instruction.
		Return(const ItemPosition& position);

	public:
		// Set the value expression of the return.
		// The return takes the ownership of the specified pointer.
		void setExpression(Expression* expression);

	public:
		// Get the value expression.
		// Returns null if the return has no value.
		Expression* getExpression() const {
			return expr.get();
		}

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual Instruction* optimize();
		virtual void prepare();

	public:
		virtual string getStringRepresentation() const { return "return"; }
		virtual bool isReturn() const { return true; }

	private:
		unique_ptr<Expression> expr; // Value expression.

	public:
		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg = "%eax");
		virtual string buildIR(ir::CFG*);
	};
}

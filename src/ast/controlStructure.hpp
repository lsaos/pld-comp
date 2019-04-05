//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "expression.hpp"

namespace ast
{
	// Represents a control structure (if, while...).
	// All controls structures have at least a condition
	// expression and an instruction to execute if
	// the condition is true.
	class ControlStructure : public Instruction
	{
	public:
		// Create a control structure.
		ControlStructure(const ItemPosition& position);

	public:
		// Set the condition expression.
		void setCondition(Expression* cond);

		// Set the instruction to execute when the condition is true.
		void setInstruction(Instruction* ins);

	public:
		// Get the condition of the control structure.
		Expression* getCondition() const {
			return condition.get();
		}

		// Get the instruction to execute when the condition is true.
		Instruction* getInstruction() const {
			return instr.get();
		}

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual Instruction* optimize();
		virtual void prepare();
		virtual bool isControlStructure() const { return true; }

	public:
		virtual string buildIR(ir::CFG*) { return string(); }

	protected:
		unique_ptr<Expression> condition; // Condition to execute the instruction.
		unique_ptr<Instruction> instr; // Instruction to execute when the condition is true.
	};
}

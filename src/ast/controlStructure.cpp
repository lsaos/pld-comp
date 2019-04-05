//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "controlStructure.hpp"

namespace ast
{
	ControlStructure::ControlStructure(const ItemPosition& position)
		: Instruction(position)
	{
	}

	void ControlStructure::setCondition(Expression* cond)
	{
		assert(cond);
		cond->setParent(this);
		condition = unique_ptr<Expression>(cond);
	}

	void ControlStructure::setInstruction(Instruction* ins)
	{
		assert(ins);
		ins->setParent(this);
		instr = unique_ptr<Instruction>(ins);
	}

	void ControlStructure::checkSemantic(bool advanced) const
	{
		if (!condition || !instr) {
			error(Error::InvalidStatement, this);
		}

		condition->checkSemantic(advanced);

		if (condition->getType() == Type::Void) {
			error(Error::InvalidInstruction, condition.get());
		}

		instr->checkSemantic(advanced);
	}

	Instruction* ControlStructure::optimize()
	{
		// Try to optimize the condition
		if (condition) {
			Instruction* optimized = condition->optimize();
			if (optimized) {
				assert(optimized != condition.get() && optimized->isExpression());
				optimized->setParent(this);
				condition = unique_ptr<Expression>((Expression*)optimized);
			}
		}

		// Try to optimize the instruction
		if (instr) {
			Instruction* optimized = instr->optimize();
			if (optimized) {
				assert(optimized != instr.get());
				optimized->setParent(this);
				instr = unique_ptr<Instruction>(optimized);
			}
		}

		// We can't optimize the control structure itself
		return nullptr;
	}

	void ControlStructure::prepare()
	{
		if (condition) {
			condition->prepare();
		}
		if (instr) {
			instr->prepare();
		}
	}
}

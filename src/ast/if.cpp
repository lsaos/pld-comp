//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "if.hpp"
#include "block.hpp"
#include "../ir/cfg.hpp"
#include "../ir/basicBlock.hpp"

using namespace ir;

namespace ast
{
	If::If(const ItemPosition& position)
		: ControlStructure(position)
	{
	}

	void If::setAlternative(Instruction* alt)
	{
		assert(alt);
		alt->setParent(this);
		alternative = unique_ptr<Instruction>(alt);
	}

	void If::checkSemantic(bool advanced) const
	{
		ControlStructure::checkSemantic(advanced);

		if (alternative) {
			alternative->checkSemantic(advanced);
		}
	}

	Instruction* If::optimize()
	{
		ControlStructure::optimize();

		// Try to optimize the instruction
		if (alternative) {
			Instruction* optimized = alternative->optimize();
			if (optimized) {
				assert(optimized != alternative.get());
				optimized->setParent(this);
				alternative = unique_ptr<Instruction>(optimized);
			}
		}

		// If the condition is constant the if is useless
		if (condition->isConstant()) {
			if (condition->getValue() != 0) {
				return instr.release();
			}
			else {
				if (alternative) {
					return alternative.release();
				}
				else {
					// Replace by an empty block
					return new Block(getPosition());
				}
			}
		}

		return nullptr;
	}

	void If::prepare()
	{
		ControlStructure::prepare();

		if (alternative) {
			alternative->prepare();
		}
	}

	void If::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "If {" << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Cond {" << endl;

		condition->toTextualRepresentation(out, i + 2);

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << '}' << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Body {" << endl;

		instr->toTextualRepresentation(out, i + 2);

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << '}' << endl;

		if (alternative) {
			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			out << "Alt {" << endl;

			alternative->toTextualRepresentation(out, i + 2);

			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			out << '}' << endl;
		}

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	string If::buildIR(ir::CFG* cfg)
	{
		condition->buildIR(cfg);
		BasicBlock* testBB = cfg->current_bb;
		
		//Construction du BasicBlock then
		BasicBlock* thenBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->current_bb = thenBB;
		instr->buildIR(cfg);

		BasicBlock* elseBB;

		if (alternative != nullptr)
		{
			elseBB = new BasicBlock(cfg, cfg->new_BB_name());
			cfg->current_bb = elseBB;
			instr->buildIR(cfg);
		}
		else
			elseBB = nullptr;

		BasicBlock* afterIfBB = new BasicBlock(cfg, cfg->new_BB_name());
		//Pourquoi ? testBB n'a pas encore de successeurs à ce moment de la génération de l'IR...
		afterIfBB->exit_true = testBB->exit_true;
		afterIfBB->exit_false = testBB->exit_false;
		testBB->exit_true = thenBB;
		testBB->exit_false = elseBB;
		thenBB->exit_true = afterIfBB;
		thenBB->exit_false = nullptr;
		
		if (elseBB != nullptr)
		{
			elseBB->exit_true = afterIfBB;
			elseBB->exit_false = nullptr;
		}

		cfg->current_bb = afterIfBB;

		return "";
	}

}

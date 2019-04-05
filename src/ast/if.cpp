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
		string var = condition->buildIR(cfg);
		cfg->current_bb->set_last_var(var);
		BasicBlock* testBB = cfg->current_bb;

		//Construction of the then BasicBlock 
		BasicBlock* thenBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(thenBB);

		BasicBlock* elseBB;

		//Construction of the next BasicBlock after if instruction
		BasicBlock* afterIfBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(afterIfBB);
	
		//AfterIF BB's pointers stitching
		afterIfBB->exit_true = testBB->exit_true;
		afterIfBB->exit_false = testBB->exit_false;

		//Construction of the else BasicBlock, if it exists
		if (alternative != nullptr)
		{
			elseBB = new BasicBlock(cfg, cfg->new_BB_name());
			cfg->add_bb(elseBB);
			elseBB->exit_true = afterIfBB;
			elseBB->exit_false = nullptr;
		}
		else
		{
			elseBB = nullptr;
		}

		//Original BB's pointers stitching
		testBB->exit_true = thenBB;
		if (elseBB == nullptr)
			testBB->exit_false = afterIfBB;
		else
			testBB->exit_false = elseBB;

		//Then BB's pointers stitching
		thenBB->exit_true = afterIfBB;
		thenBB->exit_false = nullptr;

		//IR code generation for Then BB
		cfg->current_bb = thenBB;
		var = instr->buildIR(cfg);
		cfg->current_bb->set_last_var(var);

		//IR code generation for Else BB, if it exists
		if (elseBB != nullptr)
		{
			cfg->current_bb = elseBB;
			var = alternative->buildIR(cfg);
			cfg->current_bb->set_last_var(var);
		}

		cfg->current_bb = afterIfBB;

		return "";
	}

}

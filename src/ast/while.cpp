//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "while.hpp"
#include "../ir/cfg.hpp"
#include "../ir/basicBlock.hpp"

using namespace ir;

namespace ast
{
	While::While(const ItemPosition& position)
		: ControlStructure(position)
	{
	}
	
	void While::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "While {" << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Cond {" << endl;

		getCondition()->toTextualRepresentation(out, i + 2);

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << '}' << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Body {" << endl;

		getInstruction()->toTextualRepresentation(out, i + 2);

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << '}' << endl;

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	string While::buildIR(ir::CFG* cfg)
	{
		string var;
		BasicBlock* beforeWhileBB = cfg->current_bb;
		///cfg->current_bb->set_last_var(var);

		//Construction of the body while's code BasicBlock
		BasicBlock* bodyBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(bodyBB);

		//Construction of the test while's code BasicBlock
		BasicBlock* testBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(testBB);

		//Construction of the BasicBlock of the block after while loop
		BasicBlock* afterWhileBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(afterWhileBB);

		//AfterWhileBB's pointers stitching
		afterWhileBB->exit_true = beforeWhileBB->exit_true;
		afterWhileBB->exit_false = beforeWhileBB->exit_false;

		//BeforeWhileBB's pointers stitching
		beforeWhileBB->exit_true = testBB;
		beforeWhileBB->exit_false = nullptr;

		//TestBB's pointers stitching
		testBB->exit_true = bodyBB;
		testBB->exit_false = afterWhileBB;

		//BodyBB's pointers stitching
		bodyBB->exit_true = testBB;
		bodyBB->exit_false = nullptr;

		//IR code generation for Test BB
		cfg->current_bb = testBB;
		var = condition->buildIR(cfg);
		testBB->set_last_var(var);

		//IR code generation for Body BB
		cfg->current_bb = bodyBB;
		var = instr->buildIR(cfg);
		bodyBB->set_last_var(var);

		cfg->current_bb = afterWhileBB;

		return "";
	}
}

//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "block.hpp"
#include "variable.hpp"

namespace ast
{
	//
	// Block
	//

	Block::Block(const ItemPosition& position)
		: Instruction(position)
	{
	}

	Variable* Block::getVariable(const string& name, bool withAncestors) const
	{
		for (const auto& instr : instructions) {
			if (instr->isVariable() && ((Variable*)instr.get())->getName() == name) {
				return (Variable*)instr.get();
			}
		}

		if (withAncestors) {
			Block* parentBlock = getParentBlock();
			if (parentBlock) {
				return parentBlock->getVariable(name, true);
			}
		}

		return nullptr;
	}

	vector<Variable*> Block::getVariables(bool withAncestors) const
	{
		vector<Variable*> vars;

		for (const auto& instr : instructions) {
			if (instr->isVariable()) {
				vars.push_back((Variable*)instr.get());
			}
		}

		if (withAncestors) {
			Block* parentBlock = getParentBlock();
			if (parentBlock) {
				vector<Variable*> parentVars(parentBlock->getVariables(true));
				vars.insert(vars.end(), parentVars.begin(), parentVars.end());
			}
		}

		return vars;
	}

	vector<Instruction*> Block::getInstructions() const
	{
		vector<Instruction*> instrs;

		for (const auto& instr : instructions) {
			if (!instr->isVariable()) {
				instrs.push_back(instr.get());
			}
		}

		return instrs;
	}

	void Block::checkSemantic(bool advanced) const
	{
		// Check symbols duplication
		if (getParentBlock()) {
			vector<string> symbols;

			const vector<Variable*> vars(getParentBlock()->getVariables(true));
			for (const Variable* var : vars) {
				symbols.push_back(var->getName());
			}

			/*const vector<Function*> funcs(getProgram()->getFunctions());
			for (const Function* func : funcs) {
				symbols.push_back(func->getName());
			}*/

			for (auto& instr : instructions) {
				if (instr->isVariable()) {
					const string& name(((const Variable*)instr.get())->getName());

					if (find(symbols.begin(), symbols.end(), name) != symbols.end()) {
						error(Error::DuplicatedSymbolName, instr.get());
					}

					symbols.push_back(name);
				}
			}
		}

		// Check children semantic
		for (const auto& instr : instructions) {
			instr->checkSemantic(advanced);
		}
	}

	void Block::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		cout << "ListInstr {" << endl;

		for (auto& instr : instructions) {
			instr->toTextualRepresentation(out, i + 1);
		}

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	void Block::add(Instruction* instr, bool atBeginning)
	{
		assert(instr);

		// If it's a variable and we are the program, it has a global scope
		if (instr->isVariable() && isProgram()) {
			((Variable*)instr)->setScope(Scope::Global);
		}

		instr->setParent(this);
        if(!atBeginning){
    		instructions.push_back(unique_ptr<Instruction>(instr));
        } else {
            instructions.insert(instructions.begin(),unique_ptr<Instruction>(instr));
        }
	}

	Instruction* Block::optimize()
	{
		// Optimize instructions
		for (auto& instr : instructions) {
			Instruction* optimized = instr->optimize();
			if (optimized) {
				assert(optimized != instr.get());
				instr = unique_ptr<Instruction>(optimized);
			}
		}

		// We can't optimize the block itself
		return nullptr;
	}

	void Block::prepare()
	{
		for (auto& instr : instructions) {
			instr->prepare();
		}
	}

	string Block::buildIR(ir::CFG* cfg)
	{
		string var;
		for (auto& i : instructions)
		{
			var = i->buildIR(cfg);
		}

		return var;
	}
}

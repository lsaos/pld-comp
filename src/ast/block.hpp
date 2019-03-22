#pragma once

#include <vector>

using namespace std;

#include "variable.hpp"

namespace ast
{
	class Variable;

	class Block : public Instruction
	{
	public:
		Block(const ItemPosition& position)
			: Instruction(position)
		{
		}

	public:
		Variable* getVariable(const string& name, bool withAncestors)
		{
			for (const Instruction* instr : instructions) {
				if (instr->isVariable() && ((Variable*)instr)->getName() == name) {
					return (Variable*)instr;
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

		vector<Variable*> getVariables()
		{
			vector<Variable*> vars;

			for (const Instruction* instr : instructions) {
				if (instr->isVariable()) {
					vars.push_back((Variable*)instr);
				}
			}

			return vars;
		}

	public:
		virtual void add(Instruction* instr)
		{
			assert(instr);
			instr->setParent(this);
			instructions.push_back(instr);
		}

		virtual bool isBlock() const { return true; }

	protected:
		vector<Instruction*> instructions;
	};
}

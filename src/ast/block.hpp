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
		Block(const ItemPosition& position, Block* parent)
			: Instruction(position, parent)
		{
		}

	public:
		virtual void add(Instruction* instr)
		{
			assert(instr);
			instructions.push_back(instr);
		}

		const Variable* getVariable(const string& name, bool withAncestors) const
		{
			const Instruction* ident = (const Instruction*)getIdentifiable(name, withAncestors);

			if (ident && ident->isVariable()) {
				return (const Variable*)ident;
			}
			else {
				return nullptr;
			}
		}

		const Identifiable* getIdentifiable(const string& name, bool withAncestors) const
		{
			for (const Instruction* instr : instructions) {
				if (instr->isIdentifiable() && ((const Identifiable*)instr)->getName() == name) {
					return (const Identifiable*)instr;
				}
			}

			if (withAncestors && getParent()) {
				return getParent()->getIdentifiable(name, true);
			}
			else {
				return nullptr;
			}
		}

	protected:
		vector<Instruction*> instructions;
	};
}

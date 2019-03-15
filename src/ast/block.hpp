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
		Variable* getVariable(const string& name, bool withAncestors)
		{
			Instruction* ident = (Instruction*)getIdentifiable(name, withAncestors);

			if (ident && ident->isVariable()) {
				return (Variable*)ident;
			}
			else {
				return nullptr;
			}
		}

		Identifiable* getIdentifiable(const string& name, bool withAncestors)
		{
			for (const Instruction* instr : instructions) {
				if (instr->isIdentifiable() && ((Identifiable*)instr)->getName() == name) {
					return (Identifiable*)instr;
				}
			}

			if (withAncestors && getParent()) {
				return getParent()->getIdentifiable(name, true);
			}
			else {
				return nullptr;
			}
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
			instructions.push_back(instr);
		}

	protected:
		vector<Instruction*> instructions;
	};
}

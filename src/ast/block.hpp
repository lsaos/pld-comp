#pragma once

#include <vector>
#include <memory>

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

		vector<Variable*> getVariables()
		{
			vector<Variable*> vars;

			for (const auto& instr : instructions) {
				if (instr->isVariable()) {
					vars.push_back((Variable*)instr.get());
				}
			}

			return vars;
		}

	public:
		virtual bool checkSemantic()
		{
			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			cout << "ListInstr {" << endl;

			for (auto& instr : instructions) {
				instr->toTextualRepresentation(out, i + 1);
			}

			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << '}' << endl;
		}

	public:
		virtual void add(Instruction* instr)
		{
			assert(instr);
			instr->setParent(this);
			instructions.push_back(unique_ptr<Instruction>(instr));
		}

		virtual bool isBlock() const { return true; }

	protected:
		vector<unique_ptr<Instruction>> instructions;
	};
}

#pragma once

#include <vector>
#include <memory>
#include "instruction.hpp"

using namespace std;

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

		Variable* getVariable(const string& name, bool withAncestors);

		vector<Variable*> getVariables(bool withAncestors);

		// Get block instructions which are NOT variable declarations.
		vector<Instruction*> getInstructions();

		virtual bool checkSemantic();

		virtual void toTextualRepresentation(ostream& out, size_t i);

		virtual void add(Instruction* instr);

		virtual bool isBlock() const { return true; }

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*,int>& addressTable) {}

	protected:
		vector<unique_ptr<Instruction>> instructions;
	};
}

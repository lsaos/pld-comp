#pragma once

#include <vector>

using namespace std;

#include "instruction.hpp"

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
		virtual void add(Instruction* instr)
		{
			assert(instr);
			instructions.push_back(instr);
		}

	private:
		vector<Instruction*> instructions;
	};
}

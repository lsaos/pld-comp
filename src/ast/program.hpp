#pragma once

#include "block.hpp"

namespace ast
{
	class Program : public Block
	{
	public:
		Program()
			: Block(ItemPosition())
		{
		}

	public:
		virtual void add(Instruction* instr)
		{
			assert(instr);

			if (!instr->isFunction() && !instr->isVariable()) {
				error(Error::InvalidInstruction, instr);
			}

			Block::add(instr);
		}
	};
}

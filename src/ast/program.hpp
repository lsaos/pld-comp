#pragma once

#include "block.hpp"

namespace ast
{
	class Function;

	class Program : public Block
	{
	public:
		Program()
			: Block(ItemPosition(), nullptr)
		{
		}

	public:
		const Function* getFunction(const string& name) const
		{
			const Instruction* ident = (const Instruction*)getIdentifiable(name, false);

			if (ident && ident->isFunction()) {
				return (const Function*)ident;
			}
			else {
				return nullptr;
			}
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

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
		Function* getFunction(const string& name)
		{
			const Instruction* ident = (Instruction*)getIdentifiable(name, false);

			if (ident && ident->isFunction()) {
				return (Function*)ident;
			}
			else {
				return nullptr;
			}
		}

		Function* getMain()
		{
			return getFunction("main");
		}

		vector<Function*> getFunctions()
		{
			vector< Function*> funcs;

			for (const Instruction* instr : instructions) {
				if (instr->isFunction()) {
					funcs.push_back((Function*)instr);
				}
			}

			return funcs;
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

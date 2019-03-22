#pragma once

#include "function.hpp"

namespace ast
{
	class Function;

	class Program : public Block
	{
	public:
		Program()
			: Block(ItemPosition())
		{
		}

	public:
		Function* getFunction(const string& name)
		{
			for (const Instruction* instr : instructions) {
				if (instr->isFunction() && ((Function*)instr)->getName() == name) {
					return (Function*)instr;
				}
			}

			return nullptr;
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

		size_t getFunctionsCount()
		{
			size_t cnt = 0;

			for (const Instruction* instr : instructions) {
				if (instr->isFunction()) {
					cnt++;
				}
			}

			return cnt;
		}

	public:
		virtual void add(Instruction* instr)
		{
			assert(instr);

			if (instr->isVariable()) {
				((Variable*)instr)->setScope(Scope::Global);
			}

			Block::add(instr);
		}

		virtual bool isProgram() const { return true; }
	};
}

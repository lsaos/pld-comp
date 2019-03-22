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
			for (const auto& instr : instructions) {
				if (instr->isFunction() && ((Function*)instr.get())->getName() == name) {
					return (Function*)instr.get();
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
			vector<Function*> funcs;

			for (const auto& instr : instructions) {
				if (instr->isFunction()) {
					funcs.push_back((Function*)instr.get());
				}
			}

			return funcs;
		}

		size_t getFunctionsCount()
		{
			size_t cnt = 0;

			for (const auto& instr : instructions) {
				if (instr->isFunction()) {
					cnt++;
				}
			}

			return cnt;
		}

	public:
		virtual bool checkSemantic()
		{
			// Check the program has a main function
			if (!getMain()) {
				error(Error::NoMain, this);
			}

			// Check we have only functions or global variables
			for (const auto& instr : instructions) {
				if (!instr->isFunction() && !(instr->isVariable() && ((const Variable*)instr.get())->getScope() == Scope::Global)) {
					error(Error::InvalidStatement, instr.get());
					return false;
				}
			}

			// Check we don't have duplicated function names
			vector<string> funcs;
			for (const auto& instr : instructions) {
				if (instr->isFunction()) {
					const string& name(((Function*)instr.get())->getName());
					if (find(funcs.begin(), funcs.end(), name) != funcs.end()) {
						error(Error::DuplicatedSymbolName, instr.get());
						return false;
					}
					funcs.push_back(name);
				}
			}

			// Base block check
			return Block::checkSemantic();
		}

		virtual void toTextualRepresentation(ostream& out, size_t i = 0)
		{
			cout << "Program {" << endl;

			for (auto& instr : instructions) {
				instr->toTextualRepresentation(out, i + 1);
			}

			out << '}' << endl;
		}

	public:
		virtual void add(Instruction* instr)
		{
			assert(instr);

			// If it's a variable, it has a global scope
			if (instr->isVariable()) {
				((Variable*)instr)->setScope(Scope::Global);
			}

			Block::add(instr);
		}

		virtual bool isProgram() const { return true; }
	};
}

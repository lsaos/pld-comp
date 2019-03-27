//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "program.hpp"
#include "function.hpp"
#include "variable.hpp"

namespace ast
{
	//
	// Program
	//

	Program::Program()
		: Block(ItemPosition())
	{
	}

	Function* Program::getFunction(const string& name) const
	{
		for (const auto& instr : instructions) {
			if (instr->isFunction() && ((const Function*)instr.get())->getName() == name) {
				return (Function*)instr.get();
			}
		}

		return nullptr;
	}

	vector<Function*> Program::getFunctions() const
	{
		vector<Function*> funcs;

		for (const auto& instr : instructions) {
			if (instr->isFunction()) {
				funcs.push_back((Function*)instr.get());
			}
		}

		return funcs;
	}

	size_t Program::getFunctionsCount() const
	{
		size_t cnt = 0;

		for (const auto& instr : instructions) {
			if (instr->isFunction()) {
				cnt++;
			}
		}

		return cnt;
	}

	void Program::checkSemantic(bool advanced) const
	{
		// Check we have only functions or global variables
		for (const auto& instr : instructions) {
			if (!instr->isFunction() && !(instr->isVariable() && ((const Variable*)instr.get())->getScope() == Scope::Global)) {
				error(Error::InvalidStatement, instr.get());
			}
		}

		// Check we don't have duplicated function names
		vector<string> funcs;
		for (const auto& instr : instructions) {
			if (instr->isFunction()) {
				const string& name(((Function*)instr.get())->getName());
				if (find(funcs.begin(), funcs.end(), name) != funcs.end()) {
					error(Error::DuplicatedSymbolName, instr.get());
				}
				funcs.push_back(name);
			}
		}

		// Base block check
		Block::checkSemantic(advanced);

		// Check the program has a main function
		if (!getMain()) {
			error(Error::NoMain, this);
		}
	}

	void Program::toTextualRepresentation(ostream& out, size_t i) const
	{
		cout << "Program {" << endl;

		for (const auto& instr : instructions) {
			instr->toTextualRepresentation(out, i + 1);
		}

		out << '}' << endl;
	}
}

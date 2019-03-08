#pragma once

#include <vector>

using namespace std;

namespace ast
{
	class Variable;
	class Instruction;

	class Block
	{
	private:
		vector<Variable*> variables;
		vector<Instruction*> instructions;
	};
}

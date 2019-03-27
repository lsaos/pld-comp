#pragma once

#include "function.hpp"
#include "block.hpp"

namespace ast
{

	class Program : public Block
	{

		public:
			Program();

			Function* getFunction(const string& name);

			Function* getMain();

			vector<Function*> getFunctions();

			size_t getFunctionsCount();

			virtual bool checkSemantic();

			virtual void toTextualRepresentation(ostream& out, size_t i = 0);

			virtual void add(Instruction* instr);

			virtual bool isProgram() const;
	};
}

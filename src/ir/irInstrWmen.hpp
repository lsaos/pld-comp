#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrWmen : public IRInstr {

		public:
			//Constructor
			IRInstrWmen(BasicBlock* bb, string addr, string var, string offset);

			/** Actual code generation */
			void gen_asm(ostream &o);
			void printIR(ostream &o);

		protected:
			//Name of the entry of the variable (in the Symbol table) in which var will be written
			string addr;

			//Name of the variable to write
			string var;

			//Offset of the variable in which var will be written in memory (based on addr)
			string offset;
	};
}

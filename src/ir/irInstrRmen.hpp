#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrRmen : public IRInstr {

		public:
			//Constructor
			IRInstrRmen(BasicBlock* bb, string addr, string dest, string offset);

			/** Actual code generation */
			void gen_asm(ostream &o);
			void printIR(ostream &o);

		protected:
			//Name of the entry of the variable to read (in the symbol table)
			string addr;

			//Name of the destination variable
			string dest;

			//Offset of the variable to read (based on addr)
			string offset;
	};
}

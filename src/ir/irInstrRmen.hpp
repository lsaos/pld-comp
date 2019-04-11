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
			string addr;
			string dest;
			string offset;
	};
}

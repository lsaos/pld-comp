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
			string addr;
			string var;
			string offset;
	};
}

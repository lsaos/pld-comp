#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrCopy : public IRInstr {

		public:
			/**  constructor */
			IRInstrCopy(BasicBlock* bb, string dest, string op1);

			/** Actual code generation */
			void gen_asm(ostream &o);
			void gen_asm_MSP430(ostream &o);

			void printIR(ostream &o);

		protected:
			string dest;
			string op1;
	};
}

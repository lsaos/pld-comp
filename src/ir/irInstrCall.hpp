#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrCall : public IRInstr {

		public:
			//Constructor
			IRInstrCall(BasicBlock* bb, string dest, string label, vector <string> op, bool isExternal = false);

			/** Actual code generation */
			//x86 assembly code generation
			void gen_asm(ostream &o);
			//Print IR instructions using IR mnemonics
			void printIR(ostream &o);

		protected:
			string dest;
			string label;
			vector <string> op;
			bool isExternal;
	};
}

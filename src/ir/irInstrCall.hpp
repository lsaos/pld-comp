#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrCall : public IRInstr {

		public:
			/**  constructor */
			IRInstrCall(BasicBlock* bb, string dest, string label, vector <string> op, bool isExternal = false);

			/** Actual code generation */
			void gen_asm(ostream &o);

			void printIR(ostream &o);

		protected:
			string dest;
			string label;
			vector <string> op;
			bool isExternal;
	};
}

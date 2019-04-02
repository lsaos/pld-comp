#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrCall : public virtual IRInstr {

		public:
			/**  constructor */
			IRInstrCall(BasicBlock* bb, string dest, string label, vector <string> op);

			/** Actual code generation */
			void gen_asm(ostream &o);

		protected:
			string dest;
			string label;
			vector <string> op;
	};
}
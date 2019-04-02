#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrLdconst : public virtual IRInstr {

	public:

		/**  constructor */
		//IRInstr(BasicBlock*, Type t);
		IRInstrLdconst(BasicBlock*, string dest, string op);

		/** Actual code generation */
		void gen_asm(ostream &o); /**< x86 assembly code generation for this IR instruction */

	protected:
		string destination;
		string operand;
	};
}
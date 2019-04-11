#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrLdconst : public IRInstr {

	public:

		/**  constructor */
		//IRInstr(BasicBlock*, Type t);
		IRInstrLdconst(BasicBlock*, Type t, string dest, string cst);

		/** Actual code generation */
		void gen_asm(ostream &o); /**< x86 assembly code generation for this IR instruction */
		void gen_asm_MSP430(ostream &o); /**< MSP430 assembly code generation for this IR instruction */

		void printIR(ostream &o);

		virtual void optimize(vector<IRInstr*>&, int);

		virtual bool isLdconstMnem() { return true; }

	protected:
		string destination;
		string constant;
	};
}
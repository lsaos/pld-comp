//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrLdconst : public IRInstr {

	public:

		//Constructor
		IRInstrLdconst(BasicBlock*, Type t, string dest, string cst);

		/** Actual code generation */
		//x86 assembly code generation for this IR instruction
		void gen_asm(ostream &o);
		//MSP430 assembly code generation for this IR instruction
		void gen_asm_MSP430(ostream &o);
		//Print IR instructions using IR mnemonics
		void printIR(ostream &o);

		virtual void optimize(vector<IRInstr*>&, int);

		//Returns true is putting a constant value in destination register
		virtual bool isLdconstMnem() { return true; }

	protected:
		string destination; //destination register
		string constant; //constant to copy
	};
}
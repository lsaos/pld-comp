#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrCopy : public IRInstr {

		public:
			//Constructor
			IRInstrCopy(BasicBlock* bb, string dest, string op1);

			/** Actual code generation */
			//x86 assembly code generation for this IR instruction
			void gen_asm(ostream &o);
			//MSP430 assembly code generation for this IR instruction
			void gen_asm_MSP430(ostream &o);
			//Print IR instructions using IR mnemonics
			void printIR(ostream &o);

			//Returns true if memory copy instruction
			virtual bool isCopyMnem() { return true; }

			string get_dest();
			string get_op();

		protected:
			string dest; //destination of the copying instruction
			string op1; //register containing the data to copy
	};
}

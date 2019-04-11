#pragma once

#include <ostream>
#include <vector>
#include "../ast/type.hpp"

using namespace std;
using namespace ast;

namespace ir {
	class BasicBlock;

	class IRInstr {

	public:
		//Constructor
		IRInstr(BasicBlock* bb, Type t) : bb(bb), t(t) {}

		/** Actual code generation */
		//x86 assembly code generation for this IR instruction
		virtual void gen_asm(ostream &o) = 0;
		//MSP430 assembly code generation for this IR instruction
		virtual void gen_asm_MSP430(ostream &o) {}
		//Print IR instructions using IR mnemonics
		virtual void printIR(ostream &o) {}

		//Optimisation of IR instruction
		virtual void optimize(vector<IRInstr*>& instrs, int) {}

		//Return true if IR instruction is an ldconst
		virtual bool isLdconstMnem() { return false; }
		//Return true if IR instruction is an ldconst
		virtual bool isCopyMnem() { return false; }

		protected:
			BasicBlock* bb; //The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to
			Type t; //return type of the instruction
	};
}

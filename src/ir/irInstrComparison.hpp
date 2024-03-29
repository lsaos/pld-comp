#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrComparison : public IRInstr {

	public:
		//Comparison operations available in this compiler
		typedef enum {
			cmp_eq,
			cmp_neq,
			cmp_lt,
			cmp_le,
			cmp_gt,
			cmp_ge
		} Operation;

		//Constructor
		IRInstrComparison(BasicBlock*, Operation op, string dest, string op1, string op2);

		/** Actual code generation */
		//x86 assembly code generation for this IR instruction
		void gen_asm(ostream &o);
		//Print IR instructions using IR mnemonics
		void printIR(ostream &o);

	protected:
		string destination;
		string operand1;
		string operand2;
		Operation operation;

	};
}
#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrComparison : public IRInstr {

	public:

		typedef enum {
			cmp_eq,
			cmp_neq,
			cmp_lt,
			cmp_le,
			cmp_gt,
			cmp_ge
		} Operation;

		/**  constructor */
		//IRInstr(BasicBlock*, Type t);
		IRInstrComparison(BasicBlock*, Operation op, string dest, string op1, string op2);

		/** Actual code generation */
		void gen_asm(ostream &o); /**< x86 assembly code generation for this IR instruction */

		void printIR(ostream &o);

	protected:
		string destination;
		string operand1;
		string operand2;
		Operation operation;

	};
}
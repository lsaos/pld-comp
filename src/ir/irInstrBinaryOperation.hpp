#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrBinaryOperation : public IRInstr {

	public:

		typedef enum {
			add,
			sub,
			mul,
			bitwiseAnd,
			bitwiseOr,
			bitwiseXor
		} Operation;

		/**  constructor */
		//IRInstr(BasicBlock*, Type t);
		IRInstrBinaryOperation(BasicBlock*,Operation op, string dest, string op1, string op2);

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
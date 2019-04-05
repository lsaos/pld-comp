#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrUnaryOperation : public IRInstr {

	public:

		typedef enum {
			minus,
			logicalNot
		} UnaryOperation;

		/**  constructor */
		//IRInstr(BasicBlock*, Type t);
		IRInstrUnaryOperation(BasicBlock*, UnaryOperation op, string dest, string operand);

		/** Actual code generation */
		void gen_asm(ostream &o); /**< x86 assembly code generation for this IR instruction */

		void printIR(ostream &o);

	protected:
		string destination;
		string operand;
		UnaryOperation operation;

	};
}
#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrUnaryOperation : public IRInstr {

	public:
		//Unary operations available in this compiler
		typedef enum {
			minus,
			logicalNot
		} UnaryOperation;

		//Constructor
		IRInstrUnaryOperation(BasicBlock*, UnaryOperation op, string dest, string operand);

		/** Actual code generation */
		void gen_asm(ostream &o);
		void printIR(ostream &o);

	protected:
		string destination;
		string operand;
		UnaryOperation operation;

	};
}
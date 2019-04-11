#pragma once

#include "irInstr.hpp"

using namespace std;
using namespace ast;

namespace ir {

	class IRInstrBinaryOperation : public IRInstr {

	public:

		//Binary operator taken into account in this compiler
		typedef enum {
			add,
			sub,
			mul,
			bitwiseAnd,
			bitwiseOr,
			bitwiseXor
		} Operation;

		//Constructor
		IRInstrBinaryOperation(BasicBlock*,Operation op, string dest, string op1, string op2);

		//x86 assembly code generation for this IR instruction
		void gen_asm(ostream &o);
		//MSP430 assembly code generation for this IR instruction
		void gen_asm_MSP430(ostream &o);
		//Print IR instructions using IR mnemonics
		void printIR(ostream &o);

	protected:
		string destination; //destination register
		string operand1; //first/left operand 
		string operand2; //second/right operand
		Operation operation; //operation to occure
	};
}
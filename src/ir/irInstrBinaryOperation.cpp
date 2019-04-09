#pragma once

#include "irInstrBinaryOperation.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ir;
using namespace ast;

IRInstrBinaryOperation::IRInstrBinaryOperation(BasicBlock* bb, Operation op, string dest, string op1, string op2) :
	IRInstr(bb, bb->get_cfg()->get_var_type(dest)), operation(op), operand1(op1), operand2(op2), destination(dest)
{}

void IRInstrBinaryOperation::gen_asm(ostream &o)
{
	// check the variable type
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];
	string action = "add";

	switch (operation)
	{
		case Operation::add:
			action = "add";
			break;
		case Operation::sub:
			action = "sub";
			break;
		case Operation::mul:
			action = "imul";
			break;
		case Operation::bitwiseAnd:
			action = "and";
			break;
		case Operation::bitwiseOr:
			action = "or";
			break;
		case Operation::bitwiseXor:
			action = "xor";
			break;
	}

	//Assembler's code generation 
	o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(operand1) << ", " << workingReg << endl;
	o << "\t" << action << type << " " << bb->get_cfg()->IR_reg_to_asm(operand2) << ", " << workingReg << endl;
	o << "\tmov" << type << " " << workingReg << ", " << bb->get_cfg()->IR_reg_to_asm(destination) << endl;
}

void IRInstrBinaryOperation::printIR(ostream &o)
{
	string mnemonic = "add";
	switch (operation)
	{
	case Operation::add:
		mnemonic = "add";
		break;
	case Operation::sub:
		mnemonic = "sub";
		break;
	case Operation::mul:
		mnemonic = "mul";
		break;
	}

	o << "\t" << mnemonic << " " << destination << " " << operand1 << " " << operand2 << endl;
}

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
	string type = "l";
	string action = "add";

	switch (t) {
		case Type::Integer:
			type = "l";
			break;
		case Type::Character:
			type = "b";
			break;
	}

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
	}

	//Assembler's code generation 
	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(operand1) << "(%rbp), %eax" << endl;
	o << "\t" << action << type << " " << bb->get_cfg()->get_var_index(operand2) << "(%rbp), %eax" << endl;
	o << "\tmov" << type << " %eax, " << bb->get_cfg()->get_var_index(destination) << "(%rbp)" << endl;
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

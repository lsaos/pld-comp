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
	//Get the variable type
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];
	string action;

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
		default:
			action = "";
			return;
	}

	//Assembly code generation 
	o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(operand1) << ", " << workingReg << endl;
	o << "\t" << action << type << " " << bb->get_cfg()->IR_reg_to_asm(operand2) << ", " << workingReg << endl;
	o << "\tmov" << type << " " << workingReg << ", " << bb->get_cfg()->IR_reg_to_asm(destination) << endl;
}

void IRInstrBinaryOperation::gen_asm_MSP430(ostream &o)
{
	//Check the variable type
	string type = (t == Type::Integer) ? "W" : "B";
	string workingReg = "R12";
	string action = "ADD.";

	switch (operation)
	{
	case Operation::add:
		action = "ADD.";
		break;
	case Operation::sub:
		action = "SUB.";
		break;
	case Operation::bitwiseAnd:
		action = "AND.";
		break;
	case Operation::bitwiseOr:
		action = "BIS.";
		break;
	case Operation::bitwiseXor:
		action = "XOR.";
		break;
	}

	//Assembly code generation 
	if (operation==Operation::mul)
	{
		cout << "Assembly error : MSP430 does not manage multiplication" << endl;
	}
	else
	{
		o << "\tMOV." << type << " " << bb->get_cfg()->get_var_index(operand1) << "(R4), " << workingReg << endl;
		o << "\t" << action << type << " " << bb->get_cfg()->get_var_index(operand2) << "(R4), " << workingReg << endl;
		o << "\tMOV." << type << " " << workingReg << ", " << bb->get_cfg()->get_var_index(destination) << "(R4)" << endl;
	}
	
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

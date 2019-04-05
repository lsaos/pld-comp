#pragma once

#include "irInstrUnaryOperation.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ir;
using namespace ast;

IRInstrUnaryOperation::IRInstrUnaryOperation(BasicBlock* bb, UnaryOperation op, string dest, string operand) :
	IRInstr(bb, bb->get_cfg()->get_var_type(dest)), operation(op), operand(operand), destination(dest)
{}

void IRInstrUnaryOperation::gen_asm(ostream& o)
{
	string op;
	switch (operation)
	{
		case UnaryOperation::minus:
			op = "\tneg";
			break;
		case UnaryOperation::logicalNot:
			//TODO
			break;
	}

	string type;
	switch (t) {
		case Type::Integer:
			type = "l";
			break;
		case Type::Character:
			type = "b";
			break;
	}

	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(operand) << "%(rbp), %eax" << endl;
	o << op << type << " %eax" << endl;
	o << "\tmov" << type << " %eax, " << bb->get_cfg()->get_var_index(destination) << "%(rbp)"<< endl;
}

void IRInstrUnaryOperation::printIR(ostream& o)
{
	string mnemonic;
	switch (operation)
	{
	case UnaryOperation::minus:
		mnemonic = "neg";
		break;
	case UnaryOperation::logicalNot:
		mnemonic = "not";
		break;
	}

	o << "\t" << mnemonic << " " << destination << " " << operand << endl;
}
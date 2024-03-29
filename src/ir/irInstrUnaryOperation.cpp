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
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];
	switch (operation)
	{
		case UnaryOperation::minus:
			op = "\tneg";
			//Assembly code for negation
			o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(operand) << ", " << workingReg << endl;
			o << op << type << " " << workingReg << endl;
			o << "\tmov" << type << " " << workingReg << ", " << bb->get_cfg()->IR_reg_to_asm(destination) << endl;
			break;
		case UnaryOperation::logicalNot:
			//TO VERIFY
			o << "\tcmpl $0, " << bb->get_cfg()->IR_reg_to_asm(operand) << endl;
			o << "\tsete %al";
			if (t==Type::Integer) {
				o << "\tmovzbl  %al, %eax" << endl;
				o << "\tmovl %eax, " << bb->get_cfg()->IR_reg_to_asm(destination) << endl;
			}
			else if (t==Type::Character) {
				o << "\tmovb %al, " << bb->get_cfg()->IR_reg_to_asm(destination) << endl;
			}
				
			break;
	}
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
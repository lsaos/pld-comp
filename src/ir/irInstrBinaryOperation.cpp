#pragma once

#include "irInstrBinaryOperation.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ir;
using namespace ast;

IRInstrBinaryOperation::IRInstrBinaryOperation(BasicBlock* bb, Operation op, string dest, string op1, string op2) :
	IRInstr(bb, bb->get_cfg()->get_var_type(destination)), operation(op), destination(dest), operand1(op1), operand2(op2)
{}

void IRInstrBinaryOperation::gen_asm(ostream &o)
{
	// check the variable type
	string type = "l";

	switch (t) {
	case Type::Integer:
		type = "l";
		break;
	case Type::Character:
		type = "b";
		break;
	}

	//Assembler's code generation 
	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(operand1) << "(%rbp), %eax" << endl;
	o << "\tadd" << type << " " << bb->get_cfg()->get_var_index(operand2) << "(%rbp), %eax" << endl;
	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(operand2) << "(%rbp), "<< bb->get_cfg()->get_var_index(destination) << "(%rbp)" << endl;
}

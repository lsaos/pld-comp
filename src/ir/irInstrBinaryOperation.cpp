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
	string type ;

	switch (t) {
		case Type::Integer:
			type = "l";
			break;
		case Type::Character:
			type = "b";
			break;
	}

	string operation;
	switch (this->operation)
	{
		case Operation::add:
			operation = "add";
			break;
		case Operation::mul:
			operation = "imul";
			break;
		case Operation::sub:
			operation = "sub";
			break;
	}

	//Assembler's code generation 
	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(operand1) << "(%rbp), %eax" << endl;
	o << "\t" << operation << type << " " << bb->get_cfg()->get_var_index(operand2) << "(%rbp), %eax" << endl;
	o << "\tmov" << type << " %eax, " << bb->get_cfg()->get_var_index(destination) << "(%rbp)" << endl;
}

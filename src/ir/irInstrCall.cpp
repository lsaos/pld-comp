#pragma once

#include "irInstrCall.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrCall::IRInstrCall(BasicBlock* bb, string dest, string label, vector <string> op, bool isExternal) : IRInstr(bb, (bb->get_cfg())->get_return_type())
{
	this->isExternal = isExternal;
	this->dest = dest;
	this->label = label;
	for (string s : op) {
		this->op.push_back(s);
	}
}

void IRInstrCall::gen_asm(ostream &o)
{
	string type;

	if (op.size() == 6) 
	{
		type = AssemblyType::operatorType[bb->get_cfg()->get_var_type(op[5])];
		type = (type == "b" ? "l" : type);
		o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(op[5]) << ", %eax" << endl;
		o << "\tmov" << type << " %eax, %r9" << endl;
	}

	if (op.size() >= 5)
	{
		type = AssemblyType::operatorType[bb->get_cfg()->get_var_type(op[4])];
		type = (type == "b" ? "l" : type);
		o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(op[4]) << ", %eax" << endl;
		o << "\tmov" << type << " %eax, %r8" << endl;
	}

	if (op.size() >= 4)
	{
		type = AssemblyType::operatorType[bb->get_cfg()->get_var_type(op[3])];
		type = (type == "b" ? "l" : type);
		o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(op[3]) << ", %eax" << endl;
		o << "\tmov" << type << " %eax, %ecx" << endl;
	}

	if (op.size() >= 3)
	{
		type = AssemblyType::operatorType[bb->get_cfg()->get_var_type(op[2])];
		type = (type == "b" ? "l" : type);
		o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(op[2]) << ", %eax" << endl;
		o << "\tmov" << type << " %eax, %edx" << endl;
	}

	if (op.size() >= 2)
	{
		type = AssemblyType::operatorType[bb->get_cfg()->get_var_type(op[1])];
		type = (type == "b" ? "l" : type);
		o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(op[1]) << ", %eax" << endl;
		o << "\tmov" << type << " %eax, %esi" << endl;
	}

	if (op.size() >= 1)
	{
		type = AssemblyType::operatorType[bb->get_cfg()->get_var_type(op[0])];
		type = (type == "b" ? "l" : type);
		o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(op[0]) << ", %eax" << endl;
		o << "\tmov" << type << " %eax, %edi" << endl;
	}

	o << "\tcall " << label;

	//In order to call an external function
	if (isExternal)
		o << "@PLT";

	o << endl;

	if ((bb->get_cfg())->get_return_type() != Type::Void)
	{
		type = AssemblyType::operatorType[(bb->get_cfg())->get_return_type()];
		string workingRegister = AssemblyType::registerType[(bb->get_cfg())->get_return_type()];
		o << "\tmov" << type << " " << workingRegister << ", " << bb->get_cfg()->IR_reg_to_asm(dest) << endl;
	}
} 


void IRInstrCall::printIR(ostream &o) 
{
	o << "\tcall " << dest << " " << label << " (";
	for (auto i : op) {
		if (i != op[0]) {
			o << ",";
		}
		o << " i";
	}
	o << " )" << endl;
}

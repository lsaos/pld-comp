#pragma once

#include "irInstrReturn.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrReturn::IRInstrReturn(BasicBlock* bb, string op) : IRInstr(bb, bb->get_cfg()->get_var_type(op)), op(op) {}

void IRInstrReturn::gen_asm(ostream &o)
{
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];

	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(op) << "(%rbp), " << workingReg << endl;
}

void IRInstrReturn::printIR(ostream &o)
{
	o << "\treturn " << op << endl;
}
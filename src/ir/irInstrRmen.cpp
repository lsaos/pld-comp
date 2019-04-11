#pragma once

#include "irInstrRmen.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrRmen::IRInstrRmen(BasicBlock* bb, string addr, string dest, string offset) : IRInstr(bb, (bb->get_cfg())->get_var_type(addr)), addr(addr), dest(dest), offset(offset) { }

void IRInstrRmen::gen_asm(ostream &o) {
	//Get the variable type
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];
	
	o << "\tmovl " << bb->get_cfg()->IR_reg_to_asm(offset) << ", %edx" << endl;
	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(addr) << "(%rbp,%rdx," << (bb->get_cfg()->get_var_type(addr) == Type::Integer ? 4 : 1) << "), " << workingReg << endl;
	o << "\tmov" << type << " " << workingReg << ", " << bb->get_cfg()->IR_reg_to_asm(dest) << endl;
}

void IRInstrRmen::printIR(ostream &o) {
	o << "\trmen " << dest << " " << addr << endl;
}


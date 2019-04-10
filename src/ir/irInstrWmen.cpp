#pragma once

#include "irInstrWmen.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrWmen::IRInstrWmen(BasicBlock* bb, string addr, string var, string offset) : IRInstr(bb, (bb->get_cfg())->get_var_type(var)), addr(addr), var(var), offset(offset) { }

void IRInstrWmen::gen_asm(ostream &o) {
	// check the variable type
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];

	//write the assembly code : the value of variable var is written at address addr
	o << "\tmovl " << bb->get_cfg()->IR_reg_to_asm(offset) << ", %edx" << endl;
	o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(var) << ", " << workingReg << endl;
	o << "\tmov" << type << " " << workingReg << ", " << bb->get_cfg()->get_var_index(addr) << "(%rbp,%rdx," << (bb->get_cfg()->get_var_type(addr) == Type::Integer?4:1) << ")" << endl;
} 

void IRInstrWmen::printIR(ostream &o) {
	o << "\twmen " << addr << " " << var << endl;
}



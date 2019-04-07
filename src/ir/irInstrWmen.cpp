#pragma once

#include "irInstrWmen.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrWmen::IRInstrWmen(BasicBlock* bb, string addr, string var) : IRInstr(bb, (bb->get_cfg())->get_var_type(var)), addr(addr), var(var) { }

void IRInstrWmen::gen_asm(ostream &o) {
	// check the variable type
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];

	//write the assembly code : the value of variable var is written at address addr
	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(addr) << "(%rbp), " << workingReg << endl; //" -" << addr.substr(4)
	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(var) << "(%rbp), %r10" << endl; // " -" << var.substr(4)
	o << "\tmov" << type << " %r10, " << workingReg << endl;

} 

void IRInstrWmen::printIR(ostream &o) {
	o << "\twmen " << addr << " " << var << endl;
}



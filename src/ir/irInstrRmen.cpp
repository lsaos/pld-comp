#pragma once

#include "irInstrRmen.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrRmen::IRInstrRmen(BasicBlock* bb, string addr, string dest) : IRInstr(bb, (bb->get_cfg())->get_var_type(addr)), addr(addr), dest(dest) { }

void IRInstrRmen::gen_asm(ostream &o) {
	// check the variable type
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];

	//write the assembly code : the content of address addr is copied in variable dest
	o << "\tmov" << type << " -" << bb->get_cfg()->IR_reg_to_asm(dest) << ", " << workingReg << endl;
	o << "\tmov" << type << " -" << bb->get_cfg()->IR_reg_to_asm(addr) << ", %r10" << endl;
	o << "\tmov" << type << " %r10, " << workingReg << endl;
}

void IRInstrRmen::printIR(ostream &o) {
	o << "\trmen " << dest << " " << addr << endl;
}


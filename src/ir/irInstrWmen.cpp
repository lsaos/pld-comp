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
	string TYPE;
	switch (t){
		case Type::Integer:
			TYPE = "l";
			break;
		case Type::Character:
			TYPE = "b";
			break;
	}

	//write the assembly code : the value of variable var is written at address addr
	o << "\tmov" << TYPE << " " << bb->get_cfg()->get_var_index(addr) << "(%rbp), %eax" << endl; //" -" << addr.substr(4)
	o << "\tmov" << TYPE << " " << bb->get_cfg()->get_var_index(var) << "(%rbp), %r10" << endl; // " -" << var.substr(4)
	o << "\tmov" << TYPE << " %r10, (%eax)" << endl;

} 

void IRInstrWmen::printIR(ostream &o) {
	o << "\twmen " << addr << " " << var << endl;
}



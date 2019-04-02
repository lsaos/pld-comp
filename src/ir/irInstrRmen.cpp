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
	string TYPE;
	switch (t){
		case Type::Integer:
			TYPE = "l";
			break;
		case Type::Character:
			TYPE = "b";
			break;
	}

	//write the assembly code : the content of address addr is copied in variable dest
	o << "\tmov" << TYPE << " -" << dest.substr(4) << "(%rbp), %eax" << endl;
	o << "\tmov" << TYPE << " -" << addr.substr(4) << "(%rbd), %r10" << endl;
	o << "\tmov" << TYPE << " %r10, (%eax)" << endl;
}

void IRInstrRmen::printIR(ostream &o) {
	o << "\trmen " << dest << " " << addr << endl;
}


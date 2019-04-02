#pragma once

#include "irInstrCall.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrCopy::IRInstrCopy(BasicBlock* bb, string dest, string op1) : IRInstr(bb, (bb->get_cfg())->get_var_type(op1)), dest(dest), op1(op1) { }

void IRInstrCopy::gen_asm(ostream &o) {
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

	//write the assembly code : copy op1 to dest
	o << "\tmov" << TYPE << " -" << op1.substr(4) << "(%rbp), " << (bb->get_cfg())->get_var_index(dest) << "(%rbp)" << endl;
} // TODO

copy a !tmp64

movq -64(%rbp), %rax
movq %rax, -16(%rbp)

void IRInstrCopy::printIR(ostream &o) {
	o << "\tcopy " << dest << " " << op1 << endl;
}


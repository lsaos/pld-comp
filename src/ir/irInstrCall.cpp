#pragma once

#include "irInstrCall.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrCall::IRInstrCall(BasicBlock* bb, string dest, string label, vector <string> op) : IRInstr(bb, (bb->get_cfg())->get_var_type(dest)) { 
	this->dest = dest;
	this->label = label;
	for (string s : op) {
		op.push_back(s);
	}
}

void IRInstrCall::gen_asm(ostream &o) {} // TODO

/*f(2,3);
movl $3, %esi
movl $2, %edi
call f(int, int)*/



void IRInstrCall::printIR(ostream &o) {
	o << "\tcall " << dest << " " << label << " (";
	for (auto i : op) {
		if (i != op[0]) {
			o << ",";
		}
		o << " i";
	}
	o << " )" << endl;
}

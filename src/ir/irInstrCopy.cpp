#pragma once

#include "irInstrCopy.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrCopy::IRInstrCopy(BasicBlock* bb, string dest, string op1) : IRInstr(bb, (bb->get_cfg())->get_var_type(op1)), dest(dest), op1(op1) { }

void IRInstrCopy::gen_asm(ostream &o) {
	// check the variable type
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];

	//write the assembly code : copy op1 to dest
	
	o << "\tmov" << type << " " << bb->get_cfg()->get_var_index(op1) << "(%rbp), " << workingReg << endl;
	o << "\tmov" << type << " " << workingReg << ", " << (bb->get_cfg())->get_var_index(dest) << "(%rbp)" << endl;
} 

void IRInstrCopy::printIR(ostream &o) {
	o << "\tcopy " << dest << " " << op1 << endl;
}
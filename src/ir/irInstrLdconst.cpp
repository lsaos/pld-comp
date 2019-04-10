#pragma once

#include "irInstrLdconst.hpp"
#include <string>
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ir;
using namespace ast;

IRInstrLdconst::IRInstrLdconst(BasicBlock* bb, Type t, string dest, string cst) : IRInstr(bb, t), destination(dest), constant(cst)
{}

void IRInstrLdconst::gen_asm(ostream &o)
{
	string type = AssemblyType::operatorType[t];

	o << "\tmov" << type << " $" << constant << ", " << bb->get_cfg()->IR_reg_to_asm(destination) << endl;
}

void IRInstrLdconst::gen_asm_MSP430(ostream &o)
{
	string type = (t == Type::Integer) ? "W" : "B";
	o << "\tMOV." << type << " #" << constant <<", " << bb->get_cfg()->get_var_index(destination) << "(R4)" << endl;
}

void IRInstrLdconst::printIR(ostream &o)
{
	o << "\tldconst " << destination << " " << constant << endl;
}


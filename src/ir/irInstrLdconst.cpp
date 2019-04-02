#pragma once

#include "irInstrLdconst.hpp"

using namespace std;
using namespace ir;
using namespace ast;

IRInstrLdconst::IRInstrLdconst(BasicBlock* bb, string dest, string op) : IRInstr(bb), destination(dest), operand(op)
{}

void IRInstrLdconst::gen_asm(ostream &o)
{
	//TODO
}


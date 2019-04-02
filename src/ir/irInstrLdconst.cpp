#pragma once

#include "irInstrLdconst.hpp"
#include <string>

using namespace std;
using namespace ir;
using namespace ast;

IRInstrLdconst::IRInstrLdconst(BasicBlock* bb, Type t, string dest, string cst) : IRInstr(bb, t), destination(dest), constant(cst)
{}

void IRInstrLdconst::gen_asm(ostream &o)
{
	string type;
	switch (this->t) {
		case (Type::Integer) :
			type = "l";
			break;
		case(Type::Character):
			type = "b";
			break;
	}
	o << "\tmov" << type << " $, -" << destination.substr(4) << "(%rbp)" << endl;
}


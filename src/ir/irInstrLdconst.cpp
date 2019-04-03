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
	string type;
	switch (this->t) {
		case (Type::Integer) :
			type = "l";
			o << "\tmov" << type << " $"<< constant <<", " << bb->get_cfg()->get_var_index(destination) << "(%rbp)" << endl;
			break;
		case(Type::Character):
			type = "b";
			//A faire
			break;
	}
	//o << "\tmov" << type << " $, -" << destination.substr(4) << "(%rbp)" << endl;
}


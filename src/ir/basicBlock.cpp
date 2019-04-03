#pragma once

#include "basicBlock.hpp"
#include <string>

using namespace ir;

BasicBlock::BasicBlock(CFG* cfg, string entry_label) : cfg(cfg), label(entry_label) {}

BasicBlock::~BasicBlock()
{
	for (auto i : instrs)
	{
		//delete i;
	}
}

void BasicBlock::add_IRInstr(IRInstr* instr, Type t)
{
	instrs.push_back(instr);
}

string BasicBlock::get_label()
{
	return label;
}

void BasicBlock::gen_asm(ostream& o)
{
	//o << endl << label << " :" << endl;

	for (auto i : instrs)
	{
		i->gen_asm(o);
	}
}


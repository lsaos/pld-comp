#pragma once

#include "basicBlock.hpp"

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


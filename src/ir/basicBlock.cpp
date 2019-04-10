#pragma once

#include "basicBlock.hpp"
#include "cfg.hpp"
#include <string>

using namespace ir;

BasicBlock::BasicBlock(CFG* cfg, string entry_label) : cfg(cfg), label(entry_label) 
{
	exit_false = nullptr;
	exit_true = nullptr;
}

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

void BasicBlock::set_last_var(string var)
{
	lastVar = var;
}

void BasicBlock::gen_asm(ostream& o)
{
	//o << endl << label << " :" << endl;

	for (auto i : instrs)
	{
		i->gen_asm(o);
	}

	//Ajouter les jumps ici

	if (exit_true == nullptr)
	{
		cfg->gen_asm_epilogue(o);
	}
	else {
		if (exit_false == nullptr)
			o << "\tjmp " << exit_true->get_label() << endl;
		else
		{
			o << "\tcmpl $0, " << cfg->get_var_index(lastVar) << "(%rbp)" << endl;
			o << "\tje " << exit_false->get_label() << endl;
			o << "\tjne " << exit_true->get_label() << endl;
		}
	}
}

void BasicBlock::gen_asm_MSP430(ostream& o)
{
	for (auto i : instrs)
	{
		i->gen_asm_MSP430(o);
	}
	//No jump for MSP430 as only simple linear codes are managed in this compiler
}

void BasicBlock::printIR()
{
	for (auto i : instrs)
	{
		i->printIR(cout);
	}
}


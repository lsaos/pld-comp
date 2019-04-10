#pragma once

#include "ir.hpp"
#include "cfg.hpp"
#include "basicBlock.hpp"
#include "../ast/variable.hpp"

using namespace ir;
using namespace ast;

void IR::addCFG(CFG *cfg)
{
	this->cfgs.insert(make_pair(cfg->getFunction(), cfg));
}

void IR::generateIR()
{
	vector<Function*> functions = prog->getFunctions();
	int context = 1;
	
	for (auto f : functions) 
	{
		CFG* cfg = new CFG(f);
		addCFG(cfg);
		cfg->current_context = context;
		cfg->generateCFG();
		context = cfg->current_context;
	}
}

void IR::generateAssembly(string out)
{
	file = ofstream(out.substr(0, out.size() - 1) + "s", ios::out);

	file << ".text" << endl << ".global main" << endl << ".type main, @function" << endl;

	for (auto var : prog->getVariables(true))
	{
		int i = (var->getType() == Type::Character ? 1 : 4);
		int size = (var->isArray() ? var->getArraySize() : 1);
		file << ".comm " << var->getName() << "," << (i*size) << "," << i << endl;
	}

	for (auto cfg : cfgs)
	{
		cfg.second->gen_asm(file);
	}
}

void IR::generateAssemblyMSP430(string out)
{
	file = ofstream(out.substr(0, out.size() - 2) + "_MSP430.s", ios::out);

	for (auto cfg : cfgs)
	{
		cfg.second->gen_asm_MSP430(file);
	}
}

void IR::printIR()
{
	for (auto f : cfgs)
	{
		f.second->printIR();
	}
}
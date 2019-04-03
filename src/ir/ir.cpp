#pragma once

#include "ir.hpp"

using namespace ir;
using namespace ast;

void IR::addCFG(CFG *cfg)
{
	this->cfgs.insert(make_pair(cfg->getFunction(), cfg));
}

void IR::generateIR()
{
	vector<Function*> functions = prog->getFunctions();
	
	for (auto f : functions) 
	{
		CFG* cfg = new CFG(f);
		addCFG(cfg);
		cfg->generateCFG();
	}
}

void IR::generateAssembly(string out)
{
	file = ofstream(out.substr(0, out.size() - 1) + "s", ios::out);

	file << ".text" << endl << ".global main" << endl;

	for (auto cfg : cfgs)
	{
		cfg.second->gen_asm(file);
	}
}
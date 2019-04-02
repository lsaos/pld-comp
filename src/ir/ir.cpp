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
	}
}
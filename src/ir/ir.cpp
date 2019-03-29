#pragma once

#include "ir.hpp"

using namespace ir;
using namespace ast;

void IR::addCFG(CFG *cfg)
{
	this->cfgs.insert(make_pair(cfg->getFunction(), cfg));
}


#pragma once

#include "cfg.hpp"
#include "../ast/variable.hpp"

using namespace std;
using namespace ir;
using namespace ast;

CFG::CFG(Function* function) : function(function), nextFreeSymbolIndex(0), nextBBnumber(0) 
{
	vector<Variable*> params = function->getParameters();

	for (auto i : params)
	{
		add_to_symbol_table(i);
	}

	vector<Variable*> vars = function->getVariables(false);

	for (auto var : vars)
	{
		add_to_symbol_table(var);
	}

	BasicBlock* bb = new BasicBlock(this, function->getName()+"_bb_"+to_string(nextBBnumber));
	bbs.push_back(bb);
	nextBBnumber++;

	//Maintenant, on parcours les instructions (pour créer les IRInstr) dans le CFG ou dans le BasicBloc ? Plus facile (vision globale de la fonction) dans le CFG, mais correct ?
}

void CFG::add_bb(BasicBlock* bb)
{
	bbs.push_back(bb);
}

Function* CFG::getFunction() 
{
	return function;
}

void CFG::add_to_symbol_table(Variable * var)
{
	switch (var->getType())
	{
	case Type::Character:
		nextFreeSymbolIndex -= 1;
		break;
	case Type::Integer:
		nextFreeSymbolIndex -= 4;
		break;
	}

	this->SymbolType[var] = var->getType();
	this->SymbolIndex[var] = nextFreeSymbolIndex;
}
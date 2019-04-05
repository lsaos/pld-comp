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
		add_to_symbol_table(i->getName(), i->getType());
	}

	vector<Variable*> vars = function->getVariables(false);

	for (auto var : vars)
	{
		add_to_symbol_table(var->getName(), var->getType());
	}

}

CFG::~CFG()
{
	for (auto bb : bbs) {
		delete bb;
	}
}

void CFG::generateCFG()
{
	current_bb = new BasicBlock(this, function->getName());
	bbs.push_back(current_bb);
	nextBBnumber++;

	vector<Instruction*> instructions = function->getInstructions();

	for (auto i : instructions)
	{
		i->buildIR(this);
	}
}

string CFG::new_BB_name()
{
	return function->getName() + "_bb_" + to_string(nextBBnumber);
}

void CFG::add_bb(BasicBlock* bb)
{
	bbs.push_back(bb);
}

Function* CFG::getFunction() 
{
	return function;
}

void CFG::add_to_symbol_table(string var, Type t)
{
	switch (t)
	{
	case Type::Character:
		nextFreeSymbolIndex -= 1;
		break;
	case Type::Integer:
		nextFreeSymbolIndex -= 4;
		break;
	}

	this->SymbolType[var] = t;
	this->SymbolIndex[var] = nextFreeSymbolIndex;
}

string CFG::create_new_tempvar(Type t)
{
	int nb;

	switch (t)
	{
	case Type::Character:
		nb = -nextFreeSymbolIndex + 1;
		break;
	case Type::Integer:
		nb = -nextFreeSymbolIndex + 4;
		break;
	}

	string name = "!tmp" + to_string(nb);
	add_to_symbol_table(name, t);
	return name;
}

int CFG::get_var_index(string var)
{
	return SymbolIndex[var];
}

Type CFG::get_var_type(string var)
{
	return SymbolType[var];
}

//A Revoir
string CFG::IR_reg_to_asm(string reg)
{
	int index = SymbolIndex[reg];
	return (to_string(index) + "(%rbp)");
}

void CFG::gen_asm(ostream& o)
{
	bool prologue = true;

	for (auto bb : bbs)
	{
		o << endl << bb->get_label() << ":" << endl;

		if (prologue)
		{
			gen_asm_prologue(o);
			prologue = false;
		}

		bb->gen_asm(o);
	}

	//gen_asm_epilogue(o);
}

void CFG::gen_asm_prologue(ostream& o)
{
	o << "\tpushq %rbp" << endl << "\tmovq %rsp, %rbp" << endl;
	//Si paramètres dans la fonction : ajouter les instructions assembleurs pour les récupérer dans le prologue
}

void CFG::gen_asm_epilogue(ostream& o)
{
	//Créer un nouveau bloc ou pas ?
	o << "\tpopq %rbp" << endl << "\tret" << endl;
}
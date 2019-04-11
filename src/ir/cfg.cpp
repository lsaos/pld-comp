#pragma once

#include "cfg.hpp"
#include "../ast/variable.hpp"

using namespace std;
using namespace ir;
using namespace ast;

map<Type, string> AssemblyType::operatorType = { {Type::Character, "b"}, {Type::Integer, "l"} };
map<Type, string> AssemblyType::registerType = { {Type::Character, "%al"}, {Type::Integer, "%eax"} };

CFG::CFG(Function* function) : function(function), nextFreeSymbolIndex(0), nextBBnumber(0), current_context(0), functionCall(false)
{
	add_to_symbol_table("!bp", Type::Void);

	vector<Variable*> params = function->getParameters();

	for (auto i : params)
	{
		string name = i->getName() + "_" + to_string(current_context);
		variablesName[i] = name;

		if(i->isArray())
			add_to_symbol_table(name, i->getType(), i->getArraySize());
		else
			add_to_symbol_table(name, i->getType());
	}

	vector<Variable*> vars = function->getVariables(true);

	for (auto var : vars)
	{
		string name = var->getName() + "_" + to_string(current_context);
		variablesName[var] = name;
		if(var->isArray())
			add_to_symbol_table(name, var->getType(), var->getArraySize());
		else
			add_to_symbol_table(name, var->getType());
	}

	last_bb = new BasicBlock(this, function->getName()+"_last");
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

	if (get_return_type() != Type::Void)
	{
		current_bb->exit_true = last_bb;
		add_bb(last_bb);
	}
}

string CFG::new_BB_name()
{
	return function->getName() + "_bb_" + to_string(nextBBnumber++);
}

void CFG::add_bb(BasicBlock* bb)
{
	bbs.push_back(bb);
}

Function* CFG::getFunction() 
{
	return function;
}

void CFG::add_to_symbol_table(string var, Type t, int nbCases)
{
	int size = 0;

	switch (t)
	{
		case Type::Character:
			size -= 1;
			break;
		case Type::Integer:
			size -= 4;
			break;
	}

	size = size * nbCases;

	nextFreeSymbolIndex += size;

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

	string name = "!tmp" + to_string(nb)+"_"+to_string(current_context);
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

string CFG::IR_reg_to_asm(string reg)
{
	int index;
	
	if (globalVariables[reg] != "")
		return (reg + "(%rip)");
	else
	{
		index = SymbolIndex[reg];
		return (to_string(index) + "(%rbp)");
	}
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
}

void CFG::gen_asm_MSP430(ostream& o)
{
	bool prologue = true;

	for (auto bb : bbs)
	{
		if (prologue)
		{
			gen_MSP430_prologue(o);
			prologue = false;
		}

		bb->gen_asm_MSP430(o);
	}
	gen_MSP430_epilogue(o);
}

void CFG::gen_asm_prologue(ostream& o)
{
	o << "\tpushq %rbp" << endl << "\tmovq %rsp, %rbp" << endl;

	if (functionCall)
		o << "\tsubq $16, %rsp" << endl;
	
	vector<Variable*> params = function->getParameters();

	string type;
	string reg;

	for (int i=0;i<params.size();i++)
	{
		type = AssemblyType::operatorType[get_var_type(get_var_name(params[i]))];

		if (type == "b")
			type = "l";

		o << "\tmov" << type << " ";
		switch (i)
		{
			case 0:
				reg = "%edi";
				break;
			case 1:
				reg = "%esi";
				break;
			case 2:
				reg = "%edx";
				break;
			case 3:
				reg = "%ecx";
				break;
			case 4:
				reg = "%r8";
				break;
			case 5:
				reg = "%r9";
				break;
		}

		o << reg << ", " << get_var_index(get_var_name(params[i])) << "(%rbp)" << endl;
	}

}

void CFG::gen_asm_epilogue(ostream& o)
{
	o << "\tleave" << endl << "\tret" << endl;
}

void CFG::gen_MSP430_prologue(ostream& o)
{
	vector<Variable*> variables = function->getVariables(false);
	o << "main:" << endl;
	o << "\tPUSHM.W #1, R4" << endl;
	o << "\tMOV.W R1, R4" << endl;
	o << "\tSUB.W #" << 2*variables.size() << ", R1" << endl;
}

void CFG::gen_MSP430_epilogue(ostream& o)
{
	vector<Variable*> variables = function->getVariables(false);
	o << "\tADD.W #" << 2*variables.size() << ", R1" << endl;
	o << "\tPOPW.W #1, r4" << endl;
	o << "\tRET" << endl;
	
}

void CFG::printIR()
{
	for (auto bb : bbs)
	{
		bb->printIR();
	}
}

Type CFG::get_return_type()
{
	return function->getType();
}

int CFG::get_nextFreeSymbolIndex()
{
	return nextFreeSymbolIndex;
}

void CFG::set_nextFreeSymbolIndex(int n)
{
	nextFreeSymbolIndex = n;
}

void CFG::add_variable_name(Variable* var)
{
	string name = var->getName() + "_" + to_string(current_context);
	variablesName[var] = name;

	if (var->isArray())
		add_to_symbol_table(name, var->getType(), var->getArraySize());
	else
		add_to_symbol_table(name, var->getType());
}

string CFG::get_var_name(Variable* var)
{
	return variablesName[var];
}

void CFG::set_functionCall(bool b)
{
	functionCall = b;
}

void CFG::optimize()
{
	for (auto bb : bbs) 
	{
		bb->optimize();
	}
}
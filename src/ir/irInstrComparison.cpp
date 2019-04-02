#pragma once

#include "irInstrComparison.hpp"

using namespace std;
using namespace ir;
using namespace ast;

IRInstrComparison::IRInstrComparison(BasicBlock* bb, Operation op, string dest, string op1, string op2) :
	IRInstr(bb), operation(op), destination(dest), operand1(op1), operand2(op2)
{}

void IRInstrComparison::gen_asm(ostream &o)
{
	//TODO
}
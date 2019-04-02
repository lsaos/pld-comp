#pragma once

#include "irInstrBinaryOperation.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ir;
using namespace ast;

IRInstrBinaryOperation::IRInstrBinaryOperation(BasicBlock* bb, Operation op, string dest, string op1, string op2) :
	IRInstr(bb, bb->get_cfg()->get_var_type(destination)), operation(op), destination(dest), operand1(op1), operand2(op2)
{}

void IRInstrBinaryOperation::gen_asm(ostream &o)
{
	//TODO
}

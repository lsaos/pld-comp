#pragma once

#include "irInstrComparison.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ir;
using namespace ast;

IRInstrComparison::IRInstrComparison(BasicBlock* bb, IRInstrComparison::Operation op, string dest, string op1, string op2) :
	IRInstr(bb, bb->get_cfg()->get_var_type(dest)), operation(op), destination(dest), operand1(op1), operand2(op2)
{}

void IRInstrComparison::gen_asm(ostream &o)
{
	//choix opération set
	string set = "setl";
	switch (operation)
	{
	case Operation::cmp_eq:
		set = "sete";
		break;
	case Operation::cmp_neq:
		set = "setne";
		break;
	case Operation::cmp_gt:
		set = "setg";
		break;
	case Operation::cmp_ge:
		set = "setge";
		break;
	case Operation::cmp_lt:
		set = "setl";
		break;
	case Operation::cmp_le:
		set = "setle";
		break;
	}

	switch (t)
	{
	case Type::Integer:
		o << "\tmovl " << bb->get_cfg()->get_var_index(operand1) << "(%rbp), %eax" << endl;
		o << "\tcmpl " << bb->get_cfg()->get_var_index(operand2) << "(%rbp), %eax" << endl;
		o << "\t" << set << " %al" << endl;
		o << "\tmovzbl %al, %eax" << endl;
		o << "\tmovl %eax, " << bb->get_cfg()->get_var_index(destination) << "(%rbp)" << endl;
		break;
	case Type::Character:
		o << "\tmovzbl " << bb->get_cfg()->get_var_index(operand1) << "(%rbp), %eax" << endl;
		o << "\tcmpl " << bb->get_cfg()->get_var_index(operand2) << "(%rbp), %al" << endl;
		o << "\t" << set << " %al" << endl;
		o << "\tmovb %al, " << bb->get_cfg()->get_var_index(destination) << "(%rbp)" << endl;
		break;
	}
}

void IRInstrComparison::printIR(ostream &o)
{
	string mnemonic = "cmp_eq";
	switch (operation)
	{
	case Operation::cmp_eq:
		mnemonic = "cmp_eq";
		break;
	case Operation::cmp_le:
		mnemonic = "cmp_le";
		break;
	case Operation::cmp_lt:
		mnemonic = "cmp_lt";
		break;
	}

	o << "\t" << mnemonic << " " << destination << " " << operand1 << " " << operand2 << endl;
}
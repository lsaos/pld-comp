
#include "irInstrCopy.hpp"
#include "basicBlock.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrCopy::IRInstrCopy(BasicBlock* bb, string dest, string op1) : IRInstr(bb, (bb->get_cfg())->get_var_type(op1)), dest(dest), op1(op1) { }

void IRInstrCopy::gen_asm(ostream &o) 
{
	//Get the variable type
	string type = AssemblyType::operatorType[t];
	string workingReg = AssemblyType::registerType[t];

	//Write the assembly code : copy op1 to dest
	o << "\tmov" << type << " " << bb->get_cfg()->IR_reg_to_asm(op1) << ", " << workingReg << endl;
	o << "\tmov" << type << " " << workingReg << ", " << bb->get_cfg()->IR_reg_to_asm(dest) << endl;
}

void IRInstrCopy::gen_asm_MSP430(ostream &o) 
{
	//Check the variable type
	string type = (t == Type::Integer) ? "W" : "B";
	string workingReg = "R12";

	//Write the assembly code : copy op1 to dest
	o << "\tMOV." << type << " " << bb->get_cfg()->get_var_index(op1) << "(R4), " << workingReg << endl;
	o << "\tMOV." << type << " " << workingReg << ", " << bb->get_cfg()->get_var_index(dest) << "(R4)" << endl;
}

void IRInstrCopy::printIR(ostream &o) 
{
	o << "\tcopy " << dest << " " << op1 << endl;
}

string IRInstrCopy::get_dest()
{
	return dest;
}

string IRInstrCopy::get_op()
{
	return op1;
}
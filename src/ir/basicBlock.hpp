//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//
#pragma once

using namespace std;

#include "irInstr.hpp"

/**  The class for a basic block */

namespace ir {

	class CFG;

	class BasicBlock {
	public:
		//Constructor of BasicBlock
		BasicBlock(CFG* cfg, string entry_label);

		//Delete all the IRInstr of the BB
		~BasicBlock();

		//x86 assembly code generation for this basic block
		void gen_asm(ostream &o);
		//MSP430 assembly code generation for this basic block
		void gen_asm_MSP430(ostream &o);

		//Print instructions using IR mnemonics
		void printIR();

		//Add an IR Instruction to the list of the current BB's instructions
		void add_IRInstr(IRInstr* instr, Type t);

		//Optimize the generate IR
		void optimize();

		//Set the last var to be used in the current BB
		void set_last_var(string);

		//Returns the CFG containing the current BB
		CFG* get_cfg() { return cfg; }

		//Returns the label of the current BB
		string get_label();

		//Pointer to the next basic block, true branch. If nullptr, return from procedure
		BasicBlock* exit_true; 

		//Pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump
		BasicBlock* exit_false;
		
	protected:
		//label of the BB, also will be the label in the generated code
		string label;
		
		//the CFG where this block belongs
		CFG* cfg; 

		//the instructions themselves
		vector<IRInstr*> instrs; 

		//The last variable's label to be used in this BB
		string lastVar;
	};
}
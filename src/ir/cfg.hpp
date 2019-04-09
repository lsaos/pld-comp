#pragma once

#include <map>

using namespace std;

#include "../ast/function.hpp"
#include "basicBlock.hpp"

/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
	 (again it could be identified in a more explicit way)

 */
namespace ir {

	class AssemblyType {
		public:
			static map<Type, string> operatorType;
			static map<Type, string> registerType;
	};

	class CFG {
		public:
			CFG(ast::Function* function);

			~CFG();

			void generateCFG();

			void printIR();

			ast::Function* getFunction();

			void add_bb(BasicBlock* bb);

			// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
			void gen_asm(ostream& o);
			string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
			void gen_asm_prologue(ostream& o);
			void gen_asm_epilogue(ostream& o);
			void gen_MSP430_prologue(ostream& o);
			void gen_MSP430_epilogue(ostream& o);

			// symbol table methods
			void add_to_symbol_table(string var, Type t);
			string create_new_tempvar(Type t);
			int get_var_index(string var);
			Type get_var_type(string var);
			Type get_return_type();

			// basic block management
			string new_BB_name();

			//Pointer on the current BB
			BasicBlock* current_bb; //?? public ??
			BasicBlock* last_bb;

		/*protected :
			//Return true if the BB end is reached
			bool isBBEnd(Instruction* i);*/

		protected:
			Function* function; /**< The AST this CFG comes from */
			map <string, ast::Type> SymbolType; /**< part of the symbol table  */
			map <string, int> SymbolIndex; /**< part of the symbol table  */
			map<string, string> globalVariables; /**List of the global variables of the function*/
			int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
			int nextBBnumber; /**< just for naming */

			vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/
	};
}

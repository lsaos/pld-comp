#pragma once

#include <map>

using namespace std;
using namespace ast;

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
	class CFG {
		public:
			CFG(Function* function) : function(function), nextFreeSymbolIndex(0), nextBBnumber(0) {}

			//void generateCFG();

			Function* getFunction();

			void add_bb(BasicBlock* bb);

			// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
			void gen_asm(ostream& o);
			string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
			void gen_asm_prologue(ostream& o);
			void gen_asm_epilogue(ostream& o);

			// symbol table methods
			void add_to_symbol_table(string var, Type t);
			string create_new_tempvar(Type t); //?? A quoi sert cette m�thode ??
			int get_var_index(string var);
			Type get_var_type(string var);

			// basic block management
			string new_BB_name();
			BasicBlock* current_bb;

		protected:
			Function* function; /**< The AST this CFG comes from */
			map <string, Type> SymbolType; /**< part of the symbol table  */
			map <string, int> SymbolIndex; /**< part of the symbol table  */
			int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
			int nextBBnumber; /**< just for naming */

			vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/
	};
}
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
			//Constructor and destructor
			CFG(ast::Function* function);
			~CFG();

			void generateCFG();

			void optimize();

			//Print instructions using IR mnemonics
			void printIR();

			ast::Function* getFunction();

			void add_bb(BasicBlock* bb);

			// x86 code generation
			void gen_asm(ostream& o);
			// MSP430 code generation
			void gen_asm_MSP430(ostream& o);
			//helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24
			string IR_reg_to_asm(string reg); 
			// x86 prologue and epilogue codes generation
			void gen_asm_prologue(ostream& o);
			void gen_asm_epilogue(ostream& o);
			// MSP430 prologue and epilogue codes generation
			void gen_MSP430_prologue(ostream& o);
			void gen_MSP430_epilogue(ostream& o);

			//Symbol table methods
			void add_to_symbol_table(string var, Type t, int nbCases=1);
			void add_variable_name(Variable* var);
			string create_new_tempvar(Type t);
			int get_var_index(string var);
			Type get_var_type(string var);
			string get_var_name(Variable*);
			Type get_return_type();
			int get_nextFreeSymbolIndex();
			void set_nextFreeSymbolIndex(int);
			void set_functionCall(bool);

			//Basic block management
			string new_BB_name();

			//Pointer on the current BB
			BasicBlock* current_bb;
			BasicBlock* last_bb;

			//Number of the current block context
			int current_context;

		protected:
			Function* function; //The AST this CFG comes from
			map <string, ast::Type> SymbolType; //part of the symbol table
			map <string, int> SymbolIndex; //part of the symbol table
			map<string, string> globalVariables; //List of the global variables of the function
			map<Variable*, string> variablesName;
			int nextFreeSymbolIndex; //to allocate new symbols in the symbol table
			int nextBBnumber; //just for naming

			bool functionCall;

			vector <BasicBlock*> bbs; //all the basic blocks of this CFG
	};
}

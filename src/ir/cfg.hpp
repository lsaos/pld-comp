//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <map>

using namespace std;

#include "../ast/function.hpp"
#include "basicBlock.hpp"

/** The class for the control flow graph, also includes the symbol table */

namespace ir {

	//Link between type and assembly tools
	class AssemblyType {
		public:
			//Matching between C Types and assembly operators to use
			static map<Type, string> operatorType;

			//Matching between C Types and assembly registers to use
			static map<Type, string> registerType;
	};

	class CFG {
		public:
			//Constructor and destructor
			CFG(ast::Function* function);
			~CFG();

			//Generate the CFG
			void generateCFG();

			//Optimize the CFG
			void optimize();

			//Print instructions using IR mnemonics
			void printIR();

			//Returns the function represented by this CFG
			ast::Function* getFunction();

			//Add a BB to the current CFG
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

			//Add a symbol to the symbol table (Var = variable's name, t = variable's type, nbCases = array size if it is an array)
			void add_to_symbol_table(string var, Type t, int nbCases=1);

			//Add a variable name to the symbol table
			void add_variable_name(Variable* var);

			//Create a new temporary variable
			string create_new_tempvar(Type t);

			//Returns variable's memory index
			int get_var_index(string var);

			//Returns variable's type
			Type get_var_type(string var);

			//Returns assembly variable's name
			string get_var_name(Variable*);

			//Returns the return type of the function linked to this CFG
			Type get_return_type();

			//Returns the next Free memory Index to write a variable in memory
			int get_nextFreeSymbolIndex();

			//Set the next Free memory Index to write a variable in memory
			void set_nextFreeSymbolIndex(int);

			//Set if function(s) is(are) called in the function reprensented by this CFG
			void set_functionCall(bool);

			//Basic block management
			string new_BB_name();

			//Pointer on the current BB
			BasicBlock* current_bb;

			//Pointer to the last BB of the current CFG
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

			//True if at least one function is called in the function represented by this CFG
			bool functionCall;

			vector <BasicBlock*> bbs; //all the basic blocks of this CFG
	};
}

//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "../ast/program.hpp"
#include "cfg.hpp"

using namespace std;
using namespace ast;

namespace ir {
	class IR {
		public:
			//Constructor
			IR(Program * prog) : prog(prog) {}

			//Generate the IR
			void generateIR(bool optimize);

			//Print instructions using IR mnemonics
			void printIR();

			//Add a CFG to the current IR
			void addCFG(CFG *cfg);

			//x86 assembly code generation
			void generateAssembly(string out);
			//MSP430 assembly code generation
			void generateAssemblyMSP430(string out);

		protected:
			Program* prog; //Programme after being trated in the AST
			map<Function*, CFG *> cfgs; //Links between CFG and functions
			ofstream file; //Output file for assembly code generation
	};
}

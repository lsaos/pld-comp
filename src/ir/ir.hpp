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
			IR(Program * prog) : prog(prog) {}
			//~IR();

			void generateIR();

			void printIR();

			void addCFG(CFG *cfg);

			void generateAssembly(string out);
			void generateAssemblyMSP430(string out);
			//void optimise();

		protected:
			Program* prog;
			map<Function*, CFG *> cfgs; //?? Lien entre CFG et fonctions ? <Identifiable*, CFG*> ou <Function*, CFG *> ??
			ofstream file;
	};
}

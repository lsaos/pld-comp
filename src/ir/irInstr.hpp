#pragma once

#include <ostream>
#include <vector>
#include "../ast/type.hpp"

using namespace std;
using namespace ast;

namespace ir {
	//! The class for one 3-address instruction

	class BasicBlock;

	class IRInstr {

		public:
			/**  constructor */
			IRInstr(BasicBlock* bb, Type t) : bb(bb), t(t) {}

			/** Actual code generation */
			virtual void gen_asm(ostream &o) = 0; /**< x86 assembly code generation for this IR instruction */

			virtual void printIR(ostream &o) {}

		protected:
			BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
			Type t;
			
			/**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
			// if you subclass IRInstr, each IRInstr subclass has its parameters and the previous (very important) comment becomes useless: it would be a better design. 

			/*
				A FAIRE : créer un héritage de IRInstr en créant une classe par instruction
					=> Plus long mais meilleur design et plus efficace pour l'héritage des méthodes de génération assembleur
			*/
	};
}

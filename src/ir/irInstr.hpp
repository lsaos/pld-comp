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
			/** The instructions themselves -- feel free to subclass instead */
			/*typedef enum {
				ldconst,
				add,
				sub,
				mul,
				rmem,
				wmem,
				call,
				cmp_eq,
				cmp_lt,
				cmp_le
			} Operation;*/


			/**  constructor */
			//IRInstr(BasicBlock*, Type t);
			IRInstr(BasicBlock*);

			/** Actual code generation */
			virtual void gen_asm(ostream &o) = 0; /**< x86 assembly code generation for this IR instruction */

		private:
			BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
			//Type t;
			
			/**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
			// if you subclass IRInstr, each IRInstr subclass has its parameters and the previous (very important) comment becomes useless: it would be a better design. 

			/*
				A FAIRE : cr�er un h�ritage de IRInstr en cr�ant une classe par instruction
					=> Plus long mais meilleur design et plus efficace pour l'h�ritage des m�thodes de g�n�ration assembleur
			*/
	};
}
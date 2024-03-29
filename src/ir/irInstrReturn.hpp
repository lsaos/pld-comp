#pragma once

#include "irInstr.hpp"

namespace ir
{
	class IRInstrReturn : public IRInstr
	{
		public :
			IRInstrReturn(BasicBlock* bb, string op);
			~IRInstrReturn();

			void gen_asm(ostream &o);
			void gen_asm_MSP430(ostream &o);

			void printIR(ostream &o);
		
		protected:
			string op;
	};
}
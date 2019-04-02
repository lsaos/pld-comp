//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "controlStructure.hpp"

namespace ast
{
	// Represents a loop control structure.
	class While : public ControlStructure
	{
	public:
		// Create a while.
		While(const ItemPosition& position);

	public:
		virtual string getStringRepresentation() const { return "while"; }
		virtual bool isWhile() const { return true; }
		virtual string buildIR(ir::CFG*) {}
	};
}

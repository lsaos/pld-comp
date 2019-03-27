//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "instruction.hpp"
#include "type.hpp"

namespace ast
{
	// Represents an instruction which always returns a value.
	class Expression : public Instruction
	{
	public:
		// Create an expression.
		Expression(const ItemPosition& position);

	public:
		// Get the type of the value returned.
		virtual Type getType() const = 0;

		// Precompute the value if the expression, if possible.
		virtual int getValue() const;

		// Return true if the value of the expression can be precomputed.
		virtual bool isConstant() const {
			return false;
		}

	public:
		virtual bool isExpression() const { return true; }

	public:
		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) = 0;
	};
}

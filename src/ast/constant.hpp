//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "expression.hpp"
#include "type.hpp"

namespace ast
{
	// Represents a constant value.
	class Constant : public Expression
	{
	public:
		// Create a constant.
		Constant(const ItemPosition& position);

	public:
		// Set the value of the constant.
		void setValue(int val);

		// Set the type of the constant.
		void setType(Type t);

	public:
		// Get the type of the constant.
		virtual Type getType() const {
			return type;
		}

		// Get the value of the constant.
		virtual int getValue() const {
			return value;
		}

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual string getStringRepresentation() const;

	public:
		virtual bool isConstant() const { return true; }

	private:
		Type type; // Type of the constant.
		int value; // Value of the constant.

	public:
		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}
	};
}

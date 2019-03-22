#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "instruction.hpp"
#include "identifiable.hpp"

namespace ast
{
	enum class Scope
	{
		Global,
		Parameter,
		Block
	};

	class Variable : public Instruction, public Identifiable
	{
	public:
		Variable(const ItemPosition& position)
			: Instruction(position),
			scope(Scope::Block)
		{
		}

	public:
		void setScope(Scope s)
		{
			scope = s;
		}

		Scope getScope() const
		{
			return scope;
		}

	public:
		virtual bool checkSemantic()
		{
			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << "Var {" << endl;

			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			out << getTypeName() << endl;

			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			out << "Ident(" << getName() << ')' << endl;

			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << '}' << endl;
		}

	public:
		virtual bool isVariable() const { return true; }

	private:
		Scope scope;
	};
}

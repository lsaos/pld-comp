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
		virtual bool isVariable() const { return true; }
		virtual bool isIdentifiable() const { return true; }

	private:
		Scope scope;
	};
}

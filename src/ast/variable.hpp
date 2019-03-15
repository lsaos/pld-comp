#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "instruction.hpp"

namespace ast
{
	class Variable : public Instruction
	{
	public:
		Variable(const ItemPosition& position)
			: Instruction(position),
			type(Type::Void)
		{
		}

	public:
		void setType(Type t)
		{
			type = t;
		}

		void setName(const string& n)
		{
			assert(!n.empty());
			name = n;
		}

		Type getType() const
		{
			return type;
		}

		const string& getName() const
		{
			return name;
		}

	public:
		virtual bool isVariable() const { return true; }

	private:
		Type type;
		string name;
	};
}

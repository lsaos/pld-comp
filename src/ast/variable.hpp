#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "instruction.hpp"
#include "identifiable.hpp"

namespace ast
{
	class Variable : public Instruction, public Identifiable
	{
	public:
		Variable(const ItemPosition& position, Block* parent)
			: Instruction(position, parent)
		{
		}

	public:
		virtual bool isVariable() const { return true; }
		virtual bool isIdentifiable() const { return true; }
	};
}

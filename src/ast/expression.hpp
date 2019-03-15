#pragma once

#include "instruction.hpp"
#include "type.hpp"

namespace ast
{
	class Expression : public Instruction
	{
	public:
		Expression(const ItemPosition& position, Block* parent)
			: Instruction(position, parent)
		{
		}

	public:
		virtual Type getType() const = 0;

		virtual int getValue() const
		{
			error(Error::NotConstant, this);
			return 0;
		}

		virtual bool isConstant() const
		{
			return false;
		}
	};
}

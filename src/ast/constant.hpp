#pragma once

#include "expression.hpp"
#include "type.hpp"

namespace ast
{
	class Constant : public Expression
	{
	public:
		Constant(const ItemPosition& position)
			: Expression(position),
			type(Type::Void),
			value(0)
		{
		}

	public:
		void setValue(int val)
		{
			value = val;
		}

		void setType(Type t)
		{
			type = t;
		}

	public:
		virtual Type getType() const
		{
			return type;
		}

		virtual int getValue() const
		{
			return value;
		}

	private:
		Type type;
		int value;
	};
}

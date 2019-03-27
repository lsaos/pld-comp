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

		virtual bool isConstant() const
		{
			return true;
		}

		virtual bool checkSemantic()
		{
			if (type == Type::Void) {
				error(Error::InvalidStatement, this);
				return false;
			}

			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << "Const(";

			switch (type)
			{
			case Type::Character: out << '\'' << (char)value << '\''; break;
			case Type::Integer: out << value; break;
			default: out << "error"; break;
			}

			out << ')' << endl;
		}

		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}

	private:
		Type type;
		int value;
	};
}

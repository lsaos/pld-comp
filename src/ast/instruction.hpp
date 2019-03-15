#pragma once

#include <cassert>
#include <iostream>

using namespace std;

#include "error.hpp"

namespace ast
{
	struct ItemPosition
	{
		ItemPosition() : line(0), offset(0) {}

		size_t line;
		size_t offset;
	};

	class Instruction
	{
	public:
		Instruction(const ItemPosition& position)
			: pos(position)
		{
		}

		virtual ~Instruction()
		{
		}

	public:
		const ItemPosition& getPosition() const
		{
			return pos;
		}

	public:
		virtual bool isFunction() const { return false; }
		virtual bool isVariable() const { return false; }

	protected:
		void error(Error error, const Instruction* instruction)
		{
			assert(instruction);

			cout << "Error S" << (int)error
				<< " on line " << instruction->getPosition().line
				<< ", " << instruction->getPosition().offset
				<< ": ";

			switch (error)
			{
			case Error::None:
				cout << "none";
				break;
			case Error::InvalidInstruction:
				cout << "invalid instruction";
				break;
			}

			cout << endl;
		}

	private:
		ItemPosition pos;
	};
}

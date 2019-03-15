#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "block.hpp"

namespace ast
{
	class Block;

	class Function : public Block
	{
	public:
		Function(const ItemPosition& position)
			: Block(position)
		{
		}

	public:
		void setName(const string& n)
		{
			assert(!n.empty());
			name = n;
		}

		const string& getName() const
		{
			return name;
		}

	public:
		virtual bool isFunction() const { return true; }

	private:
		string name;
	};
}

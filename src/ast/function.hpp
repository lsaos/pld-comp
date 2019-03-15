#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "block.hpp"
#include "identifiable.hpp"

namespace ast
{
	class Block;

	class Function : public Block, public Identifiable
	{
	public:
		Function(const ItemPosition& position, Block* parent)
			: Block(position, parent)
		{
		}

	public:
		virtual bool isFunction() const { return true; }
		virtual bool isIdentifiable() const { return true; }
	};
}

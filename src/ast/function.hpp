#pragma once

#include <string>

using namespace std;

#include "type.hpp"

namespace ast
{
	class Block;

	class Function
	{
	private:
		string name;
		Block* block;
		Type returnType;
	};
}

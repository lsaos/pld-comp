#pragma once

#include <string>

using namespace std;

#include "type.hpp"

namespace ast
{
	class Variable
	{
	private:
		Type type;
		string name;
	};
}

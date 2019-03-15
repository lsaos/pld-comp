#pragma once

#include <vector>

using namespace std;

namespace ast
{
	class Function;

	class Program
	{
	private:
		vector<Function*> functions;
	};
}

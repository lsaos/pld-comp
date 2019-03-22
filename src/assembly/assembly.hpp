#pragma once

#include <vector>
#include <fstream>
#include <map>
#include "../ast/variable.hpp"
#include "../ast/program.hpp"
#include "../ast/function.hpp"
#include "../ast/instruction.hpp"

using namespace std;

namespace assembly {

	enum class SizeType
	{
		Character = 1,
		Integer = 4
	};

	class AssemblyGenerator {
		public:
			AssemblyGenerator(string fileName);
			~AssemblyGenerator() {}
			void generateAssembly(ast::Program* prog);

		protected:
			ofstream file;
			map<ast::Variable, int> addressTable;

	};
}
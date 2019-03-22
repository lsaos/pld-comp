#pragma once

#include <vector>
#include <fstream>
#include <unordered_map>
#include "../ast/variable.hpp"
#include "../ast/program.hpp"
#include "../ast/function.hpp"
#include "../ast/instruction.hpp"

using namespace std;

namespace assembly {

	class AssemblyGenerator {
		public:
			AssemblyGenerator(string fileName);
			~AssemblyGenerator() {}
			void generateAssembly(ast::Program* prog);
			unordered_map<ast::Variable*, int>* getAddressTable() const;
			ofstream getFile();

		protected:
			ofstream file;
			unordered_map<ast::Variable*, int> addressTable;

	};
}
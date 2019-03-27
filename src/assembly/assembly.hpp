#pragma once

#include <vector>
#include <fstream>
#include <unordered_map>
#include "../ast/variable.hpp"
#include "../ast/program.hpp"
#include "../ast/function.hpp"
#include "../ast/instruction.hpp"

using namespace std;

namespace assembly 
{

	class AssemblyGenerator 
	{
		public:
			AssemblyGenerator(string fileName);

			~AssemblyGenerator() 
			{
				file.close(); 
			}

			void generateAssembly(ast::Program* program);
			unordered_map<ast::Variable*, int>& getAddressTable();
			ofstream& getFile();

		protected:
			ofstream file;
			unordered_map<ast::Variable*, int> addressTable;

	};
}
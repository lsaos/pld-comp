#include "assembly.hpp"

AssemblyGenerator::AssemblyGenerator(string fileName)
{
	this.file = new ofstream(fileName.substr(0, fileName.size() - 1) + "s", ios::out);
}

void AssemblyGenerator::generateAssembly(ast::Program* program)
{
	ast::Function* main = program->getMain();
	vector<ast::Instruction*> instructions = main->getInstructions;
	
}
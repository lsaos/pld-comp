#include "assembly.hpp"

using namespace assembly;

AssemblyGenerator::AssemblyGenerator(string fileName)
{
	this.file = new ofstream(fileName.substr(0, fileName.size() - 1) + "s", ios::out);
}

void AssemblyGenerator::generateAssembly(ast::Program* program)
{
	ast::Function* main = program->getMain();
	vector<unique_ptr<ast::Instruction> instructions = main->getInstructions();
	vector<ast::Variable*> variables = main->getVariables();
	int rbp = 0;

	for (auto i : variables)
	{
		switch (i->getType()) 
		{
			case ast::Type.Integer :
				rbp -= 4;
				break;
			case ast::Type.Character :
				rbp -= 1;
				break;
		}
		addressTable[i] = rbp;
	}

	//Prologue
	*file << ".text" << endl << ".global main" << endl;
	*file << "main:" << endl;
	*file << "pushq %rbp" << endl;
	*file << "movq %rsp, %rbp" << endl;

	//Corps du programme
	for (auto instr : instructions) 
	{
		//instr->generateAssembly(this);
	}

	//Epilogue
	*file << "popq %rbp" << endl << "ret" << endl;
}

unordered_map<ast::Variable*, int>* AssemblyGenerator::getAddressTable() const
{
	return &addressTable;
}

ofstream AssemblyGenerator::getFile() 
{
	return file;
}
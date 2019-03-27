#include "assembly.hpp"

using namespace assembly;

AssemblyGenerator::AssemblyGenerator(string fileName)
{
	file = new ofstream(fileName.substr(0, fileName.size() - 1) + "s", ios::out);
	addressTable = new unordered_map<ast::Variable*, int>();
}

void AssemblyGenerator::generateAssembly(ast::Program* program)
{
	ast::Function* main = program->getMain();
	vector<ast::Instruction*> instructions = main->getInstructions();
	vector<ast::Variable*> variables = main->getVariables(false);
	int rbp = 0;

	for (auto i : variables)
	{
		switch (i->getType()) 
		{
			case ast::Type::Integer :
				rbp -= 4;
				break;
			case ast::Type::Character :
				rbp -= 1;
				break;
		}
		addressTable->at(i) = rbp;
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
		//instr->generateAssembly(this->file, this->addressTable);
	}

	//Epilogue
	*file << "popq %rbp" << endl << "ret" << endl;
}

unordered_map<ast::Variable*, int>* AssemblyGenerator::getAddressTable() const
{
	return addressTable;
}

ofstream* AssemblyGenerator::getFile() 
{
	return file;
}
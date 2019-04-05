//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <vector>
#include <memory>

using namespace std;

#include "instruction.hpp"

namespace ast
{
	class Variable;

	// Represents a block of instructions.
	class Block : public Instruction
	{
	public:
		// Create a block.
		Block(const ItemPosition& position);

	public:
		// Add the specified instruction to the block.
		// The block takes the ownership of the instruction.
		void add(Instruction* instr, bool atBeginning=false);

	public:
		// Get the variable with the specified name.
		// If withAncestors, the method will search in parents too.
		Variable* getVariable(const string& name, bool withAncestors) const;

		// Get the list of existing variables in the block.
		// If withAncestors, the method will search in parents too.
		vector<Variable*> getVariables(bool withAncestors) const;

		// Get block instructions which are NOT variable declarations.
		vector<Instruction*> getInstructions() const;

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual void toTextualRepresentation(ostream& out, size_t i) const;
		virtual Instruction* optimize();
		virtual void prepare();

	public:
		virtual bool isBlock() const { return true; }

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*,int>& addressTable, string curReg = "%eax") {}
		virtual string buildIR(ir::CFG*);

	protected:
		vector<unique_ptr<Instruction>> instructions; // List of instructions in the block.
	};
}

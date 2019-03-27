#pragma once

#include "block.hpp"
#include "variable.hpp"

using namespace ast;

Variable* Block::getVariable(const string& name, bool withAncestors)
{
	for (const auto& instr : instructions) {
		if (instr->isVariable() && ((Variable*)instr.get())->getName() == name) {
			return (Variable*)instr.get();
		}
	}

	if (withAncestors) {
		Block* parentBlock = getParentBlock();
		if (parentBlock) {
			return parentBlock->getVariable(name, true);
		}
	}

	return nullptr;
}

vector<Variable*> Block::getVariables(bool withAncestors)
{
	vector<Variable*> vars;

	for (const auto& instr : instructions) {
		if (instr->isVariable()) {
			vars.push_back((Variable*)instr.get());
		}
	}

	if (withAncestors) {
		Block* parentBlock = getParentBlock();
		if (parentBlock) {
			vector<Variable*> parentVars(parentBlock->getVariables(true));
			vars.insert(vars.end(), parentVars.begin(), parentVars.end());
		}
	}

	return vars;
}

vector<Instruction*> Block::getInstructions()
{
	vector<Instruction*> instrs;

	for (const auto& instr : instructions) {
		if (!instr->isVariable()) {
			instrs.push_back(instr.get());
		}
	}

	return instrs;
}

bool Block::checkSemantic()
{
	// Check children semantic
	for (auto& instr : instructions) {
		if (!instr->checkSemantic()) {
			return false;
		}
	}

	// Check symbols duplication
	if (getParentBlock()) {
		vector<string> symbols;

		const vector<Variable*> vars(getParentBlock()->getVariables(true));
		for (const Variable* var : vars) {
			symbols.push_back(var->getName());
		}

		/*const vector<Function*> funcs(getProgram()->getFunctions());
		for (const Function* func : funcs) {
			symbols.push_back(func->getName());
		}*/

		for (auto& instr : instructions) {
			if (instr->isVariable()) {
				const string& name(((const Variable*)instr.get())->getName());

				if (find(symbols.begin(), symbols.end(), name) != symbols.end()) {
					error(Error::DuplicatedSymbolName, instr.get());
					return false;
				}

				symbols.push_back(name);
			}
		}
	}

	return true;
}

void Block::toTextualRepresentation(ostream& out, size_t i)
{
	for (size_t j = 0; j < i; j++) { out << ' '; }
	cout << "ListInstr {" << endl;

	for (auto& instr : instructions) {
		instr->toTextualRepresentation(out, i + 1);
	}

	for (size_t j = 0; j < i; j++) { out << ' '; }
	out << '}' << endl;
}

void Block::add(Instruction* instr)
{
	assert(instr);
	instr->setParent(this);
	instructions.push_back(unique_ptr<Instruction>(instr));
}

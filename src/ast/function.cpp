#pragma once

#include "function.hpp"
#include "variable.hpp"

using namespace ast;

Function::Function(const ItemPosition& position) : Block(position) { }

void Function::addParameter(Variable* var)
{
	assert(var);

	var->setScope(Scope::Parameter);
	add(var);
}

vector<Variable*> Function::getParameters()
{
	vector<Variable*> params;

	for (auto& instr : instructions) {
		if (instr->isVariable() && ((Variable*)instr.get())->getScope() == Scope::Parameter) {
			params.push_back((Variable*)instr.get());
		}
	}

	return params;
}

size_t Function::getParametersCount()
{
	size_t cnt = 0;

	for (auto& instr : instructions) {
		if (instr->isVariable() && ((Variable*)instr.get())->getScope() == Scope::Parameter) {
			cnt++;
		}
	}

	return cnt;
}

void Function::toTextualRepresentation(ostream& out, size_t i)
{
	for (size_t j = 0; j < i; j++) { out << ' '; }
	out << "DefFun {" << endl;

	for (size_t j = 0; j < i + 1; j++) { out << ' '; }
	out << getTypeName() << endl;

	for (size_t j = 0; j < i + 1; j++) { out << ' '; }
	out << "Ident(" << getName() << ')' << endl;

	Block::toTextualRepresentation(out, i + 1);

	for (size_t j = 0; j < i; j++) { out << ' '; }
	out << '}' << endl;
}

bool Function::isFunction() const 
{ 
	return true; 
}
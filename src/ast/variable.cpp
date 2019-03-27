#pragma once

#include "variable.hpp"

using namespace ast;

Variable::Variable(const ItemPosition& position)
	: Instruction(position),
	scope(Scope::Block)
{
}

void Variable::setScope(Scope s)
{
	scope = s;
}

Scope Variable::getScope() const
{
	return scope;
}

bool Variable::checkSemantic()
{
	if (getName().empty() || getType() == Type::Void) {
		error(Error::InvalidStatement, this);
		return false;
	}

	return true;
}

void Variable::toTextualRepresentation(ostream& out, size_t i)
{
	for (size_t j = 0; j < i; j++) { out << ' '; }
	out << "Var {" << endl;

	for (size_t j = 0; j < i + 1; j++) { out << ' '; }
	out << getTypeName() << endl;

	for (size_t j = 0; j < i + 1; j++) { out << ' '; }
	out << "Ident(" << getName() << ')' << endl;

	for (size_t j = 0; j < i; j++) { out << ' '; }
	out << '}' << endl;
}

void Variable::generateAssembly(ofstream& f, unordered_map<ast::Variable*,int>& addressTable) 
{
	f << "\tmovl " << addressTable[this] << "(%rbp), %eax" << endl;
}
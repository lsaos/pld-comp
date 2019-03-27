#pragma once

#include "instruction.hpp"
#include "block.hpp"
#include "function.hpp"
#include "program.hpp"

using namespace ast;

Instruction::Instruction(const ItemPosition& position)	: pos(position), parent(nullptr) {}

const ItemPosition& Instruction::getPosition() const
{
	return pos;
}

void Instruction::setParent(Instruction* parentInstruction)
{
	assert(parentInstruction);
	parent = parentInstruction;
}

Instruction* Instruction::getParent() const
{
	return parent;
}

Block* Instruction::getParentBlock() const
{
	if (parent) {
		if (parent->isBlock()) {
			return (Block*)parent;
		}
		else {
			return parent->getParentBlock();
		}
	}

	return nullptr;
}

Function* Instruction::getParentFunction() const
{
	if (parent) {
		if (parent->isFunction()) {
			return (Function*)parent;
		}
		else {
			return parent->getParentFunction();
		}
	}

	return nullptr;
}

Program* Instruction::getProgram() const
{
	if (isProgram()) {
		return (Program*)this;
	}
	else if (parent) {
		return parent->getProgram();
	}
	else {
		return nullptr;
	}
}

void Instruction::error(Error error, const Instruction* instruction) const
{
	assert(instruction);

	cout << "Error S" << (int)error
		<< " on line " << instruction->getPosition().line
		<< ", " << instruction->getPosition().offset
		<< ": ";

	switch (error)
	{
	case Error::None: cout << "none"; break;
	case Error::InvalidInstruction: cout << "invalid instruction"; break;
	case Error::DivisionByZero: cout << "division by zero"; break;
	case Error::NotConstant: cout << "not constant"; break;
	case Error::NoMain: cout << "no main function"; break;
	case Error::InvalidStatement: cout << "invalid statement"; break;
	case Error::DuplicatedSymbolName: cout << "duplicated symbol name"; break;
	case Error::ExpectingExpression: cout << "excepting an expression"; break;
	case Error::UnknownIdentifier: cout << "unknown identifier"; break;
	default: cout << "unknown error"; break;
	}

	cout << endl;
}
//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "instruction.hpp"

namespace ast
{
	//
	// ItemPosition
	//

	ItemPosition::ItemPosition()
		: line(0),
		offset(0)
	{
	}

	ItemPosition::ItemPosition(size_t _line, size_t _offset)
		: line(_line), offset(_offset)
	{
	}

	//
	// Instruction
	//

	Instruction::Instruction(const ItemPosition& position)
		: pos(position),
		parent(nullptr)
	{
	}

	Instruction::~Instruction()
	{
	}

	void Instruction::setParent(Instruction* parentInstruction)
	{
		assert(parentInstruction);
		parent = parentInstruction;
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

		cout << "Error SE" << (int)error
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

		const string representation = getStringRepresentation();
		if (!representation.empty()) {
			cout << " '" << representation << '\'';
		}

		cout << endl;

		// Throw an exception to prevent further analysis
		throw exception();
	}

	void Instruction::warning(Warning warning, const Instruction* instruction) const
	{
		assert(instruction);

		cout << "Warning SW" << (int)warning
			<< " on line " << instruction->getPosition().line
			<< ", " << instruction->getPosition().offset
			<< ": ";

		switch (warning)
		{
		case Warning::None: cout << "none"; break;
		case Warning::UnusedVariable: cout << "unused variable"; break;
		default: cout << "unknown warning"; break;
		}

		const string representation = getStringRepresentation();
		if (!representation.empty()) {
			cout << " '" << representation << '\'';
		}

		cout << endl;
	}
}

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
		assert(parentInstruction != this);

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

		cerr << "Error SE" << (int)error
			<< " on line " << instruction->getPosition().line
			<< ", " << instruction->getPosition().offset
			<< ": ";

		switch (error)
		{
		case Error::None: cerr << "none"; break;
		case Error::InvalidInstruction: cerr << "invalid instruction"; break;
		case Error::DivisionByZero: cerr << "division by zero"; break;
		case Error::NotConstant: cerr << "not constant"; break;
		case Error::NoMain: cerr << "no main function"; break;
		case Error::InvalidStatement: cerr << "invalid statement"; break;
		case Error::DuplicatedSymbolName: cerr << "duplicated symbol name"; break;
		case Error::ExpectingExpression: cerr << "expecting an expression"; break;
		case Error::UnknownIdentifier: cerr << "unknown identifier"; break;
		case Error::WrongArgumentsCount: cerr << "wrong number of arguments"; break;
		case Error::MissingArraySize: cerr << "missing array size"; break;
		case Error::InvalidArraySize: cerr << "invalid array size"; break;
		case Error::MissingArrayIndex: cerr << "missing array index"; break;
		case Error::IndexOutOfBounds: cerr << "index out of array bounds"; break;
		default: cerr << "unknown error"; break;
		}

		const string representation = instruction->getStringRepresentation();
		if (!representation.empty()) {
			cerr << " '" << representation << '\'';
		}

		cerr << endl;

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
		case Warning::UnsafeCast: cout << "cast can lose information"; break;
		default: cout << "unknown warning"; break;
		}

		const string representation = instruction->getStringRepresentation();
		if (!representation.empty()) {
			cout << " '" << representation << '\'';
		}

		cout << endl;
	}
}

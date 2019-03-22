#pragma once

#include <cassert>
#include <iostream>
#include <ostream>

using namespace std;

#include "error.hpp"

namespace ast
{
	class Block;
	class Program;
	class Function;

	struct ItemPosition
	{
		ItemPosition() : line(0), offset(0) {}

		size_t line;
		size_t offset;
	};

	class Instruction
	{
	public:
		Instruction(const ItemPosition& position)
			: pos(position),
			parent(nullptr)
		{
		}

		virtual ~Instruction()
		{
		}

	public:
		const ItemPosition& getPosition() const
		{
			return pos;
		}

		void setParent(Instruction* parentInstruction)
		{
			assert(parentInstruction);
			parent = parentInstruction;
		}

		Instruction* getParent() const
		{
			return parent;
		}

		Block* getParentBlock() const
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

		Function* getParentFunction() const
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

		Program* getProgram() const
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

	public:
		virtual bool checkSemantic() = 0;
		virtual void toTextualRepresentation(ostream& out, size_t i) {}

	public:
		virtual bool isFunction() const { return false; }
		virtual bool isVariable() const { return false; }
		virtual bool isBlock() const { return false; }
		virtual bool isProgram() const { return false; }
		virtual bool isFunctionCall() const { return false; }

	protected:
		void error(Error error, const Instruction* instruction) const
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

	private:
		ItemPosition pos;
		Instruction* parent;
	};
}

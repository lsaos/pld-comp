//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <cassert>
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

#include "error.hpp"

namespace ast
{
	class Block;
	class Program;
	class Function;
	class Variable;

	// Represents a position in a source file.
	struct ItemPosition
	{
	public:
		// Creates a null position.
		ItemPosition();

		// Creates a position from the specified line and offset.
		ItemPosition(size_t line, size_t offset);

	public:
		size_t line; // Number of the line.
		size_t offset; // Character offset on the line.
		// In a complete compiler we should have the filename here too.
	};

	// Base class for a node in the AST.
	class Instruction
	{
	public:
		// Creates an instruction with the specified position
		// in the source code file.
		Instruction(const ItemPosition& position);

		// Destructs an instruction.
		// All destructors should be empty.
		virtual ~Instruction();

	public:
		// Set the instruction's parent.
		void setParent(Instruction* parentInstruction);

	public:
		// Get the instruction position in the source code file.
		const ItemPosition& getPosition() const {
			return pos;
		}

		// Get the instruction's parent.
		// The root (program) has a null parent.
		Instruction* getParent() const {
			return parent;
		}

		// Get the instruction parent's block.
		// If the current instruction is a block,
		// return the block's parent and not the block itself.
		Block* getParentBlock() const;

		// Get the instruction's parent function.
		// If the current instruction is a function,
		// a null pointer is returned.
		Function* getParentFunction() const;

		// Get the instruction's parent program (root of the AST).
		// If the current instruction is the program, return
		// the program itself.
		Program* getProgram() const;

	public:
		// Check the semantic correctness of the instruction.
		// If the advanced parameter is true, performs advanced
		// checks which can throw errors or warnings.
		virtual void checkSemantic(bool advanced) const = 0;

		// Outputs a textual representation of the instruction
		// on the specified stream.
		virtual void toTextualRepresentation(ostream& out, size_t i) const = 0;

		// Try to optimize the instruction.
		// The method can return a new instruction which replaces
		// the current instruction in the AST.
		virtual Instruction* optimize() { return nullptr; }

		// Prepare the instruction before checking semantic.
		virtual void prepare() {}

	public:
		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable) = 0;

	public:
		// Get a string representation of the instruction.
		virtual string getStringRepresentation() const { return string(); }

		// Return true if the current instruction is a function.
		virtual bool isFunction() const { return false; }

		// Return true if the current instruction is a variable.
		virtual bool isVariable() const { return false; }

		// Return true if the current instruction is a block.
		virtual bool isBlock() const { return false; }

		// Return true if the current instruction is a program.
		virtual bool isProgram() const { return false; }

		// Return true if the current instruction is a function call.
		virtual bool isFunctionCall() const { return false; }

		// Return true if the current instruction is a return.
		virtual bool isReturn() const { return false; }

		// Return true if the current instruction is an expression.
		virtual bool isExpression() const { return false; }

		// Return true if the current instruction is an Identifier
		virtual bool isIdentifier() const { return false; }

	protected:
		// Report the specified error for the specified instruction.
		// Also throws an std::exception.
		void error(Error error, const Instruction* instruction) const;

		// Report the specified warning for the specified instruction.
		void warning(Warning warning, const Instruction* instruction) const;

	private:
		const ItemPosition pos; // Instruction's position in the source code.
		Instruction* parent; // Parent's instruction.
	};
}

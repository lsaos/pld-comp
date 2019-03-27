#pragma once

#include <cassert>
#include <iostream>
#include <ostream>
#include <unordered_map>

using namespace std;

#include "error.hpp"

namespace ast
{
	class Block;
	class Program;
	class Function;
	class Variable;

	struct ItemPosition
	{
		ItemPosition() : line(0), offset(0) {}

		size_t line;
		size_t offset;
	};

	class Instruction
	{
		public:
			Instruction(const ItemPosition& position);

			virtual ~Instruction()	{}

			const ItemPosition& getPosition() const;

			void setParent(Instruction* parentInstruction);

			Instruction* getParent() const;

			Block* getParentBlock() const;

			Function* getParentFunction() const;

			Program* getProgram() const;

			virtual bool checkSemantic() = 0;
			virtual void toTextualRepresentation(ostream& out, size_t i) {}

			virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) = 0;

			virtual bool isFunction() const { return false; }
			virtual bool isVariable() const { return false; }
			virtual bool isBlock() const { return false; }
			virtual bool isProgram() const { return false; }
			virtual bool isFunctionCall() const { return false; }

		protected:
			void error(Error error, const Instruction* instruction) const;

		private:
			ItemPosition pos;
			Instruction* parent;
	};
}

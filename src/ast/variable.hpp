#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "instruction.hpp"
#include "identifiable.hpp"
#include "program.hpp"

namespace ast
{
	enum class Scope
	{
		Global,
		Parameter,
		Block
	};

	class Variable : public Instruction, public Identifiable
	{
	public:
		Variable(const ItemPosition& position);

		void setScope(Scope s);

		Scope getScope() const;

		virtual bool checkSemantic();

		virtual void toTextualRepresentation(ostream& out, size_t i);

		virtual bool isVariable() const { return true; }

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*,int>& addressTable);

	private:
		Scope scope;
	};
}

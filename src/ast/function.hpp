#pragma once

#include <string>

using namespace std;

#include "type.hpp"
#include "block.hpp"
#include "identifiable.hpp"

namespace ast
{
	class Block;

	class Function : public Block, public Identifiable
	{
	public:
		Function(const ItemPosition& position)
			: Block(position)
		{
		}

	public:
		void addParameter(Variable* var)
		{
			assert(var);

			var->setScope(Scope::Parameter);
			add(var);
		}

		vector<Variable*> getParameters()
		{
			vector<Variable*> params;

			for (auto& instr : instructions) {
				if (instr->isVariable() && ((Variable*)instr.get())->getScope() == Scope::Parameter) {
					params.push_back((Variable*)instr.get());
				}
			}

			return params;
		}

		size_t getParametersCount()
		{
			size_t cnt = 0;

			for (auto& instr : instructions) {
				if (instr->isVariable() && ((Variable*)instr.get())->getScope() == Scope::Parameter) {
					cnt++;
				}
			}

			return cnt;
		}

	public:
		virtual void toTextualRepresentation(ostream& out, size_t i)
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

	public:
		virtual bool isFunction() const { return true; }
	};
}

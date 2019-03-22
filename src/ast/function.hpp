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

			for (Instruction* instr : instructions) {
				if (instr->isVariable() && ((Variable*)instr)->getScope() == Scope::Parameter) {
					params.push_back((Variable*)instr);
				}
			}

			return params;
		}

		size_t getParametersCount()
		{
			size_t cnt = 0;

			for (Instruction* instr : instructions) {
				if (instr->isVariable() && ((Variable*)instr)->getScope() == Scope::Parameter) {
					cnt++;
				}
			}

			return cnt;
		}

	public:
		virtual bool isFunction() const { return true; }
		virtual bool isIdentifiable() const { return true; }
	};
}

#pragma once

#include <string>
#include <vector>

using namespace std;

#include "type.hpp"
#include "identifiable.hpp"
#include "block.hpp"

namespace ast
{

	class Variable;

	class Function : public Block, public Identifiable
	{
	public:
		Function(const ItemPosition& position);

		void addParameter(Variable* var);

		vector<Variable*> getParameters();

		size_t getParametersCount();

		virtual void toTextualRepresentation(ostream& out, size_t i);

		virtual bool isFunction() const;

		virtual void generateAssembly(ofstream*, unordered_map<ast::Variable*, int>*) {}
	};
}
